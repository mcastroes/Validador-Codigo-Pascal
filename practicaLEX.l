%{
    #include <stdio.h>
    #include "y.tab.h"
    int conteoLineas = 0;
    int conteoErrores = 0;
%}

/* SECCION TOKENS */
/* Caracteres comunes */
DIGITO  [0-9]
LETRA   [a-zA-Z]

/*Expresiones complejas*/
CONST_STRING ["](.*)["]
CONST_CHAR ['](.*)[']
CONST_INT {DIGITO}*
CONST_REAL {DIGITO}*("."){DIGITO}+
COMENTARIO ("(*")(.*)("*)")
ID  {LETRA}({LETRA}|{DIGITO})*

%%
PROGRAM|program {return PROGRAM;}
BEGIN|begin {return BEGIN_KEYWORD;}
END|end {return END_KEYWORD;}
IF|if {return IF;}
THEN|then {return THEN;}
ELSE|else {return ELSE;}
WHILE|while {return WHILE;}
FOR|for {return FOR;}
TO|to {return TO;}
DOWNTO|downto {return DOWNTO;}
VAR|var {return VAR;}
CONST|const {return CONST;}
WRITELN|writeln {return WRITELN;}
READLN|readln {return READLN;}
INTEGER|integer {yylval.tipo = 1;
                 return INTEGER;}
REAL|real {yylval.tipo = 2;
           return REAL;}
STRING|string {yylval.tipo = 3;
               return STRING;}
BOOLEAN|boolean {yylval.tipo = 4;
                 return BOOLEAN;}
TRUE|true {return TRUE;}
FALSE|false {return FALSE;}

":=" {return EQUALS;}
"+" {return SUMA;}
"-" {return RESTA;}
"*" {return MULT;}
"/" {return DIVIS;}
div {return DIV;}
mod {return MOD;}
"<" {return MAYOR;}
">" {return MENOR;}
"<=" { return MENOR_O_IGUAL;} 
">=" { return MAYOR_O_IGUAL;}
"=" {  return IGUAL;}
"<>" { return DISTINTO;}
and|AND {return AND;}
or|OR {return OR;}
not|NOT {return NOT;}

"," {return COMA;}
";" {return SEMICOLON;}
"." {return PUNTO;}
":" {return DOS_PUNTOS;}
"(" {return A_PARENTESIS;}
")" {return C_PARENTESIS;}

" " { /* Ignorar espacios */ }
\t { /* Ignorar saltos de tabulador */ }
\n {conteoLineas++;}
{COMENTARIO} {/* Ignorar comentarios */}

{CONST_STRING} {yylval.tipo = 5;
                return CTE_CADENA;}
{CONST_CHAR} {yylval.tipo = 6;
              return CTE_CHAR;}
{CONST_INT} {yylval.tipo = 7;
             return CTE_INT;}
{CONST_REAL} {yylval.tipo = 8;
              return CTE_REAL;}
{ID} {strcpy(yylval.nombre,yytext);
        return ID;}

. {fprintf(yyout, "Línea %d, ERROR LÉXICO: token no reconocido: %s \n",conteoLineas, yytext); conteoErrores++;}

%%

int yywrap(){return 1;}
        