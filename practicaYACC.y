%{

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int conteoLineas;
extern int conteoErrores;

int yyerror(const char* msg) {
    printf("Línea %d, ERROR SINTÁCTICO: %s\n", conteoLineas, msg);
    conteoErrores++;
}

int yylex(void);
FILE *yyin;

struct Symbol {
    char name[50];
    int tipo;
    int cte;
    int inicializado;
};

struct Symbol symbolTable[100];
int symbolCount = 0;

int findSymbol(char name[50]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addSymbol(char name[50], int tipo, int cte) {
    if (findSymbol(name) == -1) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].tipo = tipo;
        symbolTable[symbolCount].cte = cte;
        symbolCount++;
    } else {
        printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' ya declarado.\n", conteoLineas+1, name);
        conteoErrores++;
    }
}

void initializeSymbol(char name[50]){
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].inicializado = 1;
        }
    }
}

int isInitialized(char name[50]){
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if(symbolTable[i].inicializado == 1){
              return 1;
            } else{
              return 0;
            }
        }
    }
}

int isConstant(char name[50]){
   for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if(symbolTable[i].cte == 1){
              return 1;
            } else{
              return 0;
            }
        }
    }
}

int getSymbolType(char name[50]){
   for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].tipo;
        }
    }
}

%}

%union{
    char nombre[30];
    int tipo;
}

%error-verbose

%token PROGRAM BEGIN_KEYWORD END_KEYWORD IF THEN ELSE WHILE FOR TO DOWNTO VAR CONST WRITELN READLN TRUE FALSE
%token EQUALS SUMA RESTA MULT DIVIS DIV MOD MAYOR MENOR MENOR_O_IGUAL MAYOR_O_IGUAL IGUAL DISTINTO AND OR NOT
%token COMA SEMICOLON PUNTO DOS_PUNTOS A_PARENTESIS C_PARENTESIS
%token <tipo> INTEGER REAL STRING BOOLEAN CTE_CADENA CTE_CHAR CTE_INT CTE_REAL
%token <nombre> ID

%type <tipo> factor term expression text_expression
%%

code: program_definition 
      const_section 
      var_section 
      begin_section 
      instruction_section
      end_section
      {
        if (conteoErrores == 0){
          printf("La entrada es válida.\n");
        } else {
          printf("El programa contiene errores.\n");
          printf("%d errores generados.\n", conteoErrores);
        }
      }
      ;

program_definition: PROGRAM ID SEMICOLON
      {
        printf("Apertura de programa definida.\n");
      }
      ;

const_section: CONST 
               const_list
      {
        printf("Sección de constantes.\n");
      }
      | /* Empty */
      ;

const_list: const_list const_item
      | const_item
      ;

const_item: ID IGUAL CTE_CADENA SEMICOLON
      {
        printf("Declaración de CONSTANTE DE CADENA.\n");
        addSymbol($1, $3, 1);
        initializeSymbol($1);
      }
      | ID IGUAL CTE_CHAR SEMICOLON
      {
        printf("Declaración de CONSTANTE DE CHAR.\n");
        addSymbol($1, $3, 1);
        initializeSymbol($1);
      }
      | ID IGUAL CTE_INT SEMICOLON
      {
        printf("Declaración de CONSTANTE ENTERA.\n");
        addSymbol($1, $3, 1);
        initializeSymbol($1);
      }
      | ID IGUAL CTE_REAL SEMICOLON
      {
        printf("Declaración de CONSTANTE REAL.\n");
        addSymbol($1, $3, 1);
        initializeSymbol($1);
      }
      ;

var_section: VAR 
             var_list
      {
        printf("Sección de variables.\n");
      }
      | /* Empty */
      ;

var_list: var_list var_item
      | var_item
      ;

var_item: ID DOS_PUNTOS INTEGER SEMICOLON
      {
            printf("Declaración de INTEGER\n");
            addSymbol($1, $3, 0);
      }
      | ID DOS_PUNTOS REAL SEMICOLON
      {
            printf("Declaración de REAL\n");
            addSymbol($1, $3, 0);
      }
      | ID DOS_PUNTOS STRING SEMICOLON
      {
            printf("Declaración de STRING\n");
            addSymbol($1, $3, 0);
      }
      | ID DOS_PUNTOS BOOLEAN SEMICOLON
      {
            printf("Declaración de BOOLEAN\n");
            addSymbol($1, $3, 0);
      }
      ;

begin_section: BEGIN_KEYWORD
      {
        printf("Inicio de bloque de código.\n");
      }
      ;

instruction_section: instruction_section instruction
      | instruction
      ;

instruction: assignment SEMICOLON
      {
        printf("Instrucción de asignación.\n");
      }
      | write_instruction SEMICOLON
      {
        printf("Instrucción de escritura.\n");
      }
      | read_instruction SEMICOLON
      {
        printf("Instrucción de lectura.\n");
      }
      | if_sentence SEMICOLON
      {
        printf("Sentencia condicional.\n");
      }
      | while_sentence SEMICOLON
      {
        printf("Sentencia bucle WHILE.\n");
      }
      | for_sentence SEMICOLON
      {
        printf("Sentencia bucle FOR.\n");
      }
      | /* Empty */
      ;

assignment: ID EQUALS expression
      {
        if (findSymbol($1) == -1){
            printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, $1);
            conteoErrores++;
        } else {
          if (getSymbolType($1) != $3){
             printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la asignación de '%s'.\n", conteoLineas+1, $1);
             conteoErrores++;
          }
        }
        
        
       if (isInitialized($1) == 0)
          initializeSymbol($1);
        
       if (isConstant($1) == 1){
          printf("Línea %d, ERROR SEMÁNTICO: Las constantes no se pueden redefinir.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
      | ID EQUALS text_expression {
        if (findSymbol($1) == -1){
            printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, $1);
            conteoErrores++;
        } else {
          if (getSymbolType($1) != $3){
             printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la asignación de '%s'.\n", conteoLineas+1, $1);
             conteoErrores++;
          }
        }

       if (isInitialized($1) == 0)
          initializeSymbol($1);
        
       if (isConstant($1) == 1){
          printf("Línea %d, ERROR SEMÁNTICO: Las constantes no se pueden redefinir.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
      ;

write_instruction: WRITELN A_PARENTESIS writeln_arguments C_PARENTESIS
      ;

read_instruction: READLN A_PARENTESIS ID C_PARENTESIS
        {
          if (isInitialized($3) == 0)
            initializeSymbol($3);
        }
      ;

if_sentence: IF A_PARENTESIS boolean_expression C_PARENTESIS THEN
             BEGIN_KEYWORD
             instruction_section
             END_KEYWORD
           | IF A_PARENTESIS boolean_expression C_PARENTESIS THEN
             BEGIN_KEYWORD 
             instruction_section
             END_KEYWORD
             ELSE
             BEGIN_KEYWORD
             instruction_section
             END_KEYWORD
            ;

while_sentence: WHILE A_PARENTESIS boolean_expression C_PARENTESIS
                BEGIN_KEYWORD
                instruction_section
                END_KEYWORD
               ;

for_sentence: FOR A_PARENTESIS ID EQUALS CTE_INT TO CTE_INT C_PARENTESIS
              BEGIN_KEYWORD
              instruction_section
              END_KEYWORD {
                if(getSymbolType($3) != 1){
                   printf("Línea %d, ERROR SEMÁNTICO: Los identificadores usados en las sentencias FOR deben ser siempre de tipo entero.\n", conteoLineas+1);
                   conteoErrores++;
                }
              }
            | FOR A_PARENTESIS ID EQUALS CTE_INT DOWNTO CTE_INT C_PARENTESIS
              BEGIN_KEYWORD
              instruction_section
              END_KEYWORD {
                if(getSymbolType($3) != 1){
                  printf("Línea %d, ERROR SEMÁNTICO: Los identificadores usados en las sentencias FOR deben ser siempre de tipo entero.\n", conteoLineas+1);
                  conteoErrores++;
                }

              }
             ;

expression_list: expression_list COMA expression
      | expression
      ;

expression: term {
        $$ = $1;
      }
      | expression SUMA term {
        if ($1 != $3) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de suma.\n", conteoLineas+1);
          conteoErrores++;
        }

      }
      | expression RESTA term{
        if ($1 != $3) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de resta.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
      ;

term: factor {
        $$ = $1;
      }
      | term MULT factor{
        if ($1 != $3) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de multiplicación.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
      | term DIVIS factor{
        if ($1 != $3) {
          printf("Línea %d, ERROR SEMÁNTICO: Tipos incompatibles en la operación de división.\n", conteoLineas+1);
          conteoErrores++;
        }
      }
      | term MOD factor
      ;

factor: ID
      {
        if (findSymbol($1) == -1){
          printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no declarado.\n", conteoLineas+1, $1);
          conteoErrores++;
        } else if (isInitialized($1) == 0){
          printf("Línea %d, ERROR SEMÁNTICO: Identificador '%s' no inicializado.\n", conteoLineas+1, $1);
          conteoErrores++;
        }

        $$ = getSymbolType($1);

      }
      | CTE_INT {
        $$ = 1;
      }
      | CTE_REAL {
        $$ = 2;
      }
      | A_PARENTESIS expression C_PARENTESIS
      ;

writeln_arguments: text_expression COMA expression
      | text_expression
      | expression
      ;

text_expression: CTE_CADENA {
                $$ = 3;
              }
               | CTE_CHAR {
                $$ = 3;
              }
               ;

boolean_expression: boolean_expression AND boolean_member
                    | boolean_expression OR boolean_member
                    | boolean_member
      ;

boolean_member: comparison_expression
      | NOT comparison_expression
      | A_PARENTESIS boolean_expression C_PARENTESIS
      ;

comparison_expression: expression EQUALS expression
      | expression DISTINTO expression
      | expression MAYOR expression
      | expression MENOR expression
      | expression MAYOR_O_IGUAL expression
      | expression MENOR_O_IGUAL expression
      | A_PARENTESIS comparison_expression C_PARENTESIS
      ;

end_section: END_KEYWORD PUNTO
      {
        printf("Fin del programa.\n");
      }
      ;

error_handler: error {
              yyerrok;
              yyclearin; 
            }
            ;

%%

int main()
{
    yyin=fopen("./Ficheros/entradaSintactico.pas","r");

    freopen("./Ficheros/salida.txt", "w", stdout);
    yyparse();
    fclose(stdout);

    return 0;
}
