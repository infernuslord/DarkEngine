/* Test lexer for hashtable.  */
%{
#include "lg.h"
#include "stdlib.h"
#include "string.h"
#include "hashtok.h"
#include "hashtest.h" 
char identbuffer[HASHELEMSIZE];
%}

alpha  [a-zA-Z]
alphanum [a-zA-Z0-9]
delete (D|d)(E|e)(L|l)(E|e)(T|t)(E|e)
insert (I|i)(N|n)(S|s)(E|e)(R|r)(T|t)
list   (L|l)(I|i)(S|s)(T|t)

%%

[ \n]                  {}

[0-9]*                 { yylval = atoi(yytext); return(INTLIT);} 

";"                     { return(SEMI); }        


":="                   {return (ASSIGN);}


{delete}               { return(DELETE);}

{insert}               {return (INSERT);} 

{list}                 {return(LIST);} 

{alpha}{alphanum}*     { strncpy(identbuffer,yytext,HASHELEMSIZE-1);
                         identbuffer[HASHELEMSIZE-1] = '\0';
                         yylval = (int)&identbuffer;
                         return(IDENT); } 


%% 

int yywrap(void) { return 1;} 
