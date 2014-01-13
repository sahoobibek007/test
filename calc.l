%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"
%}

%%
[0-9]+  {	
	 	yylval = atoi(yytext);
		return INTEGER;
	}
[+]	return plus;
[*]	return mul;
[\n]	return space;
[\(]	return lt_brak;
[\)]	return rt_brak;
[ \t] ; /* skip whitespace */
. 	yyerror("invalid character");

%%
int yywrap(void) 
{
	return 1;
}

