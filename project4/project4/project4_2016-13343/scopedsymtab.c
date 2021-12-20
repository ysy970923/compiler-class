/***************************************************************
 * File Name    : scopedsymtab.c
 * Description
 *      This is an implementation file for the scoped symbol table.
 *
 ****************************************************************/
#include "subc.h"

#define SCOPE_STACK_SIZE 200

static ste *scopestack[SCOPE_STACK_SIZE];
static int offsetstack[SCOPE_STACK_SIZE];
static int stacktop = 0;
static ste *globalscopenext;
static ste **globalscope = &scopestack[0];
static int loop_label_stack[SCOPE_STACK_SIZE];
static int loop_label_stack_top = 0;

void push_label(int label)
{
    loop_label_stack[loop_label_stack_top++] = label;
}

int current_label()
{
    return loop_label_stack[loop_label_stack_top - 1];
}

int pop_label()
{
    return loop_label_stack[loop_label_stack_top--];
}

/* static functions used only inside this file */

bool check_isconst(decl *decl)
{
    return (decl->declclass == CONST);
}

/*
 * Function:  check_isvar
 * --------------------
 *	check if token is variable
 * 
 * 	decl: token declaration
 *
 *  returns: true if declaration is variable else false
 */
bool check_isvar(decl *decl)
{
    return (decl->declclass == VAR);
}

/*
 * Function:  check_isfunction
 * --------------------
 *	check if token is function
 * 
 * 	decl: token declaration
 *
 *  returns: true if declaration is function else false
 */
static bool check_isfunction(decl *decl)
{
    return (decl->declclass == FUNC);
}

/*
 * Function:  check_isarray
 * --------------------
 *	check if token is type is array
 * 
 * 	decl: token type declaration
 *
 *  returns: true if type declaration is array else false
 */
static bool check_isarray(decl *typedecl)
{
    return (typedecl->typeclass == array);
}

/*
 * Function:  check_isstruct
 * --------------------
 *	check if token is type is struct
 * 
 * 	decl: token type declaration
 *
 *  returns: true if type declaration is struct else false
 */
bool check_isstruct(decl *typedecl)
{
    return (typedecl->typeclass == STRUCT_);
}

/*
 * Function:  check_isptr
 * --------------------
 *	check if token is type is pointer
 * 
 * 	decl: token type declaration
 *
 *  returns: true if type declaration is pointer else false
 */
bool check_isptr(decl *typedecl)
{
    return (typedecl->typeclass == ptr);
}

int n_glob()
{
    return offsetstack[0];
}

bool check_isglobal(decl *decl)
{
    return decl->scope == globalscope;
}

bool check_istype(decl *decl)
{
    return decl->declclass == TYPE_;
}

/*
 * Function:  insert
 * --------------------
 *	make new symbol table entry and insert into symbol table in current scope
 * 
 * 	id: token id from hash table
 *  decl: declaration for the token
 *
 *  returns: void
 */
static void insert(id *id, decl *decl, bool isstruct)
{
    ste *stenode = (ste *)malloc(sizeof(ste));
    stenode->id = id;
    stenode->decl = decl;

    if (!decl)
    {
        return;
    }

    if (isstruct)
    {
        if (globalscopenext)
        {
            globalscopenext->prev = stenode;
        }
        stenode->prev = scopestack[0];
        scopestack[0] = stenode;

        decl->scope = globalscope;
    }
    else
    {
        if (stacktop == 1)
        {
            if (scopestack[stacktop] == scopestack[0])
            {
                globalscopenext = stenode;
            }
        }
        stenode->prev = scopestack[stacktop];
        scopestack[stacktop] = stenode;

        decl->scope = &scopestack[stacktop];
        if (!check_istype(decl))
        {
            decl->offset = offsetstack[stacktop];
            if (id == returnid)
                offsetstack[stacktop] = offsetstack[stacktop] + 1;
            else
                offsetstack[stacktop] = offsetstack[stacktop] + decl->size;
        }
    }
}

/*
 * Function:  lookup
 * --------------------
 *	lookup symbol table for id from current scope to higher scope order
 * 
 * 	id: token id from hash table
 *
 *  returns: declaration of the token
 */
static decl *lookup(id *id)
{
    ste *stenode = scopestack[stacktop];
    while (stenode)
    {
        if (stenode->id == id)
        {
            return stenode->decl;
        }
        else if (stenode->prev)
        {
            stenode = stenode->prev;
        }
        else
        {
            break;
        }
    }
    return NULL;
}

/*
 * Function:  finddecl
 * --------------------
 *	find token declaration with id from function parameter entry fields
 * 
 * 	id: token id from hash table
 *  fields: function parameter entry fields
 *
 *  returns: declaration of the token
 */
static decl *finddecl(id *id, ste *fields)
{
    ste *stenode = fields;
    while (stenode)
    {
        if (stenode->id == id)
        {
            return stenode->decl;
        }
        else if (stenode->prev)
        {
            stenode = stenode->prev;
        }
        else
        {
            break;
        }
    }
    yyerror("struct not have same name field");
    return NULL;
}

/*
 * Function:  check_sametype
 * --------------------
 *	check if two token type declarations are same type
 * 
 * 	type1: type declaration 1
 *  type2: type declaration 2
 *
 *  returns: true if two types are same else false
 */
static bool check_sametype(decl *type1, decl *type2)
{
    if (type1 && type2)
    {
        if (type1 == type2)
        {
            return true;
        }
        if (type1->typeclass == ptr && type2->typeclass == ptr)
        {
            if (type1->ptrto == type2->ptrto)
            {
                return true;
            }
            if (type1->ptrto == voidtype || type2->ptrto == voidtype)
            {
                return true;
            }
        }
    }
    return false;
}

/*
 * Function:  check_isinscope
 * --------------------
 *	check if token id is not declared in scope
 * 
 * 	id: token id
 *  scopedepth: scope depth of scope to search
 *
 *  returns: true if not declared in scope else false
 */
static bool check_isinscope(id *id, int scopedepth)
{
    ste *stenode = scopestack[scopedepth];
    while (stenode)
    {
        if (scopedepth > 0)
        {
            if (stenode == scopestack[scopedepth - 1])
            {
                break;
            }
        }
        if (stenode->id == id)
        {
            return false;
        }
        stenode = stenode->prev;
    }
    return true;
}

/* static functions used only inside this file */

/**********************************************************************************/

/* external functions used in subc.y */

/*
 * Function:  push_scope
 * --------------------
 *	push new scope to scoped symbol table
 * 
 *  returns: void
 */
void push_scope()
{
    stacktop++;
    scopestack[stacktop] = scopestack[stacktop - 1];
}

/*
 * Function:  pop_scope
 * --------------------
 *	pop current scope from scoped symbol table
 *  returns: linked list of poped scope in reversed order
 */
ste *pop_scope()
{
    offsetstack[stacktop] = 0;
    ste *stenode1 = scopestack[stacktop--];
    ste *stenode2 = NULL;
    ste *temp = stenode1->prev;
    while (!(stenode1 == scopestack[stacktop]))
    {
        stenode1->prev = stenode2;
        stenode2 = stenode1;
        stenode1 = temp;
        temp = temp->prev;
    }
    return stenode2;
}

/*
 * Function:  pushstelist
 * --------------------
 *	insert symbol table entry list into symbol table current scope
 * 
 * 	stelist: symbol table entry list to insert
 *
 *  returns: void
 */
void pushstelist(ste *stelist)
{
    ste *stenode = stelist;
    while (stenode)
    {
        insert(stenode->id, stenode->decl, false);
        stenode = stenode->prev;
    }
}

/*
 * Function:  declare
 * --------------------
 *	declare new token in symbol table
 * 
 * 	id: token id
 *  decl: token declaration
 *
 *  returns: token declaration, NULL when redeclaration error
 */
decl *declare(id *id, decl *decl)
{
    if (!check_isinscope(id, stacktop))
    {
        yyerror("redeclaration");
        return NULL;
    }
    insert(id, decl, false);
    return decl;
}

/*
 * Function:  declare
 * --------------------
 *	declare new token in symbol table at global scope
 * 
 * 	id: token id
 *  decl: token declaration
 *
 *  returns: token declaration, NULL when redeclaration error
 */
decl *structdeclare(id *id, decl *decl)
{
    if (!check_isinscope(id, 0))
    {
        yyerror("redeclaration");
        return NULL;
    }
    insert(id, decl, true);
    return decl;
}

/*
 * Function:  findcurrentdecl
 * --------------------
 *	find token id in symbol table from current scope to higher scope
 * 
 * 	id: token id to find
 *
 *  returns: declaration of the token found
 */
decl *findcurrentdecl(id *id)
{
    decl *decl;
    if (!(decl = lookup(id)))
    {
        yyerror("not declared");
    }
    return decl;
}

/*
 * Function:  findcurrentdecl
 * --------------------
 *	find token id in symbol table from current scope to higher scope
 * 
 * 	id: token id to find
 *
 *  returns: declaration of the token found
 */
decl *findstructdecl(id *id)
{
    decl *decl;
    if (!(decl = lookup(id)))
    {
        yyerror("incomplete type");
    }
    return decl;
}

/*
 * Function:  makeargdecl
 * --------------------
 *	make declaration for argument
 * 
 * 	decl1: token declaration for argument
 *
 *  returns: argument token declaration
 */
decl *makeargdecl(decl *decl1)
{
    if (!decl1)
    {
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = decl1->declclass;
    declnode->typeclass = decl1->typeclass;
    declnode->type = decl1->type;
    declnode->size = decl1->size;
    return declnode;
}

/*
 * Function:  makevardecl
 * --------------------
 *	make variable declaration
 * 
 * 	typedecl: type declaration of the token
 *  isptr: make it as pointer or not
 *
 *  returns: token declaration
 */
decl *makevardecl(decl *typedecl, bool isptr)
{
    if (!typedecl)
    {
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = VAR;
    declnode->typeclass = type;
    if (isptr)
    {
        declnode->type = makeptrdecl(typedecl);
        declnode->size = 1;
    }
    else
    {
        declnode->size = typedecl->size;
        declnode->type = typedecl;
    }
    return declnode;
}

/*
 * Function:  maketypedecl
 * --------------------
 *	make type declaration of types (int, char, void)
 * 
 * 	typeclass: typeclass for declaration
 *
 *  returns: type declaration
 */
decl *maketypedecl(int typeclass)
{
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = TYPE_;
    declnode->typeclass = typeclass;
    declnode->size = 1;
    return declnode;
}

/*
 * Function:  makeconstdecl
 * --------------------
 *	make const declaration
 * 
 * 	typedecl: const type declaration
 *
 *  returns: const declaration
 */
decl *makeconstdecl(decl *typedecl)
{
    if (!typedecl)
    {
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = CONST;
    declnode->typeclass = type;
    declnode->type = typedecl;
    declnode->size = typedecl->size;
    return declnode;
}

/*
 * Function:  makearraydecl
 * --------------------
 *	make array declaration
 * 
 * 	num_index: int type declaration for num_index
 *  elementvar: element variable
 *
 *  returns: array declaration
 */
decl *makearraydecl(int num_index, decl *elementvar)
{
    if (!(elementvar))
    {
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = TYPE_;
    declnode->typeclass = array;
    declnode->elementvar = elementvar;
    declnode->num_index = num_index;
    declnode->size = num_index * (elementvar->size);
    return declnode;
}

/*
 * Function:  makeptrdecl
 * --------------------
 *	make pointer declaration
 * 
 * 	typedecl: type declaration for pointer
 *
 *  returns: pointer declaration
 */
decl *makeptrdecl(decl *typedecl)
{
    if (!typedecl)
    {
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = TYPE_;
    declnode->typeclass = ptr;
    declnode->ptrto = typedecl;
    return declnode;
}

/*
 * Function:  makestructdecl
 * --------------------
 *	make struct declaration
 * 
 *  returns: struct declaration
 */
decl *makestructdecl()
{
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = TYPE_;
    declnode->typeclass = STRUCT_;
    return declnode;
}

/*
 * Function:  makeprocdecl
 * --------------------
 *	make empty function declaration
 *
 *  returns: function declaration
 */
decl *makeprocdecl()
{
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = FUNC;
    return declnode;
}

/*
 * Function:  assign_op
 * --------------------
 *	check if two token declarations are compatible for assignment
 *  LHS and RHS should be same type
 * 
 * 	lhs: left hand side declaration, must be variable
 *  rhs: right hand side declaration
 *
 *  returns: declaration of left hand side
 */
decl *assign_op(decl *lhs, decl *rhs)
{
    if (!(lhs && rhs))
    {
        return NULL;
    }
    if (!check_isvar(lhs))
    {
        yyerror("LHS is not a variable");
        return NULL;
    }
    if (!check_sametype(lhs->type, rhs->type))
    {
        yyerror("LHS and RHS are not same type");
        return NULL;
    }
    return lhs;
}

/*
 * Function:  plus_op
 * --------------------
 *	plus operator of two operands
 * 
 * 	decl1: operand1 declaration, must be integer type
 *  decl2: operand2 declaration, must be integer type
 *
 *  returns: declaration of token1
 */
decl *plus_op(decl *decl1, decl *decl2)
{
    if (decl1 && decl2)
    {
        if (decl1->typeclass == type && decl2->typeclass == type)
        {
            if (decl1->type->typeclass == INT && decl2->type->typeclass == INT)
            {
                return makeconstdecl(decl1->type);
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  minus_op
 * --------------------
 *	minus operator of two operands
 * 
 * 	decl1: operand1 declaration, must be integer type
 *  decl2: operand2 declaration, must be integer type
 *
 *  returns: declaration of token1
 */
decl *minus_op(decl *decl1, decl *decl2)
{
    if (decl1 && decl2)
    {
        if (decl1->typeclass == type && decl2->typeclass == type)
        {
            if (decl1->type->typeclass == INT && decl2->type->typeclass == INT)
            {
                return decl1;
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  unary_minus_op
 * --------------------
 *	unary minus of operand
 * 
 * 	decl1: operand declaration, must be integer type
 *
 *  returns: declaration of the token
 */
decl *unary_minus_op(decl *decl)
{
    if (decl)
    {
        if (decl->typeclass == type)
        {
            if (decl->type->typeclass == INT)
            {
                return decl;
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  unary_not_op
 * --------------------
 *	unary not operator of operand
 * 
 * 	decl: operand declaration, must be integer type
 *
 *  returns: declaration of the token
 */
decl *unary_not_op(decl *decl)
{
    if (decl)
    {
        if (decl->typeclass == type)
        {
            if (decl->type->typeclass == INT)
            {
                return decl;
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  inc_op
 * --------------------
 *	unary not operator of operand
 * 
 * 	decl: operand declaration, must be integer type or char type
 *
 *  returns: declaration of the token
 */
decl *inc_op(decl *decl)
{
    if (decl)
    {
        if (decl->typeclass == type)
        {
            if (decl->type->typeclass == INT || decl->type->typeclass == CHAR)
            {
                return makeconstdecl(decl->type);
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  dec_op
 * --------------------
 *	unary not operator of operand
 * 
 * 	decl: operand declaration, must be integer type or char type
 *
 *  returns: declaration of the token
 */
decl *dec_op(decl *decl)
{
    if (decl)
    {
        if (decl->typeclass == type)
        {
            if (decl->type->typeclass == INT || decl->type->typeclass == CHAR)
            {
                return makeconstdecl(decl);
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  rel_op
 * --------------------
 *	relational operator of operands
 *  both operands must be same type
 * 
 * 	decl1: operand 1 declaration, must be integer type or char type
 * 	decl2: operand 2 declaration, must be integer type or char type
 *
 *  returns: declaration of the token
 */
decl *rel_op(decl *decl1, decl *decl2)
{
    if (decl1 && decl2)
    {
        if (decl1->typeclass == type && decl2->typeclass == type)
        {
            if ((decl1->type->typeclass == INT && decl2->type->typeclass == INT) || (decl1->type->typeclass == CHAR && decl2->type->typeclass == CHAR))
            {
                return decl1;
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  equ_op
 * --------------------
 *	equality operator of operands
 *  both operands must be same type
 * 
 * 	decl1: operand 1 declaration, must be integer type or char type
 * 	decl2: operand 2 declaration, must be integer type or char type
 *
 *  returns: declaration of the token
 */
decl *equ_op(decl *decl1, decl *decl2)
{
    if (decl1 && decl2)
    {
        if (decl1->typeclass == type && decl2->typeclass == type)
        {
            if ((decl1->type->typeclass == INT && decl2->type->typeclass == INT) || (decl1->type->typeclass == CHAR && decl2->type->typeclass == CHAR))
            {
                return decl1;
            }
            if (decl1->type->typeclass == ptr && decl2->type->typeclass == ptr)
            {
                return decl1;
            }
        }
        yyerror("not computable");
    }
    return NULL;
}

/*
 * Function:  address_op
 * --------------------
 *	unary address operator on variable
 * 
 * 	vardecl: variable declaration
 *
 *  returns: variable of address
 */
decl *address_op(decl *vardecl)
{
    if (!vardecl)
    {
        return NULL;
    }
    if (!check_isvar(vardecl))
    {
        yyerror("not a variable");
        return NULL;
    }
    decl *declnode = makeconstdecl(makeptrdecl(vardecl->type));
    return declnode;
}

/*
 * Function:  pointer_op
 * --------------------
 *	unary pointer operator on pointer variable
 * 
 * 	vardecl: variable declaration
 *
 *  returns: variable of address
 */
decl *pointer_op(decl *vardecl)
{
    if (!vardecl)
    {
        return NULL;
    }
    if (!check_isvar(vardecl))
    {
        yyerror("not a variable");
        return NULL;
    }
    if (!check_isptr(vardecl->type))
    {
        yyerror("not a pointer");
        return NULL;
    }
    decl *declnode = (decl *)malloc(sizeof(decl));
    declnode->declclass = VAR;
    declnode->typeclass = type;
    declnode->type = vardecl->type->ptrto;
    return declnode;
}

/*
 * Function:  structaccess
 * --------------------
 *	access field id in struct variable
 * 
 * 	decl: struct declaration, must be struct variable
 *  fieldid: id for field to access
 *
 *  returns: declaration of the accessed field
 */
decl *structaccess(decl *decl, id *fieldid)
{
    if (!decl)
    {
        return NULL;
    }
    if (!check_isvar(decl))
    {
        yyerror("not a variable");
        return NULL;
    }
    if (!check_isstruct(decl->type))
    {
        yyerror("not a struct");
        return NULL;
    }

    return finddecl(fieldid, decl->type->fields);
}

/*
 * Function:  structptraccess
 * --------------------
 *	access field id in struct pointer variable
 * 
 * 	decl: struct pointer declaration, must be struct pointer variable
 *  fieldid: id for field to access
 *
 *  returns: declaration of the accessed field
 */
decl *structptraccess(decl *decl, id *fieldid)
{
    if (!decl)
    {
        return NULL;
    }
    if (!check_isvar(decl))
    {
        yyerror("not a variable");
        return NULL;
    }
    if (!check_isptr(decl->type))
    {
        yyerror("not a struct pointer");
        return NULL;
    }
    if (!check_isstruct(decl->type->ptrto))
    {
        yyerror("not a struct pointer");
        return NULL;
    }
    return finddecl(fieldid, decl->type->ptrto->fields);
}

/*
 * Function:  arrayaccess
 * --------------------
 *	access array in index
 * 
 * 	arraydecl: array declaration, must be array variable
 *  indexdecl: index declaration, must be integer constant
 *
 *  returns: declaration of the accessed field
 */
decl *arrayaccess(decl *arraydecl, decl *indexdecl)
{
    if (!check_isarray(arraydecl->type))
    {
        yyerror("not an array type");
        return NULL;
    }
    if (!check_sametype(inttype, indexdecl->type))
    {
        return NULL;
    }
    return arraydecl->type->elementvar;
}

/*
 * Function:  functioncall
 * --------------------
 *	function call
 * 
 * 	procdecl: function token declaration, must be function declaration
 *  actuals: actual variables as parameters, each must be variable and same type with function formals
 *
 *  returns: constant declaration with type returntype of function
 */
decl *functioncall(decl *procdecl, decl *actuals)
{
    if (!procdecl)
    {
        return NULL;
    }

    if (!check_isfunction(procdecl))
    {
        yyerror("not a function");
        return NULL;
    }

    ste *formals = procdecl->formals;

    while (formals && actuals)
    {
        if (!check_isvar(formals->decl))
        {
            yyerror("actual args are not equal to formal args");
            return NULL;
        }
        if (!check_sametype(formals->decl->type, actuals->type))
        {
            yyerror("actual args are not equal to formal args");
            return NULL;
        }
        formals = formals->prev;
        actuals = actuals->next;
    }
    if (formals || actuals)
    {
        yyerror("actual args are not equal to formal args");
        return NULL;
    }
    return procdecl->returntype;
}

/*
 * Function:  functionreturn
 * --------------------
 *	return in function
 *  find function declaration closest in scope
 * 
 * 	returndecl: return declaration, must be same as function declaration
 *
 *  returns: declaration of the token
 */
decl *functionreturn(decl *returndecl)
{
    ste *stenode = scopestack[stacktop];

    while (stenode)
    {
        if (stenode->id == returnid)
        {
            if (!returndecl)
            {
                return stenode->decl;
            }
            if (!check_sametype(stenode->decl->type, returndecl->type))
            {
                yyerror("incompatible return types");
                return NULL;
            }
            return stenode->decl;
        }
        stenode = stenode->prev;
    }
    return NULL;
}