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
[\n]	return whitesp;
[\(]	return lt_brak;
[\)]	return rt;
[ \t] ; /* skip whitespace */
. 	yyerror("invalid character");

%%
int yywrap(void) 
{
	return 1;
}

