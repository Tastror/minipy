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
  YYSYMBOL__normal_expression = 117,       /* _normal_expression  */
  YYSYMBOL_star_expressions = 118,         /* star_expressions  */
  YYSYMBOL__no_endcomma_star_expressions = 119, /* _no_endcomma_star_expressions  */
  YYSYMBOL_star_expression = 120,          /* star_expression  */
  YYSYMBOL__expression_if_else = 121,      /* _expression_if_else  */
  YYSYMBOL__disjunction_or_just_conjunction = 122, /* _disjunction_or_just_conjunction  */
  YYSYMBOL_disjunction = 123,              /* disjunction  */
  YYSYMBOL__conjunction_or_just_inversion = 124, /* _conjunction_or_just_inversion  */
  YYSYMBOL_conjunction = 125,              /* conjunction  */
  YYSYMBOL_inversion = 126,                /* inversion  */
  YYSYMBOL__comparison_or_just_bitwise_or = 127, /* _comparison_or_just_bitwise_or  */
  YYSYMBOL_comparison = 128,               /* comparison  */
  YYSYMBOL_compare_op_bitwise_or_pair = 129, /* compare_op_bitwise_or_pair  */
  YYSYMBOL_bitwise_or = 130,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 131,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 132,              /* bitwise_and  */
  YYSYMBOL_shift_expr = 133,               /* shift_expr  */
  YYSYMBOL_sum = 134,                      /* sum  */
  YYSYMBOL_term = 135,                     /* term  */
  YYSYMBOL_factor = 136,                   /* factor  */
  YYSYMBOL_power = 137,                    /* power  */
  YYSYMBOL_await_primary = 138,            /* await_primary  */
  YYSYMBOL_primary = 139,                  /* primary  */
  YYSYMBOL_atom = 140,                     /* atom  */
  YYSYMBOL_strings = 141,                  /* strings  */
  YYSYMBOL_string_text = 142,              /* string_text  */
  YYSYMBOL_arguments_or_parameters = 143,  /* arguments_or_parameters  */
  YYSYMBOL_argparas = 144,                 /* argparas  */
  YYSYMBOL_argpara = 145,                  /* argpara  */
  YYSYMBOL_ast_error = 146                 /* ast_error  */
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
#define YYFINAL  105
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   968

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

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
       0,   337,   337,   343,   349,   354,   359,   369,   374,   380,
     387,   392,   400,   401,   406,   411,   416,   417,   418,   419,
     425,   440,   441,   449,   458,   468,   476,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   506,   507,   508,   511,   518,   531,   544,   558,   574,
     581,   591,   603,   617,   626,   635,   646,   655,   664,   675,
     683,   690,   721,   724,   727,   728,   743,   749,   755,   764,
     765,   768,   769,   774,   782,   789,   796,   797,   805,   806,
     816,   817,   820,   827,   834,   835,   838,   845,   852,   853,
     861,   862,   865,   871,   877,   883,   889,   895,   901,   907,
     913,   920,   926,   933,   941,   942,   951,   952,   961,   962,
     971,   972,   979,   988,   989,   996,  1005,  1006,  1013,  1020,
    1027,  1034,  1043,  1044,  1050,  1056,  1064,  1065,  1074,  1075,
    1083,  1084,  1092,  1100,  1111,  1116,  1121,  1126,  1131,  1136,
    1141,  1146,  1147,  1153,  1165,  1170,  1176,  1183,  1192,  1193,
    1200,  1205,  1212,  1213,  1220,  1226,  1232,  1239,  1256,  1273,
    1274,  1275,  1276,  1326,  1331,  1334,  1335,  1336,  1337,  1338,
    1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347
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
  "expressions_lhs", "expressions_rhs", "yield_expr", "_normal_expression",
  "star_expressions", "_no_endcomma_star_expressions", "star_expression",
  "_expression_if_else", "_disjunction_or_just_conjunction", "disjunction",
  "_conjunction_or_just_inversion", "conjunction", "inversion",
  "_comparison_or_just_bitwise_or", "comparison",
  "compare_op_bitwise_or_pair", "bitwise_or", "bitwise_xor", "bitwise_and",
  "shift_expr", "sum", "term", "factor", "power", "await_primary",
  "primary", "atom", "strings", "string_text", "arguments_or_parameters",
  "argparas", "argpara", "ast_error", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     358,  -164,  -164,  -164,  -164,  -164,    15,    40,   732,  -164,
    -164,  -164,  -164,   894,   894,    55,   894,  -164,  -164,  -164,
    -164,    55,  -164,    59,   813,   156,    70,  -164,   142,   813,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,    56,   358,  -164,
       3,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
      38,  -164,    44,  -164,    92,    93,  -164,    31,    46,    47,
      60,    61,  -164,   237,     2,    84,    87,   -23,    14,    58,
    -164,  -164,    91,   353,  -164,    30,  -164,  -164,   106,   108,
     107,   109,     8,  -164,  -164,  -164,  -164,  -164,   119,  -164,
     813,  -164,     9,     8,   116,  -164,  -164,  -164,  -164,   450,
     732,   813,   813,    55,    55,    55,    55,    55,   894,   894,
     894,   894,   894,   894,    71,   873,   894,  -164,   894,  -164,
     894,   894,   894,   894,   894,   894,   894,   894,   894,   894,
     894,   894,   142,   132,   630,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   732,
    -164,  -164,  -164,  -164,  -164,   651,  -164,   542,   711,   542,
    -164,  -164,  -164,  -164,  -164,    44,  -164,  -164,    64,  -164,
    -164,  -164,  -164,   110,   110,   110,   110,   110,   110,   894,
     894,   110,   110,    84,    87,   -23,    14,    14,    58,    58,
    -164,  -164,  -164,  -164,  -164,  -164,    97,     8,  -164,  -164,
      55,    55,  -164,    39,   126,   136,  -164,  -164,  -164,    43,
     128,   143,  -164,  -164,   141,   147,   -18,    55,   110,   110,
     732,  -164,  -164,   142,    55,  -164,   792,   542,   813,    49,
     358,   542,   144,   150,   813,  -164,  -164,  -164,  -164,     7,
    -164,  -164,  -164,   151,   542,   813,   266,  -164,   542,   542,
     159,    55,   542,  -164,   164,  -164,  -164,  -164,   542,  -164,
    -164,   542,   -18,  -164,  -164,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   158,     9,   134,   139,   140,     0,     0,     0,   159,
     160,   161,   162,     0,     0,     0,     0,   138,   137,   135,
     136,     0,    13,     0,    19,    66,     0,   163,     0,     0,
     164,    14,    15,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,     2,     3,
       0,    10,    16,    21,     4,    41,    44,    42,    49,    43,
       0,    18,    17,    69,    71,    70,    76,    78,    81,    80,
      85,    84,    88,    91,    90,   104,   106,   108,   110,   113,
     116,   122,   126,   128,   130,   141,   144,    12,     0,     0,
       0,     0,   128,   123,   124,    77,   125,    89,     0,    20,
       0,    67,     0,   129,     0,     1,     5,     6,     7,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
     145,   147,   146,   142,   143,     0,    68,     0,     0,     0,
       8,    11,    26,    25,    65,    64,    75,    74,     0,    83,
      82,    87,    86,    94,    95,    96,    98,    97,    99,     0,
       0,   103,   101,   105,   107,   109,   111,   112,   114,   115,
     117,   118,   119,   120,   121,   127,    22,    62,   131,   132,
       0,     0,   152,   128,     0,   148,   150,    24,    64,     0,
       0,     9,    61,    50,     0,     0,    54,     0,   100,   102,
       0,   154,   155,     0,     0,   133,   149,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    55,    79,    23,   153,
     156,   151,    45,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,    46,     0,    60,    52,    59,     0,   157,
      47,     0,    57,    48,    56,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   -64,     4,  -164,    68,  -164,    69,  -164,   -45,
    -164,  -164,  -164,  -164,  -164,   -94,   -88,  -163,  -164,  -164,
    -149,    -3,    -6,  -164,  -164,   -47,   -14,    72,  -164,   -39,
    -164,    -4,  -164,  -164,   112,   -89,    62,    53,    57,   -40,
     -37,    -5,  -164,  -164,     0,  -164,  -164,   102,  -153,  -164,
     -44,  -164
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    47,    48,   222,    50,    51,    52,    53,   159,    54,
      55,    56,    57,    58,    59,   245,   246,   223,   206,    60,
     173,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   127,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    92,    84,    85,    86,   214,   215,
     216,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    95,    91,   107,    49,    90,   226,   108,    93,    94,
     217,    96,   220,   132,   133,   225,   109,    97,    99,   101,
     167,   143,   143,   104,    88,   144,   144,   168,   103,   183,
     184,   185,   186,   187,   188,   128,   191,   192,   134,   135,
     118,   119,   120,   121,   122,   123,     6,     7,    83,    89,
     233,   261,   106,   143,   237,   238,   105,   144,   243,   244,
     254,   255,     3,     4,   176,   177,    98,   124,   125,   126,
       5,     6,     7,     8,   252,   179,   180,   102,   257,    13,
      14,   248,   110,   234,   136,   137,   138,   139,   -63,   140,
      16,   263,   196,   197,   166,   266,   267,   198,   199,   270,
     228,   229,   111,   112,   175,   272,   113,   174,   273,    83,
     114,   115,   181,   182,    17,    18,    19,    20,   130,   131,
      21,   141,   161,   116,   117,   162,   163,   169,   164,    28,
     212,   200,   201,   202,   203,   204,   205,   165,   189,   208,
     227,   230,   207,   128,   213,   235,   236,   239,   240,     3,
       4,   212,   241,   218,   212,   258,   174,     5,     6,     7,
       8,   259,   262,     3,     4,   213,   242,    83,   213,    83,
     268,     5,     6,     7,     8,   271,   256,   171,   274,   172,
      13,    14,    15,   194,   275,   178,   129,   160,   195,     0,
     193,    16,   251,     0,     0,     0,   231,   232,     0,     0,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,   107,     0,   247,     0,    17,    18,    19,    20,     0,
     250,    21,   212,     0,   218,     0,     0,   174,     0,     0,
      28,     0,   253,   249,     0,     0,   213,    83,   260,     0,
      83,    83,     0,   100,    49,     0,     0,   269,     0,   264,
       0,     0,     0,     0,    83,     0,    83,     0,    83,    83,
     106,     0,    83,     0,     0,     0,     0,     0,    83,     1,
       2,    83,   265,     3,     4,   118,   119,   120,   121,   122,
     123,     5,     6,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,    16,   124,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,     0,
       0,    21,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,     0,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     1,     2,     0,   142,     3,     4,   143,     0,     0,
       0,   144,     0,     5,     6,     7,     8,     0,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,     0,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     1,   170,     0,     0,     3,     4,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,     0,     0,    21,     0,     0,    22,     0,
      24,    25,     0,    27,    28,     0,     0,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     1,   221,     0,     0,     3,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,     0,     0,    21,     0,     0,
      22,     0,    24,    25,     0,    27,    28,     0,     0,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     3,     4,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     8,   209,
       0,     0,     0,     0,    13,    14,   210,     0,     3,     4,
     211,     0,     0,     0,     0,    16,     5,     6,     7,     8,
     219,     0,     0,     0,     0,    13,    14,   210,     0,     0,
       0,   211,     0,     0,     0,     0,    16,     0,     0,    17,
      18,    19,    20,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
      17,    18,    19,    20,     0,     0,    21,     0,     3,     4,
       0,     0,     0,     0,     0,    28,     5,     6,     7,     8,
     224,     0,     0,     0,     0,    13,    14,   210,     0,     3,
       4,   211,     0,     0,     0,     0,    16,     5,     6,     7,
       8,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,    18,    19,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,    17,    18,    19,    20,     0,     0,    21,     0,     3,
       4,     0,     0,    25,     0,     0,    28,     5,     6,     7,
       8,     0,     0,     0,     0,     0,    13,    14,   210,     0,
       3,     4,   211,     0,     0,     0,     0,    16,     5,     6,
       7,     8,     0,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,    18,    19,    20,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,    17,    18,    19,    20,     0,     0,    21,     0,
       3,     4,     0,     0,     0,     0,     0,    28,     5,     6,
       7,     8,     0,     0,     0,     0,     0,    13,    14,     0,
       0,     3,     4,     0,     0,     0,     0,     0,    16,     5,
       6,     7,     8,     0,     0,     0,     0,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,    18,    19,    20,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
       0,    15,     8,    48,     0,     8,   169,     4,    13,    14,
     159,    16,   165,    36,    37,   168,    13,    21,    24,    25,
      11,    14,    14,    29,     9,    18,    18,    18,    28,   118,
     119,   120,   121,   122,   123,    33,   125,   126,    24,    25,
      38,    39,    40,    41,    42,    43,    16,    17,    48,     9,
      11,    44,    48,    14,    11,    12,     0,    18,    76,    77,
      11,    12,     7,     8,   111,   112,     7,    65,    66,    67,
      15,    16,    17,    18,   237,   114,   115,     7,   241,    24,
      25,   230,    44,    44,    26,    27,    28,    29,    44,    31,
      35,   254,   132,   133,   100,   258,   259,   134,   135,   262,
     189,   190,    10,    10,   110,   268,    75,   110,   271,   109,
      64,    64,   116,   117,    59,    60,    61,    62,    34,    32,
      65,    30,    16,    63,    63,    17,    19,    11,    19,    74,
     144,   136,   137,   138,   139,   140,   141,    18,    67,     7,
      76,    44,   142,    33,   144,    19,    10,    19,     5,     7,
       8,   165,    11,   159,   168,    11,   159,    15,    16,    17,
      18,    11,    11,     7,     8,   165,    19,   167,   168,   169,
      11,    15,    16,    17,    18,    11,   240,   109,   272,   110,
      24,    25,    26,   130,   272,   113,    74,    85,   131,    -1,
     128,    35,   236,    -1,    -1,    -1,   210,   211,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,   227,    -1,    59,    60,    61,    62,    -1,
     234,    65,   236,    -1,   230,    -1,    -1,   230,    -1,    -1,
      74,    -1,   238,   233,    -1,    -1,   236,   237,   244,    -1,
     240,   241,    -1,    87,   240,    -1,    -1,   261,    -1,   255,
      -1,    -1,    -1,    -1,   254,    -1,   256,    -1,   258,   259,
     256,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,     3,
       4,   271,     6,     7,     8,    38,    39,    40,    41,    42,
      43,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     3,     4,    -1,    11,     7,     8,    14,    -1,    -1,
      -1,    18,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     3,     4,    -1,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    68,    -1,
      70,    71,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     3,     4,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      68,    -1,    70,    71,    -1,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,     7,     8,
      30,    -1,    -1,    -1,    -1,    35,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    65,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    74,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,     7,
       8,    30,    -1,    -1,    -1,    -1,    35,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,     7,
       8,    -1,    -1,    71,    -1,    -1,    74,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
       7,     8,    30,    -1,    -1,    -1,    -1,    35,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    74,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    35,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,    15,    16,    17,    18,    20,
      21,    22,    23,    24,    25,    26,    35,    59,    60,    61,
      62,    65,    68,    69,    70,    71,    72,    73,    74,    75,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    96,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   107,   108,   109,
     114,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   146,     9,     9,
     116,   117,   139,   136,   136,   121,   136,   126,     7,   117,
      87,   117,     7,   139,   117,     0,    98,   104,     4,    13,
      44,    10,    10,    75,    64,    64,    63,    63,    38,    39,
      40,    41,    42,    43,    65,    66,    67,   129,    33,   129,
      34,    32,    36,    37,    24,    25,    26,    27,    28,    29,
      31,    30,    11,    14,    18,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   103,
     142,    16,    17,    19,    19,    18,   117,    11,    18,    11,
       4,   100,   102,   115,   116,   117,   120,   120,   122,   124,
     124,   126,   126,   130,   130,   130,   130,   130,   130,    67,
      65,   130,   130,   131,   132,   133,   134,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   113,   139,     7,    19,
      26,    30,   121,   139,   143,   144,   145,   115,   117,    19,
     143,     4,    98,   112,    19,   143,   112,    76,   130,   130,
      44,   121,   121,    11,    44,    19,    10,    11,    12,    19,
       5,    11,    19,    76,    77,   110,   111,   121,   115,   139,
     121,   145,   112,   117,    11,    12,    97,   112,    11,    11,
     117,    44,    11,   112,   117,     6,   112,   112,    11,   121,
     112,    11,   112,   112,   110,   111
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
     117,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   134,   134,   134,   135,   135,   135,   135,
     135,   135,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146
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
       1,     1,     2,     2,     3,     3,     1,     2,     1,     5,
       1,     1,     3,     3,     1,     1,     3,     3,     1,     2,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     2,     3,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     2,     2,     2,     1,     3,     1,     2,
       1,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     2,     3,     3,     1,     2,
       1,     3,     1,     3,     2,     2,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 338 "src/parser.y"
            {
                ast_head = (yyvsp[0].astnode_ptr);
            }
#line 1592 "src-gen/compiler_bison.cpp"
    break;

  case 3: /* statements: simple_stmts  */
#line 344 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                remove_from_astnode_buff((yyvsp[0].astnode_ptr));
            }
#line 1602 "src-gen/compiler_bison.cpp"
    break;

  case 4: /* statements: compound_stmt  */
#line 350 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::statements);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1611 "src-gen/compiler_bison.cpp"
    break;

  case 5: /* statements: statements simple_stmts  */
#line 355 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat_sons((yyvsp[0].astnode_ptr));
                remove_from_astnode_buff((yyvsp[0].astnode_ptr));
            }
#line 1620 "src-gen/compiler_bison.cpp"
    break;

  case 6: /* statements: statements compound_stmt  */
#line 360 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1628 "src-gen/compiler_bison.cpp"
    break;

  case 7: /* simple_stmts: _no_newline_simple_stmt t_newline  */
#line 370 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 1637 "src-gen/compiler_bison.cpp"
    break;

  case 8: /* simple_stmts: _no_newline_simple_stmt t_delimiter_semicolon t_newline  */
#line 375 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for simple_stmts)");
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
            }
#line 1647 "src-gen/compiler_bison.cpp"
    break;

  case 9: /* simple_stmts: t_newline  */
#line 381 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for simple_stmts)");
                (yyval.astnode_ptr) = make_empty_astnode();  // will be eat_sons by statements, which is just empty~
            }
#line 1656 "src-gen/compiler_bison.cpp"
    break;

  case 10: /* _no_newline_simple_stmt: simple_stmt  */
#line 388 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::temp);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1665 "src-gen/compiler_bison.cpp"
    break;

  case 11: /* _no_newline_simple_stmt: _no_newline_simple_stmt t_delimiter_semicolon simple_stmt  */
#line 393 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_semicolon (for _no_newline_simple_stmt)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1675 "src-gen/compiler_bison.cpp"
    break;

  case 13: /* simple_stmt: t_keyword_pass  */
#line 402 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_pass (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_pass);
            }
#line 1684 "src-gen/compiler_bison.cpp"
    break;

  case 14: /* simple_stmt: t_keyword_break  */
#line 407 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_break (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_break);
            }
#line 1693 "src-gen/compiler_bison.cpp"
    break;

  case 15: /* simple_stmt: t_keyword_continue  */
#line 412 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_continue (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::zero_op_continue);
            }
#line 1702 "src-gen/compiler_bison.cpp"
    break;

  case 19: /* simple_stmt: t_keyword_return  */
#line 420 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1712 "src-gen/compiler_bison.cpp"
    break;

  case 20: /* simple_stmt: t_keyword_return _normal_expression  */
#line 426 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_return (for simple_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_return);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1722 "src-gen/compiler_bison.cpp"
    break;

  case 22: /* assignment: primary t_delimiter_colon expressions_type  */
#line 442 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 1734 "src-gen/compiler_bison.cpp"
    break;

  case 23: /* assignment: primary t_delimiter_colon expressions_type t_operators_assign expressions_rhs  */
#line 450 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for assignment)");
                LOG_ASTNODE("t_operators_assign (for assignment)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1747 "src-gen/compiler_bison.cpp"
    break;

  case 24: /* assignment: primary augassign expressions_rhs  */
#line 459 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_augassign);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1758 "src-gen/compiler_bison.cpp"
    break;

  case 25: /* _no_type_assign: expressions_lhs t_operators_assign expressions_rhs  */
#line 469 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1770 "src-gen/compiler_bison.cpp"
    break;

  case 26: /* _no_type_assign: expressions_lhs t_operators_assign _no_type_assign  */
#line 477 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for _no_type_assign)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_assign);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1782 "src-gen/compiler_bison.cpp"
    break;

  case 27: /* augassign: t_operators_add_assign  */
#line 486 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_add_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1788 "src-gen/compiler_bison.cpp"
    break;

  case 28: /* augassign: t_operators_sub_assign  */
#line 487 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sub_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1794 "src-gen/compiler_bison.cpp"
    break;

  case 29: /* augassign: t_operators_mul_assign  */
#line 488 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mul_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1800 "src-gen/compiler_bison.cpp"
    break;

  case 30: /* augassign: t_operators_div_assign  */
#line 489 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_div_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1806 "src-gen/compiler_bison.cpp"
    break;

  case 31: /* augassign: t_operators_ediv_assign  */
#line 490 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_ediv_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1812 "src-gen/compiler_bison.cpp"
    break;

  case 32: /* augassign: t_operators_mod_assign  */
#line 491 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_mod_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1818 "src-gen/compiler_bison.cpp"
    break;

  case 33: /* augassign: t_operators_pow_assign  */
#line 492 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_pow_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1824 "src-gen/compiler_bison.cpp"
    break;

  case 34: /* augassign: t_operators_at_assign  */
#line 493 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_at_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1830 "src-gen/compiler_bison.cpp"
    break;

  case 35: /* augassign: t_operators_and_assign  */
#line 494 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_and_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1836 "src-gen/compiler_bison.cpp"
    break;

  case 36: /* augassign: t_operators_or_assign  */
#line 495 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_or_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1842 "src-gen/compiler_bison.cpp"
    break;

  case 37: /* augassign: t_operators_xor_assign  */
#line 496 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_xor_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1848 "src-gen/compiler_bison.cpp"
    break;

  case 38: /* augassign: t_operators_not_assign  */
#line 497 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_not_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1854 "src-gen/compiler_bison.cpp"
    break;

  case 39: /* augassign: t_operators_sleft_assign  */
#line 498 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sleft_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1860 "src-gen/compiler_bison.cpp"
    break;

  case 40: /* augassign: t_operators_sright_assign  */
#line 499 "src/parser.y"
                                    { LOG_ASTNODE("t_operators_sright_assign (for augassign)"); (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom); }
#line 1866 "src-gen/compiler_bison.cpp"
    break;

  case 44: /* function_def: function_def_raw  */
#line 512 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 1874 "src-gen/compiler_bison.cpp"
    break;

  case 45: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 519 "src/parser.y"
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
#line 1891 "src-gen/compiler_bison.cpp"
    break;

  case 46: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 532 "src/parser.y"
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
#line 1908 "src-gen/compiler_bison.cpp"
    break;

  case 47: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_arrow _normal_expression t_delimiter_colon block  */
#line 545 "src/parser.y"
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
#line 1926 "src-gen/compiler_bison.cpp"
    break;

  case 48: /* function_def_raw: t_keyword_def t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_arrow _normal_expression t_delimiter_colon block  */
#line 559 "src/parser.y"
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
#line 1944 "src-gen/compiler_bison.cpp"
    break;

  case 49: /* class_def: class_def_raw  */
#line 575 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr)->eat(make_empty_astnode());
            }
#line 1952 "src-gen/compiler_bison.cpp"
    break;

  case 50: /* class_def_raw: t_keyword_class t_identifier t_delimiter_colon block  */
#line 582 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_class (for class_def_raw)");
                LOG_ASTNODE("t_identifier (for class_def_raw)");
                LOG_ASTNODE("t_delimiter_colon (for class_def_raw)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::qua_op_class_block);
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[-2].token_ptr), astnode_type::atom));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 1966 "src-gen/compiler_bison.cpp"
    break;

  case 51: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l t_bracket_parentheses_r t_delimiter_colon block  */
#line 592 "src/parser.y"
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
#line 1982 "src-gen/compiler_bison.cpp"
    break;

  case 52: /* class_def_raw: t_keyword_class t_identifier t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r t_delimiter_colon block  */
#line 604 "src/parser.y"
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
#line 1998 "src-gen/compiler_bison.cpp"
    break;

  case 53: /* if_stmt: t_keyword_if _normal_expression t_delimiter_colon block elif_stmt  */
#line 618 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2011 "src-gen/compiler_bison.cpp"
    break;

  case 54: /* if_stmt: t_keyword_if _normal_expression t_delimiter_colon block  */
#line 627 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2024 "src-gen/compiler_bison.cpp"
    break;

  case 55: /* if_stmt: t_keyword_if _normal_expression t_delimiter_colon block else_block  */
#line 636 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_if (for if_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for if_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2037 "src-gen/compiler_bison.cpp"
    break;

  case 56: /* elif_stmt: t_keyword_elif _normal_expression t_delimiter_colon block elif_stmt  */
#line 647 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2050 "src-gen/compiler_bison.cpp"
    break;

  case 57: /* elif_stmt: t_keyword_elif _normal_expression t_delimiter_colon block  */
#line 656 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2063 "src-gen/compiler_bison.cpp"
    break;

  case 58: /* elif_stmt: t_keyword_elif _normal_expression t_delimiter_colon block else_block  */
#line 665 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_elif (for elif_stmt)");
                LOG_ASTNODE("t_delimiter_colon (for elif_stmt)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_block);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2076 "src-gen/compiler_bison.cpp"
    break;

  case 59: /* else_block: t_keyword_else t_delimiter_colon block  */
#line 676 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_else (for else_block)");
                LOG_ASTNODE("t_delimiter_colon (for else_block)");
                (yyval.astnode_ptr) = (yyvsp[0].astnode_ptr);
            }
#line 2086 "src-gen/compiler_bison.cpp"
    break;

  case 60: /* block: t_newline t_indent statements t_dedent  */
#line 684 "src/parser.y"
            {
                LOG_ASTNODE("t_newline (for block)");
                LOG_ASTNODE("t_indent (for block)");
                LOG_ASTNODE("t_dedent (for block)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2097 "src-gen/compiler_bison.cpp"
    break;

  case 66: /* yield_expr: t_keyword_yield  */
#line 744 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2107 "src-gen/compiler_bison.cpp"
    break;

  case 67: /* yield_expr: t_keyword_yield _normal_expression  */
#line 750 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2117 "src-gen/compiler_bison.cpp"
    break;

  case 68: /* yield_expr: t_keyword_yield t_keyword_from _normal_expression  */
#line 756 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_yield (for yield_expr)");
                LOG_ASTNODE("t_keyword_from (for yield_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_yield_from);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2128 "src-gen/compiler_bison.cpp"
    break;

  case 72: /* star_expressions: _no_endcomma_star_expressions t_delimiter_comma  */
#line 770 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2137 "src-gen/compiler_bison.cpp"
    break;

  case 73: /* star_expressions: star_expression t_delimiter_comma  */
#line 775 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2147 "src-gen/compiler_bison.cpp"
    break;

  case 74: /* _no_endcomma_star_expressions: star_expression t_delimiter_comma star_expression  */
#line 783 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for star_expressions)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::expressions);  // to normal expressions
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2158 "src-gen/compiler_bison.cpp"
    break;

  case 75: /* _no_endcomma_star_expressions: _no_endcomma_star_expressions t_delimiter_comma star_expression  */
#line 790 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for _no_endcomma_star_expressions)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2167 "src-gen/compiler_bison.cpp"
    break;

  case 77: /* star_expression: t_operators_mul _expression_if_else  */
#line 798 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for star_expression)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_star);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2177 "src-gen/compiler_bison.cpp"
    break;

  case 79: /* _expression_if_else: _disjunction_or_just_conjunction t_keyword_if _disjunction_or_just_conjunction t_keyword_else _expression_if_else  */
#line 807 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::tri_op_if_else_expr);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-4].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2188 "src-gen/compiler_bison.cpp"
    break;

  case 82: /* disjunction: _conjunction_or_just_inversion t_keyword_or _conjunction_or_just_inversion  */
#line 821 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2199 "src-gen/compiler_bison.cpp"
    break;

  case 83: /* disjunction: disjunction t_keyword_or _conjunction_or_just_inversion  */
#line 828 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_or (for disjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2208 "src-gen/compiler_bison.cpp"
    break;

  case 86: /* conjunction: inversion t_keyword_and inversion  */
#line 839 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2219 "src-gen/compiler_bison.cpp"
    break;

  case 87: /* conjunction: conjunction t_keyword_and inversion  */
#line 846 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_and (for conjunction)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2228 "src-gen/compiler_bison.cpp"
    break;

  case 89: /* inversion: t_keyword_not inversion  */
#line 854 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for inversion)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_not);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2238 "src-gen/compiler_bison.cpp"
    break;

  case 92: /* comparison: bitwise_or compare_op_bitwise_or_pair  */
#line 866 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_comparison);
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2248 "src-gen/compiler_bison.cpp"
    break;

  case 93: /* comparison: comparison compare_op_bitwise_or_pair  */
#line 872 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2256 "src-gen/compiler_bison.cpp"
    break;

  case 94: /* compare_op_bitwise_or_pair: t_operators_eq bitwise_or  */
#line 878 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_eq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_eq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2266 "src-gen/compiler_bison.cpp"
    break;

  case 95: /* compare_op_bitwise_or_pair: t_operators_neq bitwise_or  */
#line 884 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_neq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_neq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2276 "src-gen/compiler_bison.cpp"
    break;

  case 96: /* compare_op_bitwise_or_pair: t_operators_leq bitwise_or  */
#line 890 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_leq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_leq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2286 "src-gen/compiler_bison.cpp"
    break;

  case 97: /* compare_op_bitwise_or_pair: t_operators_lt bitwise_or  */
#line 896 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_lt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_lt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2296 "src-gen/compiler_bison.cpp"
    break;

  case 98: /* compare_op_bitwise_or_pair: t_operators_geq bitwise_or  */
#line 902 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_geq (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_geq);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2306 "src-gen/compiler_bison.cpp"
    break;

  case 99: /* compare_op_bitwise_or_pair: t_operators_gt bitwise_or  */
#line 908 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_gt (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_gt);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2316 "src-gen/compiler_bison.cpp"
    break;

  case 100: /* compare_op_bitwise_or_pair: t_keyword_not t_keyword_in bitwise_or  */
#line 914 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_notin);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2327 "src-gen/compiler_bison.cpp"
    break;

  case 101: /* compare_op_bitwise_or_pair: t_keyword_in bitwise_or  */
#line 921 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_in (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_in);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2337 "src-gen/compiler_bison.cpp"
    break;

  case 102: /* compare_op_bitwise_or_pair: t_keyword_is t_keyword_not bitwise_or  */
#line 927 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                LOG_ASTNODE("t_keyword_not (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_isnot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2348 "src-gen/compiler_bison.cpp"
    break;

  case 103: /* compare_op_bitwise_or_pair: t_keyword_is bitwise_or  */
#line 934 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_is (for compare_op_bitwise_or_pair)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::comp_op_is);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2358 "src-gen/compiler_bison.cpp"
    break;

  case 105: /* bitwise_or: bitwise_or t_operators_or bitwise_xor  */
#line 943 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_or (for bitwise_or)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_or);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2369 "src-gen/compiler_bison.cpp"
    break;

  case 107: /* bitwise_xor: bitwise_xor t_operators_xor bitwise_and  */
#line 953 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_xor (for bitwise_xor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_xor);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2380 "src-gen/compiler_bison.cpp"
    break;

  case 109: /* bitwise_and: bitwise_and t_operators_and shift_expr  */
#line 963 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_and (for bitwise_and)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_and);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2391 "src-gen/compiler_bison.cpp"
    break;

  case 111: /* shift_expr: shift_expr t_operators_sleft sum  */
#line 973 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sleft (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sleft);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2402 "src-gen/compiler_bison.cpp"
    break;

  case 112: /* shift_expr: shift_expr t_operators_sright sum  */
#line 980 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sright (for shift_expr)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sright);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2413 "src-gen/compiler_bison.cpp"
    break;

  case 114: /* sum: sum t_operators_add term  */
#line 990 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_add);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2424 "src-gen/compiler_bison.cpp"
    break;

  case 115: /* sum: sum t_operators_sub term  */
#line 997 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for sum)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_sub);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2435 "src-gen/compiler_bison.cpp"
    break;

  case 117: /* term: term t_operators_mul factor  */
#line 1007 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mul);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2446 "src-gen/compiler_bison.cpp"
    break;

  case 118: /* term: term t_operators_div factor  */
#line 1014 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_div (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_div);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2457 "src-gen/compiler_bison.cpp"
    break;

  case 119: /* term: term t_operators_ediv factor  */
#line 1021 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_ediv (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_ediv);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2468 "src-gen/compiler_bison.cpp"
    break;

  case 120: /* term: term t_operators_mod factor  */
#line 1028 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mod (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_mod);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2479 "src-gen/compiler_bison.cpp"
    break;

  case 121: /* term: term t_operators_at factor  */
#line 1035 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_at (for term)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_at);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2490 "src-gen/compiler_bison.cpp"
    break;

  case 123: /* factor: t_operators_add factor  */
#line 1045 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_add (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_positive);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2500 "src-gen/compiler_bison.cpp"
    break;

  case 124: /* factor: t_operators_sub factor  */
#line 1051 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_sub (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_negative);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2510 "src-gen/compiler_bison.cpp"
    break;

  case 125: /* factor: t_operators_not factor  */
#line 1057 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_not (for factor)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_wavenot);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2520 "src-gen/compiler_bison.cpp"
    break;

  case 127: /* power: await_primary t_operators_pow factor  */
#line 1066 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for power)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_power);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2531 "src-gen/compiler_bison.cpp"
    break;

  case 129: /* await_primary: t_keyword_await primary  */
#line 1076 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_await (for await_primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_await);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2541 "src-gen/compiler_bison.cpp"
    break;

  case 131: /* primary: primary t_delimiter_dot t_identifier  */
#line 1085 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_dot (for primary)");
                LOG_ASTNODE("t_identifier (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_dot);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom));
            }
#line 2553 "src-gen/compiler_bison.cpp"
    break;

  case 132: /* primary: primary t_bracket_parentheses_l t_bracket_parentheses_r  */
#line 1093 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat(make_empty_astnode());
            }
#line 2565 "src-gen/compiler_bison.cpp"
    break;

  case 133: /* primary: primary t_bracket_parentheses_l arguments_or_parameters t_bracket_parentheses_r  */
#line 1101 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for primary)");
                LOG_ASTNODE("t_bracket_parentheses_r (for primary)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_fcall);
                (yyval.astnode_ptr)->eat((yyvsp[-3].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[-1].astnode_ptr));
            }
#line 2577 "src-gen/compiler_bison.cpp"
    break;

  case 134: /* atom: t_identifier  */
#line 1112 "src/parser.y"
            {
                LOG_ASTNODE("t_identifier (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2586 "src-gen/compiler_bison.cpp"
    break;

  case 135: /* atom: t_keyword_True  */
#line 1117 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_True (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2595 "src-gen/compiler_bison.cpp"
    break;

  case 136: /* atom: t_keyword_False  */
#line 1122 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_False (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2604 "src-gen/compiler_bison.cpp"
    break;

  case 137: /* atom: t_keyword_None  */
#line 1127 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_None (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2613 "src-gen/compiler_bison.cpp"
    break;

  case 138: /* atom: t_keyword_underline  */
#line 1132 "src/parser.y"
            {
                LOG_ASTNODE("t_keyword_underline (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2622 "src-gen/compiler_bison.cpp"
    break;

  case 139: /* atom: t_number  */
#line 1137 "src/parser.y"
            {
                LOG_ASTNODE("t_number (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2631 "src-gen/compiler_bison.cpp"
    break;

  case 140: /* atom: t_delimiter_3dot  */
#line 1142 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_3dot (for atom)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[0].token_ptr), astnode_type::atom);
            }
#line 2640 "src-gen/compiler_bison.cpp"
    break;

  case 142: /* atom: t_bracket_parentheses_l yield_expr t_bracket_parentheses_r  */
#line 1148 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2650 "src-gen/compiler_bison.cpp"
    break;

  case 143: /* atom: t_bracket_parentheses_l _normal_expression t_bracket_parentheses_r  */
#line 1154 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_parentheses_l (for atom)");
                LOG_ASTNODE("t_bracket_parentheses_r (for atom)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2660 "src-gen/compiler_bison.cpp"
    break;

  case 144: /* strings: string_text  */
#line 1166 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_strings);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2669 "src-gen/compiler_bison.cpp"
    break;

  case 145: /* strings: strings string_text  */
#line 1171 "src/parser.y"
            {
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2677 "src-gen/compiler_bison.cpp"
    break;

  case 146: /* string_text: t_bracket_dquotes t_strtext t_bracket_dquotes  */
#line 1177 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_dquotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 2688 "src-gen/compiler_bison.cpp"
    break;

  case 147: /* string_text: t_bracket_squotes t_strtext t_bracket_squotes  */
#line 1184 "src/parser.y"
            {
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                LOG_ASTNODE("t_strtext (for string_text)");
                LOG_ASTNODE("t_bracket_squotes (for string_text)");
                (yyval.astnode_ptr) = make_astnode_from_token((yyvsp[-1].token_ptr), astnode_type::atom);
            }
#line 2699 "src-gen/compiler_bison.cpp"
    break;

  case 149: /* arguments_or_parameters: argparas t_delimiter_comma  */
#line 1194 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for arguments_or_parameters)");
                (yyval.astnode_ptr) = (yyvsp[-1].astnode_ptr);
            }
#line 2708 "src-gen/compiler_bison.cpp"
    break;

  case 150: /* argparas: argpara  */
#line 1201 "src/parser.y"
            {
                (yyval.astnode_ptr) = make_astnode(astnode_type::list_op_args_or_prams);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2717 "src-gen/compiler_bison.cpp"
    break;

  case 151: /* argparas: argparas t_delimiter_comma argpara  */
#line 1206 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_comma (for argparas)");
                (yyval.astnode_ptr) = (yyvsp[-2].astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2726 "src-gen/compiler_bison.cpp"
    break;

  case 153: /* argpara: primary t_delimiter_colon primary  */
#line 1214 "src/parser.y"
            {
                LOG_ASTNODE("t_delimiter_colon (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_aptype);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2737 "src-gen/compiler_bison.cpp"
    break;

  case 154: /* argpara: t_operators_mul _expression_if_else  */
#line 1221 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_mul (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2747 "src-gen/compiler_bison.cpp"
    break;

  case 155: /* argpara: t_operators_pow _expression_if_else  */
#line 1227 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_pow (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::sin_op_apdstar);
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2757 "src-gen/compiler_bison.cpp"
    break;

  case 156: /* argpara: primary t_operators_assign _expression_if_else  */
#line 1233 "src/parser.y"
            {
                LOG_ASTNODE("t_operators_assign (for argpara)");
                (yyval.astnode_ptr) = make_astnode(astnode_type::bin_op_apequ);
                (yyval.astnode_ptr)->eat((yyvsp[-2].astnode_ptr));
                (yyval.astnode_ptr)->eat((yyvsp[0].astnode_ptr));
            }
#line 2768 "src-gen/compiler_bison.cpp"
    break;

  case 157: /* argpara: primary t_delimiter_colon primary t_operators_assign _expression_if_else  */
#line 1240 "src/parser.y"
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
#line 2783 "src-gen/compiler_bison.cpp"
    break;

  case 158: /* ast_error: t_error  */
#line 1256 "src/parser.y"
                  { GEN_ERROR_NODE("t_error (for ast_error)", (yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2789 "src-gen/compiler_bison.cpp"
    break;

  case 159: /* ast_error: t_bracket_square_l  */
#line 1273 "src/parser.y"
                             { BRACKET((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2795 "src-gen/compiler_bison.cpp"
    break;

  case 160: /* ast_error: t_bracket_square_r  */
#line 1274 "src/parser.y"
                             { BRACKET((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2801 "src-gen/compiler_bison.cpp"
    break;

  case 161: /* ast_error: t_bracket_curly_l  */
#line 1275 "src/parser.y"
                            { BRACKET((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2807 "src-gen/compiler_bison.cpp"
    break;

  case 162: /* ast_error: t_bracket_curly_r  */
#line 1276 "src/parser.y"
                            { BRACKET((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2813 "src-gen/compiler_bison.cpp"
    break;

  case 163: /* ast_error: t_keyword_lambda  */
#line 1326 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2819 "src-gen/compiler_bison.cpp"
    break;

  case 164: /* ast_error: t_keyword_for  */
#line 1331 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2825 "src-gen/compiler_bison.cpp"
    break;

  case 165: /* ast_error: t_keyword_match  */
#line 1334 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2831 "src-gen/compiler_bison.cpp"
    break;

  case 166: /* ast_error: t_keyword_case  */
#line 1335 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2837 "src-gen/compiler_bison.cpp"
    break;

  case 167: /* ast_error: t_keyword_global  */
#line 1336 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2843 "src-gen/compiler_bison.cpp"
    break;

  case 168: /* ast_error: t_keyword_nonlocal  */
#line 1337 "src/parser.y"
                             { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2849 "src-gen/compiler_bison.cpp"
    break;

  case 169: /* ast_error: t_keyword_del  */
#line 1338 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2855 "src-gen/compiler_bison.cpp"
    break;

  case 170: /* ast_error: t_keyword_import  */
#line 1339 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2861 "src-gen/compiler_bison.cpp"
    break;

  case 171: /* ast_error: t_keyword_from  */
#line 1340 "src/parser.y"
                         { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2867 "src-gen/compiler_bison.cpp"
    break;

  case 172: /* ast_error: t_keyword_as  */
#line 1341 "src/parser.y"
                       { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2873 "src-gen/compiler_bison.cpp"
    break;

  case 173: /* ast_error: t_keyword_raise  */
#line 1342 "src/parser.y"
                          { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2879 "src-gen/compiler_bison.cpp"
    break;

  case 174: /* ast_error: t_keyword_try  */
#line 1343 "src/parser.y"
                        { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2885 "src-gen/compiler_bison.cpp"
    break;

  case 175: /* ast_error: t_keyword_except  */
#line 1344 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2891 "src-gen/compiler_bison.cpp"
    break;

  case 176: /* ast_error: t_keyword_finally  */
#line 1345 "src/parser.y"
                            { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2897 "src-gen/compiler_bison.cpp"
    break;

  case 177: /* ast_error: t_keyword_assert  */
#line 1346 "src/parser.y"
                           { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2903 "src-gen/compiler_bison.cpp"
    break;

  case 178: /* ast_error: t_keyword_tastror_out  */
#line 1347 "src/parser.y"
                                { KEYWORD((yyval.astnode_ptr), (yyvsp[0].token_ptr)); }
#line 2909 "src-gen/compiler_bison.cpp"
    break;


#line 2913 "src-gen/compiler_bison.cpp"

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

#line 1349 "src/parser.y"


void yyerror(AstNode*& ast_head, char* msg)
{
    stdlog::log << stdlog::error
        << "line " << yylineno << ", column " << yycolumnno - last_string_length
        << ": '" << last_string << "' " << msg
        << stdlog::endl;
}
