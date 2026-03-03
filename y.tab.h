/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 92 "practicaYACC.y"
{
    char nombre[30];
    int tipo;
}
/* Line 1529 of yacc.c.  */
#line 152 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

