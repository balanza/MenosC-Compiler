
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
#line 107 "asin.c"

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
#line 37 "asin.y"

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
	} tdef;
    TIPO_ARG expdef; 



/* Line 214 of yacc.c  */
#line 196 "asin.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 208 "asin.c"

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
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    20,
      27,    29,    34,    36,    39,    42,    43,    50,    51,    53,
      56,    61,    66,    67,    70,    71,    74,    75,    81,    83,
      85,    87,    89,    91,    93,    96,   102,   108,   116,   126,
     127,   129,   133,   135,   139,   146,   152,   154,   158,   160,
     164,   166,   170,   172,   176,   178,   181,   184,   189,   193,
     196,   201,   205,   207,   209,   210,   212,   214,   218,   220,
     222,   224,   226,   228,   230,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250
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
      -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,    60,
      -1,     3,    -1,    61,     3,    -1,    14,     6,    35,     7,
       3,    -1,    15,     6,    61,     7,     3,    -1,    16,     6,
      61,     7,    53,    17,    53,    -1,    18,     6,    59,     3,
      61,     3,    59,     7,    53,    -1,    -1,    61,    -1,    19,
      61,     3,    -1,    62,    -1,    35,    70,    61,    -1,    35,
      10,    61,    11,    70,    61,    -1,    35,     4,    35,    70,
      61,    -1,    63,    -1,    62,    71,    63,    -1,    64,    -1,
      63,    72,    64,    -1,    65,    -1,    64,    73,    65,    -1,
      66,    -1,    65,    74,    66,    -1,    67,    -1,    76,    66,
      -1,    75,    35,    -1,    35,    10,    61,    11,    -1,    35,
       4,    35,    -1,    35,    75,    -1,    35,     6,    68,     7,
      -1,     6,    61,     7,    -1,    35,    -1,    36,    -1,    -1,
      69,    -1,    61,    -1,    61,     5,    69,    -1,    26,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    20,    -1,    22,    -1,
      21,    -1,    23,    -1,    24,    -1,    25,    -1,    20,    -1,
      22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    86,    98,    99,   104,   116,   127,   135,
     153,   159,   166,   176,   187,   200,   199,   224,   227,   232,
     247,   264,   266,   267,   280,   281,   284,   284,   293,   294,
     295,   296,   297,   299,   300,   302,   303,   305,   307,   310,
     313,   318,   320,   324,   371,   403,   429,   433,   447,   451,
     471,   475,   489,   493,   512,   516,   530,   557,   571,   590,
     596,   601,   605,   617,   622,   623,   625,   626,   628,   632,
     636,   641,   645,   650,   654,   658,   662,   667,   671,   676,
     680,   685,   689,   694,   698
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
  "instruccionEntradaSalida", "instruccionSeleccion",
  "instruccionIteraccion", "expresionOpcional", "instruccionSalto",
  "expresion", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "parametrosActuales", "listaParametrosActuales",
  "operadorAsignacion", "operadorIgualdad", "operadorRelacional",
  "operadorAditivo", "operadorMultiplicativo", "operadorIncremento",
  "operadorUnario", 0
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
      53,    53,    53,    55,    55,    56,    56,    57,    58,    59,
      59,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       1,     4,     1,     2,     2,     0,     6,     0,     1,     2,
       4,     4,     0,     2,     0,     2,     0,     5,     1,     1,
       1,     1,     1,     1,     2,     5,     5,     7,     9,     0,
       1,     3,     1,     3,     6,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     2,     4,     3,     2,
       4,     3,     1,     1,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
       0,     0,     0,    83,    84,    81,    82,    62,    63,    25,
       0,    28,    29,    30,    31,    32,     0,    42,    46,    48,
      50,    52,    54,     0,     0,    19,    16,     9,     0,     0,
       0,     0,    39,     0,     0,    64,     0,    68,    69,    70,
       0,    59,    22,    34,    71,    72,     0,    73,    74,    75,
      76,     0,    77,    78,     0,    79,    80,     0,    56,    62,
      55,     0,    61,     0,     0,     0,     0,    40,    41,    58,
      66,     0,    65,     0,    43,    24,    47,    49,    51,    53,
       0,     0,    20,     0,     0,    26,     0,     0,     0,    60,
      57,    26,    58,     0,    35,    36,     0,     0,    45,    67,
       0,    27,    57,    26,    39,    44,    37,     0,    26,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    18,    19,    10,    11,
      27,    32,    33,    16,    23,    30,    49,    50,    51,    52,
      53,    54,   106,    55,    56,    57,    58,    59,    60,    61,
      62,   111,   112,    80,    86,    91,    94,    97,    63,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
    -111,     7,    40,  -111,  -111,    11,    40,  -111,  -111,   -23,
    -111,    39,    40,  -111,    14,  -111,  -111,  -111,   -19,    37,
    -111,  -111,   -11,    40,     8,  -111,  -111,    40,    58,  -111,
      42,    24,    64,  -111,    73,  -111,    48,  -111,    76,    88,
      90,    91,    48,  -111,  -111,  -111,  -111,     4,  -111,  -111,
      93,  -111,  -111,  -111,  -111,  -111,    95,    45,    55,    43,
      72,  -111,  -111,    67,   140,    94,  -111,  -111,   103,    77,
      48,    48,    48,   104,    78,    48,    48,  -111,  -111,  -111,
      48,  -111,  -111,  -111,  -111,  -111,   140,  -111,  -111,  -111,
    -111,   140,  -111,  -111,   140,  -111,  -111,   140,  -111,    17,
    -111,    40,  -111,   110,   114,   116,   108,  -111,  -111,    53,
     122,   121,  -111,   119,  -111,    40,    55,    43,    72,  -111,
      96,    48,  -111,   129,   130,   123,    48,    48,    48,  -111,
      53,   100,  -111,   133,  -111,  -111,   117,   137,  -111,  -111,
      48,  -111,  -111,   123,    48,  -111,  -111,   142,   123,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   144,   -10,    -1,  -111,  -111,  -111,
    -111,  -111,    50,  -111,    70,    38,  -110,  -111,  -111,  -111,
    -111,  -111,    10,  -111,   -36,  -111,    69,    65,    63,   -60,
    -111,  -111,    33,   -87,  -111,  -111,  -111,  -111,   -44,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,     9,    17,    81,   100,     9,    73,     3,    74,    26,
      75,    20,    14,    29,    76,   136,    24,    20,    22,    12,
      21,   120,   127,    75,    22,    28,    31,   121,    45,    46,
      77,    78,    79,   146,   104,   105,   107,   119,   149,   110,
     113,    45,    46,   140,   114,    35,    25,    15,    36,     4,
       5,    37,     4,     5,    36,    81,    38,    39,    40,    65,
      41,    42,    43,    92,    44,    93,    45,    46,    43,    34,
      44,    66,    45,    46,    84,    85,    67,    47,    48,    77,
      78,    79,    69,    47,    48,   133,    87,    88,    89,    90,
     137,   138,   110,    95,    70,    96,    71,    72,    83,   101,
      31,    82,    98,    35,   145,    29,    36,   108,   107,   141,
     102,   126,   103,   109,    38,    39,    40,   123,    41,    42,
      43,   124,    44,   125,    45,    46,    35,   128,   129,    36,
     130,   132,   134,   135,   143,    47,    48,    38,    39,    40,
     144,    41,    42,    43,   142,    44,    36,    45,    46,   148,
      13,   122,   115,   131,   147,   116,   117,   118,    47,    48,
      43,   139,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    48
};

static const yytype_int16 yycheck[] =
{
      36,     2,    12,    47,    64,     6,    42,     0,     4,    19,
       6,     3,    35,    23,    10,   125,    35,     3,    10,     8,
       6,     4,   109,     6,    10,    36,    27,    10,    24,    25,
      26,    27,    28,   143,    70,    71,    72,    97,   148,    75,
      76,    24,    25,   130,    80,     3,     9,     8,     6,    12,
      13,     9,    12,    13,     6,    99,    14,    15,    16,    35,
      18,    19,    20,    20,    22,    22,    24,    25,    20,    11,
      22,     7,    24,    25,    29,    30,     3,    35,    36,    26,
      27,    28,     6,    35,    36,   121,    31,    32,    33,    34,
     126,   127,   128,    21,     6,    23,     6,     6,     3,     5,
     101,     8,    35,     3,   140,   115,     6,     3,   144,     9,
       7,     3,    35,    35,    14,    15,    16,     7,    18,    19,
      20,     7,    22,     7,    24,    25,     3,     5,     7,     6,
      11,    35,     3,     3,    17,    35,    36,    14,    15,    16,
       3,    18,    19,    20,    11,    22,     6,    24,    25,     7,
       6,   101,    82,   115,   144,    86,    91,    94,    35,    36,
      20,   128,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36
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
      54,    55,    56,    57,    58,    60,    61,    62,    63,    64,
      65,    66,    67,    75,    76,    35,     7,     3,    61,     6,
       6,     6,     6,    61,     4,     6,    10,    26,    27,    28,
      70,    75,     8,     3,    29,    30,    71,    31,    32,    33,
      34,    72,    20,    22,    73,    21,    23,    74,    35,    35,
      66,     5,     7,    35,    61,    61,    59,    61,     3,    35,
      61,    68,    69,    61,    61,    51,    63,    64,    65,    66,
       4,    10,    49,     7,     7,     7,     3,    70,     5,     7,
      11,    52,    35,    61,     3,     3,    53,    61,    61,    69,
      70,     9,    11,    17,     3,    61,    53,    59,     7,    53
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
#line 86 "asin.y"
    {
		nivel = 0;		
		dvar = 0;
		si = 0;
		cargaContexto(nivel);
	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 93 "asin.y"
    {
		descargaContexto(nivel);
		vuelcaCodigo("codigo");
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 100 "asin.y"
    {
		//mostrarTDS(nivel);
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "asin.y"
    {
		printf("\ndeclarando var %s", (yyvsp[(1) - (1)].tdef).id);
		if(!insertaSimbolo((yyvsp[(1) - (1)].tdef).id, VARIABLE, (yyvsp[(1) - (1)].tdef).tipo, dvar, nivel, (yyvsp[(1) - (1)].tdef).ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += (yyvsp[(1) - (1)].tdef).talla; // update shift
		}
		
		mostrarTDS(nivel);
		
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "asin.y"
    {
		printf("\ndeclarando func %s", (yyvsp[(1) - (1)].tdef).id);
		if(!insertaSimbolo((yyvsp[(1) - (1)].tdef).id, FUNCION, (yyvsp[(1) - (1)].tdef).tipo, dvar, nivel, (yyvsp[(1) - (1)].tdef).ref)){
			yyerror("---> funcion repetida");
		} else {
			dvar += (yyvsp[(1) - (1)].tdef).talla; // update shift
		}
		
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 128 "asin.y"
    {
		(yyval.tdef).id = (yyvsp[(2) - (3)].ident);
		(yyval.tdef).tipo = (yyvsp[(1) - (3)].tdef).tipo; 
		(yyval.tdef).talla = (yyvsp[(1) - (3)].tdef).talla;
		(yyval.tdef).ref = (yyvsp[(1) - (3)].tdef).ref;
		printf("\nINFO VAR: tipo: %d, nombre: %s", (yyvsp[(1) - (3)].tdef).tipo, (yyvsp[(2) - (3)].ident));
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 136 "asin.y"
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
#line 154 "asin.y"
    {
		(yyval.tdef).talla = TALLA_ENTERO;
		(yyval.tdef).tipo = T_ENTERO;
		(yyval.tdef).ref = -1;
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 160 "asin.y"
    {
  		(yyval.tdef).talla = (yyvsp[(3) - (4)].tdef).talla;
  		(yyval.tdef).tipo = T_RECORD;
  		(yyval.tdef).ref = (yyvsp[(3) - (4)].tdef).ref;
  	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 167 "asin.y"
    {
		printf("\ndeclarando campo %s", (yyvsp[(1) - (1)].tdef).id);
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
#line 177 "asin.y"
    {
		printf("\ndeclarando campo %s, ref %d", (yyvsp[(2) - (2)].tdef).id, (yyvsp[(1) - (2)].tdef).ref);
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
#line 188 "asin.y"
    {
		descargaContexto(nivel);
		nivel--;
		dvar = old_dvar;
		
		(yyval.tdef).tipo = (yyvsp[(1) - (2)].tdef).tipo;
		(yyval.tdef).ref = (yyvsp[(1) - (2)].tdef).ref;
		(yyval.tdef).id = (yyvsp[(1) - (2)].tdef).id;
		(yyval.tdef).talla = (yyvsp[(1) - (2)].tdef).talla;
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 200 "asin.y"
    {
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
#line 215 "asin.y"
    {
	
		(yyval.tdef).tipo = (yyvsp[(1) - (6)].tdef).tipo;
		(yyval.tdef).ref = (yyvsp[(5) - (6)].tdef).ref;
		(yyval.tdef).id = (yyvsp[(2) - (6)].ident);
		(yyval.tdef).talla = (yyvsp[(1) - (6)].tdef).talla;		
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 224 "asin.y"
    {
		(yyval.tdef).ref = insertaInfoDominio(-1, T_VACIO);
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 228 "asin.y"
    {
  		(yyval.tdef).ref = (yyvsp[(1) - (1)].tdef).ref;
  	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 233 "asin.y"
    {
  		if((yyvsp[(1) - (2)].tdef).tipo!=T_ENTERO){
  			yyerror("los parametro tiene que ser de tipo int");
  		} else {
	  		//RECUERDA: codigo duplicado
	  		printf("\ndeclarando parametro (a) %s", (yyvsp[(2) - (2)].ident));
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
#line 248 "asin.y"
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

  case 22:

/* Line 1455 of yacc.c  */
#line 266 "asin.y"
    {mostrarTDS(nivel);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 268 "asin.y"
    {
		printf("\ndeclarando var %s", (yyvsp[(2) - (2)].tdef).id);
		if(!insertaSimbolo((yyvsp[(2) - (2)].tdef).id, VARIABLE, (yyvsp[(2) - (2)].tdef).tipo, dvar, nivel, (yyvsp[(2) - (2)].tdef).ref)){
			yyerror("---> identificador repetido");
		} else {
			dvar += (yyvsp[(2) - (2)].tdef).talla; // update shift
		}
		
		mostrarTDS(nivel);
		
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 284 "asin.y"
    {
		nivel++;
		cargaContexto(nivel);
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 289 "asin.y"
    {
		nivel--;
		descargaContexto(nivel);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 310 "asin.y"
    {
		(yyval.expdef).val.i = 0;
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 314 "asin.y"
    {
  		(yyval.expdef).val = (yyvsp[(1) - (1)].expdef).val;
  	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 321 "asin.y"
    {
		(yyval.expdef).val = (yyvsp[(1) - (1)].expdef).val;
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 325 "asin.y"
    {
  		(yyval.expdef).val = (yyvsp[(3) - (3)].expdef).val;
  		
  		SIMB id;
		id = obtenerSimbolo((yyvsp[(1) - (3)].ident));
		if (id.categoria == NULO){
			yyerror("Identificador no declarado");
		}
		if ((id.tipo==(yyvsp[(3) - (3)].expdef).tipo)&&(id.tipo==T_ENTERO)){ 
			(yyval.expdef).tipo = T_ENTERO;
		}
		else {
		
			if (((yyvsp[(3) - (3)].expdef).tipo!=T_ERROR)&&(id.tipo!=T_ERROR)){
				yyerror("Error de tipos en la asignacion de la ((expresion))");
			}
			(yyval.expdef).tipo=T_ERROR;
		}
		
		TIPO_ARG id_arg = crArgPosicion(id.nivel, id.desp);
		TIPO_ARG exp_arg = (yyvsp[(3) - (3)].expdef);
		
		
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
		(yyval.expdef) = id_arg;
		
  		
  		
  	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 372 "asin.y"
    {
		SIMB id;
		
		id = obtenerSimbolo((yyvsp[(1) - (6)].ident));
		if(id.categoria==NULO){
			yyerror("variable array no declarada");	
			(yyval.expdef).tipo = T_ERROR;
		} else {
			TIPO_ARG indice = (yyvsp[(3) - (6)].expdef); //indice
			TIPO_ARG valor = (yyvsp[(6) - (6)].expdef); // valor de la expresion para asignar
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
			(yyval.expdef) = elem;
		}
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 404 "asin.y"
    {
		SIMB id;
		REG campo;		
		TIPO_ARG exp_arg = (yyvsp[(5) - (5)].expdef);
			
		id = obtenerSimbolo((yyvsp[(1) - (5)].ident));
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			(yyval.expdef).tipo = T_ERROR;
		} else {
			campo = obtenerInfoCampo(id.ref, (yyvsp[(3) - (5)].ident));
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				(yyval.expdef).tipo = T_ERROR;
			}else if(campo.tipo!=exp_arg.tipo){
				yyerror("se trata de asignar un valor de un tipo incorrecto a un campo");	
				(yyval.expdef).tipo = T_ERROR;			
			}else{
				TIPO_ARG campo_arg = crArgPosicion(id.nivel, id.desp + campo.desp);
				emite(ASIG, exp_arg, crArgNulo(), campo_arg);
				(yyval.expdef) = campo_arg;
			}
		}
  	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 430 "asin.y"
    {
  		(yyval.expdef).val = (yyvsp[(1) - (1)].expdef).val;
  	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 434 "asin.y"
    {
   		//TODO: TEST XOR
   		int x = (((yyvsp[(1) - (3)].expdef).val.i == (yyvsp[(3) - (3)].expdef).val.i) ^ (yyvsp[(2) - (3)].operador)==IGUAL); //TODO: COMPROBAR VALORES DE POSICIONES
   		/*
   			x es cierta si:
   				- el operador es de igualdad y los valores son iguales
   				- el operador es de no-igualidad y los valores son distintos
   			sino, x es falso
   		*/
   		printf("\n XOR v1: %d, v2: %d, op: %d, res: %d", (yyvsp[(1) - (3)].expdef).val.i, (yyvsp[(3) - (3)].expdef).val.i, (yyvsp[(2) - (3)].operador), x);
   		(yyval.expdef).val.i = x;  		
  	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 448 "asin.y"
    {
		(yyval.expdef).val = (yyvsp[(1) - (1)].expdef).val;
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 452 "asin.y"
    {
  		switch((yyvsp[(2) - (3)].operador)){
  			case MAYOR:
  				(yyval.expdef).val.i = ((yyvsp[(1) - (3)].expdef).val.i > (yyvsp[(3) - (3)].expdef).val.i);
  				break;
  			case MENOR:
  				(yyval.expdef).val.i = ((yyvsp[(1) - (3)].expdef).val.i < (yyvsp[(3) - (3)].expdef).val.i);
  				break;
  			case MAYORIG:
  				(yyval.expdef).val.i = ((yyvsp[(1) - (3)].expdef).val.i >= (yyvsp[(3) - (3)].expdef).val.i);
  				break;
  			case MENORIG:
  				(yyval.expdef).val.i = ((yyvsp[(1) - (3)].expdef).val.i <= (yyvsp[(3) - (3)].expdef).val.i);
  				break;
  			default:
  				yyerror("Operador relacional desconocido");
  		}
  	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 472 "asin.y"
    {
		(yyval.expdef).val = (yyvsp[(1) - (1)].expdef).val;
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 476 "asin.y"
    {
  		switch((yyvsp[(2) - (3)].operador)){
  			case MAS:
  				(yyval.expdef).val.i = (yyvsp[(1) - (3)].expdef).val.i + (yyvsp[(3) - (3)].expdef).val.i;
  				break;
  			case MENOS:
  				(yyval.expdef).val.i = (yyvsp[(1) - (3)].expdef).val.i - (yyvsp[(3) - (3)].expdef).val.i;
  				break;
  			default:
  				yyerror("Operador aditivo desconocido");
  		}
  	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 490 "asin.y"
    {
		(yyval.expdef) = (yyvsp[(1) - (1)].expdef);
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 494 "asin.y"
    {
  		TIPO_ARG exp1_arg = (yyvsp[(1) - (3)].expdef);
  		TIPO_ARG exp2_arg = (yyvsp[(3) - (3)].expdef);
  		
  		(yyval.expdef) = crArgPosicion(nivel, creaVarTemp());
  	
  		switch((yyvsp[(2) - (3)].operador)){
  			case POR:
  				emite(EMULT, exp1_arg, exp2_arg, (yyval.expdef));
  				break;
  			case DIV:
  				emite(EDIVI, exp1_arg, exp2_arg, (yyval.expdef));
  				break;
  			default:
  				yyerror("Operador multiplicativo desconocido");
  		}
  	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 513 "asin.y"
    {
		(yyval.expdef) = (yyvsp[(1) - (1)].expdef);
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 517 "asin.y"
    {
  		TIPO_ARG exp_arg = (yyvsp[(2) - (2)].expdef);
  		
  		if((yyvsp[(1) - (2)].operador) == MENOS){
	  		printf("\nemite expresionUnaria (-)");
	  		(yyval.expdef) = crArgPosicion(nivel, creaVarTemp());
	  		emite(EDIF, crArgEntero(0), exp_arg, (yyval.expdef));
  		} else {
	  		//printf("\nemite expresionUnaria (+)");
	  		//emite(EASIG, exp_arg, crArgNulo(), $$);
	  		(yyval.expdef) = (yyvsp[(2) - (2)].expdef);
  		}
  	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 531 "asin.y"
    {
  		 		
  		SIMB sim; 
  		TIPO_ARG res;
  		  		
		sim = obtenerSimbolo((yyvsp[(2) - (2)].ident));
		/* comprobaciones semanticas */
		res = crArgPosicion(sim.nivel, sim.desp);
		(yyval.expdef) = crArgPosicion(nivel, creaVarTemp());		
		(yyval.expdef).tipo = T_ENTERO;
		/************************************** INCREMENTA o DECREMENTA 1 */
		
		int operador;
		if((yyvsp[(1) - (2)].operador)==MASMAS){
			operador = ESUM;
		}else{
			operador = EDIF;
		}
		
		printf("\nemite incremento de variable %s", (yyvsp[(2) - (2)].ident));
		emite(operador, res, crArgEntero(1), res);
		/***************************************************** Asignacion */
		printf("\nemite incremento de variable %s (sube valor arriba)", (yyvsp[(2) - (2)].ident));
		emite(EASIG, res, crArgNulo(), (yyval.expdef));
  	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 558 "asin.y"
    {
		SIMB id;
		
		id = obtenerSimbolo((yyvsp[(1) - (4)].ident));
		if(id.categoria==NULO){
			yyerror("variable array no declarada");	
			(yyval.expdef).tipo = T_ERROR;
		} else {
			TIPO_ARG indice = (yyvsp[(3) - (4)].expdef);
			(yyval.expdef) = crArgPosicion(nivel, creaVarTemp());
			emite(EAV, crArgPosicion(id.nivel, id.desp), indice, (yyval.expdef));
		}
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 572 "asin.y"
    {
		SIMB id;
		REG campo;		
			
		id = obtenerSimbolo((yyvsp[(1) - (3)].ident));
		if(id.categoria==NULO){
			yyerror("variable struc no declarada");	
			(yyval.expdef).tipo = T_ERROR;
		} else {
			campo = obtenerInfoCampo(id.ref, (yyvsp[(3) - (3)].ident));
			if(campo.tipo==T_ERROR){
				yyerror("el campo no es parte de la struct");	
				(yyval.expdef).tipo = T_ERROR;
			}else{
				(yyval.expdef) = crArgPosicion(id.nivel, id.desp + campo.desp);
			}
		}
  	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 591 "asin.y"
    {
		(yyval.expdef).val.i = -1; //valor de ID_
					//TODO: ID_ := ID_ + 1
		(yyval.expdef).tipo = T_ENTERO;
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 597 "asin.y"
    {
		(yyval.expdef).val.i = -1; 
		//TODO: $$.tipo = tipo de la funcion
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 602 "asin.y"
    {
		(yyval.expdef) = (yyvsp[(2) - (3)].expdef);
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 605 "asin.y"
    {
  			SIMB id = obtenerSimbolo((yyvsp[(1) - (1)].ident));
  			
	  		if(id.categoria==NULO){ 
	  			yyerror("\n variable NO declarada todavia, primer uso");
	  			(yyval.expdef).tipo = T_ERROR;
	  		} else {
	  			(yyval.expdef) = crArgPosicion(id.nivel, id.desp);
	  		}
	  		
	  		
  		;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 618 "asin.y"
    {
  		(yyval.expdef) = crArgEntero((yyvsp[(1) - (1)].cent));
  	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 629 "asin.y"
    {
		(yyval.operador) = ASIG;
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 633 "asin.y"
    {
		(yyval.operador) = MASASIG;
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 637 "asin.y"
    {
		(yyval.operador) = MENOSASIG;
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 642 "asin.y"
    {
		(yyval.operador) = IGUAL;
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 646 "asin.y"
    {
		(yyval.operador) = DISTINTO;
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 651 "asin.y"
    {
		(yyval.operador) = MAYOR;
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 655 "asin.y"
    {
		(yyval.operador) = MAYORIG;
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 659 "asin.y"
    {
		(yyval.operador) = MENOR;
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 663 "asin.y"
    {
		(yyval.operador) = MENORIG;
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 668 "asin.y"
    {
		(yyval.operador) = MAS;
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 672 "asin.y"
    {
		(yyval.operador) = MENOS;
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 677 "asin.y"
    {
		(yyval.operador) = POR;
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 681 "asin.y"
    {
		(yyval.operador) = DIV;
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 686 "asin.y"
    {
		(yyval.operador) = MASMAS;
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 690 "asin.y"
    {
		(yyval.operador) = MENOSMENOS;
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 695 "asin.y"
    {
		(yyval.operador) = MAS;
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 699 "asin.y"
    {
		(yyval.operador) = MENOS;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2426 "asin.c"
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
#line 703 "asin.y"



/* Llamada por yyparse ante un error */
yyerror (char *s)
{
printf ("Linea %d: %s\n", yylineno, s);
}

