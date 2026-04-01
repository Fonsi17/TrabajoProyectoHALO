%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"
/* El include de ast.h se queda aquí para el .c */
#include "ast.h"

int  yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

ASTNode *ast_root = NULL;
%}

/* ESTE ES EL BLOQUE QUE DEBES AGREGAR */
%code requires {
    #include "ast.h"
}

/* ============================================================
 * UNIÓN SEMÁNTICA
 * ============================================================ */
%union {
    int       i_val;
    int       b_val;
    double    d_val;
    char      c_val;
    char     *s_val;
    int       type_enum;
    ASTNode  *node;  /* Ahora el compilador ya sabrá qué es ASTNode */
}

/* ============================================================
   TOKENS
   ============================================================ */
%token HALO TRANSMITIR
%token SI SINO MIENTRAS
%token FUNC_DEF FUNC_CALL RETORNAR
%token INT_TYPE CHAR_TYPE DOUBLE_TYPE BOOL_TYPE STRING_TYPE
%token SEMICOLON ASSIGN LPARENT RPARENT LBRACE RBRACE
%token PLUS SUB MULT DIV
%token EQ NEQ LT GT LEQ GEQ
%token AND OR NOT

%token <s_val>  IDENTIFIER
%token <i_val>  INT_LITERAL
%token <d_val>  DOUBLE_LITERAL
%token <c_val>  CHAR_LITERAL
%token <b_val>  BOOL_LITERAL
%token <s_val>  STRING_LITERAL

/* ============================================================
   PRECEDENCIAS
   ============================================================ */
%left OR
%left AND
%right NOT
%left EQ NEQ
%left LT GT LEQ GEQ
%left PLUS SUB
%left MULT DIV
%right UMINUS

/* ============================================================
   TIPOS DE NO TERMINALES (Declaraciones)
   ============================================================ */
%type <type_enum> tipo_dato
%type <node>      expresion sentencia lista_sentencias bloque programa
%type <node>      definicion_variable asignacion sentencia_transmitir
%type <node>      sentencia_si sentencia_mientras definicion_funcion
%type <node>      llamada_funcion sentencia_retornar

%% 
/* ============================================================
   GRAMÁTICA (Inicia después del primer %%)
   ============================================================ */

programa:
    lista_sentencias        { ast_root = $1; }
    ;

lista_sentencias:
    lista_sentencias sentencia  { $$ = ($1 || $2) ? ast_make_seq($1, $2) : NULL; }
    | /* vacío */               { $$ = NULL; }
    ;

bloque:
    LBRACE lista_sentencias RBRACE  { $$ = ast_make_block($2); }
    ;

sentencia:
    definicion_variable SEMICOLON   { $$ = $1; }
    | asignacion SEMICOLON          { $$ = $1; }
    | sentencia_transmitir SEMICOLON { $$ = $1; }
    | sentencia_si                  { $$ = $1; }
    | sentencia_mientras            { $$ = $1; }
    | definicion_funcion            { $$ = $1; }
    | llamada_funcion SEMICOLON     { $$ = $1; }
    | sentencia_retornar SEMICOLON  { $$ = $1; }
    | bloque                        { $$ = $1; }
    ;

tipo_dato:
    INT_TYPE      { $$ = TYPE_ESCUDO; }
    | DOUBLE_TYPE { $$ = TYPE_ENERGIA; }
    | CHAR_TYPE   { $$ = TYPE_SPARTAN; }
    | STRING_TYPE { $$ = TYPE_MISION; }
    | BOOL_TYPE   { $$ = TYPE_COVENANT; }
    ;

expresion:
    INT_LITERAL                          { $$ = ast_make_int($1); }
    | DOUBLE_LITERAL                     { $$ = ast_make_double($1); }
    | CHAR_LITERAL                       { $$ = ast_make_char($1); }
    | BOOL_LITERAL                       { $$ = ast_make_bool($1); }
    | STRING_LITERAL                     { $$ = ast_make_string($1); free($1); }
    | IDENTIFIER                         { $$ = ast_make_id($1); free($1); }
    | expresion PLUS expresion           { $$ = ast_make_binop(NODE_ADD, $1, $3); }
    | expresion SUB  expresion           { $$ = ast_make_binop(NODE_SUB, $1, $3); }
    | expresion MULT expresion           { $$ = ast_make_binop(NODE_MUL, $1, $3); }
    | expresion DIV  expresion           { $$ = ast_make_binop(NODE_DIV, $1, $3); }
    | SUB expresion %prec UMINUS         { $$ = ast_make_binop(NODE_MUL, ast_make_int(-1), $2); }
    | expresion EQ  expresion            { $$ = ast_make_binop(NODE_EQ,  $1, $3); }
    | expresion NEQ expresion            { $$ = ast_make_binop(NODE_NEQ, $1, $3); }
    | expresion LT  expresion            { $$ = ast_make_binop(NODE_LT,  $1, $3); }
    | expresion GT  expresion            { $$ = ast_make_binop(NODE_GT,  $1, $3); }
    | expresion LEQ expresion            { $$ = ast_make_binop(NODE_LEQ, $1, $3); }
    | expresion GEQ expresion            { $$ = ast_make_binop(NODE_GEQ, $1, $3); }
    | expresion AND expresion            { $$ = ast_make_binop(NODE_AND, $1, $3); }
    | expresion OR  expresion            { $$ = ast_make_binop(NODE_OR,  $1, $3); }
    | NOT expresion                      { $$ = ast_make_not($2); }
    | LPARENT expresion RPARENT          { $$ = $2; }
    ;

definicion_variable:
    HALO tipo_dato IDENTIFIER ASSIGN expresion {
        $$ = ast_make_decl((DataType)$2, $3, $5);
        free($3);
    }
    ;

asignacion:
    IDENTIFIER ASSIGN expresion {
        $$ = ast_make_assign($1, $3);
        free($1);
    }
    ;

sentencia_transmitir:
    TRANSMITIR expresion { $$ = ast_make_transmitir($2); }
    ;

sentencia_si:
    SI LPARENT expresion RPARENT bloque { $$ = ast_make_if($3, $5, NULL); }
    | SI LPARENT expresion RPARENT bloque SINO bloque { $$ = ast_make_if($3, $5, $7); }
    ;

sentencia_mientras:
    MIENTRAS LPARENT expresion RPARENT bloque { $$ = ast_make_while($3, $5); }
    ;

definicion_funcion:
    FUNC_DEF IDENTIFIER bloque {
        $$ = ast_make_func_def($2, $3);
        free($2);
    }
    ;

llamada_funcion:
    FUNC_CALL IDENTIFIER {
        $$ = ast_make_func_call($2);
        free($2);
    }
    ;

sentencia_retornar:
    RETORNAR expresion { $$ = ast_make_return($2); }
    ;

%%
/* ============================================================
   CÓDIGO C FINAL (Inicia después del segundo %%)
   ============================================================ */

void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico: %s\n", s);
}

int main(int argc, char **argv) {
    int print_ast   = 0;
    int print_table = 0;
    char *filename  = NULL;

    for (int i = 1; i < argc; i++) {
        if      (strcmp(argv[i], "--ast")   == 0) print_ast   = 1;
        else if (strcmp(argv[i], "--tabla") == 0) print_table = 1;
        else filename = argv[i];
    }

    if (filename) {
        FILE *f = fopen(filename, "r");
        if (!f) { fprintf(stderr, "No se pudo abrir: %s\n", filename); return 1; }
        yyin = f;
    }

    init_symbol_table();

    if (yyparse() != 0) return 1;

    if (print_ast) {
        printf("\n╔══════════════════════ AST ══════════════════════╗\n");
        ast_print(ast_root, 0);
        printf("╚═════════════════════════════════════════════════╝\n\n");
    }

    ast_exec(ast_root);

    if (print_table) dump_scopes();

    ast_free(ast_root);
    printf("\n[Compilacion exitosa]\n");
    return 0;
}