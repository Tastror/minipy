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

#ifndef YY_YY_SRC_GEN_COMPILER_BISON_H_INCLUDED
# define YY_YY_SRC_GEN_COMPILER_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 14 "src/parser.y"


#include <memory>
#include "../src/log.h"
#include "../src/timing.h"
#include "../src/lexer.h"
#include "../src/parser.h"

#define LOG_ASTNODE(log_info_string) \
    do { stdlog::log << stdlog::info << "astnode: " << log_info_string << stdlog::endl; } while(0)

// below only for ast_error
#define GEN_ERROR_NODE(log_info_string, new_astnode_ptr, token_ptr) do { \
    LOG_ASTNODE(log_info_string); \
    new_astnode_ptr = make_astnode_from_token(token_ptr); \
} while(0)
#define EMPTY(node, leaf) GEN_ERROR_NODE("... (for ast_error)", node, leaf)
#define DELIMITER(node, leaf) GEN_ERROR_NODE("t_delimiter_... (for ast_error)", node, leaf)
#define BRACKET(node, leaf) GEN_ERROR_NODE("t_bracket_... (for ast_error)", node, leaf)
#define OPERATORS(node, leaf) GEN_ERROR_NODE("t_operators_... (for ast_error)", node, leaf)
#define KEYWORD(node, leaf) GEN_ERROR_NODE("t_keyword_... (for ast_error)", node, leaf)


#line 73 "src-gen/compiler_bison.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    t_error = 258,                 /* t_error  */
    t_newline = 259,               /* t_newline  */
    t_indent = 260,                /* t_indent  */
    t_dedent = 261,                /* t_dedent  */
    t_identifier = 262,            /* t_identifier  */
    t_number = 263,                /* t_number  */
    t_strtext = 264,               /* t_strtext  */
    t_delimiter_comma = 265,       /* t_delimiter_comma  */
    t_delimiter_colon = 266,       /* t_delimiter_colon  */
    t_delimiter_arrow = 267,       /* t_delimiter_arrow  */
    t_delimiter_semicolon = 268,   /* t_delimiter_semicolon  */
    t_delimiter_dot = 269,         /* t_delimiter_dot  */
    t_delimiter_3dot = 270,        /* t_delimiter_3dot  */
    t_bracket_squotes = 271,       /* t_bracket_squotes  */
    t_bracket_dquotes = 272,       /* t_bracket_dquotes  */
    t_bracket_parentheses_l = 273, /* t_bracket_parentheses_l  */
    t_bracket_parentheses_r = 274, /* t_bracket_parentheses_r  */
    t_bracket_square_l = 275,      /* t_bracket_square_l  */
    t_bracket_square_r = 276,      /* t_bracket_square_r  */
    t_bracket_curly_l = 277,       /* t_bracket_curly_l  */
    t_bracket_curly_r = 278,       /* t_bracket_curly_r  */
    t_operators_add = 279,         /* t_operators_add  */
    t_operators_sub = 280,         /* t_operators_sub  */
    t_operators_mul = 281,         /* t_operators_mul  */
    t_operators_div = 282,         /* t_operators_div  */
    t_operators_ediv = 283,        /* t_operators_ediv  */
    t_operators_mod = 284,         /* t_operators_mod  */
    t_operators_pow = 285,         /* t_operators_pow  */
    t_operators_at = 286,          /* t_operators_at  */
    t_operators_and = 287,         /* t_operators_and  */
    t_operators_or = 288,          /* t_operators_or  */
    t_operators_xor = 289,         /* t_operators_xor  */
    t_operators_not = 290,         /* t_operators_not  */
    t_operators_sleft = 291,       /* t_operators_sleft  */
    t_operators_sright = 292,      /* t_operators_sright  */
    t_operators_eq = 293,          /* t_operators_eq  */
    t_operators_neq = 294,         /* t_operators_neq  */
    t_operators_leq = 295,         /* t_operators_leq  */
    t_operators_geq = 296,         /* t_operators_geq  */
    t_operators_lt = 297,          /* t_operators_lt  */
    t_operators_gt = 298,          /* t_operators_gt  */
    t_operators_assign = 299,      /* t_operators_assign  */
    t_operators_add_assign = 300,  /* t_operators_add_assign  */
    t_operators_sub_assign = 301,  /* t_operators_sub_assign  */
    t_operators_mul_assign = 302,  /* t_operators_mul_assign  */
    t_operators_div_assign = 303,  /* t_operators_div_assign  */
    t_operators_ediv_assign = 304, /* t_operators_ediv_assign  */
    t_operators_mod_assign = 305,  /* t_operators_mod_assign  */
    t_operators_pow_assign = 306,  /* t_operators_pow_assign  */
    t_operators_at_assign = 307,   /* t_operators_at_assign  */
    t_operators_and_assign = 308,  /* t_operators_and_assign  */
    t_operators_or_assign = 309,   /* t_operators_or_assign  */
    t_operators_xor_assign = 310,  /* t_operators_xor_assign  */
    t_operators_not_assign = 311,  /* t_operators_not_assign  */
    t_operators_sleft_assign = 312, /* t_operators_sleft_assign  */
    t_operators_sright_assign = 313, /* t_operators_sright_assign  */
    t_keyword_underline = 314,     /* t_keyword_underline  */
    t_keyword_None = 315,          /* t_keyword_None  */
    t_keyword_True = 316,          /* t_keyword_True  */
    t_keyword_False = 317,         /* t_keyword_False  */
    t_keyword_and = 318,           /* t_keyword_and  */
    t_keyword_or = 319,            /* t_keyword_or  */
    t_keyword_not = 320,           /* t_keyword_not  */
    t_keyword_is = 321,            /* t_keyword_is  */
    t_keyword_in = 322,            /* t_keyword_in  */
    t_keyword_pass = 323,          /* t_keyword_pass  */
    t_keyword_def = 324,           /* t_keyword_def  */
    t_keyword_return = 325,        /* t_keyword_return  */
    t_keyword_yield = 326,         /* t_keyword_yield  */
    t_keyword_class = 327,         /* t_keyword_class  */
    t_keyword_lambda = 328,        /* t_keyword_lambda  */
    t_keyword_await = 329,         /* t_keyword_await  */
    t_keyword_if = 330,            /* t_keyword_if  */
    t_keyword_else = 331,          /* t_keyword_else  */
    t_keyword_elif = 332,          /* t_keyword_elif  */
    t_keyword_for = 333,           /* t_keyword_for  */
    t_keyword_break = 334,         /* t_keyword_break  */
    t_keyword_continue = 335,      /* t_keyword_continue  */
    t_keyword_match = 336,         /* t_keyword_match  */
    t_keyword_case = 337,          /* t_keyword_case  */
    t_keyword_global = 338,        /* t_keyword_global  */
    t_keyword_nonlocal = 339,      /* t_keyword_nonlocal  */
    t_keyword_del = 340,           /* t_keyword_del  */
    t_keyword_import = 341,        /* t_keyword_import  */
    t_keyword_from = 342,          /* t_keyword_from  */
    t_keyword_as = 343,            /* t_keyword_as  */
    t_keyword_raise = 344,         /* t_keyword_raise  */
    t_keyword_try = 345,           /* t_keyword_try  */
    t_keyword_except = 346,        /* t_keyword_except  */
    t_keyword_finally = 347,       /* t_keyword_finally  */
    t_keyword_assert = 348,        /* t_keyword_assert  */
    t_keyword_tastror_out = 349    /* t_keyword_tastror_out  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "src/parser.y"

    Token* token_ptr;
    AstNode* astnode_ptr;

#line 189 "src-gen/compiler_bison.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (AstNode*& ast_head);


#endif /* !YY_YY_SRC_GEN_COMPILER_BISON_H_INCLUDED  */
