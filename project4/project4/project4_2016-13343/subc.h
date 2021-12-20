/******************************************************
 * File Name   : subc.h
 * Description
 *    This is a header file for the subc program.
 ******************************************************/

#ifndef __SUBC_H__
#define __SUBC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int read_line();
char *filename;
int n_string;
int n_label;
int loop_label;

int yyerror(char *s);

enum declclass
{
    VAR,
    CONST,
    TYPE_,
    FUNC
};

enum typeclass
{
    INT,
    CHAR,
    array,
    ptr,
    STRUCT_,
    type
};

typedef struct id
{
    int tokenType;
    char *name;
} id;

typedef struct decl
{
    int declclass;
    int typeclass;
    struct decl *type;
    int intval;
    char charval;
    struct decl *elementvar;
    int num_index;
    struct ste *fields;
    struct decl *ptrto;
    struct decl *next;
    struct ste *formals;
    struct decl *returntype;
    int offset;
    struct ste **scope;
    id *name;
    int size;
} decl;

typedef struct ste
{
    struct id *id;
    struct decl *decl;
    struct ste *prev;
} ste;

decl *inttype;
decl *chartype;
decl *voidtype;
id *returnid;
id *greater;
id *greater_equal;
id *less;
id *less_equal;
id *equal;
id *not_equal;


/* For hash table */
unsigned hash(char *name, int length);
id *enter(int tokenType, char *name, int length);

/* For scoped symbol table */
void push_scope();
ste *pop_scope();
void pushstelist(ste *stelist);
decl *declare(id *id, decl *decl);
decl *structdeclare(id *id, decl *decl);
decl *findcurrentdecl(id *id);
decl *findstructdecl(id *id);

decl *makeargdecl(decl *decl1);
decl *makevardecl(decl *typedecl, bool isptr);
decl *maketypedecl(int typeclass);
decl *makeconstdecl(decl *typedecl);
decl *makearraydecl(int num_index, decl *elementvar);
decl *makeptrdecl(decl *typedecl);
decl *makestructdecl();
decl *makeprocdecl();

decl *assign_op(decl *lhs, decl *rhs);
decl *plus_op(decl *decl1, decl *decl2);
decl *minus_op(decl *decl1, decl *decl2);
decl *unary_minus_op(decl *decl);
decl *unary_not_op(decl *decl);
decl *inc_op(decl *decl);
decl *dec_op(decl *decl);
decl *rel_op(decl *decl1, decl *decl2);
decl *equ_op(decl *decl1, decl *decl2);
decl *address_op(decl *vardecl);
decl *pointer_op(decl *vardecl);

decl *structaccess(decl *decl, id *fieldid);
decl *structptraccess(decl *decl, id *fieldid);
decl *arrayaccess(decl *arraydecl, decl *indexdecl);

decl *functioncall(decl *procdecl, decl *actuals);
decl *functionreturn(decl *returndecl);

#endif
