%{
#include "y.tab.h"
#include "symbols.h"
#include <string.h>

void yyerror(const char *s);
%}

%option nounput
%option noinput

DIGIT    [0-9]
LETTER   [a-zA-Z_]
ID       {LETTER}({LETTER}|{DIGIT})*
WS       [ \t\r\n]+
STRING   \"(\\.|[^"\\])*\"

%%

{WS}                        { /* ignorar */ }
"##"[^\n]* { /* comentario línea */ }
"#*"([^*]|\*+[^#])*"*#"     { /* comentario bloque */ }

"halo"          { return HALO; }
"transmitir"    { return TRANSMITIR; }
"escudo"        { return INT_TYPE; }
"energia"       { return DOUBLE_TYPE; }
"spartan"       { return CHAR_TYPE; }
"mision"        { return STRING_TYPE; }
"covenant"      { return BOOL_TYPE; }
"activo"        { yylval.b_val = 1; return BOOL_LITERAL; }
"inactivo"      { yylval.b_val = 0; return BOOL_LITERAL; }

"si"            { return SI; }
"sino"          { return SINO; }
"mientras"      { return MIENTRAS; }

"mision_inicio" { return FUNC_DEF; }
"activar"       { return FUNC_CALL; }
"retornar"      { return RETORNAR; }

"<-"            { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return SUB; }
"*"             { return MULT; }
"/"             { return DIV; }

"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }

"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

";"             { return SEMICOLON; }
"("             { return LPARENT; }
")"             { return RPARENT; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

{DIGIT}+\.{DIGIT}+ {
    yylval.d_val = atof(yytext);
    return DOUBLE_LITERAL;
}

{DIGIT}+ {
    yylval.i_val = atoi(yytext);
    return INT_LITERAL;
}

{STRING} {
    /* Quitar comillas */
    yylval.s_val = strndup(yytext + 1, strlen(yytext) - 2);
    return STRING_LITERAL;
}

\'{LETTER}\' {
    yylval.c_val = yytext[1];
    return CHAR_LITERAL;
}

{ID} {
    yylval.s_val = strdup(yytext);
    return IDENTIFIER;
}

. {
    printf("Error: caracter inesperado %s\n", yytext);
}

%%

int yywrap() {
    return 1;
}