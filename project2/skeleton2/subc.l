%{
/*
 * File Name   : subc.l
 * Description : a skeleton flex input
 */

#include "subc.h"
#include "subc.tab.h"
static int comment_depth = 0;
static int lineno = 1;

%}

/* regular definitions */
letter		[A-Za-z_]
digit		[0-9]
id		{letter}({letter}|{digit})*
integer_const	([1-9]{digit}*)|"0"
ws [ \t\n\v\r\f]
special-char	\\[nt]

%x COMMENT
%%
"int" 	|
"char"	{ 
            struct id *entered = enter(TYPE, yytext, yyleng);
            yylval.stringVal = entered->name;
            return TYPE; 
        }
"struct" 	{ return STRUCT; }
"return"    { return RETURN; }
"if"    { return IF; }
"else"  { return ELSE; }
"while" { return WHILE; }
"for"   { return FOR; }
"break" { return BREAK; }
"continue"  { return CONTINUE; }
"+="|"-="|"*="|"/="|"%="    { return ASSIGNOP; }
"||"    { return LOGICAL_OR; }
"&&"    { return LOGICAL_AND; }
"<"|"<="|">"|">="   { return RELOP; }
"=="|"!="   { return EQUOP; }
"++"    { return PLUS_PLUS; }
"--"    { return MINUS_MINUS; }
"." { return STRUCTOP; }
{id}	{
		    struct id *entered  = enter(ID, yytext, yyleng);
		    yylval.stringVal = entered->name;
		    return entered->tokenType;
		}
{integer_const}	{
		    yylval.intVal = atoi(yytext);
		    return INTEGER_CONST;
		}
\"({special-char}|[^\\\"\n])*\"	{
	        /* String Variable */
		    yylval.stringVal = yytext;
		    return STRING;
		}
'({special-char}|[^\\'\n])'	{
			/* Character Variable */
		   yylval.stringVal = yytext;
		   return CHAR_CONST;
		}
{ws}    {}
<*>\n		   ++lineno;
<INITIAL,COMMENT>"/*"	{
		   ++comment_depth;
		   BEGIN (COMMENT);
		}
<COMMENT>"*/"	   if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.		 {}
<INITIAL>. { return yytext[0]; }


%%
   
int main(int argc, char* argv[])
{
   static char *keyword[] = { "int", NULL };
   static int tokentype[] = { TYPE, 0 };
   int i;
   for(i = 0; keyword[i] != NULL; i++)
      enter(tokentype[i], keyword[i], strlen(keyword[i]));

   if(argc >= 2) yyin = fopen(argv[1], "r");
   else yyin = stdin;
   if(!yyin) {
      printf("Can't open input stream!\n");
      exit(1);
   }
	
   yyparse();
   fclose(yyin);
   return 0;
}
