%{
    #include<stdio.h>
    #include<stdlib.h>
    
    #define OPERATOR 0
    #define VALUE 1
    void yyerror(char *s)
    {
        printf("%s\n",s);
    }
    
    int yywrap(){
        return 1;
    }

    int main()
    {
        yyparse();
        return 0;
    }
    
    struct node{
        int type;
        int attrval;
        struct node *left;
        struct node *right;
    };
    void parenth(struct node *root);
    void freenode(struct node *node1);
%}


%union{
    struct node *opt;
}

%start list
%type <opt> expr
%token <opt> NUM PLUS MUL
%token LB RB END
%left PLUS
%left MUL

%%
    list :
    	 | list stat END
         | list error END {yyerrok;yyclearin;printf("Error");}
         ;
    stat : expr {parenth($1);printf("\n");}
         ;
    expr : expr PLUS expr {$2->left=$1;$2->right=$3;$$=$2;}
         | expr MUL expr {$2->left=$1;$2->right=$3;$$=$2;}
         | LB expr RB {$$=$2;}
         | NUM {$$=$1;}
         ;
%%

char operator(int opcode)
{
    switch(opcode)
    {
        case PLUS : return '+';
        case MUL  : return '*';
    }
}

void parenth(struct node *root)
{
    if(root!=NULL)
    {
        if(root->type == OPERATOR)
        {
            printf("(" );
            parenth(root->left);
            printf("%c",operator(root->attrval));
            parenth(root->right);
            printf(")");
        }
        else printf("%d",root->attrval);
    }
}

void freenode(struct node *node1)
{
    if(node1!=NULL)
    {    free(node1->left);
        free(node1->right);
        free(node1);
    }
}
