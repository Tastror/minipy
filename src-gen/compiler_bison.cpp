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
#line 1 "src/parser.y"

#include <string>
#include <memory>

#include "compiler_flex.h"
#include "../src/timing.h"
#include "../src/log.h"
#include "../src/lexer.h"
#include "../src/parser.h"

void yyerror(AstNode*& ast_head, char* msg);

#line 84 "src-gen/compiler_bison.cpp"

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

#include "compiler_bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_t_error = 3,                    /* t_error  */
  YYSYMBOL_t_newline = 4,                  /* t_newline  */
  YYSYMBOL_t_indent = 5,                   /* t_indent  */
  YYSYMBOL_t_dedent = 6,                   /* t_dedent  */
  YYSYMBOL_t_identifier = 7,               /* t_identifier  */
  YYSYMBOL_t_number = 8,                   /* t_number  */
  YYSYMBOL_t_strtext = 9,                  /* t_strtext  */
  YYSYMBOL_t_delimiter_comma = 10,         /* t_delimiter_comma  */
  YYSYMBOL_t_delimiter_colon = 11,         /* t_delimiter_colon  */
  YYSYMBOL_t_delimiter_arrow = 12,         /* t_delimiter_arrow  */
  YYSYMBOL_t_delimiter_semicolon = 13,     /* t_delimiter_semicolon  */
  YYSYMBOL_t_delimiter_dot = 14,           /* t_delimiter_dot  */
  YYSYMBOL_t_delimiter_3dot = 15,          /* t_delimiter_3dot  */
  YYSYMBOL_t_bracket_squotes = 16,         /* t_bracket_squotes  */
  YYSYMBOL_t_bracket_dquotes = 17,         /* t_bracket_dquotes  */
  YYSYMBOL_t_bracket_parentheses_l = 18,   /* t_bracket_parentheses_l  */
  YYSYMBOL_t_bracket_parentheses_r = 19,   /* t_bracket_parentheses_r  */
  YYSYMBOL_t_bracket_square_l = 20,        /* t_bracket_square_l  */
  YYSYMBOL_t_bracket_square_r = 21,        /* t_bracket_square_r  */
  YYSYMBOL_t_bracket_curly_l = 22,         /* t_bracket_curly_l  */
  YYSYMBOL_t_bracket_curly_r = 23,         /* t_bracket_curly_r  */
  YYSYMBOL_t_operators_add = 24,           /* t_operators_add  */
  YYSYMBOL_t_operators_sub = 25,           /* t_operators_sub  */
  YYSYMBOL_t_operators_mul = 26,           /* t_operators_mul  */
  YYSYMBOL_t_operators_div = 27,           /* t_operators_div  */
  YYSYMBOL_t_operators_ediv = 28,          /* t_operators_ediv  */
  YYSYMBOL_t_operators_mod = 29,           /* t_operators_mod  */
  YYSYMBOL_t_operators_pow = 30,           /* t_operators_pow  */
  YYSYMBOL_t_operators_at = 31,            /* t_operators_at  */
  YYSYMBOL_t_operators_and = 32,           /* t_operators_and  */
  YYSYMBOL_t_operators_or = 33,            /* t_operators_or  */
  YYSYMBOL_t_operators_xor = 34,           /* t_operators_xor  */
  YYSYMBOL_t_operators_not = 35,           /* t_operators_not  */
  YYSYMBOL_t_operators_sleft = 36,         /* t_operators_sleft  */
  YYSYMBOL_t_operators_sright = 37,        /* t_operators_sright  */
  YYSYMBOL_t_operators_eq = 38,            /* t_operators_eq  */
  YYSYMBOL_t_operators_neq = 39,           /* t_operators_neq  */
  YYSYMBOL_t_operators_leq = 40,           /* t_operators_leq  */
  YYSYMBOL_t_operators_geq = 41,           /* t_operators_geq  */
  YYSYMBOL_t_operators_lt = 42,            /* t_operators_lt  */
  YYSYMBOL_t_operators_gt = 43,            /* t_operators_gt  */
  YYSYMBOL_t_operators_assign = 44,        /* t_operators_assign  */
  YYSYMBOL_t_operators_add_assign = 45,    /* t_operators_add_assign  */
  YYSYMBOL_t_operators_sub_assign = 46,    /* t_operators_sub_assign  */
  YYSYMBOL_t_operators_mul_assign = 47,    /* t_operators_mul_assign  */
  YYSYMBOL_t_operators_div_assign = 48,    /* t_operators_div_assign  */
  YYSYMBOL_t_operators_ediv_assign = 49,   /* t_operators_ediv_assign  */
  YYSYMBOL_t_operators_mod_assign = 50,    /* t_operators_mod_assign  */
  YYSYMBOL_t_operators_pow_assign = 51,    /* t_operators_pow_assign  */
  YYSYMBOL_t_operators_at_assign = 52,     /* t_operators_at_assign  */
  YYSYMBOL_t_operators_and_assign = 53,    /* t_operators_and_assign  */
  YYSYMBOL_t_operators_or_assign = 54,     /* t_operators_or_assign  */
  YYSYMBOL_t_operators_xor_assign = 55,    /* t_operators_xor_assign  */
  YYSYMBOL_t_operators_not_assign = 56,    /* t_operators_not_assign  */
  YYSYMBOL_t_operators_sleft_assign = 57,  /* t_operators_sleft_assign  */
  YYSYMBOL_t_operators_sright_assign = 58, /* t_operators_sright_assign  */
  YYSYMBOL_t_keyword_underline = 59,       /* t_keyword_underline  */
  YYSYMBOL_t_keyword_None = 60,            /* t_keyword_None  */
  YYSYMBOL_t_keyword_True = 61,            /* t_keyword_True  */
  YYSYMBOL_t_keyword_False = 62,           /* t_keyword_False  */
  YYSYMBOL_t_keyword_and = 63,             /* t_keyword_and  */
  YYSYMBOL_t_keyword_or = 64,              /* t_keyword_or  */
  YYSYMBOL_t_keyword_not = 65,             /* t_keyword_not  */
  YYSYMBOL_t_keyword_is = 66,              /* t_keyword_is  */
  YYSYMBOL_t_keyword_in = 67,              /* t_keyword_in  */
  YYSYMBOL_t_keyword_pass = 68,            /* t_keyword_pass  */
  YYSYMBOL_t_keyword_def = 69,             /* t_keyword_def  */
  YYSYMBOL_t_keyword_return = 70,          /* t_keyword_return  */
  YYSYMBOL_t_keyword_yield = 71,           /* t_keyword_yield  */
  YYSYMBOL_t_keyword_class = 72,           /* t_keyword_class  */
  YYSYMBOL_t_keyword_lambda = 73,          /* t_keyword_lambda  */
  YYSYMBOL_t_keyword_await = 74,           /* t_keyword_await  */
  YYSYMBOL_t_keyword_while = 75,           /* t_keyword_while  */
  YYSYMBOL_t_keyword_if = 76,              /* t_keyword_if  */
  YYSYMBOL_t_keyword_else = 77,            /* t_keyword_else  */
  YYSYMBOL_t_keyword_elif = 78,            /* t_keyword_elif  */
  YYSYMBOL_t_keyword_for = 79,             /* t_keyword_for  */
  YYSYMBOL_t_keyword_break = 80,           /* t_keyword_break  */
  YYSYMBOL_t_keyword_continue = 81,        /* t_keyword_continue  */
  YYSYMBOL_t_keyword_match = 82,           /* t_keyword_match  */
  YYSYMBOL_t_keyword_case = 83,            /* t_keyword_case  */
  YYSYMBOL_t_keyword_global = 84,          /* t_keyword_global  */
  YYSYMBOL_t_keyword_nonlocal = 85,        /* t_keyword_nonlocal  */
  YYSYMBOL_t_keyword_del = 86,             /* t_keyword_del  */
  YYSYMBOL_t_keyword_import = 87,          /* t_keyword_import  */
  YYSYMBOL_t_keyword_from = 88,            /* t_keyword_from  */
  YYSYMBOL_t_keyword_as = 89,              /* t_keyword_as  */
  YYSYMBOL_t_keyword_raise = 90,           /* t_keyword_raise  */
  YYSYMBOL_t_keyword_try = 91,             /* t_keyword_try  */
  YYSYMBOL_t_keyword_except = 92,          /* t_keyword_except  */
  YYSYMBOL_t_keyword_finally = 93,         /* t_keyword_finally  */
  YYSYMBOL_t_keyword_assert = 94,          /* t_keyword_assert  */
  YYSYMBOL_t_keyword___in = 95,            /* t_keyword___in  */
  YYSYMBOL_t_keyword___out = 96,           /* t_keyword___out  */
  YYSYMBOL_YYACCEPT = 97,                  /* $accept  */
  YYSYMBOL_file = 98,                      /* file  */
  YYSYMBOL_statements = 99,                /* statements  */
  YYSYMBOL_simple_stmts = 100,             /* simple_stmts  */
  YYSYMBOL__no_newline_simple_stmt = 101,  /* _no_newline_simple_stmt  */
  YYSYMBOL_simple_stmt = 102,              /* simple_stmt  */
  YYSYMBOL_assignment = 103,               /* assignment  */
  YYSYMBOL__no_type_assign = 104,          /* _no_type_assign  */
  YYSYMBOL_augassign = 105,                /* augassign  */
  YYSYMBOL_compound_stmt = 106,            /* compound_stmt  */
  YYSYMBOL_function_def = 107,             /* function_def  */
  YYSYMBOL_function_def_raw = 108,         /* function_def_raw  */
  YYSYMBOL_class_def = 109,                /* class_def  */
  YYSYMBOL_class_def_raw = 110,            /* class_def_raw  */
  YYSYMBOL_while_stmt = 111,               /* while_stmt  */
  YYSYMBOL_for_stmt = 112,                 /* for_stmt  */
  YYSYMBOL_if_stmt = 113,                  /* if_stmt  */
  YYSYMBOL_elif_stmt = 114,                /* elif_stmt  */
  YYSYMBOL_else_block = 115,               /* else_block  */
  YYSYMBOL_block = 116,                    /* block  */
  YYSYMBOL_expressions_type = 117,         /* expressions_type  */
  YYSYMBOL_expressions_lhs = 118,          /* expressions_lhs  */
  YYSYMBOL_expressions_rhs = 119,          /* expressions_rhs  */
  YYSYMBOL_yield_expr = 120,               /* yield_expr  */
  YYSYMBOL__normal_multiple_or_single_expr = 121, /* _normal_multiple_or_single_expr  */
  YYSYMBOL__tuple_like_multiple_or_single_expr = 122, /* _tuple_like_multiple_or_single_expr  */
  YYSYMBOL__no_endcomma_multiple_expressions = 123, /* _no_endcomma_multiple_expressions  */
  YYSYMBOL__normal_single_expression = 124, /* _normal_single_expression  */
  YYSYMBOL_star_expression = 125,          /* star_expression  */
  YYSYMBOL__expression_if_else = 126,      /* _expression_if_else  */
  YYSYMBOL__disjunction_or_just_conjunction = 127, /* _disjunction_or_just_conjunction  */
  YYSYMBOL_disjunction = 128,              /* disjunction  */
  YYSYMBOL__conjunction_or_just_inversion = 129, /* _conjunction_or_just_inversion  */
  YYSYMBOL_conjunction = 130,              /* conjunction  */
  YYSYMBOL_inversion = 131,                /* inversion  */
  YYSYMBOL__comparison_or_just_bitwise_or = 132, /* _comparison_or_just_bitwise_or  */
  YYSYMBOL_comparison = 133,               /* comparison  */
  YYSYMBOL_compare_op_bitwise_or_pair = 134, /* compare_op_bitwise_or_pair  */
  YYSYMBOL_bitwise_or = 135,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 136,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 137,              /* bitwise_and  */
  YYSYMBOL_shift_expr = 138,               /* shift_expr  */
  YYSYMBOL_sum = 139,                      /* sum  */
  YYSYMBOL_term = 140,                     /* term  */
  YYSYMBOL_factor = 141,                   /* factor  */
  YYSYMBOL_power = 142,                    /* power  */
  YYSYMBOL_await_primary = 143,            /* await_primary  */
  YYSYMBOL_primary = 144,                  /* primary  */
  YYSYMBOL_atom = 145,                     /* atom  */
  YYSYMBOL_list = 146,                     /* list  */
  YYSYMBOL_tuple = 147,                    /* tuple  */
  YYSYMBOL_set = 148,                      /* set  */
  YYSYMBOL_slice = 149,                    /* slice  */
  YYSYMBOL_strings = 150,                  /* strings  */
  YYSYMBOL_string_text = 151,              /* string_text  */
  YYSYMBOL_arguments_or_parameters = 152,  /* arguments_or_parameters  */
  YYSYMBOL_argparas = 153,                 /* argparas  */
  YYSYMBOL_argpara = 154,                  /* argpara  */
  YYSYMBOL_ast_error = 155                 /* ast_error  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  121
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   351


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   338,   338,   344,   350,   355,   360,   370,   375,   381,
     388,   393,   401,   402,   407,   412,   417,   418,   419,   420,
     426,   441,   442,   450,   459,   469,   477,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   507,   508,   509,   510,   511,   514,   521,   534,   547,
     561,   577,   584,   594,   606,   620,   629,   640,   655,   672,
     681,   690,   701,   710,   719,   730,   738,   745,   776,   779,
     782,   783,   798,   804,   810,   819,   820,   823,   824,   829,
     837,   844,   851,   854,   855,   863,   864,   874,   875,   878,
     885,   892,   893,   896,   903,   910,   911,   919,   920,   923,
     929,   935,   941,   947,   953,   959,   965,   971,   978,   984,
     991,   999,  1000,  1009,  1010,  1019,  1020,  1029,  1030,  1037,
    1046,  1047,  1054,  1063,  1064,  1071,  1078,  1085,  1092,  1101,
    1102,  1108,  1114,  1122,  1123,  1132,  1133,  1141,  1142,  1150,
    1158,  1166,  1174,  1184,  1189,  1194,  1199,  1204,  1209,  1214,
    1219,  1224,  1229,  1230,  1231,  1232,  1233,  1239,  1251,  1257,
    1265,  1274,  1280,  1291,  1297,  1305,  1314,  1322,  1330,  1338,
    1346,  1355,  1364,  1373,  1382,  1391,  1400,  1409,  1420,  1425,
    1431,  1438,  1447,  1448,  1455,  1460,  1467,  1468,  1475,  1481,
    1487,  1494,  1511,  1581,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602
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
  "\"end of file\"", "error", "\"invalid token\"", "t_error", "t_newline",
  "t_indent", "t_dedent", "t_identifier", "t_number", "t_strtext",
  "t_delimiter_comma", "t_delimiter_colon", "t_delimiter_arrow",
  "t_delimiter_semicolon", "t_delimiter_dot", "t_delimiter_3dot",
  "t_bracket_squotes", "t_bracket_dquotes", "t_bracket_parentheses_l",
  "t_bracket_parentheses_r", "t_bracket_square_l", "t_bracket_square_r",
  "t_bracket_curly_l", "t_bracket_curly_r", "t_operators_add",
  "t_operators_sub", "t_operators_mul", "t_operators_div",
  "t_operators_ediv", "t_operators_mod", "t_operators_pow",
  "t_operators_at", "t_operators_and", "t_operators_or", "t_operators_xor",
  "t_operators_not", "t_operators_sleft", "t_operators_sright",
  "t_operators_eq", "t_operators_neq", "t_operators_leq",
  "t_operators_geq", "t_operators_lt", "t_operators_gt",
  "t_operators_assign", "t_operators_add_assign", "t_operators_sub_assign",
  "t_operators_mul_assign", "t_operators_div_assign",
  "t_operators_ediv_assign", "t_operators_mod_assign",
  "t_operators_pow_assign", "t_operators_at_assign",
  "t_operators_and_assign", "t_operators_or_assign",
  "t_operators_xor_assign", "t_operators_not_assign",
  "t_operators_sleft_assign", "t_operators_sright_assign",
  "t_keyword_underline", "t_keyword_None", "t_keyword_True",
  "t_keyword_False", "t_keyword_and", "t_keyword_or", "t_keyword_not",
  "t_keyword_is", "t_keyword_in", "t_keyword_pass", "t_keyword_def",
  "t_keyword_return", "t_keyword_yield", "t_keyword_class",
  "t_keyword_lambda", "t_keyword_await", "t_keyword_while", "t_keyword_if",
  "t_keyword_else", "t_keyword_elif", "t_keyword_for", "t_keyword_break",
  "t_keyword_continue", "t_keyword_match", "t_keyword_case",
  "t_keyword_global", "t_keyword_nonlocal", "t_keyword_del",
  "t_keyword_import", "t_keyword_from", "t_keyword_as", "t_keyword_raise",
  "t_keyword_try", "t_keyword_except", "t_keyword_finally",
  "t_keyword_assert", "t_keyword___in", "t_keyword___out", "$accept",
  "file", "statements", "simple_stmts", "_no_newline_simple_stmt",
  "simple_stmt", "assignment", "_no_type_assign", "augassign",
  "compound_stmt", "function_def", "function_def_raw", "class_def",
  "class_def_raw", "while_stmt", "for_stmt", "if_stmt", "elif_stmt",
  "else_block", "block", "expressions_type", "expressions_lhs",
  "expressions_rhs", "yield_expr", "_normal_multiple_or_single_expr",
  "_tuple_like_multiple_or_single_expr",
  "_no_endcomma_multiple_expressions", "_normal_single_expression",
  "star_expression", "_expression_if_else",
  "_disjunction_or_just_conjunction", "disjunction",
  "_conjunction_or_just_inversion", "conjunction", "inversion",
  "_comparison_or_just_bitwise_or", "comparison",
  "compare_op_bitwise_or_pair", "bitwise_or", "bitwise_xor", "bitwise_and",
  "shift_expr", "sum", "term", "factor", "power", "await_primary",
  "primary", "atom", "list", "tuple", "set", "slice", "strings",
  "string_text", "arguments_or_parameters", "argparas", "argpara",
  "ast_error", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     406,  -245,  -245,  -245,  -245,  -245,    32,    46,    42,   837,
     899,  1356,  1356,  1271,  1356,  -245,  -245,  -245,  -245,  1271,
    -245,     2,  1209,   922,    65,  -245,  1377,  1209,  1209,  1209,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,    51,   406,  -245,
      43,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,     9,  -245,    36,  -245,    53,    76,  -245,  -245,
      22,    30,    55,    37,    54,  -245,   204,   195,    90,    98,
     -17,    64,    56,  -245,  -245,    96,   166,  -245,  -245,  -245,
    -245,     8,  -245,  -245,   120,   125,  -245,   124,   128,   135,
      61,  -245,   123,    44,  -245,   133,    19,  -245,  -245,  -245,
    -245,  -245,   139,  -245,  1209,  -245,    60,    61,   148,   150,
     151,  -245,  -245,  -245,  -245,   500,  1004,  1209,  1209,  1271,
    1271,  1271,  1271,  1271,  1356,  1356,  1356,  1356,  1356,  1356,
      97,  1294,  1356,  -245,  1356,  -245,  1356,  1356,  1356,  1356,
    1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1377,   156,
     684,  1027,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  1004,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,   746,  -245,   594,
     808,   594,   594,   594,  -245,  -245,  -245,  -245,  -245,    36,
    -245,  -245,    88,  -245,  -245,  -245,  -245,   134,   134,   134,
     134,   134,   134,  1356,  1356,   134,   134,    90,    98,   -17,
      64,    64,    56,    56,  -245,  -245,  -245,  -245,  -245,  -245,
     122,    61,  -245,  -245,  1209,  1209,  -245,    25,   149,   159,
    -245,  1095,   152,    86,   153,  -245,  -245,    94,   157,   167,
    -245,  -245,   164,   162,   105,    34,   105,  1271,   134,   134,
    1004,  -245,  -245,  -245,  1377,  1209,  -245,  1118,  1209,   172,
    -245,  1186,  -245,   594,  1209,   103,   406,   594,   174,   177,
    -245,  1209,  -245,  -245,  -245,  -245,  -245,    26,  -245,  -245,
    -245,  1209,  1209,   183,  -245,   184,   594,  1209,   312,  -245,
     594,   594,   185,  1209,  -245,  -245,  1209,   594,  -245,   186,
    -245,  -245,  -245,   594,  -245,  -245,  -245,   594,    34,  -245,
    -245,  -245
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   192,     9,   143,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   146,   144,   145,     0,
      13,     0,    19,    72,     0,   193,     0,     0,     0,     0,
      14,    15,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   147,   148,     0,     2,     3,
       0,    10,    16,    21,     4,    41,    46,    42,    51,    43,
      44,    45,     0,    18,    17,    75,    77,    76,    82,    83,
      85,    88,    87,    92,    91,    95,    98,    97,   111,   113,
     115,   117,   120,   123,   129,   133,   135,   137,   152,   153,
     154,   155,   178,    12,     0,     0,   161,     0,     0,     0,
     135,   158,     0,     0,   163,     0,     0,   130,   131,    84,
     132,    96,     0,    20,     0,    73,     0,   136,     0,     0,
       0,     1,     5,     6,     7,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,   179,   181,   180,
     156,   157,   162,   159,   160,   164,   165,     0,    74,     0,
       0,     0,     0,     0,     8,    11,    26,    25,    71,    70,
      81,    80,     0,    90,    89,    94,    93,   101,   102,   103,
     105,   104,   106,     0,     0,   110,   108,   112,   114,   116,
     118,   119,   121,   122,   124,   125,   126,   127,   128,   134,
      22,    68,   138,   139,     0,     0,   186,   135,     0,   182,
     184,   166,     0,    76,     0,    24,    70,     0,     0,     9,
      67,    52,     0,     0,    55,    60,    57,     0,   107,   109,
       0,   188,    83,   189,     0,     0,   140,   183,   170,   167,
     142,   168,   141,     0,     0,     0,     0,     0,     0,     0,
      56,     0,    59,    61,    58,    86,    23,   187,   190,   185,
     171,   172,   174,   169,    47,     0,     0,     0,     0,    53,
       0,     0,     0,     0,   173,   175,   176,     0,    48,     0,
      66,    54,    65,     0,   191,   177,    49,     0,    63,    50,
      62,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,   -78,     4,  -245,    74,  -245,    75,  -245,   -47,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -118,  -244,  -178,
    -245,  -245,  -170,    -5,    -6,    83,  -245,    18,  -245,    -8,
      73,  -245,    -3,  -245,    -1,  -245,  -245,   126,  -104,    62,
      58,    63,   -15,   -10,    -4,  -245,  -245,     0,  -245,  -245,
    -245,  -245,  -245,  -245,   116,  -114,  -245,   -58,  -245
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    47,    48,   250,    50,    51,    52,    53,   176,    54,
      55,    56,    57,    58,    59,    60,    61,   282,   280,   251,
     230,    62,   197,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   143,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   100,    87,    88,
      89,    90,   244,    91,    92,   238,   239,   240,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   123,    98,    97,    49,   109,   245,   107,   108,   112,
     110,   283,   284,   254,   255,   256,   113,   115,   111,   148,
     149,   118,   119,   120,     6,     7,   117,   103,   106,   128,
     207,   208,   209,   210,   211,   212,   264,   215,   216,   159,
     159,    94,   186,   160,   160,   161,   161,   124,    86,     3,
       4,   121,   122,   126,   128,    95,   125,     5,     6,     7,
       8,    96,     9,   127,    10,   184,    11,    12,    13,   265,
     303,   189,   116,   248,   321,   159,   253,    14,   190,   160,
     -69,   161,   152,   153,   154,   155,   128,   156,   150,   151,
     286,    99,   102,   105,   130,   294,   128,   271,   129,   299,
     132,    15,    16,    17,    18,   273,   274,    19,   188,   258,
     259,   279,   281,    23,   296,   297,    26,   133,   308,   131,
     199,   198,   311,   312,   146,    86,   157,   203,   204,   316,
     147,   205,   206,   220,   221,   318,   178,    45,    46,   319,
     222,   223,   179,   180,   183,   200,   201,   181,   224,   225,
     226,   227,   228,   229,   182,   242,   185,   187,   231,   191,
     237,   192,   193,   232,   213,   257,   260,   144,   266,   267,
     246,   198,   276,   270,   272,   277,   275,   158,   236,   243,
     159,   278,   279,   291,   160,   300,   161,   237,   301,    86,
     237,    86,    86,    86,   306,   307,   313,   317,   298,   195,
     320,   196,   202,   145,   218,   236,   217,   177,   236,   289,
     219,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,   262,     0,   144,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,     0,
       0,     0,   134,   135,   136,   137,   138,   139,     0,   285,
       0,   123,   261,   263,   246,   198,     0,     0,     0,   269,
     140,   141,   142,     0,   287,     0,     0,   237,   295,   140,
     141,   142,     0,    86,     0,   302,    86,    86,     0,     0,
      49,     0,     0,   288,     0,   236,   290,     0,     0,   293,
       0,   309,     0,     0,     0,     0,    86,     0,    86,     0,
      86,    86,   122,     0,     0,     0,     0,    86,     0,   304,
     305,     0,     0,    86,     0,     1,     2,    86,   310,     3,
       4,   314,     0,     0,   315,     0,     0,     5,     6,     7,
       8,     0,     9,     0,    10,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     1,
       2,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,     9,     0,    10,     0,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,    19,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     1,   194,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
       9,     0,    10,     0,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,    17,    18,     0,     0,    19,     0,     0,    20,     0,
      22,    23,     0,    25,    26,     0,     0,     0,     0,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     1,   249,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,     9,     0,    10,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
       0,     0,    20,     0,    22,    23,     0,    25,    26,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     3,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,   233,     9,     0,    10,     0,    11,    12,
     234,     0,     0,     0,   235,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     3,     4,     0,     0,     0,    26,     0,
       0,     5,     6,     7,     8,   247,     9,     0,    10,     0,
      11,    12,   234,     0,     0,     0,   235,     0,     0,    45,
      46,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     3,     4,     0,     0,     0,
      26,     0,     0,     5,     6,     7,     8,   252,     9,     0,
      10,     0,    11,    12,   234,     0,     0,     0,   235,     0,
       0,    45,    46,    14,     3,     4,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     0,     9,   101,    10,
       0,    11,    12,    13,     0,     0,     0,    15,    16,    17,
      18,     0,    14,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,    19,    45,    46,     0,     3,     4,     0,     0,
       0,    26,     0,     0,     5,     6,     7,     8,     0,     9,
       0,    10,   104,    11,    12,    13,     0,     0,     0,     3,
       4,     0,    45,    46,    14,     0,     0,     5,     6,     7,
       8,     0,     9,     0,    10,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,    16,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    45,    46,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,     3,     4,     0,     0,     0,     0,    45,    46,     5,
       6,     7,     8,     0,     9,     0,    10,     0,    11,    12,
      13,     0,     0,     0,     3,     4,     0,     0,   241,    14,
       0,     0,     5,     6,     7,     8,     0,     9,     0,    10,
       0,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,    23,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    45,
      46,    26,     3,     4,     0,     0,   268,     0,     0,     0,
       5,     6,     7,     8,     0,     9,     0,    10,     0,    11,
      12,    13,    45,    46,     0,     3,     4,     0,     0,     0,
      14,     0,     0,     5,     6,     7,     8,     0,     9,     0,
      10,     0,    11,    12,   234,     0,     0,     0,   235,     0,
       0,     0,     0,    14,    15,    16,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      45,    46,    26,     3,     4,     0,     0,   292,     0,     0,
       0,     5,     6,     7,     8,     0,     9,     0,    10,     0,
      11,    12,    13,    45,    46,     0,     3,     4,     0,     0,
       0,    14,     0,     0,     5,     6,     7,     8,     0,     9,
       0,    10,     0,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    18,     0,     0,    19,     0,     0,     0,     3,     4,
       0,    45,    46,    26,     0,     0,     5,     6,     7,     8,
       0,     9,     0,    10,     0,    11,    12,     0,     0,     0,
       0,     3,     4,     0,    45,    46,    14,     0,     0,     5,
       6,     7,     8,     0,     9,     0,    10,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,   214,
       0,     0,     0,     3,     4,     0,    45,    46,    26,     0,
       0,     5,     6,     7,     8,     0,     9,     0,    10,     0,
      11,    12,     0,     0,     3,     4,     0,     0,     0,    45,
      46,    14,     5,     6,     7,     8,     0,     9,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    46
};

static const yytype_int16 yycheck[] =
{
       0,    48,     8,     8,     0,    13,   176,    11,    12,     7,
      14,   255,   256,   191,   192,   193,    22,    23,    19,    36,
      37,    27,    28,    29,    16,    17,    26,     9,    10,    10,
     134,   135,   136,   137,   138,   139,    11,   141,   142,    14,
      14,     9,    23,    18,    18,    20,    20,     4,    48,     7,
       8,     0,    48,    44,    10,     9,    13,    15,    16,    17,
      18,    19,    20,    10,    22,    21,    24,    25,    26,    44,
      44,    11,     7,   187,   318,    14,   190,    35,    18,    18,
      44,    20,    26,    27,    28,    29,    10,    31,    24,    25,
     260,     8,     9,    10,    64,   273,    10,    11,    76,   277,
      63,    59,    60,    61,    62,    11,    12,    65,   114,   213,
     214,    77,    78,    71,    11,    12,    74,    63,   296,    64,
     126,   126,   300,   301,    34,   125,    30,   130,   131,   307,
      32,   132,   133,   148,   149,   313,    16,    95,    96,   317,
     150,   151,    17,    19,    21,   127,   128,    19,   152,   153,
     154,   155,   156,   157,    19,   161,    23,    18,   158,    11,
     160,    11,    11,     7,    67,    77,    44,    33,    19,    10,
     176,   176,     5,    21,    21,    11,    19,    11,   160,   161,
      14,    19,    77,    11,    18,    11,    20,   187,    11,   189,
     190,   191,   192,   193,    11,    11,    11,    11,   276,   125,
     318,   126,   129,    77,   146,   187,   144,    91,   190,   267,
     147,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,   234,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    -1,   257,
      -1,   298,   234,   235,   260,   260,    -1,    -1,    -1,   241,
      65,    66,    67,    -1,   264,    -1,    -1,   267,   274,    65,
      66,    67,    -1,   273,    -1,   281,   276,   277,    -1,    -1,
     276,    -1,    -1,   265,    -1,   267,   268,    -1,    -1,   271,
      -1,   297,    -1,    -1,    -1,    -1,   296,    -1,   298,    -1,
     300,   301,   298,    -1,    -1,    -1,    -1,   307,    -1,   291,
     292,    -1,    -1,   313,    -1,     3,     4,   317,     6,     7,
       8,   303,    -1,    -1,   306,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     3,
       4,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     3,     4,    -1,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    68,    -1,
      70,    71,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     3,     4,    -1,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    68,    -1,    70,    71,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,     7,     8,    -1,    -1,    -1,    74,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    95,
      96,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,     7,     8,    -1,    -1,    -1,
      74,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    95,    96,    35,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    35,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    65,    95,    96,    -1,     7,     8,    -1,    -1,
      -1,    74,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,     7,
       8,    -1,    95,    96,    35,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,     7,     8,    -1,    -1,    -1,    -1,    95,    96,    15,
      16,    17,    18,    -1,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,     7,     8,    -1,    -1,    11,    35,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    74,     7,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    -1,    22,    -1,    24,
      25,    26,    95,    96,    -1,     7,     8,    -1,    -1,    -1,
      35,    -1,    -1,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    59,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    74,     7,     8,    -1,    -1,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    26,    95,    96,    -1,     7,     8,    -1,    -1,
      -1,    35,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,     7,     8,
      -1,    95,    96,    74,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    -1,
      -1,     7,     8,    -1,    95,    96,    35,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    -1,    22,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,     7,     8,    -1,    95,    96,    74,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,     7,     8,    -1,    -1,    -1,    95,
      96,    35,    15,    16,    17,    18,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,    15,    16,    17,    18,    20,
      22,    24,    25,    26,    35,    59,    60,    61,    62,    65,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   118,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   150,   151,   155,     9,     9,    19,   120,   121,   122,
     144,    21,   122,   124,    23,   122,   124,   141,   141,   126,
     141,   131,     7,   121,    88,   121,     7,   144,   121,   121,
     121,     0,   100,   106,     4,    13,    44,    10,    10,    76,
      64,    64,    63,    63,    38,    39,    40,    41,    42,    43,
      65,    66,    67,   134,    33,   134,    34,    32,    36,    37,
      24,    25,    26,    27,    28,    29,    31,    30,    11,    14,
      18,    20,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   105,   151,    16,    17,
      19,    19,    19,    21,    21,    23,    23,    18,   121,    11,
      18,    11,    11,    11,     4,   102,   104,   119,   120,   121,
     124,   124,   127,   129,   129,   131,   131,   135,   135,   135,
     135,   135,   135,    67,    65,   135,   135,   136,   137,   138,
     139,   139,   140,   140,   141,   141,   141,   141,   141,   141,
     117,   144,     7,    19,    26,    30,   124,   144,   152,   153,
     154,    11,   121,   124,   149,   119,   121,    19,   152,     4,
     100,   116,    19,   152,   116,   116,   116,    77,   135,   135,
      44,   124,   126,   124,    11,    44,    19,    10,    11,   124,
      21,    11,    21,    11,    12,    19,     5,    11,    19,    77,
     115,    78,   114,   115,   115,   126,   119,   144,   124,   154,
     124,    11,    11,   124,   116,   121,    11,    12,    99,   116,
      11,    11,   121,    44,   124,   124,    11,    11,   116,   121,
       6,   116,   116,    11,   124,   124,   116,    11,   116,   116,
     114,   115
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   107,   108,   108,   108,
     108,   109,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   114,   114,   114,   115,   116,   116,   117,   118,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   122,
     123,   123,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   140,   141,
     141,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     144,   144,   144,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   147,   147,   148,   148,   148,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     5,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     7,     8,
       9,     1,     4,     6,     7,     4,     5,     4,     5,     5,
       4,     5,     5,     4,     5,     3,     4,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     1,     2,     2,
       3,     3,     1,     1,     2,     1,     5,     1,     1,     3,
       3,     1,     1,     3,     3,     1,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     3,     1,     2,     1,     3,     3,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     2,     3,     2,     3,     3,     1,     2,     2,     3,
       2,     3,     3,     4,     3,     4,     4,     5,     1,     2,
       3,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
        yyerror (ast_head, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, ast_head); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstNode*& ast_head)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast_head);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstNode*& ast_head)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast_head);
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
                 int yyrule, AstNode*& ast_head)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], ast_head);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast_head); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, AstNode*& ast_head)
{
  YY_USE (yyvaluep);
  YY_USE (ast_head);
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
yyparse (AstNode*& ast_head)
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
  case 2: /* file: statements  */
#line 339 "src/parser.y"
            {
                ast_head = (yyvsp[0].astnode_ptr);
            }
#line 1732 "src-gen/compiler_bison.cpp"
    break;

  case 3: /* statements: simple_stmts  */
#line 345 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                delete_astnode((yyvsp[0].astnode_ptr));
            }
#line 1742 "src-gen/compiler_bison.cpp"
    break;

  case 4: /* statements: compound_stmt  */
#line 351 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1751 "src-gen/compiler_bison.cpp"
    break;

  case 5: /* statements: statements simple_stmts  */
#line 356 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                delete_astnode((yyvsp[0].astnode_ptr));
            }
#line 1760 "src-gen/compiler_bison.cpp"
    break;

  case 6: /* statements: statements compound_stmt  */
#line 361 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1768 "src-gen/compiler_bison.cpp"
    break;

  case 7: /* simple_stmts: _no_newline_simple_stmt t_newline  */
#line 371 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 1777 "src-gen/compiler_bison.cpp"
    break;

  case 8: /* simple_stmts: _no_newline_simple_stmt t_delimiter_semicolon t_newline  */
#line 376 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for simple_stmts)");
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
            }
#line 1787 "src-gen/compiler_bison.cpp"
    break;

  case 9: /* simple_stmts: t_newline  */
#line 382 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = make_empty_astnode();  // will be eat_sons by statements, which is just empty~
            }
#line 1796 "src-gen/compiler_bison.cpp"
    break;

  case 10: /* _no_newline_simple_stmt: simple_stmt  */
#line 389 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::temp);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1805 "src-gen/compiler_bison.cpp"
    break;

  case 11: /* _no_newline_simple_stmt: _no_newline_simple_stmt t_delimiter_semicolon simple_stmt  */
#line 394 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for _no_newline_simple_stmt)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1815 "src-gen/compiler_bison.cpp"
    break;

  case 13: /* simple_stmt: t_keyword_pass  */
#line 403 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_pass);
            }
#line 1824 "src-gen/compiler_bison.cpp"
    break;

  case 14: /* simple_stmt: t_keyword_break  */
#line 408 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_break);
            }
#line 1833 "src-gen/compiler_bison.cpp"
    break;

  case 15: /* simple_stmt: t_keyword_continue  */
#line 413 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_continue);
            }
#line 1842 "src-gen/compiler_bison.cpp"
    break;

  case 19: /* simple_stmt: t_keyword_return  */
#line 421 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1852 "src-gen/compiler_bison.cpp"
    break;

  case 20: /* simple_stmt: t_keyword_return _normal_multiple_or_single_expr  */
#line 427 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1862 "src-gen/compiler_bison.cpp"
    break;

  case 22: /* assignment: primary t_delimiter_colon expressions_type  */
#line 443 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1874 "src-gen/compiler_bison.cpp"
    break;

  case 23: /* assignment: primary t_delimiter_colon expressions_type t_operators_assign expressions_rhs  */
#line 451 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                LOG_ASTNODE("t_operators_assign (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1887 "src-gen/compiler_bison.cpp"
    break;

  case 24: /* assignment: primary augassign expressions_rhs  */
#line 460 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_augassign);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1898 "src-gen/compiler_bison.cpp"
    break;

  case 25: /* _no_type_assign: expressions_lhs t_operators_assign expressions_rhs  */
#line 470 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1910 "src-gen/compiler_bison.cpp"
    break;

  case 26: /* _no_type_assign: expressions_lhs t_operators_assign _no_type_assign  */
#line 478 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1922 "src-gen/compiler_bison.cpp"
    break;

  case 27: /* augassign: t_operators_add_assign  */
#line 487 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_add_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1928 "src-gen/compiler_bison.cpp"
    break;

  case 28: /* augassign: t_operators_sub_assign  */
#line 488 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sub_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1934 "src-gen/compiler_bison.cpp"
    break;

  case 29: /* augassign: t_operators_mul_assign  */
#line 489 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mul_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1940 "src-gen/compiler_bison.cpp"
    break;

  case 30: /* augassign: t_operators_div_assign  */
#line 490 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_div_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1946 "src-gen/compiler_bison.cpp"
    break;

  case 31: /* augassign: t_operators_ediv_assign  */
#line 491 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_ediv_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1952 "src-gen/compiler_bison.cpp"
    break;

  case 32: /* augassign: t_operators_mod_assign  */
#line 492 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mod_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1958 "src-gen/compiler_bison.cpp"
    break;

  case 33: /* augassign: t_operators_pow_assign  */
#line 493 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_pow_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1964 "src-gen/compiler_bison.cpp"
    break;

  case 34: /* augassign: t_operators_at_assign  */
#line 494 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_at_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1970 "src-gen/compiler_bison.cpp"
    break;

  case 35: /* augassign: t_operators_and_assign  */
#line 495 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_and_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1976 "src-gen/compiler_bison.cpp"
    break;

  case 36: /* augassign: t_operators_or_assign  */
#line 496 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_or_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1982 "src-gen/compiler_bison.cpp"
    break;

  case 37: /* augassign: t_operators_xor_assign  */
#line 497 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_xor_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1988 "src-gen/compiler_bison.cpp"
    break;

  case 38: /* augassign: t_operators_not_assign  */
#line 498 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_not_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1994 "src-gen/compiler_bison.cpp"
    break;

  case 39: /* augassign: t_operators_sleft_assign  */
#line 499 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sleft_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 2000 "src-gen/compiler_bison.cpp"
    break;

  case 40: /* augassign: t_operators_sright_assign  */
#line 500 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sright_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 2006 "src-gen/compiler_bison.cpp"
    break;

  case 46: /* function_def: function_def_raw  */
#line 515 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 2014 "src-gen/compiler_bison.cpp"
    break;

  case 47: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 522 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::pen_op_function_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-4].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2031 "src-gen/compiler_bison.cpp"
    break;

  case 48: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 535 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::pen_op_function_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-5].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2048 "src-gen/compiler_bison.cpp"
    break;

  case 49: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 548 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_arrow (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::pen_op_function_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-6].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2066 "src-gen/compiler_bison.cpp"
    break;

  case 50: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 562 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_def (for function_def_raw)");
                LOG_ASTNODE("t_identifier (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for function_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_arrow (for function_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for function_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::pen_op_function_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-7].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat((yyvsp[-5].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2084 "src-gen/compiler_bison.cpp"
    break;

  case 51: /* class_def: class_def_raw  */
#line 578 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 2092 "src-gen/compiler_bison.cpp"
    break;

  case 52: /* class_def_raw: t_keyword_class t_identifier t_delimiter_colon block  */
#line 585 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_class_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-2].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2106 "src-gen/compiler_bison.cpp"
    break;

  case 53: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 595 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_class_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-4].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2122 "src-gen/compiler_bison.cpp"
    break;

  case 54: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 607 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_l (for class_def_raw)");
                LOG_ASTNODE("t_bracket_parentheses_r (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_class_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-5].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2138 "src-gen/compiler_bison.cpp"
    break;

  case 55: /* while_stmt: t_keyword_while _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 621 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_while (for while_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for while_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_while_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2151 "src-gen/compiler_bison.cpp"
    break;

  case 56: /* while_stmt: t_keyword_while _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 630 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_while (for while_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for while_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_while_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2164 "src-gen/compiler_bison.cpp"
    break;

  case 57: /* for_stmt: t_keyword_for _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 641 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_for (for for_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for for_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_for_block);
                if ((yyvsp[-2].astnode_ptr)->type != astnode_type::list_op_comparison || (yyvsp[-2].astnode_ptr)->sons.size() != 2 || (yyvsp[-2].astnode_ptr)->sons[1]->type !=  astnode_type::comp_op_in) {
                    yyerror(ast_head, "for statment must use `in` expression");
                }
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr)->sons[0]);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-2].astnode_ptr)->sons[1]);
                delete_astnode((yyvsp[-2].astnode_ptr)->sons[1]);
                delete_astnode((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2183 "src-gen/compiler_bison.cpp"
    break;

  case 58: /* for_stmt: t_keyword_for _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 656 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_for (for for_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for for_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_for_block);
                if ((yyvsp[-3].astnode_ptr)->type != astnode_type::list_op_comparison || (yyvsp[-3].astnode_ptr)->sons.size() != 2 || (yyvsp[-3].astnode_ptr)->sons[1]->type !=  astnode_type::comp_op_in) {
                    yyerror(ast_head, "for statment must use `in` expression");
                }
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr)->sons[0]);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-3].astnode_ptr)->sons[1]);
                delete_astnode((yyvsp[-3].astnode_ptr)->sons[1]);
                delete_astnode((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2202 "src-gen/compiler_bison.cpp"
    break;

  case 59: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt  */
#line 673 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2215 "src-gen/compiler_bison.cpp"
    break;

  case 60: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 682 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2228 "src-gen/compiler_bison.cpp"
    break;

  case 61: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 691 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2241 "src-gen/compiler_bison.cpp"
    break;

  case 62: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt  */
#line 702 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2254 "src-gen/compiler_bison.cpp"
    break;

  case 63: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 711 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2267 "src-gen/compiler_bison.cpp"
    break;

  case 64: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 720 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2280 "src-gen/compiler_bison.cpp"
    break;

  case 65: /* else_block: t_keyword_else t_delimiter_colon block  */
#line 731 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_else (for else_block)");
                LOG_ASTNODE("t_delimiter_colon (for else_block)");
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr);
            }
#line 2290 "src-gen/compiler_bison.cpp"
    break;

  case 66: /* block: t_newline t_indent statements t_dedent  */
#line 739 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for block)");
                LOG_ASTNODE("t_indent (for block)");
                LOG_ASTNODE("t_dedent (for block)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2301 "src-gen/compiler_bison.cpp"
    break;

  case 72: /* yield_expr: t_keyword_yield  */
#line 799 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2311 "src-gen/compiler_bison.cpp"
    break;

  case 73: /* yield_expr: t_keyword_yield _normal_multiple_or_single_expr  */
#line 805 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2321 "src-gen/compiler_bison.cpp"
    break;

  case 74: /* yield_expr: t_keyword_yield t_keyword_from _normal_multiple_or_single_expr  */
#line 811 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                LOG_ASTNODE("t_keyword_from (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield_from);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2332 "src-gen/compiler_bison.cpp"
    break;

  case 78: /* _tuple_like_multiple_or_single_expr: _no_endcomma_multiple_expressions t_delimiter_comma  */
#line 825 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2341 "src-gen/compiler_bison.cpp"
    break;

  case 79: /* _tuple_like_multiple_or_single_expr: _normal_single_expression t_delimiter_comma  */
#line 830 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2351 "src-gen/compiler_bison.cpp"
    break;

  case 80: /* _no_endcomma_multiple_expressions: _normal_single_expression t_delimiter_comma _normal_single_expression  */
#line 838 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2362 "src-gen/compiler_bison.cpp"
    break;

  case 81: /* _no_endcomma_multiple_expressions: _no_endcomma_multiple_expressions t_delimiter_comma _normal_single_expression  */
#line 845 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2371 "src-gen/compiler_bison.cpp"
    break;

  case 84: /* star_expression: t_operators_mul _expression_if_else  */
#line 856 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for star_expression)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_star);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2381 "src-gen/compiler_bison.cpp"
    break;

  case 86: /* _expression_if_else: _disjunction_or_just_conjunction t_keyword_if _disjunction_or_just_conjunction t_keyword_else _expression_if_else  */
#line 865 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_expr);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2392 "src-gen/compiler_bison.cpp"
    break;

  case 89: /* disjunction: _conjunction_or_just_inversion t_keyword_or _conjunction_or_just_inversion  */
#line 879 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2403 "src-gen/compiler_bison.cpp"
    break;

  case 90: /* disjunction: disjunction t_keyword_or _conjunction_or_just_inversion  */
#line 886 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2412 "src-gen/compiler_bison.cpp"
    break;

  case 93: /* conjunction: inversion t_keyword_and inversion  */
#line 897 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2423 "src-gen/compiler_bison.cpp"
    break;

  case 94: /* conjunction: conjunction t_keyword_and inversion  */
#line 904 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2432 "src-gen/compiler_bison.cpp"
    break;

  case 96: /* inversion: t_keyword_not inversion  */
#line 912 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for inversion)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_not);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2442 "src-gen/compiler_bison.cpp"
    break;

  case 99: /* comparison: bitwise_or compare_op_bitwise_or_pair  */
#line 924 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_comparison);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2452 "src-gen/compiler_bison.cpp"
    break;

  case 100: /* comparison: comparison compare_op_bitwise_or_pair  */
#line 930 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2460 "src-gen/compiler_bison.cpp"
    break;

  case 101: /* compare_op_bitwise_or_pair: t_operators_eq bitwise_or  */
#line 936 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_eq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_eq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2470 "src-gen/compiler_bison.cpp"
    break;

  case 102: /* compare_op_bitwise_or_pair: t_operators_neq bitwise_or  */
#line 942 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_neq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_neq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2480 "src-gen/compiler_bison.cpp"
    break;

  case 103: /* compare_op_bitwise_or_pair: t_operators_leq bitwise_or  */
#line 948 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_leq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_leq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2490 "src-gen/compiler_bison.cpp"
    break;

  case 104: /* compare_op_bitwise_or_pair: t_operators_lt bitwise_or  */
#line 954 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_lt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_lt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2500 "src-gen/compiler_bison.cpp"
    break;

  case 105: /* compare_op_bitwise_or_pair: t_operators_geq bitwise_or  */
#line 960 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_geq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_geq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2510 "src-gen/compiler_bison.cpp"
    break;

  case 106: /* compare_op_bitwise_or_pair: t_operators_gt bitwise_or  */
#line 966 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_gt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_gt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2520 "src-gen/compiler_bison.cpp"
    break;

  case 107: /* compare_op_bitwise_or_pair: t_keyword_not t_keyword_in bitwise_or  */
#line 972 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_notin);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2531 "src-gen/compiler_bison.cpp"
    break;

  case 108: /* compare_op_bitwise_or_pair: t_keyword_in bitwise_or  */
#line 979 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_in);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2541 "src-gen/compiler_bison.cpp"
    break;

  case 109: /* compare_op_bitwise_or_pair: t_keyword_is t_keyword_not bitwise_or  */
#line 985 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_isnot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2552 "src-gen/compiler_bison.cpp"
    break;

  case 110: /* compare_op_bitwise_or_pair: t_keyword_is bitwise_or  */
#line 992 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_is);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2562 "src-gen/compiler_bison.cpp"
    break;

  case 112: /* bitwise_or: bitwise_or t_operators_or bitwise_xor  */
#line 1001 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_or (for bitwise_or)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2573 "src-gen/compiler_bison.cpp"
    break;

  case 114: /* bitwise_xor: bitwise_xor t_operators_xor bitwise_and  */
#line 1011 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_xor (for bitwise_xor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_xor);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2584 "src-gen/compiler_bison.cpp"
    break;

  case 116: /* bitwise_and: bitwise_and t_operators_and shift_expr  */
#line 1021 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_and (for bitwise_and)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2595 "src-gen/compiler_bison.cpp"
    break;

  case 118: /* shift_expr: shift_expr t_operators_sleft sum  */
#line 1031 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sleft (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sleft);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2606 "src-gen/compiler_bison.cpp"
    break;

  case 119: /* shift_expr: shift_expr t_operators_sright sum  */
#line 1038 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sright (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sright);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2617 "src-gen/compiler_bison.cpp"
    break;

  case 121: /* sum: sum t_operators_add term  */
#line 1048 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_add);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2628 "src-gen/compiler_bison.cpp"
    break;

  case 122: /* sum: sum t_operators_sub term  */
#line 1055 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sub);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2639 "src-gen/compiler_bison.cpp"
    break;

  case 124: /* term: term t_operators_mul factor  */
#line 1065 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mul);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2650 "src-gen/compiler_bison.cpp"
    break;

  case 125: /* term: term t_operators_div factor  */
#line 1072 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_div (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_div);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2661 "src-gen/compiler_bison.cpp"
    break;

  case 126: /* term: term t_operators_ediv factor  */
#line 1079 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_ediv (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_ediv);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2672 "src-gen/compiler_bison.cpp"
    break;

  case 127: /* term: term t_operators_mod factor  */
#line 1086 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mod (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mod);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2683 "src-gen/compiler_bison.cpp"
    break;

  case 128: /* term: term t_operators_at factor  */
#line 1093 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_at (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_at);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2694 "src-gen/compiler_bison.cpp"
    break;

  case 130: /* factor: t_operators_add factor  */
#line 1103 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_positive);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2704 "src-gen/compiler_bison.cpp"
    break;

  case 131: /* factor: t_operators_sub factor  */
#line 1109 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_negative);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2714 "src-gen/compiler_bison.cpp"
    break;

  case 132: /* factor: t_operators_not factor  */
#line 1115 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_not (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_wavenot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2724 "src-gen/compiler_bison.cpp"
    break;

  case 134: /* power: await_primary t_operators_pow factor  */
#line 1124 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for power)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_power);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2735 "src-gen/compiler_bison.cpp"
    break;

  case 136: /* await_primary: t_keyword_await primary  */
#line 1134 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_await (for await_primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_await);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2745 "src-gen/compiler_bison.cpp"
    break;

  case 138: /* primary: primary t_delimiter_dot t_identifier  */
#line 1143 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_dot (for primary)");
                LOG_ASTNODE("t_identifier (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_dot);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom));
            }
#line 2757 "src-gen/compiler_bison.cpp"
    break;

  case 139: /* primary: primary t_bracket_parentheses_l t_bracket_parentheses_r  */
#line 1151 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2769 "src-gen/compiler_bison.cpp"
    break;

  case 140: /* primary: primary t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r  */
#line 1159 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2781 "src-gen/compiler_bison.cpp"
    break;

  case 141: /* primary: primary t_bracket_square_l slice t_bracket_square_r  */
#line 1167 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_index);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2793 "src-gen/compiler_bison.cpp"
    break;

  case 142: /* primary: primary t_bracket_square_l _normal_multiple_or_single_expr t_bracket_square_r  */
#line 1175 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_index);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2805 "src-gen/compiler_bison.cpp"
    break;

  case 143: /* atom: t_identifier  */
#line 1185 "src/parser.y"
            {
                LOG_ASTNODE("t_identifier (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2814 "src-gen/compiler_bison.cpp"
    break;

  case 144: /* atom: t_keyword_True  */
#line 1190 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_True (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2823 "src-gen/compiler_bison.cpp"
    break;

  case 145: /* atom: t_keyword_False  */
#line 1195 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_False (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2832 "src-gen/compiler_bison.cpp"
    break;

  case 146: /* atom: t_keyword_None  */
#line 1200 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_None (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2841 "src-gen/compiler_bison.cpp"
    break;

  case 147: /* atom: t_keyword___in  */
#line 1205 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword___in (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2850 "src-gen/compiler_bison.cpp"
    break;

  case 148: /* atom: t_keyword___out  */
#line 1210 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword___out (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2859 "src-gen/compiler_bison.cpp"
    break;

  case 149: /* atom: t_keyword_underline  */
#line 1215 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_underline (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2868 "src-gen/compiler_bison.cpp"
    break;

  case 150: /* atom: t_number  */
#line 1220 "src/parser.y"
            {
                LOG_ASTNODE("t_number (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2877 "src-gen/compiler_bison.cpp"
    break;

  case 151: /* atom: t_delimiter_3dot  */
#line 1225 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2886 "src-gen/compiler_bison.cpp"
    break;

  case 156: /* atom: t_bracket_parentheses_l yield_expr t_bracket_parentheses_r  */
#line 1234 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2896 "src-gen/compiler_bison.cpp"
    break;

  case 157: /* atom: t_bracket_parentheses_l _normal_multiple_or_single_expr t_bracket_parentheses_r  */
#line 1240 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2906 "src-gen/compiler_bison.cpp"
    break;

  case 158: /* list: t_bracket_square_l t_bracket_square_r  */
#line 1252 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
            }
#line 2916 "src-gen/compiler_bison.cpp"
    break;

  case 159: /* list: t_bracket_square_l _tuple_like_multiple_or_single_expr t_bracket_square_r  */
#line 1258 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                delete_astnode((yyvsp[-1].astnode_ptr));
            }
#line 2928 "src-gen/compiler_bison.cpp"
    break;

  case 160: /* list: t_bracket_square_l _normal_single_expression t_bracket_square_r  */
#line 1266 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2939 "src-gen/compiler_bison.cpp"
    break;

  case 161: /* tuple: t_bracket_parentheses_l t_bracket_parentheses_r  */
#line 1275 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_tuple);
            }
#line 2949 "src-gen/compiler_bison.cpp"
    break;

  case 162: /* tuple: t_bracket_parentheses_l _tuple_like_multiple_or_single_expr t_bracket_parentheses_r  */
#line 1281 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_delimiter_comma (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_tuple);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                delete_astnode((yyvsp[-1].astnode_ptr));
            }
#line 2962 "src-gen/compiler_bison.cpp"
    break;

  case 163: /* set: t_bracket_curly_l t_bracket_curly_r  */
#line 1292 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_curly_l (for set)");
                LOG_ASTNODE("t_bracket_curly_r (for set)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
            }
#line 2972 "src-gen/compiler_bison.cpp"
    break;

  case 164: /* set: t_bracket_curly_l _tuple_like_multiple_or_single_expr t_bracket_curly_r  */
#line 1298 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                delete_astnode((yyvsp[-1].astnode_ptr));
            }
#line 2984 "src-gen/compiler_bison.cpp"
    break;

  case 165: /* set: t_bracket_curly_l _normal_single_expression t_bracket_curly_r  */
#line 1306 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2995 "src-gen/compiler_bison.cpp"
    break;

  case 166: /* slice: t_delimiter_colon  */
#line 1315 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3007 "src-gen/compiler_bison.cpp"
    break;

  case 167: /* slice: t_delimiter_colon _normal_single_expression  */
#line 1323 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3019 "src-gen/compiler_bison.cpp"
    break;

  case 168: /* slice: _normal_single_expression t_delimiter_colon  */
#line 1331 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3031 "src-gen/compiler_bison.cpp"
    break;

  case 169: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1339 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3043 "src-gen/compiler_bison.cpp"
    break;

  case 170: /* slice: t_delimiter_colon t_delimiter_colon  */
#line 1347 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3056 "src-gen/compiler_bison.cpp"
    break;

  case 171: /* slice: t_delimiter_colon t_delimiter_colon _normal_single_expression  */
#line 1356 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3069 "src-gen/compiler_bison.cpp"
    break;

  case 172: /* slice: t_delimiter_colon _normal_single_expression t_delimiter_colon  */
#line 1365 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3082 "src-gen/compiler_bison.cpp"
    break;

  case 173: /* slice: t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1374 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3095 "src-gen/compiler_bison.cpp"
    break;

  case 174: /* slice: _normal_single_expression t_delimiter_colon t_delimiter_colon  */
#line 1383 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3108 "src-gen/compiler_bison.cpp"
    break;

  case 175: /* slice: _normal_single_expression t_delimiter_colon t_delimiter_colon _normal_single_expression  */
#line 1392 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3121 "src-gen/compiler_bison.cpp"
    break;

  case 176: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon  */
#line 1401 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 3134 "src-gen/compiler_bison.cpp"
    break;

  case 177: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1410 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3147 "src-gen/compiler_bison.cpp"
    break;

  case 178: /* strings: string_text  */
#line 1421 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_strings);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3156 "src-gen/compiler_bison.cpp"
    break;

  case 179: /* strings: strings string_text  */
#line 1426 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3164 "src-gen/compiler_bison.cpp"
    break;

  case 180: /* string_text: t_bracket_dquotes t_strtext t_bracket_dquotes  */
#line 1432 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 3175 "src-gen/compiler_bison.cpp"
    break;

  case 181: /* string_text: t_bracket_squotes t_strtext t_bracket_squotes  */
#line 1439 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 3186 "src-gen/compiler_bison.cpp"
    break;

  case 183: /* arguments_or_parameters: argparas t_delimiter_comma  */
#line 1449 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for arguments_or_parameters)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 3195 "src-gen/compiler_bison.cpp"
    break;

  case 184: /* argparas: argpara  */
#line 1456 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_args_or_prams);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3204 "src-gen/compiler_bison.cpp"
    break;

  case 185: /* argparas: argparas t_delimiter_comma argpara  */
#line 1461 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for argparas)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3213 "src-gen/compiler_bison.cpp"
    break;

  case 187: /* argpara: primary t_delimiter_colon primary  */
#line 1469 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_aptype);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3224 "src-gen/compiler_bison.cpp"
    break;

  case 188: /* argpara: t_operators_mul _normal_single_expression  */
#line 1476 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3234 "src-gen/compiler_bison.cpp"
    break;

  case 189: /* argpara: t_operators_pow _normal_single_expression  */
#line 1482 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apdstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3244 "src-gen/compiler_bison.cpp"
    break;

  case 190: /* argpara: primary t_operators_assign _normal_single_expression  */
#line 1488 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_apequ);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3255 "src-gen/compiler_bison.cpp"
    break;

  case 191: /* argpara: primary t_delimiter_colon primary t_operators_assign _normal_single_expression  */
#line 1495 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                LOG_ASTNODE("t_operators_assign (for argpara)");
                auto r = make_astnode(astnode_type::bin_op_aptype);
                r->eat((yyvsp[-4].astnode_ptr));
                r->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_apequ);
                (yyval.astnode_ptr)->eat(r);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3270 "src-gen/compiler_bison.cpp"
    break;

  case 192: /* ast_error: t_error  */
#line 1511 "src/parser.y"
                  { GEN_ERROR_NODE("t_error (for ast_error)", (yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3276 "src-gen/compiler_bison.cpp"
    break;

  case 193: /* ast_error: t_keyword_lambda  */
#line 1581 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3282 "src-gen/compiler_bison.cpp"
    break;

  case 194: /* ast_error: t_keyword_match  */
#line 1590 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3288 "src-gen/compiler_bison.cpp"
    break;

  case 195: /* ast_error: t_keyword_case  */
#line 1591 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3294 "src-gen/compiler_bison.cpp"
    break;

  case 196: /* ast_error: t_keyword_global  */
#line 1592 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3300 "src-gen/compiler_bison.cpp"
    break;

  case 197: /* ast_error: t_keyword_nonlocal  */
#line 1593 "src/parser.y"
                             { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3306 "src-gen/compiler_bison.cpp"
    break;

  case 198: /* ast_error: t_keyword_del  */
#line 1594 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3312 "src-gen/compiler_bison.cpp"
    break;

  case 199: /* ast_error: t_keyword_import  */
#line 1595 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3318 "src-gen/compiler_bison.cpp"
    break;

  case 200: /* ast_error: t_keyword_from  */
#line 1596 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3324 "src-gen/compiler_bison.cpp"
    break;

  case 201: /* ast_error: t_keyword_as  */
#line 1597 "src/parser.y"
                       { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3330 "src-gen/compiler_bison.cpp"
    break;

  case 202: /* ast_error: t_keyword_raise  */
#line 1598 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3336 "src-gen/compiler_bison.cpp"
    break;

  case 203: /* ast_error: t_keyword_try  */
#line 1599 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3342 "src-gen/compiler_bison.cpp"
    break;

  case 204: /* ast_error: t_keyword_except  */
#line 1600 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3348 "src-gen/compiler_bison.cpp"
    break;

  case 205: /* ast_error: t_keyword_finally  */
#line 1601 "src/parser.y"
                            { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3354 "src-gen/compiler_bison.cpp"
    break;

  case 206: /* ast_error: t_keyword_assert  */
#line 1602 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3360 "src-gen/compiler_bison.cpp"
    break;


#line 3364 "src-gen/compiler_bison.cpp"

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
      yyerror (ast_head, YY_("syntax error"));
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
                      yytoken, &yylval, ast_head);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast_head);
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
  yyerror (ast_head, YY_("memory exhausted"));
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
                  yytoken, &yylval, ast_head);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast_head);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1606 "src/parser.y"


void yyerror(AstNode*& ast_head, char* msg)
{
    stdlog::log << stdlog::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << stdlog::endl;
}
