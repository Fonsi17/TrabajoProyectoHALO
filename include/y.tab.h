/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "src/parser.y"

    #include "../include/ast.h"

#line 53 "src/y.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    HALO = 258,                    /* HALO  */
    TRANSMITIR = 259,              /* TRANSMITIR  */
    SI = 260,                      /* SI  */
    SINO = 261,                    /* SINO  */
    MIENTRAS = 262,                /* MIENTRAS  */
    FUNC_DEF = 263,                /* FUNC_DEF  */
    FUNC_CALL = 264,               /* FUNC_CALL  */
    RETORNAR = 265,                /* RETORNAR  */
    INT_TYPE = 266,                /* INT_TYPE  */
    CHAR_TYPE = 267,               /* CHAR_TYPE  */
    DOUBLE_TYPE = 268,             /* DOUBLE_TYPE  */
    BOOL_TYPE = 269,               /* BOOL_TYPE  */
    STRING_TYPE = 270,             /* STRING_TYPE  */
    SEMICOLON = 271,               /* SEMICOLON  */
    ASSIGN = 272,                  /* ASSIGN  */
    LPARENT = 273,                 /* LPARENT  */
    RPARENT = 274,                 /* RPARENT  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    PLUS = 277,                    /* PLUS  */
    SUB = 278,                     /* SUB  */
    MULT = 279,                    /* MULT  */
    DIV = 280,                     /* DIV  */
    EQ = 281,                      /* EQ  */
    NEQ = 282,                     /* NEQ  */
    LT = 283,                      /* LT  */
    GT = 284,                      /* GT  */
    LEQ = 285,                     /* LEQ  */
    GEQ = 286,                     /* GEQ  */
    AND = 287,                     /* AND  */
    OR = 288,                      /* OR  */
    NOT = 289,                     /* NOT  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    INT_LITERAL = 291,             /* INT_LITERAL  */
    DOUBLE_LITERAL = 292,          /* DOUBLE_LITERAL  */
    CHAR_LITERAL = 293,            /* CHAR_LITERAL  */
    BOOL_LITERAL = 294,            /* BOOL_LITERAL  */
    STRING_LITERAL = 295,          /* STRING_LITERAL  */
    UMINUS = 296                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define HALO 258
#define TRANSMITIR 259
#define SI 260
#define SINO 261
#define MIENTRAS 262
#define FUNC_DEF 263
#define FUNC_CALL 264
#define RETORNAR 265
#define INT_TYPE 266
#define CHAR_TYPE 267
#define DOUBLE_TYPE 268
#define BOOL_TYPE 269
#define STRING_TYPE 270
#define SEMICOLON 271
#define ASSIGN 272
#define LPARENT 273
#define RPARENT 274
#define LBRACE 275
#define RBRACE 276
#define PLUS 277
#define SUB 278
#define MULT 279
#define DIV 280
#define EQ 281
#define NEQ 282
#define LT 283
#define GT 284
#define LEQ 285
#define GEQ 286
#define AND 287
#define OR 288
#define NOT 289
#define IDENTIFIER 290
#define INT_LITERAL 291
#define DOUBLE_LITERAL 292
#define CHAR_LITERAL 293
#define BOOL_LITERAL 294
#define STRING_LITERAL 295
#define UMINUS 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "src/parser.y"

    int       i_val;
    int       b_val;
    double    d_val;
    char      c_val;
    char     *s_val;
    int       type_enum;
    struct ASTNode  *node;

#line 165 "src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
