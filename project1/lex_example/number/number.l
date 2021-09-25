digit	[0-9]
%%

[\n\t ] { ; }

-?((({digit}+)|({digit}*\.{digit}+))([eE][-+]?{digit}+)?) { printf("number\n"); }

. { ; }

%%
int main()
{
	yylex();
}
