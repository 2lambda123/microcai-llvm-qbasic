/* A Bison parser, made by GNU Bison 2.6.2.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

/**
 ** \file /Users/kiyangqi/Desktop/llvm-qbasic/compiler/parser.hpp
 ** Define the qb::parser class.
 */

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef YY_USERS_KIYANGQI_DESKTOP_LLVM_QBASIC_COMPILER_PARSER_HPP
# define YY_USERS_KIYANGQI_DESKTOP_LLVM_QBASIC_COMPILER_PARSER_HPP



#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Line 267 of lalr1.cc  */
#line 21 "parser.ypp"
namespace qb {
/* Line 267 of lalr1.cc  */
#line 60 "/Users/kiyangqi/Desktop/llvm-qbasic/compiler/parser.hpp"

  /// A Bison parser.
  class parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {
/* Line 267 of lalr1.cc  */
#line 61 "parser.ypp"

	char *				string;         /* quoted string */
	std::string *		id;         /* general symbol */
	double 				number;        /* double number */
	long				integer;			/* long number */

	NamedExprAST *		varref;
	ExprAST*			expression;
	ExprListAST*		expression_list;

	PrintIntroAST*		printinto;
	
	
	ExprType *  		exprtype; // name of the type
	ConstNumberExprAST* number_expression;
	CallExprAST*		call_function;

    PrintStmtAST*		printstatement;
	StatementAST*		statement;
	StatementsAST*		statement_list;
	AssigmentAST*		variable_assignment;
	CodeBlockAST*		codeblocks;
	IFStmtAST * 		if_clause;
	
	WhileLoopAST* 		while_loop;
	ForLoopAST*			for_loop;
	
	VariableDimAST*		dim_item;
	ArgumentDimsAST*	arg_list;
	FunctionDimAST*		function_definition;

	PrintIntroAST *print_intro;
	std::string 	*cppstring;


/* Line 267 of lalr1.cc  */
#line 108 "/Users/kiyangqi/Desktop/llvm-qbasic/compiler/parser.hpp"
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     tEOPROG = 258,
     tOR = 259,
     tAND = 260,
     tNOT = 261,
     tNEQ = 262,
     tGEQ = 263,
     tLEQ = 264,
     tLTN = 265,
     tGTN = 266,
     tEQU = 267,
     tMOD = 268,
     UPLUS = 269,
     UMINUS = 270,
     tPOW = 271,
     tDREF = 272,
     tNEWLINE = 273,
     tAS = 274,
     tSUB = 275,
     tSUBEND = 276,
     tFUNCTION = 277,
     tFUNCTIONEND = 278,
     tRETURN = 279,
     tLET = 280,
     tPRINT = 281,
     tARRAYDIM = 282,
     tDIM = 283,
     tSTRUCTDIM = 284,
     tENDSTRUCDIM = 285,
     tIF = 286,
     tTHEN = 287,
     tENDIF = 288,
     tELSE = 289,
     tELSEIF = 290,
     tWHILE = 291,
     tENDWHILE = 292,
     tFOR = 293,
     tENDFOR = 294,
     tTO = 295,
     tSTEP = 296,
     tLONG = 297,
     tSTR = 298,
     tID = 299,
     tInteger = 300,
     tSTRING = 301,
     tNUMBER = 302
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const signed char yypact_ninf_;

    /// For a state, default reduction number.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const short int yytable_[];
    static const signed char yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[]; 

#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

    /// A type to store symbol numbers and -1.
    typedef signed char rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

  };
/* Line 267 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 267 of lalr1.cc  */
#line 337 "/Users/kiyangqi/Desktop/llvm-qbasic/compiler/parser.hpp"



#endif /* !YY_USERS_KIYANGQI_DESKTOP_LLVM_QBASIC_COMPILER_PARSER_HPP  */
