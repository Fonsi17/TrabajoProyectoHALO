/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/symbols.h"
/* El include de ast.h se queda aquí para el .c */
#include "../include/ast.h"

int  yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

ASTNode *ast_root = NULL;

#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_HALO = 3,                       /* HALO  */
  YYSYMBOL_TRANSMITIR = 4,                 /* TRANSMITIR  */
  YYSYMBOL_SI = 5,                         /* SI  */
  YYSYMBOL_SINO = 6,                       /* SINO  */
  YYSYMBOL_MIENTRAS = 7,                   /* MIENTRAS  */
  YYSYMBOL_FUNC_DEF = 8,                   /* FUNC_DEF  */
  YYSYMBOL_FUNC_CALL = 9,                  /* FUNC_CALL  */
  YYSYMBOL_RETORNAR = 10,                  /* RETORNAR  */
  YYSYMBOL_INT_TYPE = 11,                  /* INT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 12,                 /* CHAR_TYPE  */
  YYSYMBOL_DOUBLE_TYPE = 13,               /* DOUBLE_TYPE  */
  YYSYMBOL_BOOL_TYPE = 14,                 /* BOOL_TYPE  */
  YYSYMBOL_STRING_TYPE = 15,               /* STRING_TYPE  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_LPARENT = 18,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 19,                   /* RPARENT  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_SUB = 23,                       /* SUB  */
  YYSYMBOL_MULT = 24,                      /* MULT  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_LEQ = 30,                       /* LEQ  */
  YYSYMBOL_GEQ = 31,                       /* GEQ  */
  YYSYMBOL_AND = 32,                       /* AND  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 36,               /* INT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 37,            /* DOUBLE_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 38,              /* CHAR_LITERAL  */
  YYSYMBOL_BOOL_LITERAL = 39,              /* BOOL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 40,            /* STRING_LITERAL  */
  YYSYMBOL_UMINUS = 41,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_lista_sentencias = 44,          /* lista_sentencias  */
  YYSYMBOL_bloque = 45,                    /* bloque  */
  YYSYMBOL_sentencia = 46,                 /* sentencia  */
  YYSYMBOL_tipo_dato = 47,                 /* tipo_dato  */
  YYSYMBOL_expresion = 48,                 /* expresion  */
  YYSYMBOL_definicion_variable = 49,       /* definicion_variable  */
  YYSYMBOL_asignacion = 50,                /* asignacion  */
  YYSYMBOL_sentencia_transmitir = 51,      /* sentencia_transmitir  */
  YYSYMBOL_sentencia_si = 52,              /* sentencia_si  */
  YYSYMBOL_sentencia_mientras = 53,        /* sentencia_mientras  */
  YYSYMBOL_definicion_funcion = 54,        /* definicion_funcion  */
  YYSYMBOL_llamada_funcion = 55,           /* llamada_funcion  */
  YYSYMBOL_sentencia_retornar = 56         /* sentencia_retornar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    84,    85,    89,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   105,   106,   107,   108,   109,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   137,   144,   151,   155,   156,   160,   164,   171,   178
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "HALO", "TRANSMITIR",
  "SI", "SINO", "MIENTRAS", "FUNC_DEF", "FUNC_CALL", "RETORNAR",
  "INT_TYPE", "CHAR_TYPE", "DOUBLE_TYPE", "BOOL_TYPE", "STRING_TYPE",
  "SEMICOLON", "ASSIGN", "LPARENT", "RPARENT", "LBRACE", "RBRACE", "PLUS",
  "SUB", "MULT", "DIV", "EQ", "NEQ", "LT", "GT", "LEQ", "GEQ", "AND", "OR",
  "NOT", "IDENTIFIER", "INT_LITERAL", "DOUBLE_LITERAL", "CHAR_LITERAL",
  "BOOL_LITERAL", "STRING_LITERAL", "UMINUS", "$accept", "programa",
  "lista_sentencias", "bloque", "sentencia", "tipo_dato", "expresion",
  "definicion_variable", "asignacion", "sentencia_transmitir",
  "sentencia_si", "sentencia_mientras", "definicion_funcion",
  "llamada_funcion", "sentencia_retornar", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,     8,    61,   -29,    27,    49,    -4,    -1,   -17,   -11,
      49,   -29,    19,   -29,   -29,    28,    41,    44,   -29,   -29,
     -29,    45,    57,   -29,   -29,   -29,   -29,   -29,    39,    49,
      49,    49,   -29,   -29,   -29,   -29,   -29,   -29,   117,    49,
      49,    23,   -29,   117,     2,    49,   -29,   -29,   -29,   -29,
     -29,    58,    75,   -29,   140,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    90,   105,   -29,
     -29,   117,    49,   -29,    -9,    -9,   -29,   -29,     3,     3,
     -21,   -21,   -21,   -21,   140,   129,    23,    23,   117,    70,
     -29,    23,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     4,     0,    14,     3,     0,     0,     0,     9,    10,
      11,     0,     0,    15,    17,    16,    19,    18,     0,     0,
       0,     0,    25,    20,    21,    22,    23,    24,    43,     0,
       0,     0,    48,    49,     0,     0,     6,     7,     8,    12,
      13,     0,     0,    30,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       5,    42,     0,    40,    26,    27,    28,    29,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,    41,    44,
      46,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    66,   -28,   -29,   -29,   -10,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    14,    28,    38,    15,    16,    17,
      18,    19,    20,    21,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    55,    56,    57,    58,     4,     5,     6,     3,     7,
       8,     9,    10,    69,    39,    57,    58,    40,    41,    52,
      53,    54,    11,    70,    42,    55,    56,    57,    58,    67,
      68,    61,    62,    63,    64,    71,    45,    12,    23,    24,
      25,    26,    27,    11,    46,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    47,    89,    90,
      48,    49,    88,    92,     4,     5,     6,    29,     7,     8,
       9,    10,    30,    50,    51,    72,    91,    44,     0,     0,
       0,    11,     0,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,    73,     0,    12,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    86,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    87,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64
};

static const yytype_int8 yycheck[] =
{
      10,    22,    23,    24,    25,     3,     4,     5,     0,     7,
       8,     9,    10,    41,    18,    24,    25,    18,    35,    29,
      30,    31,    20,    21,    35,    22,    23,    24,    25,    39,
      40,    28,    29,    30,    31,    45,    17,    35,    11,    12,
      13,    14,    15,    20,    16,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    16,    86,    87,
      16,    16,    72,    91,     3,     4,     5,    18,     7,     8,
       9,    10,    23,    16,    35,    17,     6,    11,    -1,    -1,
      -1,    20,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    19,    -1,    35,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     3,     4,     5,     7,     8,     9,
      10,    20,    35,    45,    46,    49,    50,    51,    52,    53,
      54,    55,    56,    11,    12,    13,    14,    15,    47,    18,
      23,    34,    35,    36,    37,    38,    39,    40,    48,    18,
      18,    35,    35,    48,    44,    17,    16,    16,    16,    16,
      16,    35,    48,    48,    48,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    48,    48,    45,
      21,    48,    17,    19,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    19,    19,    48,    45,
      45,     6,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    51,    52,    52,    53,    54,    55,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     5,     3,     2,     5,     7,     5,     3,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: lista_sentencias  */
#line 80 "parser.y"
                            { ast_root = (yyvsp[0].node); }
#line 1203 "parser.tab.c"
    break;

  case 3: /* lista_sentencias: lista_sentencias sentencia  */
#line 84 "parser.y"
                                { (yyval.node) = ((yyvsp[-1].node) || (yyvsp[0].node)) ? ast_make_seq((yyvsp[-1].node), (yyvsp[0].node)) : NULL; }
#line 1209 "parser.tab.c"
    break;

  case 4: /* lista_sentencias: %empty  */
#line 85 "parser.y"
                                 { (yyval.node) = NULL; }
#line 1215 "parser.tab.c"
    break;

  case 5: /* bloque: LBRACE lista_sentencias RBRACE  */
#line 89 "parser.y"
                                    { (yyval.node) = ast_make_block((yyvsp[-1].node)); }
#line 1221 "parser.tab.c"
    break;

  case 6: /* sentencia: definicion_variable SEMICOLON  */
#line 93 "parser.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 1227 "parser.tab.c"
    break;

  case 7: /* sentencia: asignacion SEMICOLON  */
#line 94 "parser.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 1233 "parser.tab.c"
    break;

  case 8: /* sentencia: sentencia_transmitir SEMICOLON  */
#line 95 "parser.y"
                                     { (yyval.node) = (yyvsp[-1].node); }
#line 1239 "parser.tab.c"
    break;

  case 9: /* sentencia: sentencia_si  */
#line 96 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1245 "parser.tab.c"
    break;

  case 10: /* sentencia: sentencia_mientras  */
#line 97 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1251 "parser.tab.c"
    break;

  case 11: /* sentencia: definicion_funcion  */
#line 98 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1257 "parser.tab.c"
    break;

  case 12: /* sentencia: llamada_funcion SEMICOLON  */
#line 99 "parser.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 1263 "parser.tab.c"
    break;

  case 13: /* sentencia: sentencia_retornar SEMICOLON  */
#line 100 "parser.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 1269 "parser.tab.c"
    break;

  case 14: /* sentencia: bloque  */
#line 101 "parser.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 1275 "parser.tab.c"
    break;

  case 15: /* tipo_dato: INT_TYPE  */
#line 105 "parser.y"
                  { (yyval.type_enum) = TYPE_ESCUDO; }
#line 1281 "parser.tab.c"
    break;

  case 16: /* tipo_dato: DOUBLE_TYPE  */
#line 106 "parser.y"
                  { (yyval.type_enum) = TYPE_ENERGIA; }
#line 1287 "parser.tab.c"
    break;

  case 17: /* tipo_dato: CHAR_TYPE  */
#line 107 "parser.y"
                  { (yyval.type_enum) = TYPE_SPARTAN; }
#line 1293 "parser.tab.c"
    break;

  case 18: /* tipo_dato: STRING_TYPE  */
#line 108 "parser.y"
                  { (yyval.type_enum) = TYPE_MISION; }
#line 1299 "parser.tab.c"
    break;

  case 19: /* tipo_dato: BOOL_TYPE  */
#line 109 "parser.y"
                  { (yyval.type_enum) = TYPE_COVENANT; }
#line 1305 "parser.tab.c"
    break;

  case 20: /* expresion: INT_LITERAL  */
#line 113 "parser.y"
                                         { (yyval.node) = ast_make_int((yyvsp[0].i_val)); }
#line 1311 "parser.tab.c"
    break;

  case 21: /* expresion: DOUBLE_LITERAL  */
#line 114 "parser.y"
                                         { (yyval.node) = ast_make_double((yyvsp[0].d_val)); }
#line 1317 "parser.tab.c"
    break;

  case 22: /* expresion: CHAR_LITERAL  */
#line 115 "parser.y"
                                         { (yyval.node) = ast_make_char((yyvsp[0].c_val)); }
#line 1323 "parser.tab.c"
    break;

  case 23: /* expresion: BOOL_LITERAL  */
#line 116 "parser.y"
                                         { (yyval.node) = ast_make_bool((yyvsp[0].b_val)); }
#line 1329 "parser.tab.c"
    break;

  case 24: /* expresion: STRING_LITERAL  */
#line 117 "parser.y"
                                         { (yyval.node) = ast_make_string((yyvsp[0].s_val)); free((yyvsp[0].s_val)); }
#line 1335 "parser.tab.c"
    break;

  case 25: /* expresion: IDENTIFIER  */
#line 118 "parser.y"
                                         { (yyval.node) = ast_make_id((yyvsp[0].s_val)); free((yyvsp[0].s_val)); }
#line 1341 "parser.tab.c"
    break;

  case 26: /* expresion: expresion PLUS expresion  */
#line 119 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1347 "parser.tab.c"
    break;

  case 27: /* expresion: expresion SUB expresion  */
#line 120 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1353 "parser.tab.c"
    break;

  case 28: /* expresion: expresion MULT expresion  */
#line 121 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1359 "parser.tab.c"
    break;

  case 29: /* expresion: expresion DIV expresion  */
#line 122 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1365 "parser.tab.c"
    break;

  case 30: /* expresion: SUB expresion  */
#line 123 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_MUL, ast_make_int(-1), (yyvsp[0].node)); }
#line 1371 "parser.tab.c"
    break;

  case 31: /* expresion: expresion EQ expresion  */
#line 124 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_EQ,  (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1377 "parser.tab.c"
    break;

  case 32: /* expresion: expresion NEQ expresion  */
#line 125 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_NEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1383 "parser.tab.c"
    break;

  case 33: /* expresion: expresion LT expresion  */
#line 126 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_LT,  (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1389 "parser.tab.c"
    break;

  case 34: /* expresion: expresion GT expresion  */
#line 127 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_GT,  (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1395 "parser.tab.c"
    break;

  case 35: /* expresion: expresion LEQ expresion  */
#line 128 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_LEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1401 "parser.tab.c"
    break;

  case 36: /* expresion: expresion GEQ expresion  */
#line 129 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_GEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1407 "parser.tab.c"
    break;

  case 37: /* expresion: expresion AND expresion  */
#line 130 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1413 "parser.tab.c"
    break;

  case 38: /* expresion: expresion OR expresion  */
#line 131 "parser.y"
                                         { (yyval.node) = ast_make_binop(NODE_OR,  (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1419 "parser.tab.c"
    break;

  case 39: /* expresion: NOT expresion  */
#line 132 "parser.y"
                                         { (yyval.node) = ast_make_not((yyvsp[0].node)); }
#line 1425 "parser.tab.c"
    break;

  case 40: /* expresion: LPARENT expresion RPARENT  */
#line 133 "parser.y"
                                         { (yyval.node) = (yyvsp[-1].node); }
#line 1431 "parser.tab.c"
    break;

  case 41: /* definicion_variable: HALO tipo_dato IDENTIFIER ASSIGN expresion  */
#line 137 "parser.y"
                                               {
        (yyval.node) = ast_make_decl((DataType)(yyvsp[-3].type_enum), (yyvsp[-2].s_val), (yyvsp[0].node));
        free((yyvsp[-2].s_val));
    }
#line 1440 "parser.tab.c"
    break;

  case 42: /* asignacion: IDENTIFIER ASSIGN expresion  */
#line 144 "parser.y"
                                {
        (yyval.node) = ast_make_assign((yyvsp[-2].s_val), (yyvsp[0].node));
        free((yyvsp[-2].s_val));
    }
#line 1449 "parser.tab.c"
    break;

  case 43: /* sentencia_transmitir: TRANSMITIR expresion  */
#line 151 "parser.y"
                         { (yyval.node) = ast_make_transmitir((yyvsp[0].node)); }
#line 1455 "parser.tab.c"
    break;

  case 44: /* sentencia_si: SI LPARENT expresion RPARENT bloque  */
#line 155 "parser.y"
                                        { (yyval.node) = ast_make_if((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1461 "parser.tab.c"
    break;

  case 45: /* sentencia_si: SI LPARENT expresion RPARENT bloque SINO bloque  */
#line 156 "parser.y"
                                                      { (yyval.node) = ast_make_if((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1467 "parser.tab.c"
    break;

  case 46: /* sentencia_mientras: MIENTRAS LPARENT expresion RPARENT bloque  */
#line 160 "parser.y"
                                              { (yyval.node) = ast_make_while((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1473 "parser.tab.c"
    break;

  case 47: /* definicion_funcion: FUNC_DEF IDENTIFIER bloque  */
#line 164 "parser.y"
                               {
        (yyval.node) = ast_make_func_def((yyvsp[-1].s_val), (yyvsp[0].node));
        free((yyvsp[-1].s_val));
    }
#line 1482 "parser.tab.c"
    break;

  case 48: /* llamada_funcion: FUNC_CALL IDENTIFIER  */
#line 171 "parser.y"
                         {
        (yyval.node) = ast_make_func_call((yyvsp[0].s_val));
        free((yyvsp[0].s_val));
    }
#line 1491 "parser.tab.c"
    break;

  case 49: /* sentencia_retornar: RETORNAR expresion  */
#line 178 "parser.y"
                       { (yyval.node) = ast_make_return((yyvsp[0].node)); }
#line 1497 "parser.tab.c"
    break;


#line 1501 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 181 "parser.y"

/* ============================================================
   CÓDIGO C FINAL (Inicia después del segundo %%)
   ============================================================ */

void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico: %s\n", s);
}

int main(int argc, char **argv) {
    int print_ast   = 0;
    int print_table = 0;
    char *filename  = NULL;

    for (int i = 1; i < argc; i++) {
        if      (strcmp(argv[i], "--ast")   == 0) print_ast   = 1;
        else if (strcmp(argv[i], "--tabla") == 0) print_table = 1;
        else filename = argv[i];
    }

    if (filename) {
        FILE *f = fopen(filename, "r");
        if (!f) { fprintf(stderr, "No se pudo abrir: %s\n", filename); return 1; }
        yyin = f;
    }

    init_symbol_table();

    if (yyparse() != 0) return 1;

    if (print_ast) {
        printf("\n╔══════════════════════ AST ══════════════════════╗\n");
        ast_print(ast_root, 0);
        printf("╚═════════════════════════════════════════════════╝\n\n");
    }

    ast_exec(ast_root);

    if (print_table) dump_scopes();

    ast_free(ast_root);
    printf("\n[Compilacion exitosa]\n");
    return 0;
}
