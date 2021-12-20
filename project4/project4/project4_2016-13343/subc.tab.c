/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "subc.y"

/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */

#include "subc.h"
#include "subc.tab.h"
#include "scopedsymtab.c"

int    yylex ();
int    yyerror (char* s);


#line 85 "subc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SUBC_TAB_H_INCLUDED
# define YY_YY_SUBC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IFX = 258,
    ELSE = 259,
    LOGICAL_OR = 260,
    LOGICAL_AND = 261,
    EQUOP = 262,
    RELOP = 263,
    INCOP = 264,
    DECOP = 265,
    STRUCTOP = 266,
    WRITE_INT = 267,
    WRITE_CHAR = 268,
    WRITE_STRING = 269,
    READ_INT = 270,
    READ_CHAR = 271,
    ID = 272,
    TYPE = 273,
    VOID = 274,
    NULL_ = 275,
    STRUCT = 276,
    RETURN = 277,
    IF = 278,
    WHILE = 279,
    FOR = 280,
    BREAK = 281,
    CONTINUE = 282,
    STRING = 283,
    INTEGER_CONST = 284,
    CHAR_CONST = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "subc.y"

    bool    boolVal;
	int		intVal;
    char    charVal;
	char	*stringVal;
    id      *idptr;
    decl    *declptr;

#line 177 "subc.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    16,     9,     2,
      22,    23,    14,    12,     5,    13,    24,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     6,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       7,     8,    10,    11,    18,    19,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    54,    71,    76,    82,    86,    90,    94,
      99,    98,   126,   130,   134,   142,   147,   141,   160,   167,
     176,   175,   198,   203,   209,   210,   214,   215,   219,   223,
     230,   235,   241,   245,   249,   253,   261,   260,   271,   278,
     279,   283,   287,   288,   293,   292,   348,   349,   354,   353,
     363,   371,   362,   382,   386,   393,   399,   381,   410,   414,
     418,   426,   434,   452,   458,   451,   468,   469,   474,   473,
     524,   531,   538,   543,   550,   557,   562,   569,   581,   589,
     594,   599,   626,   630,   634,   640,   646,   652,   671,   676,
     681,   687,   702,   717,   730,   743,   747,   752,   759,   768,
     779,   778,   803,   815,   820,   828,   832
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IFX", "ELSE", "','", "'='",
  "LOGICAL_OR", "LOGICAL_AND", "'&'", "EQUOP", "RELOP", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "INCOP", "DECOP", "'['", "']'", "'('", "')'",
  "'.'", "STRUCTOP", "WRITE_INT", "WRITE_CHAR", "WRITE_STRING", "READ_INT",
  "READ_CHAR", "ID", "TYPE", "VOID", "NULL_", "STRUCT", "RETURN", "IF",
  "WHILE", "FOR", "BREAK", "CONTINUE", "STRING", "INTEGER_CONST",
  "CHAR_CONST", "';'", "'{'", "'}'", "$accept", "program", "$@1",
  "ext_def_list", "ext_def", "$@2", "type_specifier", "struct_specifier",
  "@3", "@4", "func_decl", "@5", "pointers", "real_param_list",
  "param_list", "param_decl", "def_list", "def", "compound_stmt", "$@6",
  "local_defs", "stmt_list", "stmt", "$@7", "$@8", "@9", "$@10", "$@11",
  "@12", "$@13", "$@14", "if_stmt", "@15", "$@16", "expr_e", "expr",
  "$@17", "or_expr", "or_list", "and_expr", "and_list", "binary", "unary",
  "@18", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,    44,    61,   260,   261,    38,
     262,   263,    43,    45,    42,    47,    37,    33,   264,   265,
      91,    93,    40,    41,    46,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    59,   123,   125
};
# endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -171,    19,  -171,  -171,     5,  -171,  -171,    -4,  -171,   -12,
    -171,   -13,     3,  -171,  -171,    14,  -171,     7,  -171,   -10,
    -171,  -171,  -171,    15,    34,  -171,     5,  -171,     5,    40,
    -171,    60,    -1,    17,  -171,  -171,    30,    36,    59,    82,
      74,    96,  -171,  -171,    72,  -171,   107,  -171,  -171,    78,
    -171,     5,    -6,    12,    12,    12,    12,    12,    12,    12,
      92,    93,    95,    97,   101,  -171,  -171,    94,  -171,  -171,
    -171,   111,   112,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
     123,   113,  -171,   133,  -171,   134,   207,    80,   141,  -171,
     124,  -171,   191,   191,   191,   191,   191,   191,   139,    65,
      12,    12,    12,   143,   147,  -171,    12,   149,   156,   157,
    -171,  -171,  -171,  -171,    12,    12,    12,    12,    12,    12,
    -171,  -171,    12,   158,   138,   165,   198,   169,   193,  -171,
    -171,    88,   175,   183,  -171,  -171,   176,    12,    12,    12,
     146,  -171,   191,   207,   119,    11,  -171,  -171,   201,  -171,
      12,  -171,  -171,    12,   202,   179,   180,   181,   182,  -171,
     205,   206,   185,  -171,  -171,  -171,  -171,    13,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,    12,  -171,   146,
     146,    12,  -171,  -171,  -171,   186,  -171,    12,   209,  -171,
     146,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,     3,    12,    13,     0,     4,    23,
      14,    10,    18,    22,     9,     0,     8,     0,    15,     0,
      31,    11,    31,     0,    20,     6,    38,    36,    16,     0,
      19,     0,    23,     0,    30,    40,     0,     0,    13,    23,
       0,    24,    26,    34,     0,    35,     0,    17,     7,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    44,    63,    50,
      53,     0,     0,    86,    84,    85,    46,    37,    42,    39,
      47,     0,    70,    71,    73,    74,    76,    81,    28,    27,
       0,    32,    95,    89,    96,    90,    93,    94,     0,    81,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
      58,    59,    48,    41,     0,     0,     0,     0,     0,     0,
      91,    92,     0,   100,     0,     0,     0,     0,     0,    82,
      83,     0,     0,     0,   103,   104,     0,     0,     0,    67,
       0,    72,    81,    75,    78,    77,    79,    80,     0,   102,
       0,    98,    99,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,    66,    49,    97,   105,     0,    69,    29,
      33,    60,    61,    62,    64,    51,    54,     0,   101,     0,
       0,    67,   106,    65,    52,     0,    55,    67,     0,    56,
       0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,  -171,    -3,  -171,  -171,  -171,
     229,  -171,   -17,  -171,  -171,   184,   212,  -171,   219,  -171,
    -171,  -171,  -120,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -170,   -59,  -171,  -171,  -171,   125,
    -171,   -43,   -50,  -171,  -171
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     8,    17,    32,    10,    22,    36,
      33,    31,    15,    40,    41,    42,    26,    34,    78,    35,
      27,    46,    79,   106,   140,   108,   180,   109,   181,   187,
     190,    80,   107,   179,   162,    81,   126,    82,    83,    84,
      85,    86,    87,   150,   167
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,     9,    13,    92,    93,    94,    95,    96,    97,    99,
      23,   185,    24,    13,    90,    44,    24,   188,   177,     3,
     164,    53,    49,   118,   119,    54,    55,    12,    39,    56,
      57,    58,    16,    14,    59,    25,   178,     5,     6,    91,
       7,    63,    64,    65,    43,    19,    66,   136,    39,    18,
     131,   132,   133,    20,    73,    74,    75,    30,    29,   183,
     184,    37,    45,   148,   142,   142,   142,   142,   142,   142,
     191,   -68,   143,   144,   145,   146,   147,    47,   160,   161,
     163,    48,   -25,   120,   121,   122,   -68,   123,   130,   124,
     125,   166,     5,    38,   168,     7,    13,    50,   120,   121,
     122,    51,   123,    52,   124,   125,   120,   121,   122,    88,
     123,   156,   124,   125,   100,   101,    53,   102,   182,   103,
      54,    55,   163,   104,    56,    57,    58,   112,   163,    59,
     117,   118,   119,    60,    61,    62,    63,    64,    65,   105,
     114,    66,   115,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    20,    77,    53,   110,   111,   113,    54,
      55,   127,   129,    56,    57,    58,   134,   128,    59,   151,
     135,   137,    60,    61,    62,    63,    64,    65,   138,   139,
      66,   149,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    20,   120,   121,   122,   152,   123,   157,   124,
     125,   120,   121,   122,   153,   123,   158,   124,   125,   120,
     121,   122,   154,   123,   155,   124,   125,   116,   117,   118,
     119,   159,   165,   169,   170,   171,   172,   173,   174,   175,
     176,   186,   189,    11,    28,    89,    21,     0,     0,   141
};

static const yytype_int16 yycheck[] =
{
      59,     4,    14,    53,    54,    55,    56,    57,    58,    59,
      20,   181,    22,    14,    20,    32,    22,   187,     5,     0,
     140,     9,    39,    12,    13,    13,    14,    31,    31,    17,
      18,    19,    45,    45,    22,    45,    23,    32,    33,    45,
      35,    29,    30,    31,    45,    31,    34,   106,    51,    46,
     100,   101,   102,    46,    42,    43,    44,    23,    43,   179,
     180,    21,    45,   122,   114,   115,   116,   117,   118,   119,
     190,     6,   115,   116,   117,   118,   119,    47,   137,   138,
     139,    45,    23,    18,    19,    20,     6,    22,    23,    24,
      25,   150,    32,    33,   153,    35,    14,    23,    18,    19,
      20,     5,    22,    31,    24,    25,    18,    19,    20,    31,
      22,    23,    24,    25,    22,    22,     9,    22,   177,    22,
      13,    14,   181,    22,    17,    18,    19,     4,   187,    22,
      11,    12,    13,    26,    27,    28,    29,    30,    31,    45,
       7,    34,     8,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     9,    45,    45,    45,    13,
      14,    20,    23,    17,    18,    19,    23,    43,    22,    31,
      23,    22,    26,    27,    28,    29,    30,    31,    22,    22,
      34,    23,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    18,    19,    20,    31,    22,    23,    24,
      25,    18,    19,    20,     6,    22,    23,    24,    25,    18,
      19,    20,    43,    22,    21,    24,    25,    10,    11,    12,
      13,    45,    21,    21,    45,    45,    45,    45,    23,    23,
      45,    45,    23,     4,    22,    51,    17,    -1,    -1,   114
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,    51,    32,    33,    35,    52,    54,
      55,    58,    31,    14,    45,    60,    45,    53,    46,    31,
      46,    66,    56,    20,    22,    45,    64,    68,    64,    43,
      23,    59,    54,    58,    65,    67,    57,    21,    33,    54,
      61,    62,    63,    45,    60,    45,    69,    47,    45,    60,
      23,     5,    31,     9,    13,    14,    17,    18,    19,    22,
      26,    27,    28,    29,    30,    31,    34,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    47,    66,    70,
      79,    83,    85,    86,    87,    88,    89,    90,    31,    63,
      20,    45,    90,    90,    90,    90,    90,    90,    83,    90,
      22,    22,    22,    22,    22,    45,    71,    80,    73,    75,
      45,    45,     4,    45,     7,     8,    10,    11,    12,    13,
      18,    19,    20,    22,    24,    25,    84,    20,    43,    23,
      23,    90,    90,    90,    23,    23,    83,    22,    22,    22,
      72,    87,    90,    89,    89,    89,    89,    89,    83,    23,
      91,    31,    31,     6,    43,    21,    23,    23,    23,    45,
      83,    83,    82,    83,    70,    21,    83,    92,    83,    21,
      45,    45,    45,    45,    23,    23,    45,     5,    23,    81,
      74,    76,    83,    70,    70,    82,    45,    77,    82,    23,
      78,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    52,    52,    52,
      53,    52,    54,    54,    54,    56,    57,    55,    55,    58,
      59,    58,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    67,    66,    68,    69,
      69,    70,    70,    70,    71,    70,    70,    70,    72,    70,
      73,    74,    70,    75,    76,    77,    78,    70,    70,    70,
      70,    70,    70,    80,    81,    79,    82,    82,    84,    83,
      83,    85,    86,    86,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    90,    90,    90,    90,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     4,     7,     2,     2,
       0,     3,     1,     1,     1,     0,     0,     7,     2,     5,
       0,     7,     1,     0,     1,     1,     1,     3,     3,     6,
       2,     0,     4,     7,     2,     2,     0,     5,     1,     2,
       0,     2,     1,     2,     0,     4,     1,     1,     0,     4,
       0,     0,     7,     0,     0,     0,     0,    13,     2,     2,
       5,     5,     5,     0,     0,     7,     1,     0,     0,     4,
       1,     1,     3,     1,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       0,     5,     3,     3,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 54 "subc.y"
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
#line 1508 "subc.tab.c"
    break;

  case 3:
#line 65 "subc.y"
        {
            printf("Lglob.  data %d\n", (yyvsp[0].intVal));
        }
#line 1516 "subc.tab.c"
    break;

  case 4:
#line 72 "subc.y"
        {
            (yyval.intVal) = (yyvsp[-1].intVal) + (yyvsp[0].intVal);
        }
#line 1524 "subc.tab.c"
    break;

  case 5:
#line 76 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1532 "subc.tab.c"
    break;

  case 6:
#line 83 "subc.y"
        {
            (yyval.intVal) = declare((yyvsp[-1].idptr), makevardecl((yyvsp[-3].declptr), (yyvsp[-2].boolVal)))->size;
        }
#line 1540 "subc.tab.c"
    break;

  case 7:
#line 87 "subc.y"
        {
            (yyval.intVal) = declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].intVal), makevardecl((yyvsp[-6].declptr), (yyvsp[-5].boolVal)))))->size;
        }
#line 1548 "subc.tab.c"
    break;

  case 8:
#line 91 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1556 "subc.tab.c"
    break;

  case 9:
#line 95 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1564 "subc.tab.c"
    break;

  case 10:
#line 99 "subc.y"
        {
            if ((yyvsp[0].declptr))
            {
                push_scope();
                decl* returndecl = declare(returnid, makevardecl((yyvsp[0].declptr)->returntype->type, false));
                returndecl->name = (yyvsp[0].declptr)->name;
                pushstelist((yyvsp[0].declptr)->formals);
                printf("%s_start:\n", (yyvsp[0].declptr)->name->name);
            }    
        }
#line 1579 "subc.tab.c"
    break;

  case 11:
#line 110 "subc.y"
        {
            if ((yyvsp[-2].declptr))
            {
                pop_scope();
                printf("%s_final:\n", (yyvsp[-2].declptr)->name->name);
                printf("\t\tpush_reg fp\n");
                printf("\t\tpop_reg sp\n");
                printf("\t\tpop_reg fp\n");
                printf("\t\tpop_reg pc\n");
                printf("%s_end:\n", (yyvsp[-2].declptr)->name->name);
            }
            (yyval.intVal) = 0;
        }
#line 1597 "subc.tab.c"
    break;

  case 12:
#line 127 "subc.y"
        {
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
        }
#line 1605 "subc.tab.c"
    break;

  case 13:
#line 131 "subc.y"
        {
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
        }
#line 1613 "subc.tab.c"
    break;

  case 14:
#line 135 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 1621 "subc.tab.c"
    break;

  case 15:
#line 142 "subc.y"
        { 
            (yyval.declptr) = structdeclare((yyvsp[-1].idptr), makestructdecl());
            push_scope();   
        }
#line 1630 "subc.tab.c"
    break;

  case 16:
#line 147 "subc.y"
        {   
            ste *fields = pop_scope();
            if ((yyvsp[-1].declptr))
            {
                (yyvsp[-1].declptr)->fields = fields;
            }
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1643 "subc.tab.c"
    break;

  case 17:
#line 156 "subc.y"
        {
            (yyval.declptr) = (yyvsp[-1].declptr);
            (yyval.declptr)->size = (yyvsp[-2].intVal);
        }
#line 1652 "subc.tab.c"
    break;

  case 18:
#line 161 "subc.y"
        {
            (yyval.declptr) = findstructdecl((yyvsp[0].idptr));
        }
#line 1660 "subc.tab.c"
    break;

  case 19:
#line 168 "subc.y"
        {
            decl *procdecl = makeprocdecl();
            procdecl->name = (yyvsp[-2].idptr);
            procdecl->returntype = makeconstdecl((yyvsp[-4].declptr));
            (yyval.declptr) = declare((yyvsp[-2].idptr), procdecl);
            printf("%s:\n", (yyvsp[-2].idptr)->name);
        }
#line 1672 "subc.tab.c"
    break;

  case 20:
#line 176 "subc.y"
        {
            decl *procdecl = makeprocdecl();
            procdecl->name = (yyvsp[-1].idptr);
            if ((yyval.declptr) = declare((yyvsp[-1].idptr), procdecl))
            {
                push_scope();
                declare(returnid, makeconstdecl((yyvsp[-3].declptr)));
            }
        }
#line 1686 "subc.tab.c"
    break;

  case 21:
#line 186 "subc.y"
        {
            if ((yyval.declptr) = (yyvsp[-2].declptr))
            {
                ste *formals = pop_scope();
                (yyval.declptr)->returntype = formals->decl;
                (yyval.declptr)->formals = formals->prev;
            }
            printf("%s:\n", (yyvsp[-4].idptr)->name);
        }
#line 1700 "subc.tab.c"
    break;

  case 22:
#line 199 "subc.y"
        {
            (yyval.boolVal) = true;
        }
#line 1708 "subc.tab.c"
    break;

  case 23:
#line 203 "subc.y"
        {
            (yyval.boolVal) = false;
        }
#line 1716 "subc.tab.c"
    break;

  case 28:
#line 220 "subc.y"
        {
            declare((yyvsp[0].idptr), makevardecl((yyvsp[-2].declptr), (yyvsp[-1].boolVal)));
        }
#line 1724 "subc.tab.c"
    break;

  case 29:
#line 224 "subc.y"
        {
            declare((yyvsp[-3].idptr), makeconstdecl(makearraydecl((yyvsp[-1].intVal), makevardecl((yyvsp[-5].declptr), (yyvsp[-4].boolVal)))));
        }
#line 1732 "subc.tab.c"
    break;

  case 30:
#line 231 "subc.y"
        {
            (yyval.intVal) = (yyvsp[-1].intVal) + (yyvsp[0].intVal);
        }
#line 1740 "subc.tab.c"
    break;

  case 31:
#line 235 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1748 "subc.tab.c"
    break;

  case 32:
#line 242 "subc.y"
        {
            (yyval.intVal) = declare((yyvsp[-1].idptr), makevardecl((yyvsp[-3].declptr), (yyvsp[-2].boolVal)))->size;
        }
#line 1756 "subc.tab.c"
    break;

  case 33:
#line 246 "subc.y"
        {
            (yyval.intVal) = declare((yyvsp[-4].idptr), makeconstdecl(makearraydecl((yyvsp[-2].intVal), makevardecl((yyvsp[-6].declptr), (yyvsp[-5].boolVal)))))->size;
        }
#line 1764 "subc.tab.c"
    break;

  case 34:
#line 250 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1772 "subc.tab.c"
    break;

  case 35:
#line 254 "subc.y"
        {
            (yyval.intVal) = 0;
        }
#line 1780 "subc.tab.c"
    break;

  case 36:
#line 261 "subc.y"
        {
            if ((yyvsp[0].intVal))
            {
                printf("\t\tshift_sp %d\n", (yyvsp[0].intVal));
            }
        }
#line 1791 "subc.tab.c"
    break;

  case 38:
#line 272 "subc.y"
        {
            (yyval.intVal) = (yyvsp[0].intVal);
        }
#line 1799 "subc.tab.c"
    break;

  case 41:
#line 284 "subc.y"
        {
            printf("\t\tshift_sp -1\n");
        }
#line 1807 "subc.tab.c"
    break;

  case 43:
#line 289 "subc.y"
        {
            functionreturn(voidtype);
        }
#line 1815 "subc.tab.c"
    break;

  case 44:
#line 293 "subc.y"
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
#line 1845 "subc.tab.c"
    break;

  case 45:
#line 319 "subc.y"
        {
            decl* returndecl = functionreturn((yyvsp[-1].declptr));
            
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
#line 1879 "subc.tab.c"
    break;

  case 47:
#line 350 "subc.y"
        {
            printf("label_%d:\n", (yyvsp[0].intVal) + 1);
        }
#line 1887 "subc.tab.c"
    break;

  case 48:
#line 354 "subc.y"
        {
            printf("\t\tjump label_%d\n", (yyvsp[-1].intVal) + 2);
            printf("label_%d:\n", (yyvsp[-1].intVal) + 1);
        }
#line 1896 "subc.tab.c"
    break;

  case 49:
#line 359 "subc.y"
        {
            printf("label_%d:\n", (yyvsp[-3].intVal) + 2);
        }
#line 1904 "subc.tab.c"
    break;

  case 50:
#line 363 "subc.y"
        {
            printf("label_%d:\n", n_label);
            (yyval.intVal) = n_label;
            push_label(n_label);
            n_label = n_label + 2;
            push_scope();
        }
#line 1916 "subc.tab.c"
    break;

  case 51:
#line 371 "subc.y"
        {
            printf("\t\tbranch_false label_%d\n", (yyvsp[-3].intVal) + 1);
        }
#line 1924 "subc.tab.c"
    break;

  case 52:
#line 375 "subc.y"
        {
            pop_scope();
            printf("\t\tjump label_%d\n", (yyvsp[-5].intVal));
            printf("label_%d:\n", (yyvsp[-5].intVal) + 1);
            pop_label();
        }
#line 1935 "subc.tab.c"
    break;

  case 53:
#line 382 "subc.y"
        {
            push_scope();
        }
#line 1943 "subc.tab.c"
    break;

  case 54:
#line 386 "subc.y"
        {
            printf("label_%d:\n", n_label);
            (yyval.intVal) = n_label;
            push_label(n_label);
            n_label = n_label + 4;
        }
#line 1954 "subc.tab.c"
    break;

  case 55:
#line 393 "subc.y"
        {
            printf("\t\tbranch_false label_%d\n", (yyvsp[-2].intVal) + 1);
            printf("\t\tjump label_%d\n", (yyvsp[-2].intVal) + 2);
            printf("label_%d:\n", (yyvsp[-2].intVal) + 3);
        }
#line 1964 "subc.tab.c"
    break;

  case 56:
#line 399 "subc.y"
        {
            printf("\t\tjump label_%d\n", (yyvsp[-5].intVal));
            printf("label_%d:\n", (yyvsp[-5].intVal) + 2);
        }
#line 1973 "subc.tab.c"
    break;

  case 57:
#line 404 "subc.y"
        {
            pop_scope();
            printf("\t\tjump label_%d\n", (yyvsp[-7].intVal) + 3);
            printf("label_%d:\n", (yyvsp[-7].intVal) + 1);
            pop_label();
        }
#line 1984 "subc.tab.c"
    break;

  case 58:
#line 411 "subc.y"
        {
            printf("\t\tjump label_%d\n", current_label() + 1);
        }
#line 1992 "subc.tab.c"
    break;

  case 59:
#line 415 "subc.y"
        {
            printf("\t\tjump label_%d\n", current_label());
        }
#line 2000 "subc.tab.c"
    break;

  case 60:
#line 419 "subc.y"
        {
            if (check_isvar((yyvsp[-2].declptr)))
            {
                printf("\t\tfetch\n");
            }
            printf("\t\twrite_int\n");
        }
#line 2012 "subc.tab.c"
    break;

  case 61:
#line 427 "subc.y"
        { 
            if (check_isvar((yyvsp[-2].declptr)))
            {
                printf("\t\tfetch\n");
            }
            printf("\t\twrite_char\n");
        }
#line 2024 "subc.tab.c"
    break;

  case 62:
#line 435 "subc.y"
        {
            if (check_isarray((yyvsp[-2].declptr)->type))
            {
                printf("\t\tpush_reg sp\n");
                printf("\t\tpush_const %d\n", (yyvsp[-2].declptr)->size);
                printf("\t\tsub\n");
            }
            else
            {
                printf("\t\tpush_const str_%d\n", (yyvsp[-2].declptr)->intval);
            }
            printf("\t\twrite_string\n");
        }
#line 2042 "subc.tab.c"
    break;

  case 63:
#line 452 "subc.y"
        {
            printf("label_%d:\n", n_label);
            (yyval.intVal) = n_label;
            n_label = n_label + 3;
        }
#line 2052 "subc.tab.c"
    break;

  case 64:
#line 458 "subc.y"
        {
            printf("\t\tbranch_false label_%d\n", (yyvsp[-3].intVal) + 1);
        }
#line 2060 "subc.tab.c"
    break;

  case 65:
#line 462 "subc.y"
        {
            (yyval.intVal) = (yyvsp[-5].intVal);
        }
#line 2068 "subc.tab.c"
    break;

  case 68:
#line 474 "subc.y"
        {
           
            if (check_isstruct((yyvsp[0].declptr)->type))
            {
                ste *stenode;
                for (stenode = (yyvsp[0].declptr)->type->fields; stenode; stenode = stenode->prev)
                {
                    printf("\t\tpush_reg fp\n");
                    if ((yyvsp[0].declptr)->offset + stenode->decl->offset)
                    {
                        printf("\t\tpush_const %d\n", (yyvsp[0].declptr)->offset + stenode->decl->offset);
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
#line 2094 "subc.tab.c"
    break;

  case 69:
#line 496 "subc.y"
        {
            (yyval.declptr) = assign_op((yyvsp[-3].declptr), (yyvsp[0].declptr));

            if (check_isstruct((yyvsp[-3].declptr)->type))
            {
                ste *stenode;
                for (stenode = (yyvsp[-3].declptr)->type->fields; stenode; stenode = stenode->prev)
                {
                    printf("\t\tpush_reg sp\n");

                    printf("\t\tpush_const %d\n", (yyvsp[-3].declptr)->size);
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tpush_reg sp\n");
                    printf("\t\tpush_const 1\n");
                    printf("\t\tsub\n");
                    printf("\t\tfetch\n");
                    printf("\t\tassign\n");
                    printf("\t\tshift_sp -1\n");
                }
                printf("\t\tshift_sp -%d\n", (yyvsp[-3].declptr)->size);
            }
            else
            {
                printf("\t\tassign\n");
                printf("\t\tfetch\n");
            }   
        }
#line 2127 "subc.tab.c"
    break;

  case 70:
#line 525 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 2135 "subc.tab.c"
    break;

  case 71:
#line 532 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 2143 "subc.tab.c"
    break;

  case 72:
#line 539 "subc.y"
        {
            (yyval.declptr) = plus_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            printf("\t\tor\n");
        }
#line 2152 "subc.tab.c"
    break;

  case 73:
#line 544 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 2160 "subc.tab.c"
    break;

  case 74:
#line 551 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 2168 "subc.tab.c"
    break;

  case 75:
#line 558 "subc.y"
        {
            (yyval.declptr) = plus_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            printf("\t\tand\n");
        }
#line 2177 "subc.tab.c"
    break;

  case 76:
#line 563 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
        }
#line 2185 "subc.tab.c"
    break;

  case 77:
#line 570 "subc.y"
        {
            (yyval.declptr) = rel_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            if ((yyvsp[-1].idptr) == greater)
                printf("\t\tgreater\n");
            else if ((yyvsp[-1].idptr) == greater_equal)
                printf("\t\tgreater_equal\n");
            else if ((yyvsp[-1].idptr) == less)
                printf("\t\tless\n");
            else if ((yyvsp[-1].idptr) == less_equal)
                printf("\t\tless_equal\n");
        }
#line 2201 "subc.tab.c"
    break;

  case 78:
#line 582 "subc.y"
        {
            (yyval.declptr) = equ_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            if ((yyvsp[-1].idptr) == equal)
                printf("\t\tequal\n");
            if ((yyvsp[-1].idptr) == not_equal)
                printf("\t\tnot_equal\n");
        }
#line 2213 "subc.tab.c"
    break;

  case 79:
#line 590 "subc.y"
        {
            (yyval.declptr) = plus_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            printf("\t\tadd\n");
        }
#line 2222 "subc.tab.c"
    break;

  case 80:
#line 595 "subc.y"
        {
            (yyval.declptr) = minus_op((yyvsp[-2].declptr), (yyvsp[0].declptr));
            printf("\t\tsub\n");
        }
#line 2231 "subc.tab.c"
    break;

  case 81:
#line 600 "subc.y"
        {
            (yyval.declptr) = (yyvsp[0].declptr);
            if (check_isstruct((yyval.declptr)->type) && !check_isconst((yyval.declptr)))
            {
                printf("\t\tfetch\n");
                ste *stenode;
                for (stenode = (yyval.declptr)->type->fields; stenode; stenode = stenode->prev)
                {
                    if (stenode->decl->offset != 0)
                    {
                        printf("\t\tpush_reg fp\n");
                        printf("\t\tpush_const %d\n", (yyval.declptr)->offset  + stenode->decl->offset);
                        printf("\t\tadd\n");
                        printf("\t\tfetch\n");
                    }
                    
                }
            }
            else if (!check_isconst((yyval.declptr)))
            {
                printf("\t\tfetch\n");
            }
        }
#line 2259 "subc.tab.c"
    break;

  case 82:
#line 627 "subc.y"
        {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 2267 "subc.tab.c"
    break;

  case 83:
#line 631 "subc.y"
        {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 2275 "subc.tab.c"
    break;

  case 84:
#line 635 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(inttype);
            (yyval.declptr)->intval = (yyvsp[0].intVal);
            printf("\t\tpush_const %d\n", (yyval.declptr)->intval);
        }
#line 2285 "subc.tab.c"
    break;

  case 85:
#line 641 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(chartype);
            (yyval.declptr)->charval = (yyvsp[0].charVal);
            printf("\t\tpush_const %d\n", (yyval.declptr)->charval);
        }
#line 2295 "subc.tab.c"
    break;

  case 86:
#line 647 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(makeptrdecl(chartype));
            (yyval.declptr)->intval = n_string++;
            printf("str_%d. string \"%s\"\n", (yyval.declptr)->intval, (yyvsp[0].stringVal));
        }
#line 2305 "subc.tab.c"
    break;

  case 87:
#line 653 "subc.y"
        {
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
            
            if (check_isfunction((yyval.declptr)))
            {
            }
            else if (check_isglobal((yyval.declptr)))
            {
                printf("\t\tpush_const Lglob+%d\n", (yyval.declptr)->offset);
            }
            
            else
            {
                printf("\t\tpush_reg fp\n");
                printf("\t\tpush_const %d\n", (yyval.declptr)->offset);
                printf("\t\tadd\n");
            }
        }
#line 2328 "subc.tab.c"
    break;

  case 88:
#line 672 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(makeptrdecl(voidtype));
            (yyval.declptr)->intval = 0;
        }
#line 2337 "subc.tab.c"
    break;

  case 89:
#line 677 "subc.y"
        {
            (yyval.declptr) = unary_minus_op((yyvsp[0].declptr));
            printf("\t\tnegate\n");
        }
#line 2346 "subc.tab.c"
    break;

  case 90:
#line 682 "subc.y"
        {
            (yyval.declptr) = unary_not_op((yyvsp[0].declptr));
            printf("\t\tnot\n");
        }
#line 2355 "subc.tab.c"
    break;

  case 91:
#line 688 "subc.y"
        {
            (yyval.declptr) = inc_op((yyvsp[-1].declptr));
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
#line 2374 "subc.tab.c"
    break;

  case 92:
#line 703 "subc.y"
        {
            (yyval.declptr) = dec_op((yyvsp[-1].declptr));
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
#line 2393 "subc.tab.c"
    break;

  case 93:
#line 718 "subc.y"
        {
            (yyval.declptr) = inc_op((yyvsp[0].declptr));
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
#line 2410 "subc.tab.c"
    break;

  case 94:
#line 731 "subc.y"
        {
            (yyval.declptr) = dec_op((yyvsp[0].declptr));
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
#line 2427 "subc.tab.c"
    break;

  case 95:
#line 744 "subc.y"
        {
            (yyval.declptr) = address_op((yyvsp[0].declptr));
        }
#line 2435 "subc.tab.c"
    break;

  case 96:
#line 748 "subc.y"
        {
            (yyval.declptr) = pointer_op((yyvsp[0].declptr));
            printf("\t\tfetch\n");
        }
#line 2444 "subc.tab.c"
    break;

  case 97:
#line 753 "subc.y"
        {
            (yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));
            printf("\t\tpush_const %d\n", (yyval.declptr)->size);
            printf("\t\tmul\n");
            printf("\t\tadd\n");
        }
#line 2455 "subc.tab.c"
    break;

  case 98:
#line 760 "subc.y"
        {
            (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            if ((yyval.declptr)->offset)
            {
                printf("\t\tpush_const %d\n", (yyval.declptr)->offset);
                printf("\t\tadd\n");
            }
        }
#line 2468 "subc.tab.c"
    break;

  case 99:
#line 769 "subc.y"
        {
            (yyval.declptr) = structptraccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            printf("\t\tfetch\n");
            if ((yyval.declptr)->offset)
            {
                printf("\t\tpush_const %d\n", (yyval.declptr)->offset);
                printf("\t\tadd\n");
            }
        }
#line 2482 "subc.tab.c"
    break;

  case 100:
#line 779 "subc.y"
        {
            printf("\t\tshift_sp %d\n", (yyvsp[-1].declptr)->returntype->size);
            printf("\t\tpush_const label_%d\n", (yyval.intVal) = n_label++);
            printf("\t\tpush_reg fp\n");
        }
#line 2492 "subc.tab.c"
    break;

  case 101:
#line 785 "subc.y"
        {
            (yyval.declptr) = functioncall((yyvsp[-4].declptr), (yyvsp[-1].declptr));
            declare(NULL, (yyval.declptr));
            int num_formals;
            num_formals = 0;
            decl* actuals = (yyvsp[-1].declptr);
            while (actuals)
            {
                num_formals = num_formals + actuals->size;
                actuals = actuals->next;
            }
            printf("\t\tpush_reg sp\n");
            printf("\t\tpush_const -%d\n", num_formals);
            printf("\t\tadd\n");
            printf("\t\tpop_reg fp\n");
            printf("\t\tjump %s\n", (yyvsp[-4].declptr)->name->name);
            printf("label_%d:\n", (yyvsp[-2].intVal));
        }
#line 2515 "subc.tab.c"
    break;

  case 102:
#line 804 "subc.y"
        {
            (yyval.declptr) = functioncall((yyvsp[-2].declptr), NULL);
            declare(NULL, (yyval.declptr));
            printf("\t\tshift_sp %d\n", (yyvsp[-2].declptr)->returntype->size);
            printf("\t\tpush_const label_%d\n", n_label);
            printf("\t\tpush_reg fp\n");
            printf("\t\tpush_reg sp\n");
            printf("\t\tpop_reg fp\n");
            printf("\t\tjump %s\n", (yyvsp[-2].declptr)->name->name);
            printf("label_%d:\n", n_label++);
        }
#line 2531 "subc.tab.c"
    break;

  case 103:
#line 816 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(inttype);
            printf("\t\tread_int\n");
        }
#line 2540 "subc.tab.c"
    break;

  case 104:
#line 821 "subc.y"
        {
            (yyval.declptr) = makeconstdecl(chartype);
            printf("\t\tread_char\n");
        }
#line 2549 "subc.tab.c"
    break;

  case 105:
#line 829 "subc.y"
        {
            (yyval.declptr) = makeargdecl((yyvsp[0].declptr));
        }
#line 2557 "subc.tab.c"
    break;

  case 106:
#line 833 "subc.y"
        {
            decl *last = (yyvsp[-2].declptr);
            while (last->next)
            {
                last = last->next;
            }
            last->next = makeargdecl((yyvsp[0].declptr));
            (yyval.declptr) = (yyvsp[-2].declptr);
        }
#line 2571 "subc.tab.c"
    break;


#line 2575 "subc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 844 "subc.y"


/*  Additional C Codes here */

int    yyerror (char* s)
{
    printf ("%s:%d: error:%s\n", filename, read_line(), s);
}
