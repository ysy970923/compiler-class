%{
/**************************************************************
* File Name   : subc.l
*
* Description
*	This is a skeleton input file to lex.
*
* Which tool to use
*	The GNU lex-clone, flex/flex++ is recommended to use.
*	It supports a C++ mode.
*	For any information about flex, refer to flex.man.
*
*	Good Luck!
*
***************************************************************/

/**************************************************************/
/* This section will appear at the head of lex.yy.c/lex.yy.cc */
/**************************************************************/

#include "subc.h"
/***************************************************************
{Other useful code segments can be here.}
***************************************************************/
int commentdepth=0;
id* yylval;
%}

ws [ \t\n\v\r\f]
letter		[A-Za-z_]
digit		[0-9]
operator	"("|")"|"["|"]"|"{"|"}"|->|,|"."|".."|!|~|"++"|--|"*"|"/"|%|"+"|-|<<|>>|<|<=|>|>=|==|!=|&|"^"|"|"|&&|"||"|"\?"|:|;|=|"+="|-=|"*="|"/="|%=|&=|"^="|"|="|<<=|>>=
id			{letter}({letter}|{digit})*
integer 	([1-9]+{digit}*)|0
float		{digit}+\.{digit}*([eE][\+-]?{digit}+)?
%start AA BB

%%
<AA>{id} {yylval = enter(IDENTIFIER, yytext, strlen(yytext)); printf("%s %s %u\n", tokenType2Text(yylval->tokenType), yylval->name, yylval->count);}
<AA>{operator} {printf("OP %s\n", yytext);}
<AA>{integer} {printf("INT %s\n", yytext);}
<AA>{float}/([^\.]) {printf("F %s\n", yytext);}
<AA>{ws} {;}
<AA>. {printf("invalid token %s\n", yytext);}
"/*" {commentdepth++; BEGIN BB;}
"*/"/[^*] {commentdepth--; if(commentdepth == 0) BEGIN AA;}
<BB>. {;}
%%
void initHash()
{
	int i;

	char* keyWord[]={
		"auto","break","case","char","continue","default","do","double","else",
		"extern","float","for","goto","if","int","long","register","return","short",
		"sizeof","static","struct","switch","typedef","union","unsigend","void","while",
		"\0"
	};

	/* Initilize Hash Tabel with Keywords */
	for (i = 0; strcmp(keyWord[i], "\0") !=0; i++) {
		enter(KEYWORD, keyWord[i], strlen(keyWord[i]));
	}
}

int main(int argc, char** argv)
{
	id* temp;

	++argv;
	--argc;

	if (argc > 0) {
		yyin = fopen(argv[0], "r");
	} else {
		yyin = stdin;
	}

	initHash();

	BEGIN AA;
	yylex ();

	return 0;
}
