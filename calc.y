%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token INTEGER plus mul space lt_brak rt_brak
%left plus
%left mul

%%
program: 

program {printf("POSTFIX: ");} expr space
|
;

expr:

INTEGER			{printf("%d ",$1);}
| expr plus expr	{printf("+ ");}
| expr mul expr		{printf("* ");}
;

%%
void yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
}

int main(void) 
{
	yyparse();
	return 0;
}
