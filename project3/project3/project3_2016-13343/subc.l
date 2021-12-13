%{
/*
 * File Name   : subc.l
 * Description : a skeleton flex input
 */

#include "subc.h"
#include "subc.tab.h"
static int comment_depth = 0;
static int lineno = 1;
static int prev_err_line;

%}

/* regular definitions */
letter		[A-Za-z_]
digit		[0-9]
id		{letter}({letter}|{digit})*
integer_const	([1-9]{digit}*)|"0"
white-space		[ \t\v\f]+
special-char	\\[nt]


%x COMMENT
%%
"int"|"char"   {
            struct id *entered  = enter(ID, yytext, yyleng);
		    yylval.idptr = entered;
            return TYPE; 
        }
"void"  { 
            struct id *entered  = enter(ID, yytext, yyleng);
		    yylval.idptr = entered;
            return VOID; 
    }
"struct" 	{ return STRUCT; }
"NULL"  { return NULL_; }
"return"    { return RETURN; }
"if"    { return IF; }
"else"  { return ELSE; }
"while" { return WHILE; }
"for"   { return FOR; }
"break" { return BREAK; }
"continue"  { return CONTINUE; }
"||"    { return LOGICAL_OR; }
"&&"    { return LOGICAL_AND; }
"<"|"<="|">"|">="   { return RELOP; }
"=="|"!="   { return EQUOP; }
"++"    { return INCOP; }
"--"    { return DECOP; }
"->"    { return STRUCTOP; }

{id}	{
        struct id *entered  = enter(ID, yytext, yyleng);
        yylval.idptr = entered;
        return ID;
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

{white-space}
<*>\n		   ++lineno;
<*>\r\n        ++lineno;
<INITIAL,COMMENT>"/*"	{
		   ++comment_depth;
		   BEGIN (COMMENT);
		}
<COMMENT>"*/"	   if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.		 {}
<INITIAL>.       { 
        return yytext[0]; 
    }


%%

/*
 * Function:  inittype
 * --------------------
 *	initialize needed types (int, char void)
 *  make returnid token
 * 
 *  returns: void
 */
void inittype()
{
    inttype = maketypedecl(INT);
    chartype = maketypedecl(CHAR);
    voidtype = maketypedecl(VOID);

    declare(enter(ID, "int", 3), inttype);
    declare(enter(ID, "char", 4), chartype);
    declare(enter(ID, "void", 4), voidtype);
    returnid = enter(ID, "*return", 7);

}

int read_line()
{
    return lineno;
}

int main(int argc, char* argv[])
{
    if(argc >= 2) yyin = fopen(argv[1], "r");
    else yyin = stdin;
    if(!yyin) {
        printf("Can't open input stream!\n");
        exit(1);
    }
    if (strchr(argv[1], '/'))
    {
        filename = strrchr(argv[1], '/') + 1;
    }
    else {
        filename = argv[1];
    }
    inittype();
    yyparse();
    fclose(yyin);
    return 0;
}
