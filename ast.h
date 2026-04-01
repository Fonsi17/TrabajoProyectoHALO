#ifndef AST_H
#define AST_H

#include "symbols.h"

/* ============================================================
 *  TIPOS DE NODOS DEL AST
 * ============================================================ */
typedef enum {
    /* Literales */
    NODE_INT_LIT, NODE_DOUBLE_LIT, NODE_CHAR_LIT, NODE_BOOL_LIT, NODE_STRING_LIT,

    /* Identificador */
    NODE_IDENTIFIER,

    /* Aritmética */
    NODE_ADD, NODE_SUB, NODE_MUL, NODE_DIV,

    /* Comparación */
    NODE_EQ, NODE_NEQ, NODE_LT, NODE_GT, NODE_LEQ, NODE_GEQ,

    /* Lógica */
    NODE_AND, NODE_OR, NODE_NOT,

    /* Sentencias */
    NODE_DECL,           /* halo tipo id <- expr  */
    NODE_ASSIGN,         /* id <- expr            */
    NODE_TRANSMITIR,     /* transmitir expr       */
    NODE_IF,             /* si (cond) bloque [sino bloque] */
    NODE_WHILE,          /* mientras (cond) bloque        */
    NODE_BLOCK,          /* { lista_sentencias }          */
    NODE_FUNC_DEF,       /* mision_inicio nombre bloque   */
    NODE_FUNC_CALL,      /* activar nombre                */
    NODE_SEQ,            /* secuencia de dos nodos        */
    NODE_RETURN          /* retornar expr                 */
} NodeType;

/* ============================================================
 *  NODO DEL AST
 * ============================================================ */
typedef struct ASTNode {
    NodeType  type;

    union {
        int    i_val;
        double d_val;
        char   c_val;
        int    b_val;
        char  *s_val;
    } value;

    DataType data_type;   /* para NODE_DECL e identificadores   */
    char    *name;        /* para ID, funciones, DECL           */

    struct ASTNode *left;   /* expr izq / condición / init / body */
    struct ASTNode *right;  /* expr der / then-branch             */
    struct ASTNode *extra;  /* else-branch en NODE_IF             */
    struct ASTNode *next;   /* encadenado (no usado con SEQ)      */
} ASTNode;

/* ============================================================
 *  API
 * ============================================================ */
ASTNode* ast_make_int      (int v);
ASTNode* ast_make_double   (double v);
ASTNode* ast_make_char     (char v);
ASTNode* ast_make_bool     (int v);
ASTNode* ast_make_string   (char *v);
ASTNode* ast_make_id       (char *name);
ASTNode* ast_make_binop    (NodeType op, ASTNode *l, ASTNode *r);
ASTNode* ast_make_not      (ASTNode *operand);
ASTNode* ast_make_decl     (DataType dt, char *name, ASTNode *expr);
ASTNode* ast_make_assign   (char *name, ASTNode *expr);
ASTNode* ast_make_transmitir(ASTNode *expr);
ASTNode* ast_make_if       (ASTNode *cond, ASTNode *then_b, ASTNode *else_b);
ASTNode* ast_make_while    (ASTNode *cond, ASTNode *body);
ASTNode* ast_make_block    (ASTNode *stmts);
ASTNode* ast_make_seq      (ASTNode *left, ASTNode *right);
ASTNode* ast_make_func_def (char *name, ASTNode *body);
ASTNode* ast_make_func_call(char *name);
ASTNode* ast_make_return   (ASTNode *expr);

double   ast_eval (ASTNode *node);
void     ast_exec (ASTNode *node);
void     ast_print(ASTNode *node, int indent);
void     ast_free (ASTNode *node);

#endif
