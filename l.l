%{
    #include<stdio.h>
    #include"y.tab.h"

    struct node{
        int type;
        int attrval;
        struct node *left,*right;
    };
    #define OPERATOR 0
    #define VALUE 1
%}

%%
[0-9]+  {yylval.opt=(struct node *)malloc(sizeof(struct node));
         yylval.opt->type=VALUE;
         yylval.opt->attrval=atoi(yytext);
         yylval.opt->left=NULL;
         yylval.opt->right=NULL;
         return NUM;
         }
"+"     {yylval.opt=(struct node *)malloc(sizeof(struct node));
         yylval.opt->type=OPERATOR;
         yylval.opt->attrval=PLUS;
         yylval.opt->left=NULL;
         yylval.opt->right=NULL;
         return PLUS;
         }
"*"	{yylval.opt=(struct node *)malloc(sizeof(struct node));
         yylval.opt->type=OPERATOR;
         yylval.opt->attrval=MUL;
         yylval.opt->left=NULL;
         yylval.opt->right=NULL;
         return MUL;
         }
"("	{return LB;}
")"	{return RB;}
"\n"	{return END;}
[ \t]	;

