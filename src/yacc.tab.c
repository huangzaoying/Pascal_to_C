
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
#line 1 "yacc.y"

    #include <fstream>
    #include <cstdio>
    #include <vector>
    #include <string> 
    #include <assert.h>
    #include <string.h>

    #include "SymbolTable.h"
    #include "SymbolType.h"
    #include "List.h"
    #include "Error.h"

    extern "C"
    {
        int yyparse(void);
        int yyerror(const char *s);
    };
        
    extern int yylex(void);
    int yyerror(std::string s);

    bool parseError = false;
    const std::string c_equal = "=";
    const std::string c_lmid = "[";
    const std::string c_rmid = "]";
    const std::string c_minus = "-";
    
    int tab_count = 0;

    SymbolTable symbol_table;
    void list_symbol_insert(List *head, TokenNUM* type);
    void make_ref_seq(std::vector<int> &seq, List* head);
    void make_type_seq(std::vector<ValueType> &seq, List* head);
    // void get_ref_seq(std::vector<int> &seq, ExpList* head, text fun);
    void print_tab();



/* Line 189 of yacc.c  */
#line 113 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     ARRAY = 258,
     BEGINNING = 259,
     BOOLEAN = 260,
     CASE = 261,
     CHAR = 262,
     CONST = 263,
     DO = 264,
     DOWNTO = 265,
     ELSE = 266,
     END = 267,
     FOR = 268,
     FUNCTION = 269,
     IF = 270,
     INTEGER = 271,
     NOT = 272,
     OF = 273,
     PROCEDURE = 274,
     PROGRAM = 275,
     REAL = 276,
     RECORD = 277,
     REPEAT = 278,
     THEN = 279,
     TO = 280,
     TYPE = 281,
     UNTIL = 282,
     VAR = 283,
     WHILE = 284,
     READ = 285,
     WRITE = 286,
     WRITELN = 287,
     ASSIGNOP = 288,
     OROP = 289,
     RELOP = 290,
     ADDOP = 291,
     MULOP = 292,
     EQUAL = 293,
     ID = 294,
     CONSTCHAR = 295,
     NUM = 296,
     PERIOD = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 40 "yacc.y"

    std::string* text;
    Period *period;
    Periods *period_list;
    Const* num;
    TokenNUM* token;
    List* list;
    ExpList* explist;



/* Line 214 of yacc.c  */
#line 203 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 215 "yacc.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNRULES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,     2,     2,    47,     2,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    11,    12,    15,    16,    20,
      23,    25,    27,    28,    34,    37,    42,    44,    50,    51,
      58,    59,    60,    61,    68,    70,    74,    78,    79,    82,
      83,    84,    91,    92,    93,   100,   101,   102,   110,   111,
     114,   115,   121,   122,   129,   130,   136,   137,   144,   145,
     151,   152,   158,   159,   164,   165,   172,   173,   179,   180,
     186,   187,   192,   193,   198,   199,   203,   205,   212,   213,
     220,   221,   228,   229,   236,   238,   240,   242,   244,   248,
     250,   251,   255,   259,   260,   261,   267,   268,   269,   270,
     277,   278,   283,   284,   291,   292,   296,   298,   302,   304,
     306,   309,   313,   317,   321,   322,   326,   329,   332,   336,
     338,   341,   345,   347,   349,   350,   353,   354,   355,   356,
     365,   366,   367,   368,   376,   377,   378,   385,   386,   391,
     392,   393,   400,   401,   402,   403,   415,   416,   417,   418,
     429,   430,   431,   432,   443,   448,   449,   454,   459,   464,
     465,   470,   474,   475,   485,   490,   491,   493,   498,   500,
     504,   507,   508,   512,   513,   514,   518,   520,   524,   526,
     530,   534,   535,   537,   540,   544,   548,   550,   554,   556,
     558,   560,   562,   565,   569
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      52,     0,    -1,    -1,    59,    53,    54,    -1,    43,    57,
      -1,    -1,    55,    57,    -1,    -1,     1,    56,    57,    -1,
      61,    58,    -1,    44,    -1,     1,    -1,    -1,    20,    39,
      45,    64,    46,    -1,    20,    39,    -1,    20,    39,    45,
      46,    -1,    20,    -1,    20,    39,    45,    64,     1,    -1,
      -1,    20,    39,     1,    60,    64,    46,    -1,    -1,    -1,
      -1,    65,    72,    62,    92,    63,   108,    -1,    39,    -1,
      64,    47,    39,    -1,    64,    47,     1,    -1,    -1,     8,
      66,    -1,    -1,    -1,    39,    38,   144,    43,    67,    66,
      -1,    -1,    -1,    39,    68,   144,    43,    69,    66,    -1,
      -1,    -1,    39,    33,    70,   144,    43,    71,    66,    -1,
      -1,    28,    73,    -1,    -1,    64,    48,    86,    43,    73,
      -1,    -1,    64,    48,     1,    74,    43,    73,    -1,    -1,
      64,    48,    75,    43,    73,    -1,    -1,    64,    48,    86,
       1,    76,    73,    -1,    -1,    64,    48,    86,    77,    73,
      -1,    -1,    64,    48,     1,    78,    73,    -1,    -1,    64,
      48,    79,    73,    -1,    -1,    64,     1,    80,    86,    43,
      73,    -1,    -1,    64,    81,    86,    43,    73,    -1,    -1,
      64,     1,    82,    43,    73,    -1,    -1,    64,    83,    43,
      73,    -1,    -1,    64,     1,    84,    73,    -1,    -1,    64,
      85,    73,    -1,    90,    -1,     3,    49,    91,    50,    18,
      90,    -1,    -1,     3,    87,    91,    50,    18,    90,    -1,
      -1,     3,    49,    91,    88,    18,    90,    -1,    -1,     3,
      49,    91,    50,    89,    90,    -1,    16,    -1,    21,    -1,
       5,    -1,     7,    -1,    91,    47,    42,    -1,    42,    -1,
      -1,    92,    93,    43,    -1,    92,    93,     1,    -1,    -1,
      -1,    99,    94,    43,    95,   107,    -1,    -1,    -1,    -1,
      99,    96,     1,    97,    98,   107,    -1,    -1,    19,    39,
     100,   102,    -1,    -1,    14,    39,   101,   102,    48,    90,
      -1,    -1,    45,   103,    46,    -1,   104,    -1,   103,    43,
     104,    -1,   105,    -1,   106,    -1,    28,   106,    -1,    64,
      48,    90,    -1,    65,    72,   108,    -1,     4,   110,    12,
      -1,    -1,   109,   110,    12,    -1,     4,   110,    -1,   111,
      43,    -1,   110,   111,    43,    -1,   111,    -1,   110,   111,
      -1,   139,    33,   144,    -1,   136,    -1,   137,    -1,    -1,
     112,   108,    -1,    -1,    -1,    -1,    15,   144,   113,    24,
     114,   111,   115,   141,    -1,    -1,    -1,    -1,    15,   144,
     116,   117,   111,   118,   141,    -1,    -1,    -1,    29,   144,
     119,     9,   120,   111,    -1,    -1,    29,   144,   121,   111,
      -1,    -1,    -1,    23,   122,   110,   123,    27,   144,    -1,
      -1,    -1,    -1,    13,    39,   124,    33,   144,   125,    25,
     144,   126,     9,   111,    -1,    -1,    -1,    -1,    13,    39,
     127,    33,   144,   128,   144,   129,     9,   111,    -1,    -1,
      -1,    -1,    13,    39,   130,    33,   144,   131,    25,   144,
     132,   111,    -1,    30,    45,   138,    46,    -1,    -1,    30,
     133,   138,    46,    -1,    30,    45,   138,     1,    -1,    31,
      45,   143,    46,    -1,    -1,    31,   134,   143,    46,    -1,
      31,    45,   143,    -1,    -1,    13,     1,   135,    33,   144,
      25,   144,     9,   111,    -1,    32,    45,   143,    46,    -1,
      -1,    39,    -1,    39,    45,   143,    46,    -1,   139,    -1,
     138,    47,   139,    -1,    39,   140,    -1,    -1,    49,   143,
      50,    -1,    -1,    -1,    11,   142,   111,    -1,   144,    -1,
     143,    47,   144,    -1,   145,    -1,   145,    35,   145,    -1,
     145,    38,   145,    -1,    -1,   146,    -1,    36,   146,    -1,
     145,    36,   146,    -1,   145,    34,   146,    -1,   147,    -1,
     146,    37,   147,    -1,    41,    -1,    40,    -1,   137,    -1,
     139,    -1,    17,   147,    -1,    45,   144,    46,    -1,    45,
     144,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    71,    73,    74,    74,    75,    75,    77,
      79,    80,    81,    84,    85,    86,    87,    89,    90,    90,
      91,   100,   101,    99,   104,   112,   121,   124,   125,   127,
     128,   128,   149,   149,   149,   158,   158,   158,   210,   211,
     213,   214,   224,   224,   225,   225,   226,   226,   236,   236,
     246,   246,   247,   247,   248,   248,   249,   249,   250,   250,
     251,   251,   252,   252,   253,   253,   255,   256,   280,   280,
     284,   284,   288,   288,   292,   293,   294,   295,   297,   304,
     313,   314,   315,   317,   317,   317,   338,   338,   338,   338,
     360,   360,   401,   400,   502,   503,   509,   510,   519,   520,
     522,   530,   540,   542,   543,   543,   550,   557,   559,   560,
     562,   564,   586,   587,   588,   588,   589,   594,   594,   589,
     597,   602,   602,   597,   605,   610,   605,   614,   614,   623,
     629,   623,   636,   650,   653,   636,   663,   677,   683,   663,
     693,   707,   710,   693,   722,   750,   750,   775,   801,   830,
     830,   857,   885,   885,   886,   915,   917,   928,  1030,  1033,
    1038,  1075,  1076,  1095,  1096,  1096,  1098,  1104,  1113,  1126,
    1149,  1172,  1174,  1188,  1200,  1221,  1235,  1249,  1294,  1299,
    1304,  1308,  1314,  1322,  1326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "BEGINNING", "BOOLEAN", "CASE",
  "CHAR", "CONST", "DO", "DOWNTO", "ELSE", "END", "FOR", "FUNCTION", "IF",
  "INTEGER", "NOT", "OF", "PROCEDURE", "PROGRAM", "REAL", "RECORD",
  "REPEAT", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE", "READ", "WRITE",
  "WRITELN", "ASSIGNOP", "OROP", "RELOP", "ADDOP", "MULOP", "EQUAL", "ID",
  "CONSTCHAR", "NUM", "PERIOD", "';'", "'.'", "'('", "')'", "','", "':'",
  "'['", "']'", "$accept", "programstruct", "$@1", "program_body1", "$@2",
  "$@3", "program_body2", "program_body3", "program_head", "$@4",
  "program_body", "$@5", "$@6", "idlist", "const_declarations",
  "const_declaration", "$@7", "$@8", "$@9", "$@10", "$@11",
  "var_declarations", "var_declaration", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "type",
  "$@24", "$@25", "$@26", "basic_type", "periods",
  "subprogram_declarations", "subprogram", "$@27", "$@28", "$@29", "$@30",
  "$@31", "subprogram_head", "$@32", "$@33", "formal_parameter",
  "parameter_list", "parameter", "var_parameter", "value_parameter",
  "subprogram_body", "compound_statement", "$@34", "statement_list",
  "statement", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41",
  "$@42", "$@43", "$@44", "$@45", "$@46", "$@47", "$@48", "$@49", "$@50",
  "$@51", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58",
  "procedure_call", "function_call", "variable_list", "variable",
  "id_varpart", "else_part", "$@59", "expression_list", "expression",
  "simple_expression", "term", "factor", 0
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
     295,   296,   297,    59,    46,    40,    41,    44,    58,    91,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    55,    54,    56,    54,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    59,
      59,    62,    63,    61,    64,    64,    64,    65,    65,    66,
      67,    66,    68,    69,    66,    70,    71,    66,    72,    72,
      73,    73,    74,    73,    75,    73,    76,    73,    77,    73,
      78,    73,    79,    73,    80,    73,    81,    73,    82,    73,
      83,    73,    84,    73,    85,    73,    86,    86,    87,    86,
      88,    86,    89,    86,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    94,    95,    93,    96,    97,    98,    93,
     100,    99,   101,    99,   102,   102,   103,   103,   104,   104,
     105,   106,   107,   108,   109,   108,   108,   110,   110,   110,
     110,   111,   111,   111,   112,   111,   113,   114,   115,   111,
     116,   117,   118,   111,   119,   120,   111,   121,   111,   122,
     123,   111,   124,   125,   126,   111,   127,   128,   129,   111,
     130,   131,   132,   111,   111,   133,   111,   111,   111,   134,
     111,   111,   135,   111,   111,   111,   136,   137,   138,   138,
     139,   140,   140,   141,   142,   141,   143,   143,   144,   144,
     144,   144,   145,   145,   145,   145,   146,   146,   147,   147,
     147,   147,   147,   147,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     2,     0,     3,     2,
       1,     1,     0,     5,     2,     4,     1,     5,     0,     6,
       0,     0,     0,     6,     1,     3,     3,     0,     2,     0,
       0,     6,     0,     0,     6,     0,     0,     7,     0,     2,
       0,     5,     0,     6,     0,     5,     0,     6,     0,     5,
       0,     5,     0,     4,     0,     6,     0,     5,     0,     5,
       0,     4,     0,     4,     0,     3,     1,     6,     0,     6,
       0,     6,     0,     6,     1,     1,     1,     1,     3,     1,
       0,     3,     3,     0,     0,     5,     0,     0,     0,     6,
       0,     4,     0,     6,     0,     3,     1,     3,     1,     1,
       2,     3,     3,     3,     0,     3,     2,     2,     3,     1,
       2,     3,     1,     1,     0,     2,     0,     0,     0,     8,
       0,     0,     0,     7,     0,     0,     6,     0,     4,     0,
       0,     6,     0,     0,     0,    11,     0,     0,     0,    10,
       0,     0,     0,    10,     4,     0,     4,     4,     4,     0,
       4,     3,     0,     9,     4,     0,     1,     4,     1,     3,
       2,     0,     3,     0,     0,     3,     1,     3,     1,     3,
       3,     0,     1,     2,     3,     3,     1,     3,     1,     1,
       1,     1,     2,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,    16,     0,     2,     0,     1,     0,    18,     0,     7,
      27,     3,    27,     0,    24,    15,     0,    27,    29,     4,
       0,    38,     6,     0,    17,    13,     0,     8,    32,    28,
      11,    10,     9,    40,    21,    19,    26,    25,    35,   171,
     171,     0,    39,    80,   171,     0,     0,   161,   179,   178,
     171,   180,   181,     0,   168,   172,   176,     0,    62,     0,
       0,     0,    40,    22,     0,   182,   173,   171,   171,   160,
     184,    30,     0,     0,     0,     0,     0,    33,     0,     0,
      40,    50,    68,    76,    77,    74,    75,     0,    40,     0,
      66,     0,    40,    65,     0,     0,   104,     0,    83,    36,
       0,   166,     0,   183,    29,   175,   169,   174,   170,   177,
      29,     0,    40,    63,     0,    40,     0,     0,    40,    53,
      46,    40,    40,    40,    61,    92,    90,   155,    23,   114,
      82,    81,     0,     0,    29,   157,   171,   162,    31,    34,
      40,    59,    40,    51,    79,    70,     0,    45,    40,    41,
      49,    57,    94,    94,     0,   171,   129,   171,   145,   149,
       0,   156,   106,   109,   104,   112,   113,     0,   114,    84,
      87,    37,   167,    55,    43,     0,    72,     0,     0,    47,
       0,     0,    91,   152,   132,   120,   114,   127,     0,     0,
     171,   171,   171,   103,   110,   107,   115,   171,   105,    27,
      88,    78,     0,     0,     0,     0,     0,     0,     0,    96,
      98,    99,     0,     0,     0,     0,     0,     0,   121,   114,
       0,   155,   161,     0,   158,     0,   151,     0,     0,   108,
     111,    38,    85,    27,    67,    73,    71,    69,   100,     0,
       0,    95,    93,   171,   171,   171,   171,   117,   155,     0,
     125,   128,   147,   144,     0,   146,   148,   150,   154,   104,
      89,   101,    97,     0,   133,   137,   141,   155,   122,   171,
     155,   159,   102,   171,     0,   171,     0,   118,   163,   131,
     126,     0,   171,   138,   171,   163,   164,   123,   155,   134,
       0,   142,   119,   155,   153,     0,   155,   155,   165,   155,
     139,   143,   135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    11,    12,    17,    19,    32,     3,    13,
      20,    43,    96,    41,    21,    29,   104,    40,   110,    44,
     134,    34,    42,   114,    87,   148,   122,   115,    88,    78,
      60,    79,    61,    80,    62,    89,   117,   177,   203,    90,
     145,    63,    97,   132,   199,   133,   200,   233,    98,   153,
     152,   181,   208,   209,   210,   211,   232,   128,   129,   162,
     163,   164,   217,   267,   285,   218,   248,   278,   220,   270,
     221,   186,   249,   214,   274,   295,   215,   275,   290,   216,
     276,   297,   189,   191,   213,   165,    51,   223,    52,    69,
     287,   293,   100,   101,    54,    55,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -180
static const yytype_int16 yypact[] =
{
      15,   -13,    62,  -180,   245,  -180,   314,  -180,     0,  -180,
      47,  -180,    47,    38,  -180,  -180,    12,    47,    60,  -180,
      16,    56,  -180,    45,  -180,  -180,    17,  -180,    55,  -180,
    -180,  -180,  -180,    38,  -180,  -180,  -180,  -180,  -180,   120,
     120,   208,  -180,  -180,   120,   147,   147,    31,  -180,  -180,
     120,  -180,  -180,    70,    96,    85,  -180,   114,    82,   282,
      29,   119,    38,   101,   123,  -180,    85,   120,   120,  -180,
     124,  -180,   147,   120,   147,   120,   147,  -180,    29,   140,
      38,   142,   144,  -180,  -180,  -180,  -180,   155,    38,   335,
    -180,   160,    38,  -180,   152,   169,   210,     6,   224,  -180,
      81,  -180,    89,  -180,    60,    85,    75,    85,    75,  -180,
      60,   185,    38,  -180,   189,    38,   191,   191,    38,  -180,
    -180,    38,    38,    38,  -180,  -180,  -180,   356,  -180,   410,
    -180,  -180,   198,   241,    60,  -180,   120,  -180,  -180,  -180,
      38,  -180,    38,  -180,  -180,    91,   103,  -180,    38,  -180,
    -180,  -180,   199,   199,    18,   120,  -180,   120,   203,   205,
     207,    41,   187,   211,   210,  -180,  -180,   228,   377,  -180,
    -180,  -180,  -180,  -180,  -180,   220,   247,   248,   249,  -180,
       5,   215,  -180,  -180,  -180,   246,   388,   260,   232,   232,
     120,   120,   120,  -180,   229,  -180,  -180,   120,  -180,    47,
    -180,  -180,   105,   105,   105,   105,    38,   129,   108,  -180,
    -180,  -180,   105,   258,   259,   266,   267,   254,  -180,   399,
     270,   356,   231,    23,  -180,   133,   143,   148,   150,  -180,
    -180,    56,  -180,    47,  -180,  -180,  -180,  -180,  -180,   105,
       5,  -180,  -180,   120,   120,   120,   120,  -180,   356,   255,
    -180,  -180,  -180,  -180,   232,  -180,  -180,  -180,  -180,   210,
    -180,  -180,  -180,   256,  -180,  -180,  -180,   356,  -180,   120,
     356,  -180,  -180,   120,   268,   120,   277,  -180,   293,  -180,
    -180,   297,   120,  -180,   120,   293,  -180,  -180,   356,  -180,
     298,  -180,  -180,   356,  -180,   299,   356,   356,  -180,   356,
    -180,  -180,  -180
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,  -180,  -180,  -180,   107,  -180,  -180,  -180,
    -180,  -180,  -180,    -5,  -179,   -83,  -180,  -180,  -180,  -180,
    -180,    78,   -40,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,   -37,  -180,  -180,  -180,  -174,
     193,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,   163,  -180,    77,  -180,   113,    87,  -158,  -180,  -119,
    -153,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -115,   134,  -125,  -180,
      39,  -180,   -43,   -39,    94,    33,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -162
static const yytype_int16 yytable[] =
{
      53,    57,   167,    16,   167,    64,   196,   130,    23,   194,
     168,    70,   166,    24,   166,   194,   -12,    30,    36,   183,
     231,   138,    93,    91,   252,   102,     4,   139,   234,   235,
     236,   237,    82,   206,    83,     1,    84,   167,   242,    14,
     113,   111,    65,   167,    14,    85,    15,   166,   119,   131,
      86,   171,   124,   166,   231,    18,    37,   184,    25,    26,
      31,   167,     5,   224,   224,   261,   194,   219,   251,   253,
     254,   166,   141,   109,  -161,   143,    67,    14,   147,    66,
      68,   149,   150,   151,    33,   -54,    67,   -54,    38,   -54,
      68,    35,    26,    39,   167,   268,   167,   172,   -54,    28,
     173,   272,   174,   -54,   166,   105,   166,   107,   179,    72,
      83,    74,    84,    71,   277,    94,   185,   280,   187,    22,
      95,    85,    76,   167,    27,   -58,    86,   135,   136,   271,
      72,    73,    74,   166,    75,   294,   136,    45,   175,   137,
     298,   176,   167,   300,   301,   167,   302,   226,   227,   228,
     175,   240,   166,   178,   241,   166,    46,    77,   230,    47,
      48,    49,    92,   167,    45,    50,    99,   106,   167,   108,
     103,   167,   167,   166,   167,   207,    26,   239,   166,   255,
     254,   166,   166,   112,   166,   -42,    47,    48,    49,   256,
     136,   125,    50,   116,   257,   136,   258,   136,   118,   193,
     154,   207,   155,   123,   263,   264,   265,   266,   126,    58,
     156,   -56,   -64,   -56,   127,   -56,   157,   158,   159,   160,
     -64,   -64,   -64,   -64,   -56,   -86,   161,   -64,   140,   -56,
     279,   -64,   142,   144,   281,   207,   283,   -64,   -64,   -64,
     -64,   169,   170,   289,   180,   291,     7,   -64,   188,   -14,
     190,   -60,   192,   -14,   195,    26,    59,   -14,   -14,   -14,
     -14,   197,   201,   212,   -14,   202,   204,   205,   -14,  -124,
    -116,   222,   229,   -14,   -14,   -14,   -14,   -14,   247,   250,
      68,   273,   269,    81,   -14,    82,   -52,    83,   -14,    84,
       8,   243,   244,   282,   -52,   -52,   -52,   -52,    85,   245,
     246,   -52,   284,    86,   286,   -52,   288,   296,   299,   259,
     146,   -52,   -52,   -52,   -52,     9,   182,   262,    -5,   238,
     260,   -52,    -5,   225,   292,   -44,    -5,    -5,    -5,    -5,
       0,     0,     0,    -5,     0,     0,   120,    -5,     0,   -48,
       0,     0,    -5,    -5,    -5,    -5,    -5,   -48,   -48,   -48,
     -48,     0,     0,    -5,   -48,     0,     0,    10,   -48,     0,
    -114,     0,     0,     0,   -48,   -48,   -48,   -48,  -114,   154,
       0,   155,     0,     0,   -48,     0,     0,     0,   121,   156,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   198,
     154,     0,   155,     0,     0,   161,     0,     0,     0,  -114,
     156,   154,     0,   155,     0,     0,   157,   158,   159,   160,
       0,   156,   154,     0,   155,  -155,   161,   157,   158,   159,
     160,     0,   156,   154,     0,   155,  -130,   161,   157,   158,
     159,   160,     0,   156,     0,     0,     0,     0,   161,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161
};

static const yytype_int16 yycheck[] =
{
      39,    40,   127,     8,   129,    44,   164,     1,    13,   162,
     129,    50,   127,     1,   129,   168,     0,     1,     1,     1,
     199,   104,    62,    60,     1,    68,    39,   110,   202,   203,
     204,   205,     3,    28,     5,    20,     7,   162,   212,    39,
      80,    78,    45,   168,    39,    16,    46,   162,    88,    43,
      21,   134,    92,   168,   233,     8,    39,    39,    46,    47,
      44,   186,     0,   188,   189,   239,   219,   186,   221,    46,
      47,   186,   112,    76,    33,   115,    45,    39,   118,    46,
      49,   121,   122,   123,    28,     3,    45,     5,    33,     7,
      49,    46,    47,    38,   219,   248,   221,   136,    16,    39,
     140,   259,   142,    21,   219,    72,   221,    74,   148,    34,
       5,    36,     7,    43,   267,    14,   155,   270,   157,    12,
      19,    16,    37,   248,    17,    43,    21,    46,    47,   254,
      34,    35,    36,   248,    38,   288,    47,    17,    47,    50,
     293,    50,   267,   296,   297,   270,   299,   190,   191,   192,
      47,    43,   267,    50,    46,   270,    36,    43,   197,    39,
      40,    41,    43,   288,    17,    45,    43,    73,   293,    75,
      46,   296,   297,   288,   299,   180,    47,    48,   293,    46,
      47,   296,   297,    43,   299,    43,    39,    40,    41,    46,
      47,    39,    45,    49,    46,    47,    46,    47,    43,    12,
      13,   206,    15,    43,   243,   244,   245,   246,    39,     1,
      23,     3,     4,     5,     4,     7,    29,    30,    31,    32,
      12,    13,    14,    15,    16,     1,    39,    19,    43,    21,
     269,    23,    43,    42,   273,   240,   275,    29,    30,    31,
      32,    43,     1,   282,    45,   284,     1,    39,    45,     4,
      45,    43,    45,     8,    43,    47,    48,    12,    13,    14,
      15,    33,    42,    48,    19,    18,    18,    18,    23,     9,
      24,    39,    43,    28,    29,    30,    31,    32,    24,     9,
      49,    25,    27,     1,    39,     3,     4,     5,    43,     7,
      45,    33,    33,    25,    12,    13,    14,    15,    16,    33,
      33,    19,    25,    21,    11,    23,     9,     9,     9,   231,
     117,    29,    30,    31,    32,     1,   153,   240,     4,   206,
     233,    39,     8,   189,   285,    43,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,     1,    23,    -1,     4,
      -1,    -1,    28,    29,    30,    31,    32,    12,    13,    14,
      15,    -1,    -1,    39,    19,    -1,    -1,    43,    23,    -1,
       4,    -1,    -1,    -1,    29,    30,    31,    32,    12,    13,
      -1,    15,    -1,    -1,    39,    -1,    -1,    -1,    43,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    12,
      13,    -1,    15,    -1,    -1,    39,    -1,    -1,    -1,    43,
      23,    13,    -1,    15,    -1,    -1,    29,    30,    31,    32,
      -1,    23,    13,    -1,    15,    27,    39,    29,    30,    31,
      32,    -1,    23,    13,    -1,    15,    27,    39,    29,    30,
      31,    32,    -1,    23,    -1,    -1,    -1,    -1,    39,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    52,    59,    39,     0,    53,     1,    45,     1,
      43,    54,    55,    60,    39,    46,    64,    56,     8,    57,
      61,    65,    57,    64,     1,    46,    47,    57,    39,    66,
       1,    44,    58,    28,    72,    46,     1,    39,    33,    38,
      68,    64,    73,    62,    70,    17,    36,    39,    40,    41,
      45,   137,   139,   144,   145,   146,   147,   144,     1,    48,
      81,    83,    85,    92,   144,   147,   146,    45,    49,   140,
     144,    43,    34,    35,    36,    38,    37,    43,    80,    82,
      84,     1,     3,     5,     7,    16,    21,    75,    79,    86,
      90,    86,    43,    73,    14,    19,    63,    93,    99,    43,
     143,   144,   143,    46,    67,   146,   145,   146,   145,   147,
      69,    86,    43,    73,    74,    78,    49,    87,    43,    73,
       1,    43,    77,    43,    73,    39,    39,     4,   108,   109,
       1,    43,    94,    96,    71,    46,    47,    50,    66,    66,
      43,    73,    43,    73,    42,    91,    91,    73,    76,    73,
      73,    73,   101,   100,    13,    15,    23,    29,    30,    31,
      32,    39,   110,   111,   112,   136,   137,   139,   110,    43,
       1,    66,   144,    73,    73,    47,    50,    88,    50,    73,
      45,   102,   102,     1,    39,   144,   122,   144,    45,   133,
      45,   134,    45,    12,   111,    43,   108,    33,    12,    95,
      97,    42,    18,    89,    18,    18,    28,    64,   103,   104,
     105,   106,    48,   135,   124,   127,   130,   113,   116,   110,
     119,   121,    39,   138,   139,   138,   143,   143,   143,    43,
     144,    65,   107,    98,    90,    90,    90,    90,   106,    48,
      43,    46,    90,    33,    33,    33,    33,    24,   117,   123,
       9,   111,     1,    46,    47,    46,    46,    46,    46,    72,
     107,    90,   104,   144,   144,   144,   144,   114,   111,    27,
     120,   139,   108,    25,   125,   128,   131,   111,   118,   144,
     111,   144,    25,   144,    25,   115,    11,   141,     9,   144,
     129,   144,   141,   142,   111,   126,     9,   132,   111,     9,
     111,   111,   111
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
#line 71 "yacc.y"
    { printf("#include <stdio.h>\n\n"); symbol_table.locate("__global__");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 74 "yacc.y"
    {error_14();;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 75 "yacc.y"
    {error_14(); ;yyclearin; yyerrok;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "yacc.y"
    { error_22();yyclearin;  yyerrok; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "yacc.y"
    { error_22();  yyerrok; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 87 "yacc.y"
    {error_2(); yyerrok;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 89 "yacc.y"
    {error_4(); yyerrok;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 90 "yacc.y"
    {error_9(); yyerrok;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 91 "yacc.y"
    { error_3(); yyerrok;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 100 "yacc.y"
    { printf("\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 101 "yacc.y"
    { printf("int main()\n{\n"); symbol_table.locate("__main__"); tab_count ++;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 102 "yacc.y"
    { print_tab(); tab_count --; printf("return 0;\n}"); symbol_table.relocate(); symbol_table.relocate();;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 104 "yacc.y"
    {
                                        if (symbol_table.get_location() == *(yyvsp[(1) - (1)].text))
                                            (yyval.list) = new List(new TokenID(std::string("_") + *(yyvsp[(1) - (1)].text), _NONE_));
                                        else if (symbol_table.get_reference(*(yyvsp[(1) - (1)].text)))
                                            (yyval.list) = new List(new TokenID(std::string("*") + *(yyvsp[(1) - (1)].text), _NONE_));
                                        else
                                            (yyval.list) = new List(new TokenID(*(yyvsp[(1) - (1)].text), _NONE_));
                                    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 112 "yacc.y"
    {
                                        (yyval.list) = (yyvsp[(1) - (3)].list);
                                        if (symbol_table.get_location() == *(yyvsp[(3) - (3)].text))
                                            list_append((yyval.list), new TokenID(std::string("_") + *(yyvsp[(3) - (3)].text), _NONE_));
                                        else if (symbol_table.get_reference(*(yyvsp[(3) - (3)].text)))
                                            list_append((yyval.list), new TokenID(std::string("*") + *(yyvsp[(3) - (3)].text), _NONE_));
                                        else
                                            list_append((yyval.list), new TokenID(*(yyvsp[(3) - (3)].text), _NONE_));
                                    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 121 "yacc.y"
    {error_37();yyerrok;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 125 "yacc.y"
    { printf("\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 128 "yacc.y"
    {
                                        if ((yyvsp[(3) - (4)].num)==nullptr)
                                            yyerror("ERROR: Illegal expression");
                                        else {
                                            auto type = (yyvsp[(3) - (4)].num)->value_type;
                                            if (type == _INT_)
                                                type = _CONSTINT_;
                                            if (type == _REAL_)
                                                type = _CONSTREAL_;
                                            if (type == _BOOL_)
                                                type = _CONSTBOOL_;
                                            if (type == _CHAR_)
                                                type = _CONSTCHAR_;
                                            if(symbol_table.insert(new TokenNUM(_NUM_, *(yyvsp[(1) - (4)].text), type))==0){
                                                yyerror(std::string() + "ERROR: Duplicate identifier");	
                                            }
                                            print_tab();
                                            printf("const %s %s = %s;\n", codeTypeName[(yyvsp[(3) - (4)].num)->value_type].c_str(),
                                                (yyvsp[(1) - (4)].text) -> c_str(), (yyvsp[(3) - (4)].num) -> value.c_str());
                                        }
                                    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 149 "yacc.y"
    {error_25(); yyerrok;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 149 "yacc.y"
    {
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *(yyvsp[(1) - (4)].text), (yyvsp[(3) - (4)].num)->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[(yyvsp[(3) - (4)].num)->value_type].c_str(),
                                            (yyvsp[(1) - (4)].text) -> c_str(), (yyvsp[(3) - (4)].num) -> value.c_str());
                                        
                                    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 158 "yacc.y"
    {error_25(); yyerrok;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 158 "yacc.y"
    {
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *(yyvsp[(1) - (5)].text), (yyvsp[(4) - (5)].num)->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[(yyvsp[(4) - (5)].num)->value_type].c_str(),
                                            (yyvsp[(1) - (5)].text) -> c_str(), (yyvsp[(4) - (5)].num) -> value.c_str());
                                        
                                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 214 "yacc.y"
    {
                                        list_symbol_insert((yyvsp[(1) - (5)].list), (yyvsp[(3) - (5)].token));
                                        print_tab();
                                        printf("%s ", codeTypeName[(yyvsp[(3) - (5)].token)->get_value_type()].c_str());
                                        if ((yyvsp[(3) - (5)].token)->get_token_type() == _ARRAY_)
                                            list_print((yyvsp[(1) - (5)].list), (TokenARRAY*)(yyvsp[(3) - (5)].token));
                                        else
                                            list_print((yyvsp[(1) - (5)].list));
                                        printf(";\n");
                                    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 224 "yacc.y"
    {error_29(); yyclearin; yyerrok;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 225 "yacc.y"
    {error_29(); yyerrok;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 226 "yacc.y"
    {error_14();yyclearin; yyerrok;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 226 "yacc.y"
    {
                                        list_symbol_insert((yyvsp[(1) - (6)].list), (yyvsp[(3) - (6)].token));
                                        print_tab();
                                        printf("%s ", codeTypeName[(yyvsp[(3) - (6)].token)->get_value_type()].c_str());
                                        if ((yyvsp[(3) - (6)].token)->get_token_type() == _ARRAY_)
                                            list_print((yyvsp[(1) - (6)].list), (TokenARRAY*)(yyvsp[(3) - (6)].token));
                                        else
                                            list_print((yyvsp[(1) - (6)].list));
                                        printf(";\n");
                                    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 236 "yacc.y"
    {error_14(); yyerrok;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 236 "yacc.y"
    {
                                        list_symbol_insert((yyvsp[(1) - (5)].list), (yyvsp[(3) - (5)].token));
                                        print_tab();
                                        printf("%s ", codeTypeName[(yyvsp[(3) - (5)].token)->get_value_type()].c_str());
                                        if ((yyvsp[(3) - (5)].token)->get_token_type() == _ARRAY_)
                                            list_print((yyvsp[(1) - (5)].list), (TokenARRAY*)(yyvsp[(3) - (5)].token));
                                        else
                                            list_print((yyvsp[(1) - (5)].list));
                                        printf(";\n");
                                    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 246 "yacc.y"
    { error_29(); error_14();yyclearin; yyerrok;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 247 "yacc.y"
    { error_29(); error_14(); yyerrok;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 248 "yacc.y"
    {error_5(); yyerrok;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 249 "yacc.y"
    {error_5(); yyerrok;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    {error_5(); error_29();yyclearin; yyerrok;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 251 "yacc.y"
    {error_5(); error_29(); yyerrok;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {error_5(); error_29(); error_14();yyclearin; yyerrok;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    {error_5(); error_29(); error_14(); yyerrok;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 256 "yacc.y"
    {
                                        (yyval.token) = new TokenARRAY("", (yyvsp[(6) - (6)].token)->get_value_type(), (yyvsp[(3) - (6)].period_list)->l_list, (yyvsp[(3) - (6)].period_list)->r_list);
                                    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 280 "yacc.y"
    {error_11();yyerrok;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 280 "yacc.y"
    {
                                        (yyval.token) = new TokenARRAY("", (yyvsp[(6) - (6)].token)->get_value_type(), (yyvsp[(3) - (6)].period_list)->l_list, (yyvsp[(3) - (6)].period_list)->r_list);
                                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 284 "yacc.y"
    {error_12();yyerrok;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 284 "yacc.y"
    {
                                        (yyval.token) = new TokenARRAY("", (yyvsp[(6) - (6)].token)->get_value_type(), (yyvsp[(3) - (6)].period_list)->l_list, (yyvsp[(3) - (6)].period_list)->r_list);
                                    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 288 "yacc.y"
    {error_8();yyerrok;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 288 "yacc.y"
    {
                                        (yyval.token) = new TokenARRAY("", (yyvsp[(6) - (6)].token)->get_value_type(), (yyvsp[(3) - (6)].period_list)->l_list, (yyvsp[(3) - (6)].period_list)->r_list);
                                    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 292 "yacc.y"
    { (yyval.token) = new TokenID("", _INT_); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 293 "yacc.y"
    { (yyval.token) = new TokenID("", _REAL_); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 294 "yacc.y"
    { (yyval.token) = new TokenID("", _BOOL_); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 295 "yacc.y"
    { (yyval.token) = new TokenID("", _CHAR_); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    {
                                        (yyval.period_list) = (yyvsp[(1) - (3)].period_list);
                                        (yyval.period_list)->l_list.push_back((yyvsp[(3) - (3)].period)->lower);
                                        (yyval.period_list)->r_list.push_back((yyvsp[(3) - (3)].period)->upper);
                                    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 304 "yacc.y"
    {
                                        (yyval.period_list) = new Periods();
                                        (yyval.period_list)->l_list.push_back((yyvsp[(1) - (1)].period)->lower);
                                        (yyval.period_list)->r_list.push_back((yyvsp[(1) - (1)].period)->upper);
                                    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 315 "yacc.y"
    {error_14(); yyerrok;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 317 "yacc.y"
    { print_tab(); printf("%s\n{\n", (yyvsp[(1) - (1)].text)->c_str()); tab_count ++; ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 317 "yacc.y"
    {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            auto type = symbol_table.get_type(temp);
                                            if(symbol_table.insert(new TokenID(std::string("_") + temp, type))==0){
                                            	yyerror(std::string() + "ERROR: Duplicate identifier");	
											}
                                            print_tab();
                                            printf("%s _%s;\n", codeTypeName[type].c_str(), temp.c_str());
                                        }
                                    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 327 "yacc.y"
    {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            print_tab();
                                            printf("return _%s;\n", temp.c_str());
                                        }
                                        tab_count --;
                                        print_tab();
                                        printf("}\n\n");
                                        symbol_table.relocate();
                                    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 338 "yacc.y"
    {print_tab(); printf("%s\n{\n", (yyvsp[(1) - (1)].text)->c_str()); tab_count ++; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 338 "yacc.y"
    {error_14(); yyerrok;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 338 "yacc.y"
    {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            auto type = symbol_table.get_type(temp);
                                            if(symbol_table.insert(new TokenID(std::string("_") + temp, type))==0){
                                            	yyerror(std::string() + "ERROR: Duplicate identifier");	
											}
                                            print_tab();
                                            printf("%s _%s;\n", codeTypeName[type].c_str(), temp.c_str());
                                        }
                                    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 348 "yacc.y"
    {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            print_tab();
                                            printf("return _%s;\n", temp.c_str());
                                        }
                                        tab_count --;
                                        print_tab();
                                        printf("}\n\n");
                                        symbol_table.relocate();
                                    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 360 "yacc.y"
    {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*(yyvsp[(2) - (2)].text), _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*(yyvsp[(2) - (2)].text));
                                    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 369 "yacc.y"
    {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        make_ref_seq(v1, (yyvsp[(4) - (4)].list));
                                        make_type_seq(v2, (yyvsp[(4) - (4)].list));
                                        TokenFUNC *t = new TokenFUNC(*(yyvsp[(2) - (4)].text), _VOID_, v1, v2);
                                        symbol_table.reset_token(*(yyvsp[(2) - (4)].text), (TokenNUM*)t);
                                        (yyval.text) = new std::string;
                                        *(yyval.text) = *(yyval.text) + "void " + *(yyvsp[(2) - (4)].text) + "(";
                                        int cnt = 0;
                                        auto i = (yyvsp[(4) - (4)].list);
                                        while (i && i->next) {
                                            *(yyval.text) += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *(yyval.text) += "* ";
                                            else
                                                *(yyval.text) +=  " ";
                                            *(yyval.text) +=  i->x->get_value() + ", ";
                                            i = i->next;
                                            ++cnt;
                                        }
                                        if (i) {
                                            *(yyval.text) += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *(yyval.text) += "* ";
                                            else
                                                *(yyval.text) +=  " ";
                                            *(yyval.text) +=  i->x->get_value();
                                        }
                                        *(yyval.text) +=  ")";
                                    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 401 "yacc.y"
    {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*(yyvsp[(2) - (2)].text), _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*(yyvsp[(2) - (2)].text));
                                    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 410 "yacc.y"
    {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        make_ref_seq(v1, (yyvsp[(4) - (6)].list));
                                        make_type_seq(v2, (yyvsp[(4) - (6)].list));
                                        TokenFUNC *t = new TokenFUNC(*(yyvsp[(2) - (6)].text), (yyvsp[(6) - (6)].token)->get_value_type(), v1, v2);
                                        symbol_table.reset_token(*(yyvsp[(2) - (6)].text), (TokenNUM*)t);
                                        (yyval.text) = new std::string;
                                        *(yyval.text) = codeTypeName[(yyvsp[(6) - (6)].token)->get_value_type()] + " " + *(yyvsp[(2) - (6)].text) + "(";
                                        int cnt = 0;
                                        auto i = (yyvsp[(4) - (6)].list);
                                        while (i && i->next) {
                                            *(yyval.text) += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *(yyval.text) += "* ";
                                            else
                                                *(yyval.text) +=  " ";
                                            *(yyval.text) +=  i->x->get_value() + ", ";
                                            i = i->next;
                                            ++cnt;
                                        }
                                        if (i) {
                                            *(yyval.text) += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *(yyval.text) += "* ";
                                            else
                                                *(yyval.text) +=  " ";
                                            *(yyval.text) +=  i->x->get_value();
                                        }
                                        *(yyval.text) +=  ")";
                                    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 502 "yacc.y"
    { (yyval.list) = nullptr; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 503 "yacc.y"
    { (yyval.list) = (yyvsp[(2) - (3)].list); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 509 "yacc.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 510 "yacc.y"
    {
                                        (yyval.list) = (yyvsp[(1) - (3)].list);
                                        list_add((yyval.list), (yyvsp[(3) - (3)].list));
                                    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 519 "yacc.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 520 "yacc.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 522 "yacc.y"
    {
                                        (yyval.list) = (yyvsp[(2) - (2)].list);
                                        for (auto i = (yyval.list); i; i = i->next) {
                                            symbol_table.set_reference(i->x->get_value());
                                            ((TokenID*)(i->x))->set_reference(1);
                                        }
                                    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 530 "yacc.y"
    {
                                        list_symbol_insert((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].token));
                                        (yyval.list) = (yyvsp[(1) - (3)].list);
                                    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 542 "yacc.y"
    { (yyval.text) = (yyvsp[(2) - (3)].text); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 543 "yacc.y"
    {
                                        error_56();
                                        yyerrok;
                                        truncate();
                                    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 547 "yacc.y"
    { 
                                        (yyval.text) = (yyvsp[(2) - (3)].text); 
                                    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 550 "yacc.y"
    {
                                        error_57();
                                        (yyval.text) = (yyvsp[(2) - (2)].text); 
                                        yyerrok;
                                    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 557 "yacc.y"
    { (yyval.text) = (yyvsp[(1) - (2)].text); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 559 "yacc.y"
    {(yyval.text) = (yyvsp[(1) - (3)].text); *(yyval.text) = *(yyval.text) + "+" + *(yyvsp[(2) - (3)].text); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 560 "yacc.y"
    { error_14(); yyerrok; (yyval.text) = (yyvsp[(1) - (1)].text); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 562 "yacc.y"
    { error_14(); yyerrok; (yyval.text) = (yyvsp[(1) - (2)].text); *(yyval.text) = *(yyval.text) + "+" + *(yyvsp[(2) - (2)].text); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 564 "yacc.y"
    {
										if((yyvsp[(1) - (3)].num)->value_type==_CONSTCHAR_ || (yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_ || (yyvsp[(1) - (3)].num)->value_type==_CONSTINT_ || (yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        else if(((yyvsp[(3) - (3)].num)->value_type==_INT_ || (yyvsp[(3) - (3)].num)->value_type==_CONSTINT_) && (yyvsp[(1) - (3)].num)->value_type!=_INT_ && (yyvsp[(1) - (3)].num)->value_type!=_REAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected "+ valueTypeName[(yyvsp[(1) - (3)].num)->value_type]); 
                                        else if(((yyvsp[(3) - (3)].num)->value_type==_REAL_ || (yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_) && (yyvsp[(1) - (3)].num)->value_type!=_REAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected "+ valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
                                        else if(((yyvsp[(3) - (3)].num)->value_type==_CHAR_ || (yyvsp[(3) - (3)].num)->value_type==_CONSTCHAR_) && (yyvsp[(1) - (3)].num)->value_type!=_CHAR_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected "+ valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
                                        else if(((yyvsp[(3) - (3)].num)->value_type==_BOOL_ || (yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_) && (yyvsp[(1) - (3)].num)->value_type!=_BOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected "+ valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
                                        else if((yyvsp[(1) - (3)].num)->value_type!=_BOOL_ && (yyvsp[(1) - (3)].num)->value_type!=_CHAR_ && (yyvsp[(1) - (3)].num)->value_type!=_REAL_ && (yyvsp[(1) - (3)].num)->value_type!=_INT_&& symbol_table.get_token_type((yyvsp[(1) - (3)].num)->value)!=_FUNC_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected "+ valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
										else if(symbol_table.get_token_type((yyvsp[(1) - (3)].num)->value)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected Array");
                                        else if(symbol_table.get_token_type((yyvsp[(1) - (3)].num)->value)==_FUNC_ && (yyvsp[(1) - (3)].num)->value != symbol_table.get_location())
                                            yyerror(std::string() + "Argument cannot be assigned to");
										(yyval.text) = new std::string;
                                        *(yyval.text) = (yyvsp[(1) - (3)].num)->value + " = " + (yyvsp[(3) - (3)].num)->value;
                                        print_tab();
                                        printf("%s;\n", (yyval.text)->c_str());
                                    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 586 "yacc.y"
    { (yyval.text) = new std::string((yyvsp[(1) - (1)].num)->value); print_tab(); printf("%s;\n", (yyval.text)->c_str()); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 587 "yacc.y"
    { (yyval.text) = new std::string((yyvsp[(1) - (1)].num)->value); print_tab(); printf("%s;\n", (yyval.text)->c_str()); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 588 "yacc.y"
    { tab_count --; print_tab(); printf("{\n"); tab_count ++; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 588 "yacc.y"
    { (yyval.text) = (yyvsp[(2) - (2)].text); tab_count --; print_tab(); printf("}\n"); tab_count ++;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 589 "yacc.y"
    {
                                        if((yyvsp[(2) - (2)].num)->value_type!=_BOOL_&&(yyvsp[(2) - (2)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("if (%s)\n", (yyvsp[(2) - (2)].num)->value.c_str());
                                    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 594 "yacc.y"
    {tab_count ++;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 594 "yacc.y"
    {tab_count --;;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 594 "yacc.y"
    {
                                        (yyval.text) = new std::string((yyvsp[(2) - (8)].num)->value);
                                    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 597 "yacc.y"
    {
                                        if((yyvsp[(2) - (2)].num)->value_type!=_BOOL_&&(yyvsp[(2) - (2)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("if (%s)\n", (yyvsp[(2) - (2)].num)->value.c_str());
                                    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 602 "yacc.y"
    { error_52(); yyerrok; tab_count ++;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 602 "yacc.y"
    {tab_count --;;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 602 "yacc.y"
    {
                                        (yyval.text) = new std::string((yyvsp[(2) - (7)].num)->value);
                                    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 605 "yacc.y"
    {
                                        if((yyvsp[(2) - (2)].num)->value_type!=_BOOL_&&(yyvsp[(2) - (2)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (%s)\n", (yyvsp[(2) - (2)].num)->value.c_str());
                                    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 610 "yacc.y"
    {tab_count ++; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 610 "yacc.y"
    {
                                        tab_count --; 
                                        (yyval.text) = new std::string((yyvsp[(2) - (6)].num)->value);
                                    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 614 "yacc.y"
    {
                                        if((yyvsp[(2) - (2)].num)->value_type!=_BOOL_&&(yyvsp[(2) - (2)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (%s)\n", (yyvsp[(2) - (2)].num)->value.c_str());
                                        error_54(); yyerrok; tab_count ++; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 619 "yacc.y"
    {
                                        tab_count --; 
                                        (yyval.text) = new std::string((yyvsp[(2) - (4)].num)->value);
                                    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 623 "yacc.y"
    {
                                        print_tab();
                                        printf("do\n");
                                        print_tab();
                                        printf("{\n");
                                        tab_count ++;
                                    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 629 "yacc.y"
    { tab_count --; print_tab(); printf("}\n");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 629 "yacc.y"
    {
                                        if ((yyvsp[(6) - (6)].num)->value_type!=_BOOL_&&(yyvsp[(6) - (6)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(6) - (6)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (!(%s));\n", (yyvsp[(6) - (6)].num)->value.c_str());
                                        (yyval.text) = new std::string((yyvsp[(6) - (6)].num)->value);
                                    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 636 "yacc.y"
    {
                                        if (*(yyvsp[(2) - (2)].text) == symbol_table.get_location())
                                            *(yyvsp[(2) - (2)].text) = std::string("_") + *(yyvsp[(2) - (2)].text);
                                        if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *(yyvsp[(2) - (2)].text) + ")");
                                        else if(symbol_table.get_token_type(*(yyvsp[(2) - (2)].text))==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*(yyvsp[(2) - (2)].text))] + " expected INT");
                                        auto type = symbol_table.get_type(*(yyvsp[(2) - (2)].text));
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*(yyvsp[(2) - (2)].text)))
                                            *(yyvsp[(2) - (2)].text) = std::string("*") + *(yyvsp[(2) - (2)].text);
                                    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 650 "yacc.y"
    {
                                        if((yyvsp[(5) - (5)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(5) - (5)].num)->value_type] + " expected INT");
                                    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 653 "yacc.y"
    {
                                        if((yyvsp[(8) - (8)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(8) - (8)].num)->value_type] + " expected INT");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", (yyvsp[(2) - (8)].text)->c_str(), (yyvsp[(5) - (8)].num)->value.c_str(), (yyvsp[(2) - (8)].text)->c_str(), (yyvsp[(8) - (8)].num)->value.c_str(), (yyvsp[(2) - (8)].text)->c_str());
                                        tab_count ++;
                                    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 659 "yacc.y"
    {
                                        (yyval.text) = (yyvsp[(11) - (11)].text);
                                        tab_count --;
                                    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 663 "yacc.y"
    {
                                        if (*(yyvsp[(2) - (2)].text) == symbol_table.get_location())
                                            *(yyvsp[(2) - (2)].text) = std::string("_") + *(yyvsp[(2) - (2)].text);
                                        if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *(yyvsp[(2) - (2)].text) + ")");
                                        else if(symbol_table.get_token_type(*(yyvsp[(2) - (2)].text))==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*(yyvsp[(2) - (2)].text))] + " expected INT");
                                        auto type = symbol_table.get_type(*(yyvsp[(2) - (2)].text));
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*(yyvsp[(2) - (2)].text)))
                                            *(yyvsp[(2) - (2)].text) = std::string("*") + *(yyvsp[(2) - (2)].text);
                                    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 677 "yacc.y"
    {
                                        if((yyvsp[(5) - (5)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(5) - (5)].num)->value_type] + " expected BOOL");
                                        printf("sdadas");
                                        error_55();
                                        yyerrok;
                                    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 683 "yacc.y"
    {
                                        if((yyvsp[(7) - (7)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(7) - (7)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", (yyvsp[(2) - (7)].text)->c_str(), (yyvsp[(5) - (7)].num)->value.c_str(), (yyvsp[(2) - (7)].text)->c_str(), (yyvsp[(7) - (7)].num)->value.c_str(), (yyvsp[(2) - (7)].text)->c_str());
                                        tab_count ++;
                                    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 689 "yacc.y"
    {
                                        (yyval.text) = (yyvsp[(10) - (10)].text);
                                        tab_count --;
                                    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 693 "yacc.y"
    {
                                        if (*(yyvsp[(2) - (2)].text) == symbol_table.get_location())
                                            *(yyvsp[(2) - (2)].text) = std::string("_") + *(yyvsp[(2) - (2)].text);
                                        if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *(yyvsp[(2) - (2)].text) + ")");
                                        else if(symbol_table.get_token_type(*(yyvsp[(2) - (2)].text))==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*(yyvsp[(2) - (2)].text))!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*(yyvsp[(2) - (2)].text))] + " expected INT");
                                        auto type = symbol_table.get_type(*(yyvsp[(2) - (2)].text));
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*(yyvsp[(2) - (2)].text)))
                                            *(yyvsp[(2) - (2)].text) = std::string("*") + *(yyvsp[(2) - (2)].text);
                                    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 707 "yacc.y"
    {
                                        if((yyvsp[(5) - (5)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(5) - (5)].num)->value_type] + " expected BOOL");
                                    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 710 "yacc.y"
    {
                                        if((yyvsp[(8) - (8)].num)->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(8) - (8)].num)->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", (yyvsp[(2) - (8)].text)->c_str(), (yyvsp[(5) - (8)].num)->value.c_str(), (yyvsp[(2) - (8)].text)->c_str(), (yyvsp[(8) - (8)].num)->value.c_str(), (yyvsp[(2) - (8)].text)->c_str());
                                        tab_count ++;
                                        error_54();
                                        yyerrok;
                                    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 718 "yacc.y"
    {
                                        (yyval.text) = (yyvsp[(10) - (10)].text);
                                        tab_count --;
                                    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 722 "yacc.y"
    {
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 = s2 + "&" + i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            (yyval.text) = new std::string("scanf(\"");
                                            *(yyval.text) += s1 + "\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", (yyval.text)->c_str());
                                        }
                                    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 750 "yacc.y"
    {error_9(); yyerrok;;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 750 "yacc.y"
    {
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "E: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 = s2 + "&" + i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        (yyval.text) = new std::string("scanf(\"");
                                        *(yyval.text) += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", (yyval.text)->c_str());
                                    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 775 "yacc.y"
    {
                                        error_4(); yyerrok;
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "E: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 = s2 + "&" + i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        (yyval.text) = new std::string("scanf(\"");
                                        *(yyval.text) += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", (yyval.text)->c_str());
                                    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 801 "yacc.y"
    {
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 += i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            (yyval.text) = new std::string("printf(\"");
                                            *(yyval.text) += s1 + "\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", (yyval.text)->c_str());
                                        }
                                    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 830 "yacc.y"
    {error_9(); yyerrok;;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 830 "yacc.y"
    {
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 += i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        (yyval.text) = new std::string("printf(\"");
                                        *(yyval.text) += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", (yyval.text)->c_str());
                                    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 857 "yacc.y"
    {
                                        error_4(); yyerrok;
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (3)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = (yyvsp[(3) - (3)].explist); i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 += i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        (yyval.text) = new std::string("printf(\"");
                                        *(yyval.text) += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", (yyval.text)->c_str());
                                    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 885 "yacc.y"
    {error_37(); yyerrok;;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 886 "yacc.y"
    {
                                        int flag=0;
                                        for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = (yyvsp[(3) - (4)].explist); i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 += i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            (yyval.text) = new std::string("printf(\"");
                                            *(yyval.text) += s1 + "\\n\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", (yyval.text)->c_str());
                                        }
                                    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 915 "yacc.y"
    {(yyval.text) = new std::string; print_tab(); printf("%s;\n", (yyval.text)->c_str());;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 917 "yacc.y"
    {
                                        if(symbol_table.get_type(*(yyvsp[(1) - (1)].text))==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared "+ *(yyvsp[(1) - (1)].text));
                                        else if(symbol_table.get_func_size(*(yyvsp[(1) - (1)].text))==-1)
                                            yyerror(std::string() + "ERROR: Illegal expression");
                                        else if(symbol_table.get_func_size(*(yyvsp[(1) - (1)].text))!=0)
                                            yyerror(std::string() + "ERROR: Wrong number of parameters specified for call to " + *(yyvsp[(1) - (1)].text));
                                        (yyval.num) = new Const(*(yyvsp[(1) - (1)].text) + "()", _VOID_);
                                    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 928 "yacc.y"
    {
                                        auto id_type = symbol_table.get_type(*(yyvsp[(1) - (4)].text));
                                        if(id_type==_ERROR_)
                                            yyerror(std::string() + "ERROR: Identifier not found "+ *(yyvsp[(1) - (4)].text));
                                        else if(symbol_table.get_func_size(*(yyvsp[(1) - (4)].text))==-1)
                                            yyerror(std::string() + "ERROR: Illegal expression");
                                        else if(((yyvsp[(3) - (4)].explist)==nullptr&&symbol_table.get_func_size(*(yyvsp[(1) - (4)].text))!=0) || ((yyvsp[(3) - (4)].explist)&&symbol_table.get_func_size(*(yyvsp[(1) - (4)].text))!=(yyvsp[(3) - (4)].explist)->size))
                                            yyerror(std::string() + "ERROR: Wrong number of parameters specified for call to " + *(yyvsp[(1) - (4)].text));
                                        else{
                                            int cnt = 0;
                                            for(auto i = (yyvsp[(3) - (4)].explist); i; i = i->next){
                                                auto type1 = i->x->value_type;
                                                auto type2 = symbol_table.get_func_type(*(yyvsp[(1) - (4)].text), cnt);
                                                if(symbol_table.get_func_ref(*(yyvsp[(1) - (4)].text), cnt)==1 && i->x->ref==false)
                                                	yyerror(std::string() + "ERROR: Variable identifier expected");
                                                ++cnt;
                                                if( type1==_INT_&&type2==_INT_ || type1==_CONSTINT_&&type2==_INT_ ||\
                                                    type1==_REAL_&&type2==_REAL_ || type1==_CONSTREAL_&&type2==_REAL_ ||\
                                                    type1==_CHAR_&&type2==_CHAR_ || type1==_CONSTCHAR_&&type2==_CHAR_ ||\
                                                    type1==_BOOL_&&type2==_BOOL_ || type1==_CONSTBOOL_&&type2==_BOOL_ ||\
                                                    type1==_INT_&&type2==_REAL_ && symbol_table.get_func_ref(*(yyvsp[(1) - (4)].text), cnt)==0||\
                                                    type1==_CONSTINT_&&type2==_REAL_ && symbol_table.get_func_ref(*(yyvsp[(1) - (4)].text), cnt)==0)
                                                    continue;
                                                yyerror(std::string() + "ERROR: Incompatible type for arg no. " + std::to_string(cnt) +\
                                                    ": Got " + valueTypeName[type1] + " , expected "+valueTypeName[type2]);
                                            }
                                        }
                                        std::string* temp = new std::string(*(yyvsp[(1) - (4)].text));
                                        *temp = *temp + "(";
                                        auto i = (yyvsp[(3) - (4)].explist);
                                        int cnt = 0;
                                        while (i && i->next) {
                                            // printf("\n----------\n%s %d %d\n----------\n", $1->c_str(), cnt, symbol_table.get_func_ref(*$1, cnt));
                                            if (symbol_table.get_func_ref(*(yyvsp[(1) - (4)].text), cnt))
                                                *temp = *temp + "&" + i->x->value + ", ";
                                            else
                                                *temp = *temp + i->x->value + ", ";
                                            cnt ++;
                                            i = i->next;
                                        }
                                        if (i) {
                                            if (symbol_table.get_func_ref(*(yyvsp[(1) - (4)].text), cnt))
                                                *temp = *temp + "&" + i->x->value + ")";
                                            else
                                                *temp = *temp + i->x->value + ")";
                                        } else {
                                            *temp = *temp + ")";
                                        }
                                        (yyval.num) = new Const(*temp, symbol_table.get_type(*(yyvsp[(1) - (4)].text)));
                                    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1030 "yacc.y"
    {
                                        (yyval.explist) = new ExpList((yyvsp[(1) - (1)].num));
                                    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1033 "yacc.y"
    {
                                        (yyval.explist) = (yyvsp[(1) - (3)].explist);
                                        list_append((yyval.explist), (yyvsp[(3) - (3)].num));
                                    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1038 "yacc.y"
    {
                                        if (*(yyvsp[(1) - (2)].text) == symbol_table.get_location())
                                            *(yyvsp[(1) - (2)].text) = std::string("_") + *(yyvsp[(1) - (2)].text);
                                        if (symbol_table.get_type(*(yyvsp[(1) - (2)].text))==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *(yyvsp[(1) - (2)].text) + ")");
                                        else if(symbol_table.get_token_type(*(yyvsp[(1) - (2)].text))==_FUNC_) // 需要判断是否为函数
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *(yyvsp[(1) - (2)].text) + ")");
                                        if ((yyvsp[(2) - (2)].explist) == nullptr) {
                                            (yyval.num) = new Const(*(yyvsp[(1) - (2)].text), symbol_table.get_type(*(yyvsp[(1) - (2)].text)));
                                            if (symbol_table.get_reference(*(yyvsp[(1) - (2)].text)))
                                                (yyval.num)->value = std::string("*") + *(yyvsp[(1) - (2)].text);
                                        } else {
                                            std::string str = *(yyvsp[(1) - (2)].text);
                                            int len = symbol_table.get_array_size(*(yyvsp[(1) - (2)].text));
                                            if(symbol_table.get_array_size(*(yyvsp[(1) - (2)].text))!=(yyvsp[(2) - (2)].explist)->size)
                                                yyerror(std::string() + "ERROR: Illegal qualifier");
                                            // 类型检查，ID 是不是数组
                                            auto h = (yyvsp[(2) - (2)].explist);
                                            auto j = (yyvsp[(2) - (2)].explist);
                                            for (int i = 0; i < len; i++) { 
                                                if(j->x->value_type!=_INT_)
                                                    yyerror(std::string() + "ERROR: Illegal qualifier");
                                                j=j->next;
                                                std::string l = symbol_table.get_array_l(*(yyvsp[(1) - (2)].text), i);
                                                if (l[0] == '-') {
                                                    l[0] = '+';
                                                    str = str + "[" + h->x->value + l + "]";
                                                } else {
                                                    str = str + "[" + h->x->value + "-" + l + "]";
                                                }
                                                h=h->next;
                                            }
                                            (yyval.num) = new Const(str, symbol_table.get_type(*(yyvsp[(1) - (2)].text)));
                                        }
                                    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1075 "yacc.y"
    { (yyval.explist) = nullptr; ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1076 "yacc.y"
    { (yyval.explist) = (yyvsp[(2) - (3)].explist); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1096 "yacc.y"
    { print_tab(); printf("else\n"); tab_count ++;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1096 "yacc.y"
    {tab_count --;;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1098 "yacc.y"
    {
                                        if((yyvsp[(1) - (1)].num)==nullptr)
                                            (yyval.explist)=nullptr;
                                        else
                                            (yyval.explist) = new ExpList((yyvsp[(1) - (1)].num));
                                    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1104 "yacc.y"
    {
                                        if ((yyvsp[(1) - (3)].explist)==nullptr)
                                            (yyval.explist) = new ExpList((yyvsp[(3) - (3)].num));
                                        else {
                                            (yyval.explist) = (yyvsp[(1) - (3)].explist);
                                            list_append((yyval.explist), (yyvsp[(3) - (3)].num));
                                        }
                                    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1113 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        if((yyvsp[(1) - (1)].num)->value_type==_INT_||(yyvsp[(1) - (1)].num)->value_type==_CONSTINT_)
                                            (yyval.num)->value_type=_INT_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_REAL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTREAL_)
                                            (yyval.num)->value_type=_REAL_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_CHAR_||(yyvsp[(1) - (1)].num)->value_type==_CONSTCHAR_)
                                            (yyval.num)->value_type=_CHAR_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_BOOL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTBOOL_)
                                            (yyval.num)->value_type=_BOOL_;
                                        //else
                                        //    yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
									;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1126 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (3)].num); 
                                        if (((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
                                            (yyval.num)->value_type==_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_CHAR_||(yyvsp[(1) - (3)].num)->value_type==_CONSTCHAR_) && ((yyvsp[(3) - (3)].num)->value_type==_CHAR_||(yyvsp[(3) - (3)].num)->value_type==_CONSTCHAR_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if((yyvsp[(1) - (3)].num)->value_type!=_INT_ && (yyvsp[(1) - (3)].num)->value_type!=_REAL_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTINT_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTREAL_ && (yyvsp[(1) - (3)].num)->value_type!=_CHAR_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTCHAR_) 
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected INT or REAL or CHAR or BOOL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
                                        (yyval.num)->value = (yyval.num)->value + *(yyvsp[(2) - (3)].text) + (yyvsp[(3) - (3)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1149 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (3)].num); 
                                        if (((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
                                            (yyval.num)->value_type==_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_CHAR_||(yyvsp[(1) - (3)].num)->value_type==_CONSTCHAR_) && ((yyvsp[(3) - (3)].num)->value_type==_CHAR_||(yyvsp[(3) - (3)].num)->value_type==_CONSTCHAR_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if(((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if((yyvsp[(1) - (3)].num)->value_type!=_INT_ && (yyvsp[(1) - (3)].num)->value_type!=_REAL_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTINT_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTREAL_ && (yyvsp[(1) - (3)].num)->value_type!=_CHAR_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTCHAR_) 
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected INT or REAL or CHAR or BOOL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type]);
                                        (yyval.num)->value = (yyval.num)->value + "==" + (yyvsp[(3) - (3)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1172 "yacc.y"
    {(yyval.num)=nullptr;;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1174 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        if((yyvsp[(1) - (1)].num)->value_type==_INT_||(yyvsp[(1) - (1)].num)->value_type==_CONSTINT_)
                                            (yyval.num)->value_type=_INT_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_REAL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTREAL_)
                                            (yyval.num)->value_type=_REAL_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_CHAR_||(yyvsp[(1) - (1)].num)->value_type==_CONSTCHAR_)
                                            (yyval.num)->value_type=_CHAR_;
                                        else if((yyvsp[(1) - (1)].num)->value_type==_BOOL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTBOOL_)
                                            (yyval.num)->value_type=_BOOL_;
                                        //else
                                        //    yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                        //        valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1188 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(2) - (2)].num); 
                                        if((yyvsp[(2) - (2)].num)->value_type==_INT_||(yyvsp[(2) - (2)].num)->value_type==_CONSTINT_)
                                            (yyval.num)->value_type=_INT_;
                                        else if((yyvsp[(2) - (2)].num)->value_type==_REAL_||(yyvsp[(2) - (2)].num)->value_type==_CONSTREAL_)
                                            (yyval.num)->value_type=_REAL_;
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected INT or REAL");
                                        (yyval.num)->value = *(yyvsp[(1) - (2)].text) + (yyvsp[(2) - (2)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1200 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (3)].num);
                                        auto typel = (yyvsp[(1) - (3)].num)->value_type;
                                        auto typer = (yyvsp[(3) - (3)].num)->value_type;
                                        if((typel == _INT_ || typel == _CONSTINT_) && (typer == _INT_ || typer == _CONSTINT_))
                                            (yyval.num)->value_type = _INT_;
                                        else if((typel == _REAL_ || typel == _CONSTREAL_) && (typer == _REAL_ || typer == _CONSTREAL_))
                                            (yyval.num)->value_type = _REAL_;
                                        else if((typel == _INT_ || typel == _CONSTINT_) && (typer == _REAL_ || typer == _CONSTREAL_))
                                            (yyval.num)->value_type = _REAL_;
                                        else if((typel == _REAL_ || typel == _CONSTREAL_) && (typer == _INT_ || typer == _CONSTINT_))
                                            (yyval.num)->value_type = _REAL_;
                                        else if(typel != _REAL_ && typel != _INT_ && typel != _CONSTINT_ && typel != _CONSTREAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[typel] + " expected _INT_ or REAL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[typer] + " expected _INT_ or REAL");
                                        (yyval.num)->value = (yyval.num)->value + *(yyvsp[(2) - (3)].text) + (yyvsp[(3) - (3)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1221 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (3)].num);
                                        if(((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
                                            (yyval.num)->value_type=_BOOL_;
                                        else if((yyvsp[(1) - (3)].num)->value_type!=_BOOL_&&(yyvsp[(1) - (3)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected BOOLEAN");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected BOOLEAN");
                                        (yyval.num)->value = (yyval.num)->value + "|" + (yyvsp[(3) - (3)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1235 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        if((yyvsp[(1) - (1)].num)->value_type==_INT_||(yyvsp[(1) - (1)].num)->value_type==_CONSTINT_)
											(yyval.num)->value_type=_INT_;
										else if((yyvsp[(1) - (1)].num)->value_type==_REAL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTREAL_)
											(yyval.num)->value_type=_REAL_;
										else if((yyvsp[(1) - (1)].num)->value_type==_CHAR_||(yyvsp[(1) - (1)].num)->value_type==_CONSTCHAR_)
											(yyval.num)->value_type=_CHAR_;
										else if((yyvsp[(1) - (1)].num)->value_type==_BOOL_||(yyvsp[(1) - (1)].num)->value_type==_CONSTBOOL_)
											(yyval.num)->value_type=_BOOL_;
										//else
										//	yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                    	
									;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1249 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (3)].num);
                                        if(*(yyvsp[(2) - (3)].text)=="and"){
											if(((yyvsp[(1) - (3)].num)->value_type==_BOOL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTBOOL_) && ((yyvsp[(3) - (3)].num)->value_type==_BOOL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTBOOL_))
											    (yyval.num)->value_type=_BOOL_;
										    else if((yyvsp[(1) - (3)].num)->value_type!=_BOOL_&&(yyvsp[(1) - (3)].num)->value_type!=_CONSTBOOL_)
											    yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected BOOL");
											else
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected BOOL");
										}
										else if(*(yyvsp[(2) - (3)].text)=="div" || *(yyvsp[(2) - (3)].text)=="mod"){
											if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
												(yyval.num)->value_type=_INT_;
											else if((yyvsp[(1) - (3)].num)->value_type!=_INT_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTINT_)
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected INT");
											else
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected INT");
										}
										else{
                                            if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                                (yyval.num)->value_type=_INT_;
                                            else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_INT_||(yyvsp[(3) - (3)].num)->value_type==_CONSTINT_))
                                                (yyval.num)->value_type=_REAL_;
                                            else if(((yyvsp[(1) - (3)].num)->value_type==_INT_||(yyvsp[(1) - (3)].num)->value_type==_CONSTINT_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                                (yyval.num)->value_type=_REAL_;
                                            else if(((yyvsp[(1) - (3)].num)->value_type==_REAL_||(yyvsp[(1) - (3)].num)->value_type==_CONSTREAL_) && ((yyvsp[(3) - (3)].num)->value_type==_REAL_||(yyvsp[(3) - (3)].num)->value_type==_CONSTREAL_))
                                                (yyval.num)->value_type=_REAL_;
                                            else if((yyvsp[(1) - (3)].num)->value_type!=_INT_ && (yyvsp[(1) - (3)].num)->value_type!=_REAL_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTINT_ && (yyvsp[(1) - (3)].num)->value_type!=_CONSTREAL_) 
                                                yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(1) - (3)].num)->value_type] + " expected INT or REAL");
                                            else
                                                yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[(yyvsp[(3) - (3)].num)->value_type] + " expected INT or REAL");
                                        }
                                        std::string op = "*";
                                        if (*(yyvsp[(2) - (3)].text) == "and")
                                            op = " & ";
                                        else if (*(yyvsp[(2) - (3)].text) == "div")
                                            op = " / ";
                                        else if (*(yyvsp[(2) - (3)].text) == "mod")
                                            op = " % ";
                                        else
                                            op = "*";
                                        (yyval.num)->value = (yyval.num)->value + op + (yyvsp[(3) - (3)].num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1294 "yacc.y"
    {
                                        symbol_table.insert(new TokenNUM(_NUM_, (yyvsp[(1) - (1)].num)->value, (yyvsp[(1) - (1)].num)->value_type));
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1299 "yacc.y"
    {
                                        (yyval.num) = new Const(*(yyvsp[(1) - (1)].text), _CONSTCHAR_);
                                        symbol_table.insert(new TokenNUM(_NUM_, (yyval.num)->value, (yyval.num)->value_type));
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1304 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1308 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(1) - (1)].num);
                                        (yyval.num)->ref=true;
                                        if(symbol_table.get_token_type((yyvsp[(1) - (1)].num)->value)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types(Array)");
                                    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1314 "yacc.y"
    {
                                        if((yyvsp[(2) - (2)].num)->value_type!=_BOOL_ && (yyvsp[(2) - (2)].num)->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got "
                                                + valueTypeName[(yyvsp[(2) - (2)].num)->value_type] + " expected BOOL");
                                        (yyval.num) = (yyvsp[(2) - (2)].num);
                                        (yyval.num)->value = "!" + (yyval.num)->value;
                                        (yyval.num)->ref=false;
                                    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1322 "yacc.y"
    {
                                        (yyval.num) = (yyvsp[(2) - (3)].num);
                                        (yyval.num)->value = "(" + (yyval.num)->value + ")";
                                    ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1326 "yacc.y"
    {
                                        error_4();
                                        yyerrok;
                                        (yyval.num) = (yyvsp[(2) - (2)].num);
                                        (yyval.num)->value = "(" + (yyval.num)->value + ")";
                                    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3667 "yacc.tab.c"
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
#line 1337 "yacc.y"


void make_ref_seq(std::vector<int> &seq, List* head) {
    seq.clear();
    while(head != nullptr)
    {
        assert(head->x->get_token_type() == _IDENTIFIER_);
        TokenID *t = (TokenID*) head->x;
        seq.push_back(t->get_reference());
        head = head->next;
    }
}

void make_type_seq(std::vector<ValueType> &seq, List* head) {
    seq.clear();
    while(head != nullptr)
    {
        seq.push_back(symbol_table.get_type(head->x->get_value()));
        head = head->next;
    }
}

/* void get_ref_seq(std::vector<int> &seq, text func) {
    seq.clear();
    int siz = symbol_table.get_func_size(*func);
    for (int i = 0; i < siz; i ++) {
        seq.push_back(symbol_table.get_func_ref(*func, i));
    }
} */

void list_symbol_insert(List *head, TokenNUM* type) {
    for (auto i = head; i; i = i->next) {
        /* fprintf(stderr,"id:%s\n",i->x->get_value().c_str()); */
        if (type->get_token_type() == _ARRAY_) {
            TokenARRAY* tmp = new TokenARRAY(*(TokenARRAY*)type);
            tmp->set_value(i->x->get_value());
            if(symbol_table.insert(tmp)==0){
                yyerror(std::string() + "ERROR: Duplicate identifier");
			}
        } else
            if(symbol_table.insert(new TokenID(i->x->get_value(), type->get_value_type(), false))==0){
                yyerror(std::string() + "ERROR: Duplicate identifier");
			}
        i->x->set_value_type(type->get_value_type());
        /* fprintf(stderr,"id:%s\n",i->x->get_value().c_str()); */
    }
}

void print_tab() {
    for (int i = 0; i < tab_count; i ++)
        printf("\t");
}

int yyerror(const char *msg) {
    error_0(msg);
    return 0;
}

int yyerror(std::string x) {
    x+='\n';
    return yyerror(x.c_str());
}

int main(int argc, char **argv) {
#ifndef Debug
    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-o")==0)
            freopen(argv[i + 1], "w", stdout);
        else if (strcmp(argv[i], "-f")==0)
            freopen(argv[i + 1], "r", stdin);
        else if (strcmp(argv[i], "-d")==0)
            freopen(argv[i + 1], "w", stderr);
    }
#endif
    yyparse();
    fprintf(stderr, "\nfinished.");
    return 0;
}

