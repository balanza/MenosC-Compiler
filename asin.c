
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "asin.y"

#include <stdio.h>
#include "include/libgci.h"
#include "include/libtds.h"
extern int yylineno;

/**************** Variables globales **********************/
int old_dvar;              /* Desplazamiento en el Segmento de Variables  */
int dpar;              /* Desplazamiento en el Segmento de Parametros de funcion  */
int dcmp;              /* Desplazamiento del campo en una estructura  */
int nivel; 			   /* Nivel de anidamiento */
int hayMain;           /* Se pone a 1 cuando encontramos la funcion main */
int lansMain;          /* instruccion a la cual se encuentra el main */    
int lansDespGlobal;         /* tamaño del desplazamento global */ 
int hayReturn;         /* Indica si una funcion tiene una devolucion de valor*/ 
int tallaReturn;       /* Talla del eventual valor de return*/
int lansDespFuncion;    /* Se utiliza para resolver la lans del tamaño del desplazamento inicial de una funcion*/



/************************************* Codigos para los distintos operadores */
#define DISTINTO      0
#define IGUAL         1
#define MAYOR         2
#define MENOR         3
#define MAYORIG       4
#define MENORIG       5
#define POR           6
#define DIV           7
#define MAS           8
#define MENOS         9
#define ASIG         10
#define MASASIG      11
#define MENOSASIG    12
#define MASMAS       13
#define MENOSMENOS   14 
/******************************************* Tallas de los tipos y segmentos */
#define TALLA_ENTERO     1
#define TALLA_SEGENLACES 2       /* Talla del segmento de Enlaces de Control */



/* Line 189 of yacc.c  */
#line 116 "asin.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PUNTOYCOMA_ = 258,
     PUNTO_ = 259,
     COMA_ = 260,
     PARABR_ = 261,
     PARCER_ = 262,
     LLAVABR_ = 263,
     LLAVCER_ = 264,
     CORABR_ = 265,
     CORCER_ = 266,
     INT_ = 267,
     STRUCT_ = 268,
     READ_ = 269,
     PRINT_ = 270,
     IF_ = 271,
     ELSE_ = 272,
     FOR_ = 273,
     RETURN_ = 274,
     MAS_ = 275,
     POR_ = 276,
     MENOS_ = 277,
     DIV_ = 278,
     INCMAS_ = 279,
     INCMENOS_ = 280,
     ASIG_ = 281,
     ASIGMAS_ = 282,
     ASIGMENOS_ = 283,
     IGUAL_ = 284,
     DIF_ = 285,
     GT_ = 286,
     GTE_ = 287,
     LT_ = 288,
     LTE_ = 289,
     ID_ = 290,
     CTE_ = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "asin.y"

  char* ident;  
  /* Para los identificadores  */
  int cent;  /* Para constantes enteras */
  int operador;
  struct tipo_def /* Estructura para una descricion de tipo */
	{
	  int talla;                            
	  int tipo;  
	  char* id;
	  int ref; 
	  TIPO_ARG exp;
	  int instr1;  //2 slots de referencia a instruciones
	  int instr2;                         
	} tdef;





/* Line 214 of yacc.c  */
#line 209 "asin.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 221 "asin.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    20,
      27,    29,    34,    36,    39,    42,    43,    50,    51,    53,
      56,    61,    66,    67,    70,    71,    74,    75,    81,    83,
      85,    87,    89,    91,    93,    96,    97,   104,   105,   112,
     113,   114,   124,   125,   126,   127,   140,   141,   143,   147,
     149,   153,   160,   166,   168,   172,   174,   178,   180,   184,
     186,   190,   192,   195,   198,   203,   207,   210,   215,   219,
     221,   223,   224,   226,   228,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    -1,    39,    40,    -1,    41,    -1,    40,
      41,    -1,    42,    -1,    45,    -1,    43,    35,     3,    -1,
      43,    35,    10,    36,    11,     3,    -1,    12,    -1,    13,
       8,    44,     9,    -1,    42,    -1,    44,    42,    -1,    46,
      50,    -1,    -1,    43,    35,     6,    47,    48,     7,    -1,
      -1,    49,    -1,    43,    35,    -1,    43,    35,     5,    49,
      -1,     8,    51,    52,     9,    -1,    -1,    51,    42,    -1,
      -1,    52,    53,    -1,    -1,    54,     8,    51,    52,     9,
      -1,    55,    -1,    56,    -1,    59,    -1,    62,    -1,    67,
      -1,     3,    -1,    68,     3,    -1,    -1,    14,     6,    35,
      57,     7,     3,    -1,    -1,    15,     6,    68,    58,     7,
       3,    -1,    -1,    -1,    16,     6,    68,     7,    60,    53,
      61,    17,    53,    -1,    -1,    -1,    -1,    18,     6,    66,
       3,    63,    68,     3,    64,    66,     7,    65,    53,    -1,
      -1,    68,    -1,    19,    68,     3,    -1,    69,    -1,    35,
      77,    68,    -1,    35,    10,    68,    11,    77,    68,    -1,
      35,     4,    35,    77,    68,    -1,    70,    -1,    69,    78,
      70,    -1,    71,    -1,    70,    79,    71,    -1,    72,    -1,
      71,    80,    72,    -1,    73,    -1,    72,    81,    73,    -1,
      74,    -1,    83,    73,    -1,    82,    35,    -1,    35,    10,
      68,    11,    -1,    35,     4,    35,    -1,    35,    82,    -1,
      35,     6,    75,     7,    -1,     6,    68,     7,    -1,    35,
      -1,    36,    -1,    -1,    76,    -1,    68,    -1,    68,     5,
      76,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      20,    -1,    22,    -1,    21,    -1,    23,    -1,    24,    -1,
      25,    -1,    20,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   108,   141,   145,   150,   163,   195,   203,
     221,   227,   234,   244,   255,   280,   279,   318,   321,   326,
     341,   358,   364,   369,   384,   385,   388,   388,   397,   398,
     399,   400,   401,   403,   407,   410,   409,   425,   424,   431,
     437,   430,   448,   453,   462,   447,   477,   480,   485,   504,
     508,   554,   587,   614,   618,   648,   652,   690,   694,   716,
     720,   741,   745,   759,   789,   806,   826,   830,   859,   863,
     876,   883,   886,   893,   899,   905,   909,   913,   918,   922,
     927,   931,   935,   939,   944,   948,   953,   957,   962,   966,
     971,   975
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PUNTOYCOMA_", "PUNTO_", "COMA_",
  "PARABR_", "PARCER_", "LLAVABR_", "LLAVCER_", "CORABR_", "CORCER_",
  "INT_", "STRUCT_", "READ_", "PRINT_", "IF_", "ELSE_", "FOR_", "RETURN_",
  "MAS_", "POR_", "MENOS_", "DIV_", "INCMAS_", "INCMENOS_", "ASIG_",
  "ASIGMAS_", "ASIGMENOS_", "IGUAL_", "DIF_", "GT_", "GTE_", "LT_", "LTE_",
  "ID_", "CTE_", "$accept", "programa", "$@1", "secuenciaDeclaraciones",
  "declaracion", "declaracionVariable", "tipo", "listaCampos",
  "declaracionFuncion", "cabeceraFuncion", "$@2", "parametrosFormales",
  "listaParametrosFormales", "bloque", "declaracionVariableLocal",
  "listaInstrucciones", "instruccion", "$@3", "instruccionExpresion",
  "instruccionEntradaSalida", "$@4", "$@5", "instruccionSeleccion", "@6",
  "@7", "instruccionIteraccion", "@8", "@9", "@10", "expresionOpcional",
  "instruccionSalto", "expresion", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "parametrosActuales",
  "listaParametrosActuales", "operadorAsignacion", "operadorIgualdad",
  "operadorRelacional", "operadorAditivo", "operadorMultiplicativo",
  "operadorIncremento", "operadorUnario", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    47,    46,    48,    48,    49,
      49,    50,    51,    51,    52,    52,    54,    53,    53,    53,
      53,    53,    53,    55,    55,    57,    56,    58,    56,    60,
      61,    59,    63,    64,    65,    62,    66,    66,    67,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       1,     4,     1,     2,     2,     0,     6,     0,     1,     2,
       4,     4,     0,     2,     0,     2,     0,     5,     1,     1,
       1,     1,     1,     1,     2,     0,     6,     0,     6,     0,
       0,     9,     0,     0,     0,    12,     0,     1,     3,     1,
       3,     6,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     2,     4,     3,     2,     4,     3,     1,
       1,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    10,     0,     3,     4,     6,     0,
       7,     0,     0,     5,     0,    22,    14,    12,     0,     0,
       8,    15,     0,    24,     0,    11,    13,    17,     0,    23,
      26,     0,     0,    18,     0,    33,     0,    21,     0,     0,
       0,     0,     0,    90,    91,    88,    89,    69,    70,    25,
       0,    28,    29,    30,    31,    32,     0,    49,    53,    55,
      57,    59,    61,     0,     0,    19,    16,     9,     0,     0,
       0,     0,    46,     0,     0,    71,     0,    75,    76,    77,
       0,    66,    22,    34,    78,    79,     0,    80,    81,    82,
      83,     0,    84,    85,     0,    86,    87,     0,    63,    69,
      62,     0,    68,    35,    37,     0,     0,    47,    48,    65,
      73,     0,    72,     0,    50,    24,    54,    56,    58,    60,
       0,     0,    20,     0,     0,    39,    42,     0,     0,    67,
      64,    26,    65,     0,     0,     0,    26,     0,    52,    74,
       0,    27,    64,    36,    38,    40,     0,    51,     0,    43,
      26,    46,    41,     0,    44,    26,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    18,    19,    10,    11,
      27,    32,    33,    16,    23,    30,    49,    50,    51,    52,
     123,   124,    53,   136,   148,    54,   137,   151,   155,   106,
      55,    56,    57,    58,    59,    60,    61,    62,   111,   112,
      80,    86,    91,    94,    97,    63,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
    -113,    11,    62,  -113,  -113,     9,    62,  -113,  -113,   -28,
    -113,    51,    62,  -113,    12,  -113,  -113,  -113,    28,     7,
    -113,  -113,   -11,    62,    43,  -113,  -113,    62,    54,  -113,
      42,    34,    69,  -113,    68,  -113,    48,  -113,    76,    84,
      89,    90,    48,  -113,  -113,  -113,  -113,     4,  -113,  -113,
      91,  -113,  -113,  -113,  -113,  -113,    94,    64,    55,    27,
      29,  -113,  -113,    63,   143,    97,  -113,  -113,    96,    72,
      48,    48,    48,   105,    75,    48,    48,  -113,  -113,  -113,
      48,  -113,  -113,  -113,  -113,  -113,   143,  -113,  -113,  -113,
    -113,   143,  -113,  -113,   143,  -113,  -113,   143,  -113,    17,
    -113,    62,  -113,  -113,  -113,   104,   110,  -113,  -113,    53,
     109,   113,  -113,   115,  -113,    62,    55,    27,    29,  -113,
      81,    48,  -113,   117,   123,  -113,  -113,    48,    48,  -113,
      53,   103,  -113,   120,   130,   131,   126,    48,  -113,  -113,
      48,  -113,  -113,  -113,  -113,  -113,   132,  -113,   119,  -113,
     126,    48,  -113,   136,  -113,   126,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,  -113,   141,   -10,    -1,  -113,  -113,  -113,
    -113,  -113,    36,  -113,    70,    38,  -112,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     3,
    -113,   -36,  -113,    71,    65,    61,   -60,  -113,  -113,    30,
     -97,  -113,  -113,  -113,  -113,   -44,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,     9,    17,    81,   100,     9,    73,    14,    74,    26,
      75,     3,   127,    29,    76,    20,    25,    12,    21,     4,
       5,   120,    22,    75,   145,    28,    31,   121,    45,    46,
      77,    78,    79,   140,   104,   105,   107,   119,   152,   110,
     113,    45,    46,   156,   114,    35,    20,    92,    36,    93,
      95,    37,    96,    22,    36,    81,    38,    39,    40,    15,
      41,    42,    43,    24,    44,    34,    45,    46,    43,    65,
      44,    67,    45,    46,     4,     5,    66,    47,    48,    77,
      78,    79,    69,    47,    48,   133,    87,    88,    89,    90,
      70,   138,   110,    84,    85,    71,    72,    83,    98,    82,
      31,   146,   101,   102,   147,    29,    35,   103,   108,    36,
     109,   125,   141,   126,   128,   107,   132,    38,    39,    40,
     129,    41,    42,    43,   134,    44,   130,    45,    46,    35,
     135,   142,    36,   143,   144,   149,   150,   122,    47,    48,
      38,    39,    40,   154,    41,    42,    43,    13,    44,    36,
      45,    46,   115,   131,   153,   118,   117,   116,   139,     0,
       0,    47,    48,    43,     0,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    48
};

static const yytype_int16 yycheck[] =
{
      36,     2,    12,    47,    64,     6,    42,    35,     4,    19,
       6,     0,   109,    23,    10,     3,     9,     8,     6,    12,
      13,     4,    10,     6,   136,    36,    27,    10,    24,    25,
      26,    27,    28,   130,    70,    71,    72,    97,   150,    75,
      76,    24,    25,   155,    80,     3,     3,    20,     6,    22,
      21,     9,    23,    10,     6,    99,    14,    15,    16,     8,
      18,    19,    20,    35,    22,    11,    24,    25,    20,    35,
      22,     3,    24,    25,    12,    13,     7,    35,    36,    26,
      27,    28,     6,    35,    36,   121,    31,    32,    33,    34,
       6,   127,   128,    29,    30,     6,     6,     3,    35,     8,
     101,   137,     5,     7,   140,   115,     3,    35,     3,     6,
      35,     7,     9,     3,     5,   151,    35,    14,    15,    16,
       7,    18,    19,    20,     7,    22,    11,    24,    25,     3,
       7,    11,     6,     3,     3,     3,    17,   101,    35,    36,
      14,    15,    16,     7,    18,    19,    20,     6,    22,     6,
      24,    25,    82,   115,   151,    94,    91,    86,   128,    -1,
      -1,    35,    36,    20,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,    12,    13,    40,    41,    42,    43,
      45,    46,     8,    41,    35,     8,    50,    42,    43,    44,
       3,     6,    10,    51,    35,     9,    42,    47,    36,    42,
      52,    43,    48,    49,    11,     3,     6,     9,    14,    15,
      16,    18,    19,    20,    22,    24,    25,    35,    36,    53,
      54,    55,    56,    59,    62,    67,    68,    69,    70,    71,
      72,    73,    74,    82,    83,    35,     7,     3,    68,     6,
       6,     6,     6,    68,     4,     6,    10,    26,    27,    28,
      77,    82,     8,     3,    29,    30,    78,    31,    32,    33,
      34,    79,    20,    22,    80,    21,    23,    81,    35,    35,
      73,     5,     7,    35,    68,    68,    66,    68,     3,    35,
      68,    75,    76,    68,    68,    51,    70,    71,    72,    73,
       4,    10,    49,    57,    58,     7,     3,    77,     5,     7,
      11,    52,    35,    68,     7,     7,    60,    63,    68,    76,
      77,     9,    11,     3,     3,    53,    68,    68,    61,     3,
      17,    64,    53,    66,     7,    65,    53
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 108 "asin.y"
    {
		nivel = 0;		
		dvar = 0;
		hayMain = 0;
		cargaContexto(nivel);
		
		/**************************** Desplazamiento global ****************************/
		// 	Lo calculamos sumando la talla de todas las "declaraciones de variables
		//	que se dan en la declaración inicial. 				        
		lansDespGlobal = creaLans(si);
		emite(INCTOP, crArgNulo(), crArgNulo(), crArgNulo());
		
		/*********************** Direccion de la funcion "main" ************************/
		lansMain=creaLans(si);
		emite(GOTOS, crArgNulo(), crArgNulo(), crArgNulo());
		
	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 126 "asin.y"
    {
		//completa la instruccion de INCTOP inicial
		completaLans(lansDespGlobal, crArgEntero((yyvsp[(2) - (2)].tdef).talla));
		
		
		//averigua que haya un main en el programa
		if(hayMain==0){
			yyerror("ni un main en todo el programa");
		}
		
		descargaContexto(nivel);
		vuelcaCodigo("codigo");
		
	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 142 "asin.y"
    {
		(yyval.tdef).talla = (yyvsp[(1) - (1)].tdef).talla;
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 146 "asin.y"
    {
		(yyval.tdef).talla = (yyvsp[(1) - (2)].tdef).talla + (yyvsp[(2) - (2)].tdef).talla;
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 151 "asin.y"
    {
		
		if(!insertaSimbolo((yyvsp[(1) - (1)].tdef).id, VARIABLE, (yyvsp[(1) - (1)].tdef).tipo, dvar, nivel, (yyvsp[(1) - (1)].tdef).ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += (yyvsp[(1) - (1)].tdef).talla; // update shift
		}
		
		
		(yyval.tdef).talla = (yyvsp[(1) - (1)].tdef).talla;
		
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 164 "asin.y"
    {
printf("\nLOG: decalara funcion %s tipo %d nivel %d ref %d", (yyvsp[(1) - (1)].tdef).id, (yyvsp[(1) - (1)].tdef).tipo, nivel, (yyvsp[(1) - (1)].tdef).ref);
		if(!insertaSimbolo((yyvsp[(1) - (1)].tdef).id, FUNCION, (yyvsp[(1) - (1)].tdef).tipo, si, nivel, (yyvsp[(1) - (1)].tdef).ref)){
			yyerror("---> funcion repetida");
		}
		
		//detectando main
		if(strcmp("main",(yyvsp[(1) - (1)].tdef).id) == 0){
			if(hayMain==0){
				hayMain = 1;
				completaLans(lansMain, crArgEtiqueta(si));
			} else {
				yyerror("hay dos declaraciones de main en el programa");
			}		
		}
		
		
		if(hayReturn == 1){
			(yyvsp[(1) - (1)].tdef).talla += tallaReturn;
		}
		
		completaLans(lansDespFuncion, crArgEntero((yyvsp[(1) - (1)].tdef).talla));
				
		
		emite(RET, crArgNulo(), crArgNulo(), crArgNulo());
		
		
		//las funciones no ocupan espacio en la memoria estatica
		(yyval.tdef).talla = 0;
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 196 "asin.y"
    {
		(yyval.tdef).id = (yyvsp[(2) - (3)].ident);
		(yyval.tdef).tipo = (yyvsp[(1) - (3)].tdef).tipo; 
		(yyval.tdef).talla = (yyvsp[(1) - (3)].tdef).talla;
		(yyval.tdef).ref = (yyvsp[(1) - (3)].tdef).ref;
		
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 204 "asin.y"
    {
  	//printf("\n cte: %d, tipo: %d", $4, $1.tipo);
  	if((yyvsp[(1) - (6)].tdef).tipo!=T_ENTERO){
		yyerror("el tipo de los vectores tiene que ser int");
	} else if((yyvsp[(4) - (6)].cent)<=0){
		yyerror("el array debe contener un numero positivo de elementos");
	} else {	
		(yyval.tdef).id = (yyvsp[(2) - (6)].ident);
		(yyval.tdef).tipo = T_ARRAY;
		(yyval.tdef).talla = 1; // ???
		(yyval.tdef).ref = insertaInfoArray((yyvsp[(1) - (6)].tdef).tipo, (yyvsp[(4) - (6)].cent));	
	}
	
	
	
  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 222 "asin.y"
    {
		(yyval.tdef).talla = TALLA_ENTERO;
		(yyval.tdef).tipo = T_ENTERO;
		(yyval.tdef).ref = -1;
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 228 "asin.y"
    {
  		(yyval.tdef).talla = (yyvsp[(3) - (4)].tdef).talla;
  		(yyval.tdef).tipo = T_RECORD;
  		(yyval.tdef).ref = (yyvsp[(3) - (4)].tdef).ref;
  	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 235 "asin.y"
    {
		
		if((yyvsp[(1) - (1)].tdef).tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else if((yyval.tdef).ref=insertaInfoCampo(-1, (yyvsp[(1) - (1)].tdef).id, (yyvsp[(1) - (1)].tdef).tipo, 0) == -1){
			yyerror("error en la declaracion de campo de la estructura");
		}
		dcmp = (yyvsp[(1) - (1)].tdef).talla;
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 245 "asin.y"
    {
		
		if((yyvsp[(2) - (2)].tdef).tipo != T_ENTERO){
			yyerror("el tipo de los campos tiene que ser int");
		} else if((yyval.tdef).ref=insertaInfoCampo((yyvsp[(1) - (2)].tdef).ref, (yyvsp[(2) - (2)].tdef).id, (yyvsp[(2) - (2)].tdef).tipo, dcmp)==-1){
			yyerror("error en la declaracion de campo de la estructura");
		}
		dcmp += (yyvsp[(2) - (2)].tdef).talla;
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 256 "asin.y"
    {
		descargaContexto(nivel);
		nivel--;
		dvar = old_dvar;
		
		(yyval.tdef).tipo = (yyvsp[(1) - (2)].tdef).tipo;
		(yyval.tdef).ref = (yyvsp[(1) - (2)].tdef).ref;
		(yyval.tdef).id = (yyvsp[(1) - (2)].tdef).id;
		/*
			la talla de una funcion nos dice el tamaño del RA, siendo la suma de:
			 1. talla de parametros
			 2. talla de segmento de enlaces
			 3. talla de valor devuelto
			(1) está contenido en el no-terminal cabeceraFuncion
			(2) en bloque
			(3) si hayReturn==1, es la talla del tipo --> lo comprobamos en declaracionFuncion
		*/
		(yyval.tdef).talla = (yyvsp[(1) - (2)].tdef).talla + (yyvsp[(2) - (2)].tdef).talla; //
		
		
		
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 280 "asin.y"
    {
	
		//emision de codigo por la inicializacion del RA de la funcion
		emite(PUSHFP, crArgNulo(), crArgNulo(), crArgNulo());
		emite(FPTOP, crArgNulo(), crArgNulo(), crArgNulo());	
  		lansDespFuncion = creaLans(si);	
		emite(INCTOP, crArgNulo(), crArgNulo(), crArgNulo());
		
		if((yyvsp[(1) - (3)].tdef).tipo!=T_ENTERO){
  			yyerror("la funcion tiene que ser de tipo int");
  			//TODO: parar ejecucion
  		} 
  		
  			nivel++;
			cargaContexto(nivel);
			dpar = TALLA_SEGENLACES;
			old_dvar = dvar;
			dvar = 0;
  		
		
	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 302 "asin.y"
    {
	
		(yyval.tdef).tipo = (yyvsp[(1) - (6)].tdef).tipo;
		printf("\nLOG: ref %d", (yyvsp[(5) - (6)].tdef).ref);
		(yyval.tdef).ref = 99;//$5.ref;
		printf("\nLOG: ref %d", (yyvsp[(5) - (6)].tdef).ref);
		(yyval.tdef).id = (yyvsp[(2) - (6)].ident);
		(yyval.tdef).talla = dpar;//$1.talla;		
		
		
		//init: por defecto pongo que lafuncion no haya return 
		hayReturn = 0;
		tallaReturn = (yyvsp[(1) - (6)].tdef).talla;
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 318 "asin.y"
    {
		(yyval.tdef).ref = insertaInfoDominio(-1, T_VACIO);
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 322 "asin.y"
    {
  		(yyval.tdef).ref = (yyvsp[(1) - (1)].tdef).ref;
  	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 327 "asin.y"
    {
  		if((yyvsp[(1) - (2)].tdef).tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		
			if(!insertaSimbolo((yyvsp[(2) - (2)].ident), PARAMETRO, (yyvsp[(1) - (2)].tdef).tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += (yyvsp[(1) - (2)].tdef).talla;
				(yyval.tdef).ref = insertaInfoDominio(-1, (yyvsp[(1) - (2)].tdef).tipo);
			}
		}
  	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 342 "asin.y"
    {
  		if((yyvsp[(1) - (4)].tdef).tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		printf("\ndeclarando parametro (b) %s", (yyvsp[(2) - (4)].ident));
	  		if(!insertaSimbolo((yyvsp[(2) - (4)].ident), PARAMETRO, (yyvsp[(1) - (4)].tdef).tipo, -dpar, nivel, -1)){
				yyerror("Error en la declaracion de paramentro");
			} else {
				dpar += (yyvsp[(1) - (4)].tdef).talla;
			}
			(yyval.tdef).ref = insertaInfoDominio((yyvsp[(4) - (4)].tdef).ref, (yyvsp[(1) - (4)].tdef).tipo);
			//mostrarTDS(nivel);
		}
  	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 359 "asin.y"
    {
		(yyval.tdef).talla = (yyvsp[(2) - (4)].tdef).talla;
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 364 "asin.y"
    {
		mostrarTDS(nivel);
		(yyval.tdef).talla = dvar;
	
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 370 "asin.y"
    {
		
		if(!insertaSimbolo((yyvsp[(2) - (2)].tdef).id, VARIABLE, (yyvsp[(2) - (2)].tdef).tipo, dvar, nivel, (yyvsp[(2) - (2)].tdef).ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += (yyvsp[(2) - (2)].tdef).talla; // update shift
		}
		
		mostrarTDS(nivel);
		
		(yyval.tdef).talla = dvar;
		
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 388 "asin.y"
    {
		nivel++;
		cargaContexto(nivel);
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 393 "asin.y"
    {
		descargaContexto(nivel);
		nivel--;
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 404 "asin.y"
    {
		
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 410 "asin.y"
    {
		SIMB sim = obtenerSimbolo((yyvsp[(3) - (3)].ident));
		if(sim.categoria == NULO)
		{
			yyerror("Error: Identificador no declarado");
		}
		else
		{
			TIPO_ARG argRead = crArgPosicion(sim.nivel,sim.desp);
			emite(EREAD, crArgNulo(), crArgNulo(), argRead);
		}
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 425 "asin.y"
    {
		emite(EWRITE, crArgNulo(), crArgNulo(), (yyvsp[(3) - (3)].tdef).exp);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 431 "asin.y"
    {
		//condiccion para saltar al cuerpo del else
		(yyval.tdef).instr1 = creaLans(si);
		emite(EIGUAL, (yyvsp[(3) - (4)].tdef).exp, crArgEntero(0), crArgNulo());
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 437 "asin.y"
    {
		(yyval.tdef).instr2 = creaLans(si); //fin del bloque if-else
		emite(GOTOS, crArgNulo(), crArgNulo(), crArgNulo());
		completaLans((yyval.tdef).instr1, crArgEtiqueta(si));		
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 443 "asin.y"
    {
		completaLans((yyval.tdef).instr2, crArgEtiqueta(si));
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 448 "asin.y"
    {
		//principio del bucle (justo despues de las instrucciones de inicializaccion)
		(yyval.tdef).instr1 = si;
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 453 "asin.y"
    {
		//instruccion para salir del bucle
		(yyvsp[(6) - (7)].tdef).instr1 = creaLans(si);
		emite(EIGUAL, (yyvsp[(6) - (7)].tdef).exp, crArgEntero(0), crArgNulo());
		//instruccion para volver a las instrucciones cuerpo del bucle
		(yyvsp[(6) - (7)].tdef).instr2 = creaLans(si);
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgNulo());	
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 462 "asin.y"
    {
		//inicio de la funcion de incremento
		(yyvsp[(8) - (10)].tdef).instr1 = si;
		//vuelve a ejecutar la condiccion de entrada al bucle
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgEtiqueta((yyval.tdef).instr1));
		completaLans((yyvsp[(6) - (10)].tdef).instr2, crArgEtiqueta(si));
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 470 "asin.y"
    {
		emite(GOTOS,crArgNulo(),crArgNulo(), crArgEtiqueta((yyvsp[(8) - (12)].tdef).instr1));
		
		completaLans((yyvsp[(6) - (12)].tdef).instr1, crArgEtiqueta(si));
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 477 "asin.y"
    {
		
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 481 "asin.y"
    {
  		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
  	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 486 "asin.y"
    {
		//enciende el flag de existencian de return en la funcion
		hayReturn = 1;
		
		
		INF inf = obtenerInfoFuncion(-1);
		if((yyvsp[(2) - (3)].tdef).tipo != inf.tipo)	{
			yyerror("Tipo devuelto por el return es incorrecto.");
		}
		//if(strcmp("main",inf.nombre) != 0 ){ // No es main
		
	
		int desp = -(inf.tparam + TALLA_SEGENLACES + tallaTipo((yyvsp[(2) - (3)].tdef).tipo));
		emite(EASIG,(yyvsp[(2) - (3)].tdef).exp,crArgNulo(),crArgPosicion(nivel,desp));
		//}
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 505 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 509 "asin.y"
    {
  		
  		SIMB id;
		id = obtenerSimbolo((yyvsp[(1) - (3)].ident));
		if (id.categoria == NULO){
			yyerror("Identificador no declarado");
		}
		if ((id.tipo==(yyvsp[(3) - (3)].tdef).tipo)&&(id.tipo==T_ENTERO)){ 
			(yyval.tdef).tipo = T_ENTERO;
		}
		else {
		
			if (((yyvsp[(3) - (3)].tdef).tipo==T_ERROR)||(id.tipo==T_ERROR)){
				yyerror("Error de tipos en la asignacion de la ((expresion))");
			}
			(yyval.tdef).tipo=T_ERROR;
		}
		
		TIPO_ARG id_arg = crArgPosicion(id.nivel, id.desp);
		TIPO_ARG exp_arg = (yyvsp[(3) - (3)].tdef).exp;
		
		
		switch((yyvsp[(2) - (3)].operador)){
			case MASASIG: // id = id + exp
				emite(ESUM, id_arg, exp_arg, id_arg);
				printf("\nemite asignacion de variable %s+=%d", (yyvsp[(1) - (3)].ident), id_arg.val.i);
				break;
			case MENOSASIG:
				emite(EDIF, id_arg, exp_arg, id_arg);
				printf("\nemite asignacion de variable %s-=%d", (yyvsp[(1) - (3)].ident), id_arg.val.i);
				break;
			case ASIG:
				emite(EASIG, exp_arg, crArgNulo(), id_arg);
				printf("\nemite asignacion de variable %s=%d", (yyvsp[(1) - (3)].ident), id_arg.val.i);
				break;

		}
		
		//printf("\nemite asignacion de variable para %s (sube valor arriba)", $1);
		//emite(EASIG, id_arg, crArgNulo(), $$);
		(yyval.tdef).exp = id_arg;
		(yyval.tdef).tipo = id.tipo;
  		
  		
  	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 555 "asin.y"
    {
		SIMB id;
		
		id = obtenerSimbolo((yyvsp[(1) - (6)].ident));
		if(id.categoria==NULO){
			yyerror("variable array no declarada");	
			(yyval.tdef).tipo = T_ERROR;
		} else {
			TIPO_ARG indice = (yyvsp[(3) - (6)].tdef).exp; //indice
			TIPO_ARG valor = (yyvsp[(6) - (6)].tdef).exp; // valor de la expresion para asignar
			TIPO_ARG elem = crArgPosicion(nivel, creaVarTemp()); //variable por el valor del elemento id[expresion]
			TIPO_ARG id_arg = crArgPosicion(id.nivel, id.desp);
			
			//leo el elemento del array
			emite(EAV, id_arg, indice, elem);
			
			switch((yyvsp[(5) - (6)].operador)){
				case MASASIG: 
					emite(ESUM, valor, elem, elem);
					break;
				case MENOSASIG:
					emite(EDIF, elem, valor, elem);
					break;
				case ASIG:
					break;
			}			

			emite(EVA, id_arg, indice, elem);
			(yyval.tdef).exp = elem;
			(yyval.tdef).tipo = id.tipo;
		}
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 588 "asin.y"
    {
		SIMB id;
		REG campo;		
		TIPO_ARG exp_arg = (yyvsp[(5) - (5)].tdef).exp;
			
		id = obtenerSimbolo((yyvsp[(1) - (5)].ident));
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			(yyval.tdef).tipo = T_ERROR;
		} else {
			campo = obtenerInfoCampo(id.ref, (yyvsp[(3) - (5)].ident));
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				(yyval.tdef).tipo = T_ERROR;
			}else if(campo.tipo!=exp_arg.tipo){
				yyerror("se trata de asignar un valor de un tipo incorrecto a un campo");	
				(yyval.tdef).tipo = T_ERROR;			
			}else{
				TIPO_ARG campo_arg = crArgPosicion(id.nivel, id.desp + campo.desp);
				emite(ASIG, exp_arg, crArgNulo(), campo_arg);
				(yyval.tdef).exp = campo_arg;
				(yyval.tdef).tipo = campo.tipo;
			}
		}
  	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 615 "asin.y"
    {
  		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
  	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 619 "asin.y"
    {
   		int oprel;
  		
  		TIPO_ARG exp1_arg = (yyvsp[(1) - (3)].tdef).exp;
  		TIPO_ARG exp2_arg = (yyvsp[(3) - (3)].tdef).exp;
  		TIPO_ARG true_arg = crArgEntero(1);
  		TIPO_ARG false_arg = crArgEntero(0);
  		
  	
  		switch((yyvsp[(2) - (3)].operador)){
  			case IGUAL:
  				oprel = EIGUAL;
  				break;
  			case DISTINTO:
				oprel = EDIST;		
  				break;
  			default:
  				yyerror("Operador igualdad desconocido");
  		}
  		
  		
  		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());  	
 		emite(EASIG, true_arg, crArgNulo(), (yyval.tdef).exp);  	
 		emite(oprel, exp1_arg, exp2_arg, crArgEtiqueta(si+2));  	
 		emite(EASIG, false_arg, crArgNulo(), (yyval.tdef).exp);
 		
 		(yyval.tdef).tipo = T_LOGICO;
  	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 649 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 653 "asin.y"
    {
  		int oprel;
  		
  		TIPO_ARG exp1_arg = (yyvsp[(1) - (3)].tdef).exp;
  		TIPO_ARG exp2_arg = (yyvsp[(3) - (3)].tdef).exp;
  		TIPO_ARG true_arg = crArgEntero(1);
  		TIPO_ARG false_arg = crArgEntero(0);
  		
  	
  		switch((yyvsp[(2) - (3)].operador)){
  			case MAYOR:
  				oprel = EMAY;
  				break;
  			case MENOR:
				oprel = EMEN;		
  				break;
  			case MAYORIG:
  				oprel = EMAYEQ;
  				break;
  			case MENORIG:
  				oprel = EMENEQ;
  				break;
  			default:
  				yyerror("Operador relacional desconocido");
  		}
  		
  		
  		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());  	
 		emite(EASIG, true_arg, crArgNulo(), (yyval.tdef).exp);  	
 		emite(oprel, exp1_arg, exp2_arg, crArgEtiqueta(si+2));  	
 		emite(EASIG, false_arg, crArgNulo(), (yyval.tdef).exp);
  		
  		
 		(yyval.tdef).tipo = T_LOGICO;
  		
  	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 691 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 695 "asin.y"
    {
  		TIPO_ARG exp1_arg = (yyvsp[(1) - (3)].tdef).exp;
  		TIPO_ARG exp2_arg = (yyvsp[(3) - (3)].tdef).exp;
  		
  		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());
  	
  		switch((yyvsp[(2) - (3)].operador)){
  			case MAS:
  				emite(ESUM, exp1_arg, exp2_arg, (yyval.tdef).exp);
  				break;
  			case MENOS:
  				emite(EDIF, exp1_arg, exp2_arg, (yyval.tdef).exp);
  				break;
  			default:
  				yyerror("Operador aditivo desconocido");
  		}
  		
  		
  		(yyval.tdef).tipo = (yyvsp[(1) - (3)].tdef).tipo;
  	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 717 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 721 "asin.y"
    {
  		TIPO_ARG exp1_arg = (yyvsp[(1) - (3)].tdef).exp;
  		TIPO_ARG exp2_arg = (yyvsp[(3) - (3)].tdef).exp;
  		
  		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());
  	
  		switch((yyvsp[(2) - (3)].operador)){
  			case POR:
  				emite(EMULT, exp1_arg, exp2_arg, (yyval.tdef).exp);
  				break;
  			case DIV:
  				emite(EDIVI, exp1_arg, exp2_arg, (yyval.tdef).exp);
  				break;
  			default:
  				yyerror("Operador multiplicativo desconocido");
  		}
  		
  		(yyval.tdef).tipo = (yyvsp[(1) - (3)].tdef).tipo;
  	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 742 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(1) - (1)].tdef);
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 746 "asin.y"
    {
  		TIPO_ARG exp_arg = (yyvsp[(2) - (2)].tdef).exp;
  		
  		if((yyvsp[(1) - (2)].operador) == MENOS){
	  		
	  		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());
	  		emite(EDIF, crArgEntero(0), exp_arg, (yyval.tdef).exp);
  		} else {
	  		//printf("\nemite expresionUnaria (+)");
	  		//emite(EASIG, exp_arg, crArgNulo(), $$);
	  		(yyval.tdef) = (yyvsp[(2) - (2)].tdef);
  		}
  	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 760 "asin.y"
    {
  		 		
  		SIMB sim; 
  		TIPO_ARG res;
  		  		
		sim = obtenerSimbolo((yyvsp[(2) - (2)].ident));
		/* comprobaciones semanticas */
		res = crArgPosicion(sim.nivel, sim.desp);
		(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());		
		(yyval.tdef).tipo = T_ENTERO;
		/************************************** INCREMENTA o DECREMENTA 1 */
		
		int operador;
		if((yyvsp[(1) - (2)].operador)==MASMAS){
			operador = ESUM;
		}else{
			operador = EDIF;
		}
		
		
		emite(operador, res, crArgEntero(1), res);
		/***************************************************** Asignacion */
		
		emite(EASIG, res, crArgNulo(), (yyval.tdef).exp);
		
		
  		(yyval.tdef).tipo = sim.tipo;
  	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 790 "asin.y"
    {
		SIMB id;
		
		id = obtenerSimbolo((yyvsp[(1) - (4)].ident));
		if(id.categoria==NULO){
			yyerror("variable array no declarada");	
			(yyval.tdef).tipo = T_ERROR;
		} else {
			TIPO_ARG indice = (yyvsp[(3) - (4)].tdef).exp;
			(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());
			emite(EAV, crArgPosicion(id.nivel, id.desp), indice, (yyval.tdef).exp);
		}
		
		
  		(yyval.tdef).tipo = id.tipo;
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 807 "asin.y"
    {
		SIMB id;
		REG campo;		
			
		id = obtenerSimbolo((yyvsp[(1) - (3)].ident));
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			(yyval.tdef).tipo = T_ERROR;
		} else {
			campo = obtenerInfoCampo(id.ref, (yyvsp[(3) - (3)].ident));
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				(yyval.tdef).tipo = T_ERROR;
			}else{
				(yyval.tdef).exp = crArgPosicion(id.nivel, id.desp + campo.desp);
				(yyval.tdef).tipo = campo.tipo;
			}
		}
  	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 827 "asin.y"
    {
		(yyval.tdef).tipo = T_ENTERO;
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 831 "asin.y"
    {
		//obtener simbolo de la funcion desde la tabla de simbolos
		SIMB id = obtenerSimbolo((yyvsp[(1) - (4)].ident)); 
		
		
		if(id.categoria == NULO){
			yyerror("Funcion no declarada.");
			(yyval.tdef).tipo=T_ERROR;
		} else {
			
			if(comparaDominio(id.ref, (yyvsp[(3) - (4)].tdef).ref)==1){
				INF info = obtenerInfoFuncion(id.ref);
		  		
  				//emitir call
				(yyval.tdef).exp = crArgPosicion(nivel, creaVarTemp());
				(yyval.tdef).tipo = info.tipo;
				emite(CALL, crArgNulo(), crArgNulo(), crArgEtiqueta(id.desp));
				emite(DECTOP, crArgNulo(), crArgNulo(), crArgEntero(info.tparam));
				emite(EPOP, crArgNulo(), crArgNulo(), (yyval.tdef).exp);
			}
			else
			{
				yyerror("Parametros incorrectos");
				(yyval.tdef).tipo=T_ERROR;
			}
		}
		
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 860 "asin.y"
    {
		(yyval.tdef) = (yyvsp[(2) - (3)].tdef);
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 863 "asin.y"
    {
  			SIMB id = obtenerSimbolo((yyvsp[(1) - (1)].ident));
  			
	  		if(id.categoria==NULO){ 
	  			yyerror("\n variable NO declarada todavia, primer uso");
	  			(yyval.tdef).tipo = T_ERROR;
	  		} else {
	  			(yyval.tdef).exp = crArgPosicion(id.nivel, id.desp);
	  			(yyval.tdef).tipo = id.tipo; 
	  		}
	  		
	  		
  		;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 877 "asin.y"
    {
  		(yyval.tdef).exp = crArgEntero((yyvsp[(1) - (1)].cent));
  		(yyval.tdef).tipo = T_ENTERO;
  	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 883 "asin.y"
    {
		(yyval.tdef).ref = insertaInfoDominio(-1,T_VACIO);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 887 "asin.y"
    {
		if((yyvsp[(1) - (1)].tdef).tipo != T_ERROR){
			(yyval.tdef).ref = (yyvsp[(1) - (1)].tdef).ref;
		}  
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 894 "asin.y"
    {
		
		(yyval.tdef).ref = insertaInfoDominio(-1, (yyvsp[(1) - (1)].tdef).tipo);
		emite(EPUSH, crArgNulo(), crArgNulo(), (yyvsp[(1) - (1)].tdef).exp);
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 900 "asin.y"
    {
		(yyval.tdef).ref = insertaInfoDominio((yyvsp[(3) - (3)].tdef).ref, (yyvsp[(1) - (3)].tdef).tipo);
		emite(EPUSH, crArgNulo(), crArgNulo(), (yyvsp[(1) - (3)].tdef).exp);
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 906 "asin.y"
    {
		(yyval.operador) = ASIG;
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 910 "asin.y"
    {
		(yyval.operador) = MASASIG;
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 914 "asin.y"
    {
		(yyval.operador) = MENOSASIG;
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 919 "asin.y"
    {
		(yyval.operador) = IGUAL;
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 923 "asin.y"
    {
		(yyval.operador) = DISTINTO;
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 928 "asin.y"
    {
		(yyval.operador) = MAYOR;
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 932 "asin.y"
    {
		(yyval.operador) = MAYORIG;
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 936 "asin.y"
    {
		(yyval.operador) = MENOR;
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 940 "asin.y"
    {
		(yyval.operador) = MENORIG;
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 945 "asin.y"
    {
		(yyval.operador) = MAS;
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 949 "asin.y"
    {
		(yyval.operador) = MENOS;
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 954 "asin.y"
    {
		(yyval.operador) = POR;
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 958 "asin.y"
    {
		(yyval.operador) = DIV;
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 963 "asin.y"
    {
		(yyval.operador) = MASMAS;
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 967 "asin.y"
    {
		(yyval.operador) = MENOSMENOS;
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 972 "asin.y"
    {
		(yyval.operador) = MAS;
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 976 "asin.y"
    {
		(yyval.operador) = MENOS;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2796 "asin.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 980 "asin.y"



/* Llamada por yyparse ante un error */
yyerror (char *s)
{
printf ("\nERROR ->Linea %d: %s", yylineno, s);
}



/**************** Funciones de utilidad **********************/
int tallaTipo(int tipo){
	if(tipo == T_ENTERO){
		return TALLA_ENTERO;
	} 
	return 0;
}



