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
    char    charVal;
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
%token              WRITE_INT WRITE_CHAR WRITE_STRING READ_INT READ_CHAR
%token<idptr>       ID TYPE VOID NULL_ STRUCT RETURN IF ELSE WHILE FOR BREAK CONTINUE LOGICAL_OR LOGICAL_AND RELOP EQUOP INCOP DECOP STRUCTOP
%token<stringVal>	STRING
%token<intVal>		INTEGER_CONST
%token<charVal>     CHAR_CONST

%type<intVal>       if_stmt def def_list local_defs ext_def_list ext_def
%type<boolVal>      pointers
%type<declptr>      args func_decl struct_specifier type_specifier unary expr or_expr or_list and_expr and_list binary

%%
program:
        {
            printf("\t\tshift_sp 1\n");
            printf("\t\tpush_const EXIT\n");
            printf("\t\tpush_reg fp\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tpop_reg fp\n");
            printf("\t\tjump main\n");
            printf("EXIT:\n");
            printf("\t\texit\n");
        }
        ext_def_list
        {
            printf("Lglob.  data %d\n", $2);
        }
		;

ext_def_list:   
        ext_def_list ext_def
        {
            $$ = $1 + $2;
        }
		| /* empty */
        {
            $$ = 0;
        }
		;

ext_def:
        type_specifier pointers ID ';'  
        {
            $$ = declare($3, makevardecl($1, $2))->size;
        }
        | type_specifier pointers ID '[' INTEGER_CONST ']' ';' 
        {
            $$ = declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))))->size;
        }
        | func_decl ';'
        {
            $$ = 0;
        }
        | type_specifier ';'
        {
            $$ = 0;
        }
        | func_decl
        {
            if ($1)
            {
                push_scope();
                decl* returndecl = declare(returnid, makevardecl($1->returntype->type, false));
                returndecl->name = $1->name;
                pushstelist($1->formals);
                printf("%s_start:\n", $1->name->name);
            }    
        }
        compound_stmt
        {
            if ($1)
            {
                pop_scope();
                printf("%s_final:\n", $1->name->name);
                printf("\t\tpush_reg fp\n");
                printf("\t\tpop_reg sp\n");
                printf("\t\tpop_reg fp\n");
                printf("\t\tpop_reg pc\n");
                printf("%s_end:\n", $1->name->name);
            }
            $$ = 0;
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
            $<declptr>$ = structdeclare($2, makestructdecl());
            push_scope();   
        }
        def_list    
        {   
            ste *fields = pop_scope();
            if ($<declptr>4)
            {
                $<declptr>4->fields = fields;
            }
            $<declptr>$ = $<declptr>4;
        }
        '}' 
        {
            $$ = $<declptr>6;
            $$->size = $5;
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
            procdecl->name = $3;
            procdecl->returntype = makeconstdecl($1);
            $$ = declare($3, procdecl);
            printf("%s:\n", $3->name);
        }
		| type_specifier pointers ID '('
        {
            decl *procdecl = makeprocdecl();
            procdecl->name = $3;
            if ($<declptr>$ = declare($3, procdecl))
            {
                push_scope();
                declare(returnid, makeconstdecl($1));
            }
        }
        real_param_list ')'
        {
            if ($$ = $<declptr>5)
            {
                ste *formals = pop_scope();
                $$->returntype = formals->decl;
                $$->formals = formals->prev;
            }
            printf("%s:\n", $3->name);
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

real_param_list:
        param_list
        | VOID
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
		| type_specifier pointers ID '[' INTEGER_CONST ']'
        {
            declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))));
        }
        ;

def_list: 
        def_list def
        {
            $$ = $1 + $2;
        }
		| /* empty */
        {
            $$ = 0;
        }
        ;

def: 
        type_specifier pointers ID ';'
        {
            $$ = declare($3, makevardecl($1, $2))->size;
        }
		| type_specifier pointers ID '[' INTEGER_CONST ']' ';'
        {
            $$ = declare($3, makeconstdecl(makearraydecl($5, makevardecl($1, $2))))->size;
        }
		| type_specifier ';'
        {
            $$ = 0;
        }
		| func_decl ';'
        {
            $$ = 0;
        }
        ;

compound_stmt: 
        '{' local_defs
        {
            if ($2)
            {
                printf("\t\tshift_sp %d\n", $2);
            }
        }
        stmt_list '}'
        ;

local_defs:	
        def_list
        {
            $$ = $1;
        }
        ;

stmt_list: 
        stmt_list stmt
		| /* empty */
        ;

stmt: 
        expr ';'
        {
            printf("\t\tshift_sp -1\n");
        }
		| compound_stmt
		| RETURN ';'
        {
            functionreturn(voidtype);
        }
		| RETURN
        {
            decl* returndecl = functionreturn(NULL);
            
            if (check_isstruct(returndecl->type))
            {
                ste *stenode;
                for (stenode = returndecl->type->fields; stenode; stenode = stenode->prev)
                {
                    
                    printf("\t\tpush_reg fp\n");
                    printf("\t\tpush_const -1\n");
                    printf("\t\tadd\n");
                    printf("\t\tpush_const -%d\n", returndecl->size - stenode->decl->offset);
                    printf("\t\tadd\n");
                }
            }
            else
            {
                printf("\t\tpush_reg fp\n");
                printf("\t\tpush_const -1\n");
                printf("\t\tadd\n");
                printf("\t\tpush_const -1\n");
                printf("\t\tadd\n");
            }
        }
        expr ';'
        {
            decl* returndecl = functionreturn($3);
            
            if (check_isstruct(returndecl->type))
            {
                ste *stenode;
                for (stenode = returndecl->type->fields; stenode; stenode = stenode->prev)
                {
                    printf("\t\tpush_reg sp\n");

                    printf("\t\tpush_const %d\n", returndecl->size);
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tpush_reg sp\n");
                    printf("\t\tpush_const 1\n");
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tassign\n");
                    printf("\t\tshift_sp -1\n");
                }
                printf("\t\tshift_sp -%d\n", returndecl->size);
                printf("\t\tjump %s_final\n", returndecl->name->name);
            }
            else
            {
                printf("\t\tassign\n");
                printf("\t\tjump %s_final\n", returndecl->name->name);
            }   
        }
		| ';'
        | if_stmt %prec IFX
        {
            printf("label_%d:\n", $1 + 1);
        }
        | if_stmt ELSE
        {
            printf("\t\tjump label_%d\n", $1 + 2);
            printf("label_%d:\n", $1 + 1);
        }
        stmt
        {
            printf("label_%d:\n", $1 + 2);
        }
		| WHILE
        {
            printf("label_%d:\n", n_label);
            $<intVal>$ = n_label;
            push_label(n_label);
            n_label = n_label + 2;
            push_scope();
        }
        '(' expr ')'
        {
            printf("\t\tbranch_false label_%d\n", $<intVal>2 + 1);
        }
          stmt
        {
            pop_scope();
            printf("\t\tjump label_%d\n", $<intVal>2);
            printf("label_%d:\n", $<intVal>2 + 1);
            pop_label();
        }
		| FOR
        {
            push_scope();
        }
        '(' expr_e ';'
        {
            printf("label_%d:\n", n_label);
            $<intVal>$ = n_label;
            push_label(n_label);
            n_label = n_label + 4;
        }
        expr_e ';'
        {
            printf("\t\tbranch_false label_%d\n", $<intVal>6 + 1);
            printf("\t\tjump label_%d\n", $<intVal>6 + 2);
            printf("label_%d:\n", $<intVal>6 + 3);
        }
        expr_e ')'
        {
            printf("\t\tjump label_%d\n", $<intVal>6);
            printf("label_%d:\n", $<intVal>6 + 2);
        }
        stmt
        {
            pop_scope();
            printf("\t\tjump label_%d\n", $<intVal>6 + 3);
            printf("label_%d:\n", $<intVal>6 + 1);
            pop_label();
        }
		| BREAK ';'
        {
            printf("\t\tjump label_%d\n", current_label() + 1);
        }
		| CONTINUE ';'
        {
            printf("\t\tjump label_%d\n", current_label());
        }
        | WRITE_INT '(' unary ')' ';'
        {
            if (check_isvar($3))
            {
                printf("\t\tfetch\n");
            }
            printf("\t\twrite_int\n");
        }
        | WRITE_CHAR '(' unary ')' ';'
        { 
            if (check_isvar($3))
            {
                printf("\t\tfetch\n");
            }
            printf("\t\twrite_char\n");
        }
        | WRITE_STRING '(' unary ')' ';'
        {
            if (check_isarray($3->type))
            {
                printf("\t\tpush_reg sp\n");
                printf("\t\tpush_const %d\n", $3->size);
                printf("\t\tsub\n");
            }
            else
            {
                printf("\t\tpush_const str_%d\n", $3->intval);
            }
            printf("\t\twrite_string\n");
        }
        ;

if_stmt:
        IF
        {
            printf("label_%d:\n", n_label);
            $<intVal>$ = n_label;
            n_label = n_label + 3;
        }
        '(' expr ')'
        {
            printf("\t\tbranch_false label_%d\n", $<intVal>2 + 1);
        }
        stmt
        {
            $$ = $<intVal>2;
        }
        ;

expr_e: 
        expr 
		| /* empty */
        ;

expr: 
        unary
        {
           
            if (check_isstruct($1->type))
            {
                ste *stenode;
                for (stenode = $1->type->fields; stenode; stenode = stenode->prev)
                {
                    printf("\t\tpush_reg fp\n");
                    if ($1->offset + stenode->decl->offset)
                    {
                        printf("\t\tpush_const %d\n", $1->offset + stenode->decl->offset);
                        printf("\t\tadd\n");
                    }
                }
            }
            else
            {
                printf("\t\tpush_reg sp\n");
                printf("\t\tfetch\n");
            }
        }
        '=' expr  
        {
            $$ = assign_op($1, $4);

            if (check_isstruct($1->type))
            {
                ste *stenode;
                for (stenode = $1->type->fields; stenode; stenode = stenode->prev)
                {
                    printf("\t\tpush_reg sp\n");

                    printf("\t\tpush_const %d\n", $1->size);
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tpush_reg sp\n");
                    printf("\t\tpush_const 1\n");
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tassign\n");
                    printf("\t\tshift_sp -1\n");
                }
                printf("\t\tshift_sp -%d\n", $1->size);
            }
            else
            {
                printf("\t\tassign\n");
                printf("\t\tfetch\n");
            }   
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
            printf("\t\tor\n");
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
            printf("\t\tand\n");
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
            if ($2 == greater)
                printf("\t\tgreater\n");
            else if ($2 == greater_equal)
                printf("\t\tgreater_equal\n");
            else if ($2 == less)
                printf("\t\tless\n");
            else if ($2 == less_equal)
                printf("\t\tless_equal\n");
        }
		| binary EQUOP binary
        {
            $$ = equ_op($1, $3);
            if ($2 == equal)
                printf("\t\tequal\n");
            if ($2 == not_equal)
                printf("\t\tnot_equal\n");
        }
		| binary '+' binary 
        {
            $$ = plus_op($1, $3);
            printf("\t\tadd\n");
        }
		| binary '-' binary 
        {
            $$ = minus_op($1, $3);
            printf("\t\tsub\n");
        }
		| unary %prec '='   
        {
            $$ = $1;
            if (check_isstruct($$->type) && !check_isconst($$))
            {
                printf("\t\tfetch\n");
                ste *stenode;
                for (stenode = $$->type->fields; stenode; stenode = stenode->prev)
                {
                    if (stenode->decl->offset != 0)
                    {
                        printf("\t\tpush_reg fp\n");
                        printf("\t\tpush_const %d\n", $$->offset  + stenode->decl->offset);
                        printf("\t\tadd\n");
                        printf("\t\tfetch\n");
                    }
                    
                }
            }
            else if (!check_isconst($$))
            {
                printf("\t\tfetch\n");
            }
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
            $$->intval = $1;
            printf("\t\tpush_const %d\n", $$->intval);
        }
		| CHAR_CONST    
        {
            $$ = makeconstdecl(chartype);
            $$->charval = $1;
            printf("\t\tpush_const %d\n", $$->charval);
        }
		| STRING    
        {
            $$ = makeconstdecl(makeptrdecl(chartype));
            $$->intval = n_string++;
            printf("str_%d. string \"%s\"\n", $$->intval, $1);
        }
		| ID    
        {
            $$ = findcurrentdecl($1);
            
            if (check_isfunction($$))
            {
            }
            else if (check_isglobal($$))
            {
                printf("\t\tpush_const Lglob+%d\n", $$->offset);
            }
            
            else
            {
                printf("\t\tpush_reg fp\n");
                printf("\t\tpush_const %d\n", $$->offset);
                printf("\t\tadd\n");
            }
        }
        | NULL_
        {
            $$ = makeconstdecl(makeptrdecl(voidtype));
            $$->intval = 0;
        }
		| '-' unary	%prec '!'   
        {
            $$ = unary_minus_op($2);
            printf("\t\tnegate\n");
        }
		| '!' unary 
        {
            $$ = unary_not_op($2);
            printf("\t\tnot\n");
        }
		|
        unary INCOP   
        {
            $$ = inc_op($1);
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\tadd\n");
            printf("\t\tassign\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\tsub\n");
        }
		| unary DECOP   
        {
            $$ = dec_op($1);
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\tsub\n");
            printf("\t\tassign\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\add\n");
        }
		| INCOP unary   
        {
            $$ = inc_op($2);
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\tadd\n");
            printf("\t\tassign\n");
            printf("\t\tfetch\n");
        }
		| DECOP unary   
        {
            $$ = dec_op($2);
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tfetch\n");
            printf("\t\tfetch\n");
            printf("\t\tpush_const 1\n");
            printf("\t\tsub\n");
            printf("\t\tassign\n");
            printf("\t\tfetch\n");
        }
		| '&' unary	%prec '!'   
        {
            $$ = address_op($2);
        }
		| '*' unary	%prec '!'   
        {
            $$ = pointer_op($2);
            printf("\t\tfetch\n");
        }
		| unary '[' expr ']'
        {
            $$ = arrayaccess($1, $3);
            printf("\t\tpush_const %d\n", $$->size);
            printf("\t\tmul\n");
            printf("\t\tadd\n");
        }
		| unary '.' ID
        {
            $$ = structaccess($1, $3);
            if ($$->offset)
            {
                printf("\t\tpush_const %d\n", $$->offset);
                printf("\t\tadd\n");
            }
        }
		| unary STRUCTOP ID
        {
            $$ = structptraccess($1, $3);
            printf("\t\tfetch\n");
            if ($$->offset)
            {
                printf("\t\tpush_const %d\n", $$->offset);
                printf("\t\tadd\n");
            }
        }
		| unary '('
        {
            printf("\t\tshift_sp %d\n", $1->returntype->size);
            printf("\t\tpush_const label_%d\n", $<intVal>$ = n_label++);
            printf("\t\tpush_reg fp\n");
        }
        args ')'
        {
            $$ = functioncall($1, $4);
            declare(NULL, $$);
            int num_formals;
            num_formals = 0;
            decl* actuals = $4;
            while (actuals)
            {
                num_formals = num_formals + actuals->size;
                actuals = actuals->next;
            }
            printf("\t\tpush_reg sp\n");
            printf("\t\tpush_const -%d\n", num_formals);
            printf("\t\tadd\n");
            printf("\t\tpop_reg fp\n");
            printf("\t\tjump %s\n", $1->name->name);
            printf("label_%d:\n", $<intVal>3);
        }
		| unary '(' ')'
        {
            $$ = functioncall($1, NULL);
            declare(NULL, $$);
            printf("\t\tshift_sp %d\n", $1->returntype->size);
            printf("\t\tpush_const label_%d\n", n_label);
            printf("\t\tpush_reg fp\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tpop_reg fp\n");
            printf("\t\tjump %s\n", $1->name->name);
            printf("label_%d:\n", n_label++);
        }
        | READ_INT '(' ')'
        {
            $$ = makeconstdecl(inttype);
            printf("\t\tread_int\n");
        }
        | READ_CHAR '(' ')'
        {
            $$ = makeconstdecl(chartype);
            printf("\t\tread_char\n");
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
    printf ("%s:%d: error:%s\n", filename, read_line(), s);
}