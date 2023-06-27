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
  YYSYMBOL_t_keyword_if = 75,              /* t_keyword_if  */
  YYSYMBOL_t_keyword_else = 76,            /* t_keyword_else  */
  YYSYMBOL_t_keyword_elif = 77,            /* t_keyword_elif  */
  YYSYMBOL_t_keyword_for = 78,             /* t_keyword_for  */
  YYSYMBOL_t_keyword_break = 79,           /* t_keyword_break  */
  YYSYMBOL_t_keyword_continue = 80,        /* t_keyword_continue  */
  YYSYMBOL_t_keyword_match = 81,           /* t_keyword_match  */
  YYSYMBOL_t_keyword_case = 82,            /* t_keyword_case  */
  YYSYMBOL_t_keyword_global = 83,          /* t_keyword_global  */
  YYSYMBOL_t_keyword_nonlocal = 84,        /* t_keyword_nonlocal  */
  YYSYMBOL_t_keyword_del = 85,             /* t_keyword_del  */
  YYSYMBOL_t_keyword_import = 86,          /* t_keyword_import  */
  YYSYMBOL_t_keyword_from = 87,            /* t_keyword_from  */
  YYSYMBOL_t_keyword_as = 88,              /* t_keyword_as  */
  YYSYMBOL_t_keyword_raise = 89,           /* t_keyword_raise  */
  YYSYMBOL_t_keyword_try = 90,             /* t_keyword_try  */
  YYSYMBOL_t_keyword_except = 91,          /* t_keyword_except  */
  YYSYMBOL_t_keyword_finally = 92,         /* t_keyword_finally  */
  YYSYMBOL_t_keyword_assert = 93,          /* t_keyword_assert  */
  YYSYMBOL_t_keyword_tastror_out = 94,     /* t_keyword_tastror_out  */
  YYSYMBOL_YYACCEPT = 95,                  /* $accept  */
  YYSYMBOL_file = 96,                      /* file  */
  YYSYMBOL_statements = 97,                /* statements  */
  YYSYMBOL_simple_stmts = 98,              /* simple_stmts  */
  YYSYMBOL__no_newline_simple_stmt = 99,   /* _no_newline_simple_stmt  */
  YYSYMBOL_simple_stmt = 100,              /* simple_stmt  */
  YYSYMBOL_assignment = 101,               /* assignment  */
  YYSYMBOL__no_type_assign = 102,          /* _no_type_assign  */
  YYSYMBOL_augassign = 103,                /* augassign  */
  YYSYMBOL_compound_stmt = 104,            /* compound_stmt  */
  YYSYMBOL_function_def = 105,             /* function_def  */
  YYSYMBOL_function_def_raw = 106,         /* function_def_raw  */
  YYSYMBOL_class_def = 107,                /* class_def  */
  YYSYMBOL_class_def_raw = 108,            /* class_def_raw  */
  YYSYMBOL_if_stmt = 109,                  /* if_stmt  */
  YYSYMBOL_elif_stmt = 110,                /* elif_stmt  */
  YYSYMBOL_else_block = 111,               /* else_block  */
  YYSYMBOL_block = 112,                    /* block  */
  YYSYMBOL_expressions_type = 113,         /* expressions_type  */
  YYSYMBOL_expressions_lhs = 114,          /* expressions_lhs  */
  YYSYMBOL_expressions_rhs = 115,          /* expressions_rhs  */
  YYSYMBOL_yield_expr = 116,               /* yield_expr  */
  YYSYMBOL__normal_multiple_or_single_expr = 117, /* _normal_multiple_or_single_expr  */
  YYSYMBOL__tuple_like_multiple_or_single_expr = 118, /* _tuple_like_multiple_or_single_expr  */
  YYSYMBOL__no_endcomma_multiple_expressions = 119, /* _no_endcomma_multiple_expressions  */
  YYSYMBOL__normal_single_expression = 120, /* _normal_single_expression  */
  YYSYMBOL_star_expression = 121,          /* star_expression  */
  YYSYMBOL__expression_if_else = 122,      /* _expression_if_else  */
  YYSYMBOL__disjunction_or_just_conjunction = 123, /* _disjunction_or_just_conjunction  */
  YYSYMBOL_disjunction = 124,              /* disjunction  */
  YYSYMBOL__conjunction_or_just_inversion = 125, /* _conjunction_or_just_inversion  */
  YYSYMBOL_conjunction = 126,              /* conjunction  */
  YYSYMBOL_inversion = 127,                /* inversion  */
  YYSYMBOL__comparison_or_just_bitwise_or = 128, /* _comparison_or_just_bitwise_or  */
  YYSYMBOL_comparison = 129,               /* comparison  */
  YYSYMBOL_compare_op_bitwise_or_pair = 130, /* compare_op_bitwise_or_pair  */
  YYSYMBOL_bitwise_or = 131,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 132,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 133,              /* bitwise_and  */
  YYSYMBOL_shift_expr = 134,               /* shift_expr  */
  YYSYMBOL_sum = 135,                      /* sum  */
  YYSYMBOL_term = 136,                     /* term  */
  YYSYMBOL_factor = 137,                   /* factor  */
  YYSYMBOL_power = 138,                    /* power  */
  YYSYMBOL_await_primary = 139,            /* await_primary  */
  YYSYMBOL_primary = 140,                  /* primary  */
  YYSYMBOL_atom = 141,                     /* atom  */
  YYSYMBOL_list = 142,                     /* list  */
  YYSYMBOL_tuple = 143,                    /* tuple  */
  YYSYMBOL_set = 144,                      /* set  */
  YYSYMBOL_slice = 145,                    /* slice  */
  YYSYMBOL_strings = 146,                  /* strings  */
  YYSYMBOL_string_text = 147,              /* string_text  */
  YYSYMBOL_arguments_or_parameters = 148,  /* arguments_or_parameters  */
  YYSYMBOL_argparas = 149,                 /* argparas  */
  YYSYMBOL_argpara = 150,                  /* argpara  */
  YYSYMBOL_ast_error = 151                 /* ast_error  */
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
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  310

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   349


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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   336,   336,   342,   348,   353,   358,   368,   373,   379,
     386,   391,   399,   400,   405,   410,   415,   416,   417,   418,
     424,   439,   440,   448,   457,   467,   475,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   505,   506,   507,   510,   517,   530,   543,   557,   573,
     580,   590,   602,   616,   625,   634,   645,   654,   663,   674,
     682,   689,   720,   723,   726,   727,   742,   748,   754,   763,
     764,   767,   768,   773,   781,   788,   795,   798,   799,   807,
     808,   818,   819,   822,   829,   836,   837,   840,   847,   854,
     855,   863,   864,   867,   873,   879,   885,   891,   897,   903,
     909,   915,   922,   928,   935,   943,   944,   953,   954,   963,
     964,   973,   974,   981,   990,   991,   998,  1007,  1008,  1015,
    1022,  1029,  1036,  1045,  1046,  1052,  1058,  1066,  1067,  1076,
    1077,  1085,  1086,  1094,  1102,  1110,  1118,  1128,  1133,  1138,
    1143,  1148,  1153,  1158,  1163,  1164,  1165,  1166,  1167,  1173,
    1185,  1191,  1199,  1208,  1214,  1225,  1231,  1239,  1248,  1256,
    1264,  1272,  1280,  1289,  1298,  1307,  1316,  1325,  1334,  1343,
    1354,  1359,  1365,  1372,  1381,  1382,  1389,  1394,  1401,  1402,
    1409,  1415,  1421,  1428,  1445,  1515,  1520,  1523,  1524,  1525,
    1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,
    1536
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
  "t_keyword_lambda", "t_keyword_await", "t_keyword_if", "t_keyword_else",
  "t_keyword_elif", "t_keyword_for", "t_keyword_break",
  "t_keyword_continue", "t_keyword_match", "t_keyword_case",
  "t_keyword_global", "t_keyword_nonlocal", "t_keyword_del",
  "t_keyword_import", "t_keyword_from", "t_keyword_as", "t_keyword_raise",
  "t_keyword_try", "t_keyword_except", "t_keyword_finally",
  "t_keyword_assert", "t_keyword_tastror_out", "$accept", "file",
  "statements", "simple_stmts", "_no_newline_simple_stmt", "simple_stmt",
  "assignment", "_no_type_assign", "augassign", "compound_stmt",
  "function_def", "function_def_raw", "class_def", "class_def_raw",
  "if_stmt", "elif_stmt", "else_block", "block", "expressions_type",
  "expressions_lhs", "expressions_rhs", "yield_expr",
  "_normal_multiple_or_single_expr", "_tuple_like_multiple_or_single_expr",
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

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     392,  -175,  -175,  -175,  -175,  -175,     5,    13,   664,   826,
     847,   172,   172,  1150,   172,  -175,  -175,  -175,  -175,  1150,
    -175,    30,  1090,    16,    59,  -175,    89,  1090,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,    72,   392,  -175,    31,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    40,  -175,
      44,  -175,    64,    82,  -175,  -175,    27,    48,    56,    69,
      78,  -175,   289,    95,    88,   123,    43,    58,    42,  -175,
    -175,   134,  1202,  -175,  -175,  -175,  -175,    70,  -175,  -175,
     149,   150,  -175,   147,   151,   152,    29,  -175,   148,     8,
    -175,   153,     7,  -175,  -175,  -175,  -175,  -175,   156,  -175,
    1090,  -175,     1,    29,   164,  -175,  -175,  -175,  -175,   484,
     907,  1090,  1090,  1150,  1150,  1150,  1150,  1150,   172,   172,
     172,   172,   172,   172,   110,  1171,   172,  -175,   172,  -175,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,    89,   171,   685,   928,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
     907,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   745,  -175,   576,   766,   576,  -175,  -175,  -175,  -175,
    -175,    44,  -175,  -175,   106,  -175,  -175,  -175,  -175,   158,
     158,   158,   158,   158,   158,   172,   172,   158,   158,    88,
     123,    43,    58,    58,    42,    42,  -175,  -175,  -175,  -175,
    -175,  -175,   142,    29,  -175,  -175,  1090,  1090,  -175,    47,
     174,   185,  -175,   988,   177,    84,   179,  -175,  -175,    87,
     182,   198,  -175,  -175,   193,   186,    24,  1150,   158,   158,
     907,  -175,  -175,  -175,    89,  1090,  -175,  1009,  1090,   195,
    -175,  1069,  -175,   576,  1090,   105,   392,   576,   197,   199,
    1090,  -175,  -175,  -175,  -175,    -5,  -175,  -175,  -175,  1090,
    1090,   200,  -175,   201,   576,  1090,   300,  -175,   576,   576,
     202,  1090,  -175,  -175,  1090,   576,  -175,   203,  -175,  -175,
    -175,   576,  -175,  -175,  -175,   576,    24,  -175,  -175,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   184,     9,   137,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   140,   138,   139,     0,
      13,     0,    19,    66,     0,   185,     0,     0,   186,    14,
      15,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     2,     3,     0,    10,
      16,    21,     4,    41,    44,    42,    49,    43,     0,    18,
      17,    69,    71,    70,    76,    77,    79,    82,    81,    86,
      85,    89,    92,    91,   105,   107,   109,   111,   114,   117,
     123,   127,   129,   131,   144,   145,   146,   147,   170,    12,
       0,     0,   153,     0,     0,     0,   129,   150,     0,     0,
     155,     0,     0,   124,   125,    78,   126,    90,     0,    20,
       0,    67,     0,   130,     0,     1,     5,     6,     7,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,   171,   173,   172,   148,   149,   154,   151,   152,   156,
     157,     0,    68,     0,     0,     0,     8,    11,    26,    25,
      65,    64,    75,    74,     0,    84,    83,    88,    87,    95,
      96,    97,    99,    98,   100,     0,     0,   104,   102,   106,
     108,   110,   112,   113,   115,   116,   118,   119,   120,   121,
     122,   128,    22,    62,   132,   133,     0,     0,   178,   129,
       0,   174,   176,   158,     0,    70,     0,    24,    64,     0,
       0,     9,    61,    50,     0,     0,    54,     0,   101,   103,
       0,   180,    77,   181,     0,     0,   134,   175,   162,   159,
     136,   160,   135,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    55,    80,    23,   179,   182,   177,   163,   164,
     166,   161,    45,     0,     0,     0,     0,    51,     0,     0,
       0,     0,   165,   167,   168,     0,    46,     0,    60,    52,
      59,     0,   183,   169,    47,     0,    57,    48,    56,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,   -57,     4,  -175,    96,  -175,    97,  -175,   -44,
    -175,  -175,  -175,  -175,  -175,   -88,   -87,  -174,  -175,  -175,
    -165,    -7,    -2,    54,  -175,    18,  -175,   -10,    98,  -175,
      32,  -175,    -3,  -175,  -175,   154,   -76,    85,    80,    81,
     -17,    14,    -4,  -175,  -175,     0,  -175,  -175,  -175,  -175,
    -175,  -175,   137,  -136,  -175,   -32,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    45,    46,   242,    48,    49,    50,    51,   170,    52,
      53,    54,    55,    56,    57,   271,   272,   243,   222,    58,
     189,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   137,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    96,    83,    84,    85,    86,
     236,    87,    88,   230,   231,   232,    89
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    93,   117,   105,    47,   237,    94,   103,   104,   153,
     106,   246,   183,   154,    90,   155,   107,   122,   122,   184,
     109,   111,    91,     3,     4,   114,   113,    99,   102,   178,
     180,     5,     6,     7,     8,   118,     9,   108,    10,   291,
      11,    12,    13,   153,   119,   240,    82,   154,   245,   155,
     116,    14,   199,   200,   201,   202,   203,   204,   254,   207,
     208,   153,    95,    98,   101,   154,   112,   155,   146,   147,
     148,   149,   115,   150,   121,    15,    16,    17,    18,   142,
     143,    19,   144,   145,   120,   274,     6,     7,   -63,   282,
      26,   255,   122,   287,   122,   261,     3,     4,   263,   264,
     269,   270,   123,   110,     5,     6,     7,     8,   182,     9,
     296,    10,   124,   190,   299,   300,   284,   285,   191,    82,
     125,   304,   140,   197,   198,   212,   213,   306,   138,   248,
     249,   307,   126,   128,   129,   130,   131,   132,   133,   192,
     193,   127,   216,   217,   218,   219,   220,   221,    15,    16,
      17,    18,   223,   234,   229,   141,   195,   196,   214,   215,
     134,   135,   136,   190,   151,   172,   174,   173,   238,   177,
     175,   176,   228,   235,   181,   185,   179,   205,   224,     3,
       4,   229,   247,    82,   229,    82,   250,     5,     6,     7,
       8,   138,     9,   256,    10,   257,    11,    12,   260,   228,
     262,   265,   228,   266,   267,   268,   279,    14,   288,   286,
     289,   294,   295,   301,   305,   187,   252,   188,   308,   309,
     210,   194,   211,   209,   171,   277,     0,   139,     0,     0,
       0,    15,    16,    17,    18,     0,     0,   273,     0,     0,
       0,     0,   117,   190,   251,   253,    26,     0,   238,     0,
       0,   259,     0,     0,   275,     0,     0,   229,     0,     0,
       0,     0,   283,    82,     0,     0,    82,    82,   290,     0,
      47,     0,     0,   276,     0,   228,   278,     0,     0,   281,
       0,     0,     0,   297,    82,     0,    82,     0,    82,    82,
     116,     0,     0,     0,     0,    82,     0,   292,   293,     0,
       0,    82,     0,     1,     2,    82,   298,     3,     4,   302,
       0,     0,   303,     0,     0,     5,     6,     7,     8,     0,
       9,     0,    10,     0,    11,    12,    13,   128,   129,   130,
     131,   132,   133,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,     0,    15,
      16,    17,    18,     0,     0,    19,     0,     0,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     1,     2,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     9,     0,    10,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     1,   186,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,     9,     0,    10,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
       0,     0,    20,     0,    22,    23,     0,    25,    26,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     1,
     241,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     0,     9,     0,    10,     0,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,    19,     0,     0,    20,     0,    22,    23,     0,    25,
      26,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     3,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,    92,     9,     0,    10,     0,    11,    12,
      13,     0,     3,     4,     0,     0,     0,     0,     0,    14,
       5,     6,     7,     8,   225,     9,     0,    10,     0,    11,
      12,   226,     0,     0,     0,   227,     0,     0,     0,     0,
      14,     0,     0,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,    23,     0,     0,    26,     0,
       0,     0,     0,     0,    15,    16,    17,    18,     0,     0,
      19,     0,     3,     4,     0,     0,     0,     0,     0,    26,
       5,     6,     7,     8,   239,     9,     0,    10,     0,    11,
      12,   226,     0,     3,     4,   227,     0,     0,     0,     0,
      14,     5,     6,     7,     8,   244,     9,     0,    10,     0,
      11,    12,   226,     0,     0,     0,   227,     0,     0,     0,
       0,    14,     0,     0,    15,    16,    17,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,    19,     0,     3,     4,     0,     0,     0,     0,     0,
      26,     5,     6,     7,     8,     0,     9,    97,    10,     0,
      11,    12,    13,     0,     3,     4,     0,     0,     0,     0,
       0,    14,     5,     6,     7,     8,     0,     9,     0,    10,
     100,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,    19,     0,     3,     4,     0,     0,     0,     0,
       0,    26,     5,     6,     7,     8,     0,     9,     0,    10,
       0,    11,    12,    13,     0,     3,     4,     0,     0,   233,
       0,     0,    14,     5,     6,     7,     8,     0,     9,     0,
      10,     0,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    16,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,    23,     0,
       0,    26,     0,     0,     0,     0,     0,    15,    16,    17,
      18,     0,     0,    19,     0,     3,     4,     0,     0,   258,
       0,     0,    26,     5,     6,     7,     8,     0,     9,     0,
      10,     0,    11,    12,    13,     0,     3,     4,     0,     0,
       0,     0,     0,    14,     5,     6,     7,     8,     0,     9,
       0,    10,     0,    11,    12,   226,     0,     0,     0,   227,
       0,     0,     0,     0,    14,     0,     0,    15,    16,    17,
      18,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,    15,    16,
      17,    18,     0,     0,    19,     0,     3,     4,     0,     0,
     280,     0,     0,    26,     5,     6,     7,     8,     0,     9,
       0,    10,     0,    11,    12,    13,     0,     3,     4,     0,
       0,     0,     0,     0,    14,     5,     6,     7,     8,     0,
       9,     0,    10,     0,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    15,
      16,    17,    18,     0,     0,    19,     0,     3,     4,     0,
       0,     0,     0,     0,    26,     5,     6,     7,     8,     0,
       9,     0,    10,     0,    11,    12,     0,     0,     3,     4,
       0,     0,     0,     0,     0,    14,     5,     6,     7,     8,
       0,     9,     0,    10,     0,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,   152,     0,    19,   153,     0,     0,     0,
     154,     0,   155,     0,    26,     0,     0,     0,     0,     0,
      15,    16,    17,    18,     0,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169
};

static const yytype_int16 yycheck[] =
{
       0,     8,    46,    13,     0,   170,     8,    11,    12,    14,
      14,   185,    11,    18,     9,    20,    19,    10,    10,    18,
      22,    23,     9,     7,     8,    27,    26,     9,    10,    21,
      23,    15,    16,    17,    18,     4,    20,     7,    22,    44,
      24,    25,    26,    14,    13,   181,    46,    18,   184,    20,
      46,    35,   128,   129,   130,   131,   132,   133,    11,   135,
     136,    14,     8,     9,    10,    18,     7,    20,    26,    27,
      28,    29,     0,    31,    10,    59,    60,    61,    62,    36,
      37,    65,    24,    25,    44,   250,    16,    17,    44,   263,
      74,    44,    10,   267,    10,    11,     7,     8,    11,    12,
      76,    77,    75,    87,    15,    16,    17,    18,   110,    20,
     284,    22,    64,   120,   288,   289,    11,    12,   120,   119,
      64,   295,    34,   126,   127,   142,   143,   301,    33,   205,
     206,   305,    63,    38,    39,    40,    41,    42,    43,   121,
     122,    63,   146,   147,   148,   149,   150,   151,    59,    60,
      61,    62,   152,   155,   154,    32,   124,   125,   144,   145,
      65,    66,    67,   170,    30,    16,    19,    17,   170,    21,
      19,    19,   154,   155,    18,    11,    23,    67,     7,     7,
       8,   181,    76,   183,   184,   185,    44,    15,    16,    17,
      18,    33,    20,    19,    22,    10,    24,    25,    21,   181,
      21,    19,   184,     5,    11,    19,    11,    35,    11,   266,
      11,    11,    11,    11,    11,   119,   226,   120,   306,   306,
     140,   123,   141,   138,    87,   257,    -1,    73,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,   247,    -1,    -1,
      -1,    -1,   286,   250,   226,   227,    74,    -1,   250,    -1,
      -1,   233,    -1,    -1,   254,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   264,   263,    -1,    -1,   266,   267,   270,    -1,
     266,    -1,    -1,   255,    -1,   257,   258,    -1,    -1,   261,
      -1,    -1,    -1,   285,   284,    -1,   286,    -1,   288,   289,
     286,    -1,    -1,    -1,    -1,   295,    -1,   279,   280,    -1,
      -1,   301,    -1,     3,     4,   305,     6,     7,     8,   291,
      -1,    -1,   294,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    26,    38,    39,    40,
      41,    42,    43,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     3,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     3,     4,    -1,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    68,    -1,    70,    71,    -1,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     3,
       4,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    68,    -1,    70,    71,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    35,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      65,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    74,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    26,    -1,     7,     8,    30,    -1,    -1,    -1,    -1,
      35,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      74,    15,    16,    17,    18,    -1,    20,    21,    22,    -1,
      24,    25,    26,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    35,    15,    16,    17,    18,    -1,    20,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    65,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    74,    15,    16,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    25,    26,    -1,     7,     8,    -1,    -1,    11,
      -1,    -1,    35,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    65,    -1,     7,     8,    -1,    -1,    11,
      -1,    -1,    74,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    24,    25,    26,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    35,    15,    16,    17,    18,    -1,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    65,    -1,     7,     8,    -1,    -1,
      11,    -1,    -1,    74,    15,    16,    17,    18,    -1,    20,
      -1,    22,    -1,    24,    25,    26,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    35,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    65,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    74,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    -1,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    35,    15,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    59,
      60,    61,    62,    11,    -1,    65,    14,    -1,    -1,    -1,
      18,    -1,    20,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,    15,    16,    17,    18,    20,
      22,    24,    25,    26,    35,    59,    60,    61,    62,    65,
      68,    69,    70,    71,    72,    73,    74,    75,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    96,    97,    98,    99,   100,
     101,   102,   104,   105,   106,   107,   108,   109,   114,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   146,   147,   151,
       9,     9,    19,   116,   117,   118,   140,    21,   118,   120,
      23,   118,   120,   137,   137,   122,   137,   127,     7,   117,
      87,   117,     7,   140,   117,     0,    98,   104,     4,    13,
      44,    10,    10,    75,    64,    64,    63,    63,    38,    39,
      40,    41,    42,    43,    65,    66,    67,   130,    33,   130,
      34,    32,    36,    37,    24,    25,    26,    27,    28,    29,
      31,    30,    11,    14,    18,    20,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     103,   147,    16,    17,    19,    19,    19,    21,    21,    23,
      23,    18,   117,    11,    18,    11,     4,   100,   102,   115,
     116,   117,   120,   120,   123,   125,   125,   127,   127,   131,
     131,   131,   131,   131,   131,    67,    65,   131,   131,   132,
     133,   134,   135,   135,   136,   136,   137,   137,   137,   137,
     137,   137,   113,   140,     7,    19,    26,    30,   120,   140,
     148,   149,   150,    11,   117,   120,   145,   115,   117,    19,
     148,     4,    98,   112,    19,   148,   112,    76,   131,   131,
      44,   120,   122,   120,    11,    44,    19,    10,    11,   120,
      21,    11,    21,    11,    12,    19,     5,    11,    19,    76,
      77,   110,   111,   122,   115,   140,   120,   150,   120,    11,
      11,   120,   112,   117,    11,    12,    97,   112,    11,    11,
     117,    44,   120,   120,    11,    11,   112,   117,     6,   112,
     112,    11,   120,   120,   112,    11,   112,   112,   110,   111
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    97,    97,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   106,   106,   106,   106,   107,
     108,   108,   108,   109,   109,   109,   110,   110,   110,   111,
     112,   112,   113,   114,   115,   115,   116,   116,   116,   117,
     117,   118,   118,   118,   119,   119,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   135,   135,   135,   136,   136,   136,
     136,   136,   136,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   142,   142,   143,   143,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     5,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     7,     8,     9,     1,
       4,     6,     7,     5,     4,     5,     5,     4,     5,     3,
       4,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     2,     2,     3,     3,     1,     1,     2,     1,
       5,     1,     1,     3,     3,     1,     1,     3,     3,     1,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     3,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     1,     2,     2,     2,     1,     3,     1,
       2,     1,     3,     3,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     3,     2,     3,     3,     1,     2,
       2,     3,     2,     3,     3,     4,     3,     4,     4,     5,
       1,     2,     3,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 337 "src/parser.y"
            {
                ast_head = (yyvsp[0].astnode_ptr);
            }
#line 1678 "src-gen/compiler_bison.cpp"
    break;

  case 3: /* statements: simple_stmts  */
#line 343 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                remove_from_astnode_buff((yyvsp[0].astnode_ptr));
            }
#line 1688 "src-gen/compiler_bison.cpp"
    break;

  case 4: /* statements: compound_stmt  */
#line 349 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1697 "src-gen/compiler_bison.cpp"
    break;

  case 5: /* statements: statements simple_stmts  */
#line 354 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                remove_from_astnode_buff((yyvsp[0].astnode_ptr));
            }
#line 1706 "src-gen/compiler_bison.cpp"
    break;

  case 6: /* statements: statements compound_stmt  */
#line 359 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1714 "src-gen/compiler_bison.cpp"
    break;

  case 7: /* simple_stmts: _no_newline_simple_stmt t_newline  */
#line 369 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 1723 "src-gen/compiler_bison.cpp"
    break;

  case 8: /* simple_stmts: _no_newline_simple_stmt t_delimiter_semicolon t_newline  */
#line 374 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for simple_stmts)");
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
            }
#line 1733 "src-gen/compiler_bison.cpp"
    break;

  case 9: /* simple_stmts: t_newline  */
#line 380 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = make_empty_astnode();  // will be eat_sons by statements, which is just empty~
            }
#line 1742 "src-gen/compiler_bison.cpp"
    break;

  case 10: /* _no_newline_simple_stmt: simple_stmt  */
#line 387 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::temp);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1751 "src-gen/compiler_bison.cpp"
    break;

  case 11: /* _no_newline_simple_stmt: _no_newline_simple_stmt t_delimiter_semicolon simple_stmt  */
#line 392 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for _no_newline_simple_stmt)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1761 "src-gen/compiler_bison.cpp"
    break;

  case 13: /* simple_stmt: t_keyword_pass  */
#line 401 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_pass);
            }
#line 1770 "src-gen/compiler_bison.cpp"
    break;

  case 14: /* simple_stmt: t_keyword_break  */
#line 406 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_break);
            }
#line 1779 "src-gen/compiler_bison.cpp"
    break;

  case 15: /* simple_stmt: t_keyword_continue  */
#line 411 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_continue);
            }
#line 1788 "src-gen/compiler_bison.cpp"
    break;

  case 19: /* simple_stmt: t_keyword_return  */
#line 419 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1798 "src-gen/compiler_bison.cpp"
    break;

  case 20: /* simple_stmt: t_keyword_return _normal_multiple_or_single_expr  */
#line 425 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1808 "src-gen/compiler_bison.cpp"
    break;

  case 22: /* assignment: primary t_delimiter_colon expressions_type  */
#line 441 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1820 "src-gen/compiler_bison.cpp"
    break;

  case 23: /* assignment: primary t_delimiter_colon expressions_type t_operators_assign expressions_rhs  */
#line 449 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                LOG_ASTNODE("t_operators_assign (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1833 "src-gen/compiler_bison.cpp"
    break;

  case 24: /* assignment: primary augassign expressions_rhs  */
#line 458 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_augassign);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1844 "src-gen/compiler_bison.cpp"
    break;

  case 25: /* _no_type_assign: expressions_lhs t_operators_assign expressions_rhs  */
#line 468 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1856 "src-gen/compiler_bison.cpp"
    break;

  case 26: /* _no_type_assign: expressions_lhs t_operators_assign _no_type_assign  */
#line 476 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1868 "src-gen/compiler_bison.cpp"
    break;

  case 27: /* augassign: t_operators_add_assign  */
#line 485 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_add_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1874 "src-gen/compiler_bison.cpp"
    break;

  case 28: /* augassign: t_operators_sub_assign  */
#line 486 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sub_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1880 "src-gen/compiler_bison.cpp"
    break;

  case 29: /* augassign: t_operators_mul_assign  */
#line 487 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mul_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1886 "src-gen/compiler_bison.cpp"
    break;

  case 30: /* augassign: t_operators_div_assign  */
#line 488 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_div_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1892 "src-gen/compiler_bison.cpp"
    break;

  case 31: /* augassign: t_operators_ediv_assign  */
#line 489 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_ediv_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1898 "src-gen/compiler_bison.cpp"
    break;

  case 32: /* augassign: t_operators_mod_assign  */
#line 490 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mod_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1904 "src-gen/compiler_bison.cpp"
    break;

  case 33: /* augassign: t_operators_pow_assign  */
#line 491 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_pow_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1910 "src-gen/compiler_bison.cpp"
    break;

  case 34: /* augassign: t_operators_at_assign  */
#line 492 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_at_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1916 "src-gen/compiler_bison.cpp"
    break;

  case 35: /* augassign: t_operators_and_assign  */
#line 493 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_and_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1922 "src-gen/compiler_bison.cpp"
    break;

  case 36: /* augassign: t_operators_or_assign  */
#line 494 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_or_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1928 "src-gen/compiler_bison.cpp"
    break;

  case 37: /* augassign: t_operators_xor_assign  */
#line 495 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_xor_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1934 "src-gen/compiler_bison.cpp"
    break;

  case 38: /* augassign: t_operators_not_assign  */
#line 496 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_not_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1940 "src-gen/compiler_bison.cpp"
    break;

  case 39: /* augassign: t_operators_sleft_assign  */
#line 497 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sleft_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1946 "src-gen/compiler_bison.cpp"
    break;

  case 40: /* augassign: t_operators_sright_assign  */
#line 498 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sright_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1952 "src-gen/compiler_bison.cpp"
    break;

  case 44: /* function_def: function_def_raw  */
#line 511 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 1960 "src-gen/compiler_bison.cpp"
    break;

  case 45: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 518 "src/parser.y"
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
#line 1977 "src-gen/compiler_bison.cpp"
    break;

  case 46: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 531 "src/parser.y"
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
#line 1994 "src-gen/compiler_bison.cpp"
    break;

  case 47: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 544 "src/parser.y"
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
#line 2012 "src-gen/compiler_bison.cpp"
    break;

  case 48: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_arrow _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 558 "src/parser.y"
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
#line 2030 "src-gen/compiler_bison.cpp"
    break;

  case 49: /* class_def: class_def_raw  */
#line 574 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 2038 "src-gen/compiler_bison.cpp"
    break;

  case 50: /* class_def_raw: t_keyword_class t_identifier t_delimiter_colon block  */
#line 581 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_class_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-2].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2052 "src-gen/compiler_bison.cpp"
    break;

  case 51: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 591 "src/parser.y"
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
#line 2068 "src-gen/compiler_bison.cpp"
    break;

  case 52: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 603 "src/parser.y"
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
#line 2084 "src-gen/compiler_bison.cpp"
    break;

  case 53: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt  */
#line 617 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2097 "src-gen/compiler_bison.cpp"
    break;

  case 54: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 626 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2110 "src-gen/compiler_bison.cpp"
    break;

  case 55: /* if_stmt: t_keyword_if _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 635 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2123 "src-gen/compiler_bison.cpp"
    break;

  case 56: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block elif_stmt  */
#line 646 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2136 "src-gen/compiler_bison.cpp"
    break;

  case 57: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block  */
#line 655 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2149 "src-gen/compiler_bison.cpp"
    break;

  case 58: /* elif_stmt: t_keyword_elif _normal_multiple_or_single_expr t_delimiter_colon block else_block  */
#line 664 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2162 "src-gen/compiler_bison.cpp"
    break;

  case 59: /* else_block: t_keyword_else t_delimiter_colon block  */
#line 675 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_else (for else_block)");
                LOG_ASTNODE("t_delimiter_colon (for else_block)");
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr);
            }
#line 2172 "src-gen/compiler_bison.cpp"
    break;

  case 60: /* block: t_newline t_indent statements t_dedent  */
#line 683 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for block)");
                LOG_ASTNODE("t_indent (for block)");
                LOG_ASTNODE("t_dedent (for block)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2183 "src-gen/compiler_bison.cpp"
    break;

  case 66: /* yield_expr: t_keyword_yield  */
#line 743 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2193 "src-gen/compiler_bison.cpp"
    break;

  case 67: /* yield_expr: t_keyword_yield _normal_multiple_or_single_expr  */
#line 749 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2203 "src-gen/compiler_bison.cpp"
    break;

  case 68: /* yield_expr: t_keyword_yield t_keyword_from _normal_multiple_or_single_expr  */
#line 755 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                LOG_ASTNODE("t_keyword_from (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield_from);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2214 "src-gen/compiler_bison.cpp"
    break;

  case 72: /* _tuple_like_multiple_or_single_expr: _no_endcomma_multiple_expressions t_delimiter_comma  */
#line 769 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2223 "src-gen/compiler_bison.cpp"
    break;

  case 73: /* _tuple_like_multiple_or_single_expr: _normal_single_expression t_delimiter_comma  */
#line 774 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _tuple_like_multiple_or_single_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2233 "src-gen/compiler_bison.cpp"
    break;

  case 74: /* _no_endcomma_multiple_expressions: _normal_single_expression t_delimiter_comma _normal_single_expression  */
#line 782 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2244 "src-gen/compiler_bison.cpp"
    break;

  case 75: /* _no_endcomma_multiple_expressions: _no_endcomma_multiple_expressions t_delimiter_comma _normal_single_expression  */
#line 789 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_multiple_expressions)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2253 "src-gen/compiler_bison.cpp"
    break;

  case 78: /* star_expression: t_operators_mul _expression_if_else  */
#line 800 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for star_expression)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_star);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2263 "src-gen/compiler_bison.cpp"
    break;

  case 80: /* _expression_if_else: _disjunction_or_just_conjunction t_keyword_if _disjunction_or_just_conjunction t_keyword_else _expression_if_else  */
#line 809 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_expr);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2274 "src-gen/compiler_bison.cpp"
    break;

  case 83: /* disjunction: _conjunction_or_just_inversion t_keyword_or _conjunction_or_just_inversion  */
#line 823 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2285 "src-gen/compiler_bison.cpp"
    break;

  case 84: /* disjunction: disjunction t_keyword_or _conjunction_or_just_inversion  */
#line 830 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2294 "src-gen/compiler_bison.cpp"
    break;

  case 87: /* conjunction: inversion t_keyword_and inversion  */
#line 841 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2305 "src-gen/compiler_bison.cpp"
    break;

  case 88: /* conjunction: conjunction t_keyword_and inversion  */
#line 848 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2314 "src-gen/compiler_bison.cpp"
    break;

  case 90: /* inversion: t_keyword_not inversion  */
#line 856 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for inversion)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_not);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2324 "src-gen/compiler_bison.cpp"
    break;

  case 93: /* comparison: bitwise_or compare_op_bitwise_or_pair  */
#line 868 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_comparison);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2334 "src-gen/compiler_bison.cpp"
    break;

  case 94: /* comparison: comparison compare_op_bitwise_or_pair  */
#line 874 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2342 "src-gen/compiler_bison.cpp"
    break;

  case 95: /* compare_op_bitwise_or_pair: t_operators_eq bitwise_or  */
#line 880 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_eq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_eq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2352 "src-gen/compiler_bison.cpp"
    break;

  case 96: /* compare_op_bitwise_or_pair: t_operators_neq bitwise_or  */
#line 886 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_neq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_neq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2362 "src-gen/compiler_bison.cpp"
    break;

  case 97: /* compare_op_bitwise_or_pair: t_operators_leq bitwise_or  */
#line 892 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_leq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_leq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2372 "src-gen/compiler_bison.cpp"
    break;

  case 98: /* compare_op_bitwise_or_pair: t_operators_lt bitwise_or  */
#line 898 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_lt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_lt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2382 "src-gen/compiler_bison.cpp"
    break;

  case 99: /* compare_op_bitwise_or_pair: t_operators_geq bitwise_or  */
#line 904 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_geq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_geq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2392 "src-gen/compiler_bison.cpp"
    break;

  case 100: /* compare_op_bitwise_or_pair: t_operators_gt bitwise_or  */
#line 910 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_gt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_gt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2402 "src-gen/compiler_bison.cpp"
    break;

  case 101: /* compare_op_bitwise_or_pair: t_keyword_not t_keyword_in bitwise_or  */
#line 916 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_notin);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2413 "src-gen/compiler_bison.cpp"
    break;

  case 102: /* compare_op_bitwise_or_pair: t_keyword_in bitwise_or  */
#line 923 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_in);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2423 "src-gen/compiler_bison.cpp"
    break;

  case 103: /* compare_op_bitwise_or_pair: t_keyword_is t_keyword_not bitwise_or  */
#line 929 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_isnot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2434 "src-gen/compiler_bison.cpp"
    break;

  case 104: /* compare_op_bitwise_or_pair: t_keyword_is bitwise_or  */
#line 936 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_is);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2444 "src-gen/compiler_bison.cpp"
    break;

  case 106: /* bitwise_or: bitwise_or t_operators_or bitwise_xor  */
#line 945 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_or (for bitwise_or)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2455 "src-gen/compiler_bison.cpp"
    break;

  case 108: /* bitwise_xor: bitwise_xor t_operators_xor bitwise_and  */
#line 955 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_xor (for bitwise_xor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_xor);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2466 "src-gen/compiler_bison.cpp"
    break;

  case 110: /* bitwise_and: bitwise_and t_operators_and shift_expr  */
#line 965 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_and (for bitwise_and)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2477 "src-gen/compiler_bison.cpp"
    break;

  case 112: /* shift_expr: shift_expr t_operators_sleft sum  */
#line 975 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sleft (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sleft);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2488 "src-gen/compiler_bison.cpp"
    break;

  case 113: /* shift_expr: shift_expr t_operators_sright sum  */
#line 982 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sright (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sright);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2499 "src-gen/compiler_bison.cpp"
    break;

  case 115: /* sum: sum t_operators_add term  */
#line 992 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_add);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2510 "src-gen/compiler_bison.cpp"
    break;

  case 116: /* sum: sum t_operators_sub term  */
#line 999 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sub);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2521 "src-gen/compiler_bison.cpp"
    break;

  case 118: /* term: term t_operators_mul factor  */
#line 1009 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mul);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2532 "src-gen/compiler_bison.cpp"
    break;

  case 119: /* term: term t_operators_div factor  */
#line 1016 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_div (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_div);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2543 "src-gen/compiler_bison.cpp"
    break;

  case 120: /* term: term t_operators_ediv factor  */
#line 1023 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_ediv (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_ediv);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2554 "src-gen/compiler_bison.cpp"
    break;

  case 121: /* term: term t_operators_mod factor  */
#line 1030 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mod (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mod);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2565 "src-gen/compiler_bison.cpp"
    break;

  case 122: /* term: term t_operators_at factor  */
#line 1037 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_at (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_at);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2576 "src-gen/compiler_bison.cpp"
    break;

  case 124: /* factor: t_operators_add factor  */
#line 1047 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_positive);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2586 "src-gen/compiler_bison.cpp"
    break;

  case 125: /* factor: t_operators_sub factor  */
#line 1053 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_negative);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2596 "src-gen/compiler_bison.cpp"
    break;

  case 126: /* factor: t_operators_not factor  */
#line 1059 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_not (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_wavenot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2606 "src-gen/compiler_bison.cpp"
    break;

  case 128: /* power: await_primary t_operators_pow factor  */
#line 1068 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for power)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_power);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2617 "src-gen/compiler_bison.cpp"
    break;

  case 130: /* await_primary: t_keyword_await primary  */
#line 1078 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_await (for await_primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_await);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2627 "src-gen/compiler_bison.cpp"
    break;

  case 132: /* primary: primary t_delimiter_dot t_identifier  */
#line 1087 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_dot (for primary)");
                LOG_ASTNODE("t_identifier (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_dot);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom));
            }
#line 2639 "src-gen/compiler_bison.cpp"
    break;

  case 133: /* primary: primary t_bracket_parentheses_l t_bracket_parentheses_r  */
#line 1095 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2651 "src-gen/compiler_bison.cpp"
    break;

  case 134: /* primary: primary t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r  */
#line 1103 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2663 "src-gen/compiler_bison.cpp"
    break;

  case 135: /* primary: primary t_bracket_square_l slice t_bracket_square_r  */
#line 1111 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_index);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2675 "src-gen/compiler_bison.cpp"
    break;

  case 136: /* primary: primary t_bracket_square_l _normal_multiple_or_single_expr t_bracket_square_r  */
#line 1119 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for primary)");
                LOG_ASTNODE("t_bracket_square_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_index);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2687 "src-gen/compiler_bison.cpp"
    break;

  case 137: /* atom: t_identifier  */
#line 1129 "src/parser.y"
            {
                LOG_ASTNODE("t_identifier (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2696 "src-gen/compiler_bison.cpp"
    break;

  case 138: /* atom: t_keyword_True  */
#line 1134 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_True (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2705 "src-gen/compiler_bison.cpp"
    break;

  case 139: /* atom: t_keyword_False  */
#line 1139 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_False (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2714 "src-gen/compiler_bison.cpp"
    break;

  case 140: /* atom: t_keyword_None  */
#line 1144 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_None (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2723 "src-gen/compiler_bison.cpp"
    break;

  case 141: /* atom: t_keyword_underline  */
#line 1149 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_underline (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2732 "src-gen/compiler_bison.cpp"
    break;

  case 142: /* atom: t_number  */
#line 1154 "src/parser.y"
            {
                LOG_ASTNODE("t_number (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2741 "src-gen/compiler_bison.cpp"
    break;

  case 143: /* atom: t_delimiter_3dot  */
#line 1159 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2750 "src-gen/compiler_bison.cpp"
    break;

  case 148: /* atom: t_bracket_parentheses_l yield_expr t_bracket_parentheses_r  */
#line 1168 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2760 "src-gen/compiler_bison.cpp"
    break;

  case 149: /* atom: t_bracket_parentheses_l _normal_multiple_or_single_expr t_bracket_parentheses_r  */
#line 1174 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2770 "src-gen/compiler_bison.cpp"
    break;

  case 150: /* list: t_bracket_square_l t_bracket_square_r  */
#line 1186 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
            }
#line 2780 "src-gen/compiler_bison.cpp"
    break;

  case 151: /* list: t_bracket_square_l _tuple_like_multiple_or_single_expr t_bracket_square_r  */
#line 1192 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                remove_from_astnode_buff((yyvsp[-1].astnode_ptr));
            }
#line 2792 "src-gen/compiler_bison.cpp"
    break;

  case 152: /* list: t_bracket_square_l _normal_single_expression t_bracket_square_r  */
#line 1200 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_list);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2803 "src-gen/compiler_bison.cpp"
    break;

  case 153: /* tuple: t_bracket_parentheses_l t_bracket_parentheses_r  */
#line 1209 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_tuple);
            }
#line 2813 "src-gen/compiler_bison.cpp"
    break;

  case 154: /* tuple: t_bracket_parentheses_l _tuple_like_multiple_or_single_expr t_bracket_parentheses_r  */
#line 1215 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for tuple)");
                LOG_ASTNODE("t_delimiter_comma (for tuple)");
                LOG_ASTNODE("t_bracket_parentheses_r (for tuple)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_tuple);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                remove_from_astnode_buff((yyvsp[-1].astnode_ptr));
            }
#line 2826 "src-gen/compiler_bison.cpp"
    break;

  case 155: /* set: t_bracket_curly_l t_bracket_curly_r  */
#line 1226 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_curly_l (for set)");
                LOG_ASTNODE("t_bracket_curly_r (for set)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
            }
#line 2836 "src-gen/compiler_bison.cpp"
    break;

  case 156: /* set: t_bracket_curly_l _tuple_like_multiple_or_single_expr t_bracket_curly_r  */
#line 1232 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
                (yyval.astnode_ptr)->eat_sons((yyvsp[-1].astnode_ptr));
                remove_from_astnode_buff((yyvsp[-1].astnode_ptr));
            }
#line 2848 "src-gen/compiler_bison.cpp"
    break;

  case 157: /* set: t_bracket_curly_l _normal_single_expression t_bracket_curly_r  */
#line 1240 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_square_l (for list)");
                LOG_ASTNODE("t_bracket_square_r (for list)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_mayempty_op_set);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2859 "src-gen/compiler_bison.cpp"
    break;

  case 158: /* slice: t_delimiter_colon  */
#line 1249 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2871 "src-gen/compiler_bison.cpp"
    break;

  case 159: /* slice: t_delimiter_colon _normal_single_expression  */
#line 1257 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2883 "src-gen/compiler_bison.cpp"
    break;

  case 160: /* slice: _normal_single_expression t_delimiter_colon  */
#line 1265 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2895 "src-gen/compiler_bison.cpp"
    break;

  case 161: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1273 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2907 "src-gen/compiler_bison.cpp"
    break;

  case 162: /* slice: t_delimiter_colon t_delimiter_colon  */
#line 1281 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2920 "src-gen/compiler_bison.cpp"
    break;

  case 163: /* slice: t_delimiter_colon t_delimiter_colon _normal_single_expression  */
#line 1290 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2933 "src-gen/compiler_bison.cpp"
    break;

  case 164: /* slice: t_delimiter_colon _normal_single_expression t_delimiter_colon  */
#line 1299 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2946 "src-gen/compiler_bison.cpp"
    break;

  case 165: /* slice: t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1308 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2959 "src-gen/compiler_bison.cpp"
    break;

  case 166: /* slice: _normal_single_expression t_delimiter_colon t_delimiter_colon  */
#line 1317 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2972 "src-gen/compiler_bison.cpp"
    break;

  case 167: /* slice: _normal_single_expression t_delimiter_colon t_delimiter_colon _normal_single_expression  */
#line 1326 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2985 "src-gen/compiler_bison.cpp"
    break;

  case 168: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon  */
#line 1335 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2998 "src-gen/compiler_bison.cpp"
    break;

  case 169: /* slice: _normal_single_expression t_delimiter_colon _normal_single_expression t_delimiter_colon _normal_single_expression  */
#line 1344 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                LOG_ASTNODE("t_delimiter_colon (for slice)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_slice);
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3011 "src-gen/compiler_bison.cpp"
    break;

  case 170: /* strings: string_text  */
#line 1355 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_strings);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3020 "src-gen/compiler_bison.cpp"
    break;

  case 171: /* strings: strings string_text  */
#line 1360 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3028 "src-gen/compiler_bison.cpp"
    break;

  case 172: /* string_text: t_bracket_dquotes t_strtext t_bracket_dquotes  */
#line 1366 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 3039 "src-gen/compiler_bison.cpp"
    break;

  case 173: /* string_text: t_bracket_squotes t_strtext t_bracket_squotes  */
#line 1373 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 3050 "src-gen/compiler_bison.cpp"
    break;

  case 175: /* arguments_or_parameters: argparas t_delimiter_comma  */
#line 1383 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for arguments_or_parameters)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 3059 "src-gen/compiler_bison.cpp"
    break;

  case 176: /* argparas: argpara  */
#line 1390 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_args_or_prams);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3068 "src-gen/compiler_bison.cpp"
    break;

  case 177: /* argparas: argparas t_delimiter_comma argpara  */
#line 1395 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for argparas)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3077 "src-gen/compiler_bison.cpp"
    break;

  case 179: /* argpara: primary t_delimiter_colon primary  */
#line 1403 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_aptype);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3088 "src-gen/compiler_bison.cpp"
    break;

  case 180: /* argpara: t_operators_mul _normal_single_expression  */
#line 1410 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3098 "src-gen/compiler_bison.cpp"
    break;

  case 181: /* argpara: t_operators_pow _normal_single_expression  */
#line 1416 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apdstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3108 "src-gen/compiler_bison.cpp"
    break;

  case 182: /* argpara: primary t_operators_assign _normal_single_expression  */
#line 1422 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_apequ);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 3119 "src-gen/compiler_bison.cpp"
    break;

  case 183: /* argpara: primary t_delimiter_colon primary t_operators_assign _normal_single_expression  */
#line 1429 "src/parser.y"
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
#line 3134 "src-gen/compiler_bison.cpp"
    break;

  case 184: /* ast_error: t_error  */
#line 1445 "src/parser.y"
                  { GEN_ERROR_NODE("t_error (for ast_error)", (yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3140 "src-gen/compiler_bison.cpp"
    break;

  case 185: /* ast_error: t_keyword_lambda  */
#line 1515 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3146 "src-gen/compiler_bison.cpp"
    break;

  case 186: /* ast_error: t_keyword_for  */
#line 1520 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3152 "src-gen/compiler_bison.cpp"
    break;

  case 187: /* ast_error: t_keyword_match  */
#line 1523 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3158 "src-gen/compiler_bison.cpp"
    break;

  case 188: /* ast_error: t_keyword_case  */
#line 1524 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3164 "src-gen/compiler_bison.cpp"
    break;

  case 189: /* ast_error: t_keyword_global  */
#line 1525 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3170 "src-gen/compiler_bison.cpp"
    break;

  case 190: /* ast_error: t_keyword_nonlocal  */
#line 1526 "src/parser.y"
                             { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3176 "src-gen/compiler_bison.cpp"
    break;

  case 191: /* ast_error: t_keyword_del  */
#line 1527 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3182 "src-gen/compiler_bison.cpp"
    break;

  case 192: /* ast_error: t_keyword_import  */
#line 1528 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3188 "src-gen/compiler_bison.cpp"
    break;

  case 193: /* ast_error: t_keyword_from  */
#line 1529 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3194 "src-gen/compiler_bison.cpp"
    break;

  case 194: /* ast_error: t_keyword_as  */
#line 1530 "src/parser.y"
                       { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3200 "src-gen/compiler_bison.cpp"
    break;

  case 195: /* ast_error: t_keyword_raise  */
#line 1531 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3206 "src-gen/compiler_bison.cpp"
    break;

  case 196: /* ast_error: t_keyword_try  */
#line 1532 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3212 "src-gen/compiler_bison.cpp"
    break;

  case 197: /* ast_error: t_keyword_except  */
#line 1533 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3218 "src-gen/compiler_bison.cpp"
    break;

  case 198: /* ast_error: t_keyword_finally  */
#line 1534 "src/parser.y"
                            { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3224 "src-gen/compiler_bison.cpp"
    break;

  case 199: /* ast_error: t_keyword_assert  */
#line 1535 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3230 "src-gen/compiler_bison.cpp"
    break;

  case 200: /* ast_error: t_keyword_tastror_out  */
#line 1536 "src/parser.y"
                                { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 3236 "src-gen/compiler_bison.cpp"
    break;


#line 3240 "src-gen/compiler_bison.cpp"

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

#line 1538 "src/parser.y"


void yyerror(AstNode*& ast_head, char* msg)
{
    stdlog::log << stdlog::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << stdlog::endl;
}
