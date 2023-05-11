
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 40 "yacc.y"

    std::string* text;
    Period *period;
    Periods *period_list;
    Const* num;
    TokenNUM* token;
    List* list;
    ExpList* explist;



/* Line 1676 of yacc.c  */
#line 106 "yacc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


