%{
/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */

#include "subc.h"
#include "subc.tab.h"
#include "scopedsymtab.c"

int    yylex ();
int    yyerror (char* s);

%}

/* yylval types */
%union {
    bool    boolVal;
	int		intVal;
	char	*stringVal;
    id      *idptr;
    decl    *declptr;
}

/* Precedences and Associativities */
%nonassoc IFX
%nonassoc ELSE
%left	','
%right '='
%left LOGICAL_OR
%left LOGICAL_AND
%left '&'
%left EQUOP
%left RELOP
%left '+' '-'
%left '*' '/' '%'
%right '!' INCOP DECOP
%left '[' ']' '(' ')' '.' STRUCTOP

/* Token and Types */
%token<idptr>       ID TYPE VOID NULL_ STRUCT RETURN IF ELSE WHILE FOR BREAK CONTINUE LOGICAL_OR LOGICAL_AND RELOP EQUOP INCOP DECOP STRUCTOP
%token<stringVal>	CHAR_CONST STRING
%token<intVal>		INTEGER_CONST

%type<boolVal>       pointers
%type<declptr>      args func_decl struct_specifier type_specifier const_expr unary expr or_expr or_list and_expr and_list binary

%%
program:
        ext_def_list
		;

ext_def_list:   
        ext_def_list ext_def
		| /* empty */
		;

ext_def:
        type_specifier pointers ID ';'  
        {
            declare($3, makevardecl($1, $2));
        }
        | type_specifier pointers ID '[' const_expr ']' ';' 
        {
            declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))));
        }
        | func_decl ';'
        | type_specifier ';'
        | func_decl
        {
            if ($1)
            {
                push_scope();
                pushstelist($1->formals);
            }    
        }
         compound_stmt
        {
            if ($1)
            {
                pop_scope();
            }
        }
        ;

type_specifier: 
        TYPE    
        {
            $$ = findcurrentdecl($1);
        }
		| VOID    
        {
            $$ = findcurrentdecl($1);
        }
		| struct_specifier
        {
            $$ = $1;
        }
        ;

struct_specifier: 
        STRUCT ID '{'   
        { 
            push_scope();   
        }
        def_list    
        {   
            ste *fields = pop_scope();
            $<declptr>$ = globaldeclare($2, makestructdecl(fields));
        }
        '}' 
        {
            $$ = $<declptr>6;
        }
		| STRUCT ID 
        {
            $$ = findstructdecl($2);
        }
        ;

func_decl: 
        type_specifier pointers ID '(' ')'
        {
            decl *procdecl = makeprocdecl();
            procdecl->returntype = $1;
            $$ = declare($3, procdecl);
        }
		| type_specifier pointers ID '(' VOID ')'
        {
            decl *procdecl = makeprocdecl();
            procdecl->returntype = $1;
            $$ = declare($3, procdecl);
        }
		| type_specifier pointers ID '('
        {
            decl *procdecl = makeprocdecl();
            if ($<declptr>$ = declare($3, procdecl))
            {
                push_scope();
                declare(returnid, $1);
            }
        }
        param_list ')'
        {
            if ($$ = $<declptr>5)
            {
                ste *formals = pop_scope();
                $$->returntype = formals->decl;
                $$->formals = formals->prev;
            }
        }
        ;

pointers: 
        '*'
        {
            $$ = true;
        }
		| /* empty */
        {
            $$ = false;
        }
        ;

param_list:
        param_decl
		| param_list ',' param_decl
        ;

param_decl: 
        type_specifier pointers ID
        {
            declare($3, makevardecl($1, $2));
        }
		| type_specifier pointers ID '[' const_expr ']'
        {
            declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))));
        }
        ;

def_list: 
        def_list def
		| /* empty */
        ;

def: 
        type_specifier pointers ID ';'
        {
            declare($3, makevardecl($1, $2));
        }
		| type_specifier pointers ID '[' const_expr ']' ';'
        {
            declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))));
        }
		| type_specifier ';'
		| func_decl ';'
        ;

compound_stmt: 
        '{' local_defs stmt_list '}'
        ;

local_defs:	
        def_list
        ;

stmt_list: 
        stmt_list stmt
		| /* empty */
        ;

stmt: 
        expr ';'
		| compound_stmt
		| RETURN ';'
        {
            functionreturn(voidtype);
        }
		| RETURN expr ';'
        {
            functionreturn($2);
        }
		| ';'
		| IF '(' expr ')' stmt %prec IFX
		| IF '(' expr ')' stmt ELSE stmt
		| WHILE '(' expr ')' stmt
		| FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt
		| BREAK ';'
		| CONTINUE ';'
        ;

expr_e: 
        expr 
		| /* empty */
        ;

const_expr: 
        expr    {
            $$ = $1;
        }
        ;

expr: 
        unary '=' expr  
        {
            $$ = assign_op($1, $3);
        }
		| or_expr
        {
            $$ = $1;
        }
        ;

or_expr: 
        or_list 
        {
            $$ = $1;
        }
        ;

or_list: 
        or_list LOGICAL_OR and_expr
        {
            $$ = plus_op($1, $3);
        }
		| and_expr
        {
            $$ = $1;
        }
        ;

and_expr: 
        and_list
        {
            $$ = $1;
        }
        ;

and_list:
        and_list LOGICAL_AND binary
        {
            $$ = plus_op($1, $3);
        }
		| binary
        {
            $$ = $1;
        }
        ;

binary: 
        binary RELOP binary
        {
            $$ = rel_op($1, $3);
        }
		| binary EQUOP binary
        {
            $$ = equ_op($1, $3);
        }
		| binary '+' binary 
        {
            $$ = plus_op($1, $3);
        }
		| binary '-' binary 
        {
            $$ = minus_op($1, $3);
        }
		| unary %prec '='   
        {
            $$ = $1;
        }
        ;

unary:  
        '(' expr ')'    
        {
            $$ = $2;
        }
		| '(' unary ')' 
        {
            $$ = $2;
        }
		| INTEGER_CONST 
        {
            $$ = makeconstdecl(inttype);
        }
		| CHAR_CONST    
        {
            $$ = makeconstdecl(chartype);
        }
		| STRING    
        {
            $$ = makeconstdecl(chartype);
        }
		| ID    
        {
            $$ = findcurrentdecl($1);
        }
        | NULL_
        {
            $$ = makeconstdecl(voidtype);
        }
		| '-' unary	%prec '!'   
        {
            $$ = unary_minus_op($2);
        }
		| '!' unary 
        {
            $$ = unary_not_op($2);
        }
		| unary INCOP   
        {
            $$ = inc_op($1);
        }
		| unary DECOP   
        {
            $$ = dec_op($1);
        }
		| INCOP unary   
        {
            $$ = inc_op($2);
        }
		| DECOP unary   
        {
            $$ = dec_op($2);
        }
		| '&' unary	%prec '!'   
        {
            $$ = address_op($2);
        }
		| '*' unary	%prec '!'   
        {
            $$ = pointer_op($2);
        }
		| unary '[' expr ']'
        {
            $$ = arrayaccess($1, $3);
        }
		| unary '.' ID
        {
            $$ = structaccess($1, $3);
        }
		| unary STRUCTOP ID
        {
            $$ = structptraccess($1, $3);
        }
		| unary '(' args ')'
        {
            $$ = functioncall($1, $3);
        }
		| unary '(' ')'
        {
            $$ = functioncall($1, NULL);
        }
        ;

args:
        expr
        {
            $$ = makeargdecl($1);
        }
		| args ',' expr
        {
            decl *last = $1;
            while (last->next)
            {
                last = last->next;
            }
            last->next = makeargdecl($3);
            $$ = $1;
        }
        ;
    
%%

/*  Additional C Codes here */

int    yyerror (char* s)
{
    fprintf (stderr, "%s:%d: error:%s\n", filename, read_line(), s);
}