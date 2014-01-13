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

program expr space	{printf("Value: %d\n",$2);}
|
;

expr:

INTEGER			{$$=$1;}
| expr plus expr	{$$=$1+$3;}
| expr mul expr		{$$=$1*$3;}
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
