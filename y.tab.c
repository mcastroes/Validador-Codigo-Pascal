/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     BEGIN_KEYWORD = 259,
     END_KEYWORD = 260,
     IF = 261,
     THEN = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     TO = 266,
     DOWNTO = 267,
     VAR = 268,
     CONST = 269,
     WRITELN = 270,
     READLN = 271,
     TRUE = 272,
     FALSE = 273,
     EQUALS = 274,
     SUMA = 275,
     RESTA = 276,
     MULT = 277,
     DIVIS = 278,
     DIV = 279,
     MOD = 280,
     MAYOR = 281,
     MENOR = 282,
     MENOR_O_IGUAL = 283,
     MAYOR_O_IGUAL = 284,
     IGUAL = 285,
     DISTINTO = 286,
     AND = 287,
     OR = 288,
     NOT = 289,
     COMA = 290,
     SEMICOLON = 291,
     PUNTO = 292,
     DOS_PUNTOS = 293,
     A_PARENTESIS = 294,
     C_PARENTESIS = 295,
     INTEGER = 296,
     REAL = 297,
     STRING = 298,
     BOOLEAN = 299,
     CTE_CADENA = 300,
     CTE_CHAR = 301,
     CTE_INT = 302,
     CTE_REAL = 303,
     ID = 304
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define BEGIN_KEYWORD 259
#define END_KEYWORD 260
#define IF 261
#define THEN 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define TO 266
#define DOWNTO 267
#define VAR 268
#define CONST 269
#define WRITELN 270
#define READLN 271
#define TRUE 272
#define FALSE 273
#define EQUALS 274
#define SUMA 275
#define RESTA 276
#define MULT 277
#define DIVIS 278
#define DIV 279
#define MOD 280
#define MAYOR 281
#define MENOR 282
#define MENOR_O_IGUAL 283
#define MAYOR_O_IGUAL 284
#define IGUAL 285
#define DISTINTO 286
#define AND 287
#define OR 288
#define NOT 289
#define COMA 290
#define SEMICOLON 291
#define PUNTO 292
#define DOS_PUNTOS 293
#define A_PARENTESIS 294
#define C_PARENTESIS 295
#define INTEGER 296
#define REAL 297
#define STRING 298
#define BOOLEAN 299
#define CTE_CADENA 300
#define CTE_CHAR 301
#define CTE_INT 302
#define CTE_REAL 303
#define ID 304




/* Copy the first part of user declarations.  */
#line 1 "practicaYACC.y"


#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int conteoLineas;
extern int conteoErrores;

int yyerror(const char* msg) {
    printf("Línea %d, ERROR SINTÁCTICO: %s\n", conteoLineas, msg);
    conteoErrores++;
}

int yylex(void);
FILE *yyin;

struct Symbol {
    char name[50];
    int tipo;
    int cte;
    int inicializado;
};

struct Symbol symbolTable[100];
int symbolCount = 0;

int findSymbol(char name[50]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addSymbol(char name[50], int tipo, int cte) {
    if (findSymbol(name) == -1) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].tipo = tipo;
        symbolTable[symbolCount].cte = cte;
        symbolCount++;
    } else {
        printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' ya declarado.\n", conteoLineas+1, name);
        conteoErrores++;
    }
}

void initializeSymbol(char name[50]){
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].inicializado = 1;
        }
    }
}

int isInitialized(char name[50]){
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if(symbolTable[i].inicializado == 1){
              return 1;
            } else{
              return 0;
            }
        }
    }
}

int isConstant(char name[50]){
   for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if(symbolTable[i].cte == 1){
              return 1;
            } else{
              return 0;
            }
        }
    }
}

int getSymbolType(char name[50]){
   for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].tipo;
        }
    }
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 92 "practicaYACC.y"
{
    char nombre[30];
    int tipo;
}
/* Line 193 of yacc.c.  */
#line 290 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 303 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    14,    17,    18,    21,    23,    28,
      33,    38,    43,    46,    47,    50,    52,    57,    62,    67,
      72,    74,    77,    79,    82,    85,    88,    91,    94,    97,
      98,   102,   106,   111,   116,   125,   138,   146,   158,   170,
     172,   176,   180,   182,   186,   190,   194,   196,   198,   200,
     204,   208,   210,   212,   214,   216,   220,   224,   226,   228,
     231,   235,   239,   243,   247,   251,   255,   259,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    53,    56,    59,    60,    76,    -1,
       3,    49,    36,    -1,    14,    54,    -1,    -1,    54,    55,
      -1,    55,    -1,    49,    30,    45,    36,    -1,    49,    30,
      46,    36,    -1,    49,    30,    47,    36,    -1,    49,    30,
      48,    36,    -1,    13,    57,    -1,    -1,    57,    58,    -1,
      58,    -1,    49,    38,    41,    36,    -1,    49,    38,    42,
      36,    -1,    49,    38,    43,    36,    -1,    49,    38,    44,
      36,    -1,     4,    -1,    60,    61,    -1,    61,    -1,    62,
      36,    -1,    63,    36,    -1,    64,    36,    -1,    65,    36,
      -1,    66,    36,    -1,    67,    36,    -1,    -1,    49,    19,
      68,    -1,    49,    19,    72,    -1,    15,    39,    71,    40,
      -1,    16,    39,    49,    40,    -1,     6,    39,    73,    40,
       7,     4,    60,     5,    -1,     6,    39,    73,    40,     7,
       4,    60,     5,     8,     4,    60,     5,    -1,     9,    39,
      73,    40,     4,    60,     5,    -1,    10,    39,    49,    19,
      47,    11,    47,    40,     4,    60,     5,    -1,    10,    39,
      49,    19,    47,    12,    47,    40,     4,    60,     5,    -1,
      69,    -1,    68,    20,    69,    -1,    68,    21,    69,    -1,
      70,    -1,    69,    22,    70,    -1,    69,    23,    70,    -1,
      69,    25,    70,    -1,    49,    -1,    47,    -1,    48,    -1,
      39,    68,    40,    -1,    72,    35,    68,    -1,    72,    -1,
      68,    -1,    45,    -1,    46,    -1,    73,    32,    74,    -1,
      73,    33,    74,    -1,    74,    -1,    75,    -1,    34,    75,
      -1,    39,    73,    40,    -1,    68,    19,    68,    -1,    68,
      31,    68,    -1,    68,    26,    68,    -1,    68,    27,    68,
      -1,    68,    29,    68,    -1,    68,    28,    68,    -1,    39,
      75,    40,    -1,     5,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   124,   130,   135,   138,   139,   142,   148,
     154,   160,   168,   173,   176,   177,   180,   185,   190,   195,
     202,   208,   209,   212,   216,   220,   224,   228,   232,   236,
     239,   260,   281,   284,   291,   295,   305,   311,   320,   336,
     339,   346,   354,   357,   363,   369,   372,   385,   388,   391,
     394,   395,   396,   399,   402,   407,   408,   409,   412,   413,
     414,   417,   418,   419,   420,   421,   422,   423,   426
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGIN_KEYWORD",
  "END_KEYWORD", "IF", "THEN", "ELSE", "WHILE", "FOR", "TO", "DOWNTO",
  "VAR", "CONST", "WRITELN", "READLN", "TRUE", "FALSE", "EQUALS", "SUMA",
  "RESTA", "MULT", "DIVIS", "DIV", "MOD", "MAYOR", "MENOR",
  "MENOR_O_IGUAL", "MAYOR_O_IGUAL", "IGUAL", "DISTINTO", "AND", "OR",
  "NOT", "COMA", "SEMICOLON", "PUNTO", "DOS_PUNTOS", "A_PARENTESIS",
  "C_PARENTESIS", "INTEGER", "REAL", "STRING", "BOOLEAN", "CTE_CADENA",
  "CTE_CHAR", "CTE_INT", "CTE_REAL", "ID", "$accept", "code",
  "program_definition", "const_section", "const_list", "const_item",
  "var_section", "var_list", "var_item", "begin_section",
  "instruction_section", "instruction", "assignment", "write_instruction",
  "read_instruction", "if_sentence", "while_sentence", "for_sentence",
  "expression", "term", "factor", "writeln_arguments", "text_expression",
  "boolean_expression", "boolean_member", "comparison_expression",
  "end_section", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    72,    72,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     2,     0,     2,     1,     4,     4,
       4,     4,     2,     0,     2,     1,     4,     4,     4,     4,
       1,     2,     1,     2,     2,     2,     2,     2,     2,     0,
       3,     3,     4,     4,     8,    12,     7,    11,    11,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     3,     3,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,     0,    13,     3,     0,
       4,     7,     0,     0,     0,     6,     0,    12,    15,    20,
      29,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     2,    23,    24,
      25,    26,    27,    28,    16,    17,    18,    19,     0,     0,
      47,    48,    46,     0,    39,    42,     0,    57,    58,     0,
       0,     0,    53,    54,    52,     0,    51,     0,    30,    31,
      68,     0,    59,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    33,     0,    49,    60,    67,
      61,    40,    41,    63,    64,    66,    65,    62,    43,    44,
      45,    55,    56,     0,    29,     0,    50,    29,     0,     0,
       0,     0,    36,     0,     0,    34,     0,     0,     0,    29,
      29,    29,     0,     0,     0,    37,    38,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    10,    11,    13,    17,    18,    20,
      33,    34,    35,    36,    37,    38,    39,    40,    73,    74,
      75,    85,    86,    76,    77,    78,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
      -1,   -41,    39,     3,   -10,   -63,    -6,    43,   -63,    32,
      -6,   -63,    25,    62,   104,   -63,    50,    25,   -63,   -63,
      74,    60,    73,    81,    82,   112,   -63,    52,   101,   120,
     125,   126,   147,     4,   -63,   131,   132,   133,   134,   136,
     137,   -63,   -63,   -63,   -63,   138,   139,   140,   141,    77,
      77,   122,    99,   129,    99,   142,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    83,    77,
     -63,   -63,   -63,   108,   135,   -63,    14,   -63,   -63,    67,
     161,    94,   -63,   -63,   -16,   143,   146,   144,   -16,   -63,
     -63,    83,   -63,    66,    70,   145,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    77,    77,   175,
     182,   148,    17,   -63,    94,   -63,   145,   -63,   -63,   -63,
     -16,   135,   135,   -16,   -16,   -16,   -16,   -16,   -63,   -63,
     -63,   -63,   -63,   183,    74,    47,   -16,    74,     6,   149,
     150,    18,   -63,   151,   152,   180,   185,   186,   189,    74,
      74,    74,    26,    55,    63,   -63,   -63,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,   184,   -63,   -63,   181,   -63,
     -36,   -33,   -63,   -63,   -63,   -63,   -63,   -63,   -51,   -21,
      57,   -63,   153,   -25,   -26,   -62,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    84,     1,    88,    97,    98,    92,    95,     4,    55,
      27,   142,    27,    28,    29,    28,    29,     6,    93,    30,
      31,    30,    31,   145,    27,    79,     8,    28,    29,   116,
     112,   155,    27,    30,    31,    28,    29,    97,    98,     5,
      93,    30,    31,     9,    94,   120,   107,   108,   123,   124,
     125,   126,   127,    32,   109,    32,    12,   117,   139,   140,
     156,    27,    14,   136,    28,    29,    19,    32,   157,    27,
      30,    31,    28,    29,    16,    32,   121,   122,    30,    31,
      27,   131,   132,    28,    29,    96,    97,    98,    25,    30,
      31,    49,    99,   100,   101,   102,    41,   103,   138,   107,
     108,   141,   107,   108,    32,    56,   117,   110,    56,    42,
     118,    68,    32,   152,   153,   154,    69,    43,    44,    56,
      56,    56,    91,    32,    70,    71,    72,    96,    97,    98,
      70,    71,    72,    81,    99,   100,   101,   102,    81,   103,
      50,    70,    71,    72,    82,    83,    70,    71,    72,    21,
      22,    23,    24,    45,    46,    47,    48,   104,   105,    51,
     106,   128,   129,   130,    52,    53,    54,    58,    59,    60,
      61,    80,    62,    63,    64,    65,    66,    67,    87,    90,
     111,   114,   133,   113,   115,   119,   134,   137,   148,   149,
     150,   146,   147,   151,    15,   135,   143,   144,    26,     0,
       0,     0,     0,     0,     0,     0,     0,    89
};

static const yytype_int16 yycheck[] =
{
      33,    52,     3,    54,    20,    21,    68,    69,    49,     5,
       6,     5,     6,     9,    10,     9,    10,    14,    69,    15,
      16,    15,    16,     5,     6,    50,    36,     9,    10,    91,
      81,     5,     6,    15,    16,     9,    10,    20,    21,     0,
      91,    15,    16,    49,    69,    96,    32,    33,    99,   100,
     101,   102,   103,    49,    40,    49,    13,    40,    11,    12,
       5,     6,    30,   114,     9,    10,     4,    49,     5,     6,
      15,    16,     9,    10,    49,    49,    97,    98,    15,    16,
       6,   107,   108,     9,    10,    19,    20,    21,    38,    15,
      16,    39,    26,    27,    28,    29,    36,    31,   134,    32,
      33,   137,    32,    33,    49,   138,    40,    40,   141,    36,
      40,    34,    49,   149,   150,   151,    39,    36,    36,   152,
     153,   154,    39,    49,    47,    48,    49,    19,    20,    21,
      47,    48,    49,    39,    26,    27,    28,    29,    39,    31,
      39,    47,    48,    49,    45,    46,    47,    48,    49,    45,
      46,    47,    48,    41,    42,    43,    44,    22,    23,    39,
      25,   104,   105,   106,    39,    39,    19,    36,    36,    36,
      36,    49,    36,    36,    36,    36,    36,    36,    49,    37,
      19,    35,     7,    40,    40,    40,     4,     4,     8,     4,
       4,    40,    40,     4,    10,    47,    47,    47,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    51,    52,    49,     0,    14,    53,    36,    49,
      54,    55,    13,    56,    30,    55,    49,    57,    58,     4,
      59,    45,    46,    47,    48,    38,    58,     6,     9,    10,
      15,    16,    49,    60,    61,    62,    63,    64,    65,    66,
      67,    36,    36,    36,    36,    41,    42,    43,    44,    39,
      39,    39,    39,    39,    19,     5,    61,    76,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    34,    39,
      47,    48,    49,    68,    69,    70,    73,    74,    75,    73,
      49,    39,    45,    46,    68,    71,    72,    49,    68,    72,
      37,    39,    75,    68,    73,    75,    19,    20,    21,    26,
      27,    28,    29,    31,    22,    23,    25,    32,    33,    40,
      40,    19,    68,    40,    35,    40,    75,    40,    40,    40,
      68,    69,    69,    68,    68,    68,    68,    68,    70,    70,
      70,    74,    74,     7,     4,    47,    68,     4,    60,    11,
      12,    60,     5,    47,    47,     5,    40,    40,     8,     4,
       4,     4,    60,    60,    60,     5,     5,     5
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 114 "practicaYACC.y"
    {
        if (conteoErrores == 0){
          printf("La entrada es válida.\n");
        } else {
          printf("El programa contiene errores.\n");
          printf("%d errores generados.\n", conteoErrores);
        }
      }
    break;

  case 3:
#line 125 "practicaYACC.y"
    {
        printf("Apertura de programa definida.\n");
      }
    break;

  case 4:
#line 132 "practicaYACC.y"
    {
        printf("Sección de constantes.\n");
      }
    break;

  case 8:
#line 143 "practicaYACC.y"
    {
        printf("Declaración de CONSTANTE DE CADENA.\n");
        addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 1);
        initializeSymbol((yyvsp[(1) - (4)].nombre));
      }
    break;

  case 9:
#line 149 "practicaYACC.y"
    {
        printf("Declaración de CONSTANTE DE CHAR.\n");
        addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 1);
        initializeSymbol((yyvsp[(1) - (4)].nombre));
      }
    break;

  case 10:
#line 155 "practicaYACC.y"
    {
        printf("Declaración de CONSTANTE ENTERA.\n");
        addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 1);
        initializeSymbol((yyvsp[(1) - (4)].nombre));
      }
    break;

  case 11:
#line 161 "practicaYACC.y"
    {
        printf("Declaración de CONSTANTE REAL.\n");
        addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 1);
        initializeSymbol((yyvsp[(1) - (4)].nombre));
      }
    break;

  case 12:
#line 170 "practicaYACC.y"
    {
        printf("Sección de variables.\n");
      }
    break;

  case 16:
#line 181 "practicaYACC.y"
    {
            printf("Declaración de INTEGER\n");
            addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 0);
      }
    break;

  case 17:
#line 186 "practicaYACC.y"
    {
            printf("Declaración de REAL\n");
            addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 0);
      }
    break;

  case 18:
#line 191 "practicaYACC.y"
    {
            printf("Declaración de STRING\n");
            addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 0);
      }
    break;

  case 19:
#line 196 "practicaYACC.y"
    {
            printf("Declaración de BOOLEAN\n");
            addSymbol((yyvsp[(1) - (4)].nombre), (yyvsp[(3) - (4)].tipo), 0);
      }
    break;

  case 20:
#line 203 "practicaYACC.y"
    {
        printf("Inicio de bloque de código.\n");
      }
    break;

  case 23:
#line 213 "practicaYACC.y"
    {
        printf("Instrucción de asignación.\n");
      }
    break;

  case 24:
#line 217 "practicaYACC.y"
    {
        printf("Instrucción de escritura.\n");
      }
    break;

  case 25:
#line 221 "practicaYACC.y"
    {
        printf("Instrucción de lectura.\n");
      }
    break;

  case 26:
#line 225 "practicaYACC.y"
    {
        printf("Sentencia condicional.\n");
      }
    break;

  case 27:
#line 229 "practicaYACC.y"
    {
        printf("Sentencia bucle WHILE.\n");
      }
    break;

  case 28:
#line 233 "practicaYACC.y"
    {
        printf("Sentencia bucle FOR.\n");
      }
    break;

  case 30:
#line 240 "practicaYACC.y"
    {
        if (findSymbol((yyvsp[(1) - (3)].nombre)) == -1){
            printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, (yyvsp[(1) - (3)].nombre));
            conteoErrores++;
        } else {
          if (getSymbolType((yyvsp[(1) - (3)].nombre)) != (yyvsp[(3) - (3)].tipo)){
             printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la asignación de '%s'.\n", conteoLineas+1, (yyvsp[(1) - (3)].nombre));
             conteoErrores++;
          }
        }
        
        
       if (isInitialized((yyvsp[(1) - (3)].nombre)) == 0)
          initializeSymbol((yyvsp[(1) - (3)].nombre));
        
       if (isConstant((yyvsp[(1) - (3)].nombre)) == 1){
          printf("Línea %d, ERROR SEMÁNTICO: Las constantes no se pueden redefinir.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
    break;

  case 31:
#line 260 "practicaYACC.y"
    {
        if (findSymbol((yyvsp[(1) - (3)].nombre)) == -1){
            printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, (yyvsp[(1) - (3)].nombre));
            conteoErrores++;
        } else {
          if (getSymbolType((yyvsp[(1) - (3)].nombre)) != (yyvsp[(3) - (3)].tipo)){
             printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la asignación de '%s'.\n", conteoLineas+1, (yyvsp[(1) - (3)].nombre));
             conteoErrores++;
          }
        }

       if (isInitialized((yyvsp[(1) - (3)].nombre)) == 0)
          initializeSymbol((yyvsp[(1) - (3)].nombre));
        
       if (isConstant((yyvsp[(1) - (3)].nombre)) == 1){
          printf("Línea %d, ERROR SEMÁNTICO: Las constantes no se pueden redefinir.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
    break;

  case 33:
#line 285 "practicaYACC.y"
    {
          if (isInitialized((yyvsp[(3) - (4)].nombre)) == 0)
            initializeSymbol((yyvsp[(3) - (4)].nombre));
        }
    break;

  case 37:
#line 314 "practicaYACC.y"
    {
                if(getSymbolType((yyvsp[(3) - (11)].nombre)) != 1){
                   printf("Línea %d, ERROR SEMÁNTICO: Los identificadores usados en las sentencias FOR deben ser siempre de tipo entero.\n", conteoLineas+1);
                   conteoErrores++;
                }
              }
    break;

  case 38:
#line 323 "practicaYACC.y"
    {
                if(getSymbolType((yyvsp[(3) - (11)].nombre)) != 1){
                  printf("Línea %d, ERROR SEMÁNTICO: Los identificadores usados en las sentencias FOR deben ser siempre de tipo entero.\n", conteoLineas+1);
                  conteoErrores++;
                }

              }
    break;

  case 39:
#line 336 "practicaYACC.y"
    {
        (yyval.tipo) = (yyvsp[(1) - (1)].tipo);
      }
    break;

  case 40:
#line 339 "practicaYACC.y"
    {
        if ((yyvsp[(1) - (3)].tipo) != (yyvsp[(3) - (3)].tipo)) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de suma.\n", conteoLineas+1);
          conteoErrores++;
        }

      }
    break;

  case 41:
#line 346 "practicaYACC.y"
    {
        if ((yyvsp[(1) - (3)].tipo) != (yyvsp[(3) - (3)].tipo)) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de resta.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
    break;

  case 42:
#line 354 "practicaYACC.y"
    {
        (yyval.tipo) = (yyvsp[(1) - (1)].tipo);
      }
    break;

  case 43:
#line 357 "practicaYACC.y"
    {
        if ((yyvsp[(1) - (3)].tipo) != (yyvsp[(3) - (3)].tipo)) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de multiplicación.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
    break;

  case 44:
#line 363 "practicaYACC.y"
    {
        if ((yyvsp[(1) - (3)].tipo) != (yyvsp[(3) - (3)].tipo)) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de división.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
    break;

  case 46:
#line 373 "practicaYACC.y"
    {
        if (findSymbol((yyvsp[(1) - (1)].nombre)) == -1){
          printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, (yyvsp[(1) - (1)].nombre));
          conteoErrores++;
        } else if (isInitialized((yyvsp[(1) - (1)].nombre)) == 0){
          printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no inicializado.\n", conteoLineas+1, (yyvsp[(1) - (1)].nombre));
          conteoErrores++;
        }

        (yyval.tipo) = getSymbolType((yyvsp[(1) - (1)].nombre));

      }
    break;

  case 47:
#line 385 "practicaYACC.y"
    {
        (yyval.tipo) = 1;
      }
    break;

  case 48:
#line 388 "practicaYACC.y"
    {
        (yyval.tipo) = 2;
      }
    break;

  case 53:
#line 399 "practicaYACC.y"
    {
                (yyval.tipo) = 3;
              }
    break;

  case 54:
#line 402 "practicaYACC.y"
    {
                (yyval.tipo) = 3;
              }
    break;

  case 68:
#line 427 "practicaYACC.y"
    {
        printf("Fin del programa.\n");
      }
    break;


/* Line 1267 of yacc.c.  */
#line 1975 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 438 "practicaYACC.y"


int main()
{
    yyin=fopen("./Ficheros/entradaSintactico.pas","r");

    freopen("./Ficheros/salida.txt", "w", stdout);
    yyparse();
    fclose(stdout);

    return 0;
}

