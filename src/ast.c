#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

/* ============================================================
 * Registro de funciones del usuario
 * ============================================================ */
#define MAX_FUNCS 256

typedef struct {
    char    *name;
    ASTNode *body;
} FuncEntry;

static FuncEntry func_table[MAX_FUNCS];
static int       func_count = 0;

/* Señal de retorno: cuando un NODE_RETURN se ejecuta, levanta esta bandera
   para que ast_exec deje de procesar sentencias en la función actual.    */
static int  g_return_flag  = 0;
static double g_return_val = 0.0;

static void register_func(char *name, ASTNode *body) {
    if (func_count >= MAX_FUNCS) {
        fprintf(stderr, "Error: límite de funciones alcanzado\n");
        return;
    }
    /* Buscar si ya existe (redefinición) */
    for (int i = 0; i < func_count; i++) {
        if (strcmp(func_table[i].name, name) == 0) {
            func_table[i].body = body;
            return;
        }
    }
    func_table[func_count].name = strdup(name);
    func_table[func_count].body = body;
    func_count++;
}

static ASTNode* find_func(char *name) {
    for (int i = 0; i < func_count; i++)
        if (strcmp(func_table[i].name, name) == 0)
            return func_table[i].body;
    return NULL;
}

/* ============================================================
 * Helper: nodo vacío
 * ============================================================ */
static ASTNode* new_node(NodeType t) {
    ASTNode *n = (ASTNode*) calloc(1, sizeof(ASTNode));
    if (!n) { fprintf(stderr, "Error: sin memoria\n"); exit(1); }
    n->type = t;
    return n;
}

/* ============================================================
 * CONSTRUCTORES
 * ============================================================ */
ASTNode* ast_make_int(int v)          { ASTNode *n=new_node(NODE_INT_LIT);    n->value.i_val=v; n->data_type=TYPE_ESCUDO;   return n; }
ASTNode* ast_make_double(double v)    { ASTNode *n=new_node(NODE_DOUBLE_LIT); n->value.d_val=v; n->data_type=TYPE_ENERGIA;  return n; }
ASTNode* ast_make_char(char v)        { ASTNode *n=new_node(NODE_CHAR_LIT);   n->value.c_val=v; n->data_type=TYPE_SPARTAN;  return n; }
ASTNode* ast_make_bool(int v)         { ASTNode *n=new_node(NODE_BOOL_LIT);   n->value.b_val=v; n->data_type=TYPE_COVENANT; return n; }

ASTNode* ast_make_string(char *v) {
    ASTNode *n = new_node(NODE_STRING_LIT);
    n->value.s_val = strdup(v);
    n->data_type   = TYPE_MISION;
    return n;
}

ASTNode* ast_make_id(char *name) {
    ASTNode *n = new_node(NODE_IDENTIFIER);
    n->name = strdup(name);
    return n;
}

ASTNode* ast_make_binop(NodeType op, ASTNode *l, ASTNode *r) {
    ASTNode *n = new_node(op);
    n->left  = l;
    n->right = r;
    return n;
}

ASTNode* ast_make_not(ASTNode *operand) {
    ASTNode *n = new_node(NODE_NOT);
    n->left = operand;
    return n;
}

ASTNode* ast_make_decl(DataType dt, char *name, ASTNode *expr) {
    ASTNode *n = new_node(NODE_DECL);
    n->data_type = dt;
    n->name      = strdup(name);
    n->left      = expr;
    return n;
}

ASTNode* ast_make_assign(char *name, ASTNode *expr) {
    ASTNode *n = new_node(NODE_ASSIGN);
    n->name = strdup(name);
    n->left = expr;
    return n;
}

ASTNode* ast_make_transmitir(ASTNode *expr) {
    ASTNode *n = new_node(NODE_TRANSMITIR);
    n->left = expr;
    return n;
}

ASTNode* ast_make_if(ASTNode *cond, ASTNode *then_b, ASTNode *else_b) {
    ASTNode *n = new_node(NODE_IF);
    n->left  = cond;
    n->right = then_b;
    n->extra = else_b;
    return n;
}

ASTNode* ast_make_while(ASTNode *cond, ASTNode *body) {
    ASTNode *n = new_node(NODE_WHILE);
    n->left  = cond;
    n->right = body;
    return n;
}

ASTNode* ast_make_block(ASTNode *stmts) {
    ASTNode *n = new_node(NODE_BLOCK);
    n->left = stmts;
    return n;
}

ASTNode* ast_make_seq(ASTNode *left, ASTNode *right) {
    ASTNode *n = new_node(NODE_SEQ);
    n->left  = left;
    n->right = right;
    return n;
}

ASTNode* ast_make_func_def(char *name, ASTNode *body) {
    ASTNode *n = new_node(NODE_FUNC_DEF);
    n->name = strdup(name);
    n->left = body;
    return n;
}

ASTNode* ast_make_func_call(char *name) {
    ASTNode *n = new_node(NODE_FUNC_CALL);
    n->name = strdup(name);
    return n;
}

ASTNode* ast_make_return(ASTNode *expr) {
    ASTNode *n = new_node(NODE_RETURN);
    n->left = expr;
    return n;
}

/* ============================================================
 * EVALUACIÓN DE EXPRESIONES  → double
 * ============================================================ */
double ast_eval(ASTNode *node) {
    if (!node) return 0.0;

    switch (node->type) {

        case NODE_INT_LIT:    return (double) node->value.i_val;
        case NODE_DOUBLE_LIT: return node->value.d_val;
        case NODE_CHAR_LIT:   return (double) node->value.c_val;
        case NODE_BOOL_LIT:   return (double) node->value.b_val;

        case NODE_IDENTIFIER: {
            SymbolEntry *e = lookup(node->name);
            if (!e) {
                fprintf(stderr, "Error Semantico: variable '%s' no declarada\n", node->name);
                return 0;
            }
            switch (e->data_type) {
                case TYPE_ESCUDO:   return (double) e->data.i_value;
                case TYPE_ENERGIA:  return e->data.d_value;
                case TYPE_SPARTAN:  return (double) e->data.c_value;
                case TYPE_COVENANT: return (double) e->data.b_value;
                default:            return 0;
            }
        }

        /* Aritmética */
        case NODE_ADD: return ast_eval(node->left) + ast_eval(node->right);
        case NODE_SUB: return ast_eval(node->left) - ast_eval(node->right);
        case NODE_MUL: return ast_eval(node->left) * ast_eval(node->right);
        case NODE_DIV: {
            double r = ast_eval(node->right);
            if (r == 0.0) { fprintf(stderr, "Error: division por cero\n"); return 0; }
            return ast_eval(node->left) / r;
        }

        /* Comparación (devuelven 1.0 o 0.0) */
        case NODE_EQ:  return ast_eval(node->left) == ast_eval(node->right) ? 1.0 : 0.0;
        case NODE_NEQ: return ast_eval(node->left) != ast_eval(node->right) ? 1.0 : 0.0;
        case NODE_LT:  return ast_eval(node->left) <  ast_eval(node->right) ? 1.0 : 0.0;
        case NODE_GT:  return ast_eval(node->left) >  ast_eval(node->right) ? 1.0 : 0.0;
        case NODE_LEQ: return ast_eval(node->left) <= ast_eval(node->right) ? 1.0 : 0.0;
        case NODE_GEQ: return ast_eval(node->left) >= ast_eval(node->right) ? 1.0 : 0.0;

        /* Lógica */
        case NODE_AND: return (ast_eval(node->left) && ast_eval(node->right)) ? 1.0 : 0.0;
        case NODE_OR:  return (ast_eval(node->left) || ast_eval(node->right)) ? 1.0 : 0.0;
        case NODE_NOT: return ast_eval(node->left) == 0.0 ? 1.0 : 0.0;

        default:
            fprintf(stderr, "Error: nodo tipo %d no es una expresion\n", node->type);
            return 0;
    }
}

/* ============================================================
 * EJECUCIÓN DE INSTRUCCIONES
 * ============================================================ */
void ast_exec(ASTNode *node) {
    if (!node || g_return_flag) return;

    switch (node->type) {

        /* --- Secuencia --- */
        case NODE_SEQ:
            ast_exec(node->left);
            if (!g_return_flag) ast_exec(node->right);
            break;

        /* --- Bloque: abre y cierra ámbito propio --- */
        case NODE_BLOCK:
            push_scope();
            ast_exec(node->left);
            pop_scope();
            break;

        /* ---- Declaración de variable ---- */
        case NODE_DECL: {
            /* Reporte de colisiones: detecta redeclaración en el nivel actual */
            if (lookup_current(node->name)) {
                fprintf(stderr,
                    "Error Semantico: '%s' ya declarada en nivel %d "
                    "(colision de ambito).\n",
                    node->name, current_level());
                break;
            }
            SymbolEntry *e = insert_entry(node->name, node->data_type);
            if (!e) break;

            if (!node->left) break;   /* declaración sin inicializador */

            if (node->data_type == TYPE_MISION) {
                if (node->left->type == NODE_STRING_LIT)
                    e->data.s_value = strdup(node->left->value.s_val);
            } else if (node->data_type == TYPE_COVENANT) {
                e->data.b_value = (int) ast_eval(node->left);
            } else {
                double val = ast_eval(node->left);
                switch (node->data_type) {
                    case TYPE_ESCUDO:  e->data.i_value = (int)  val; break;
                    case TYPE_ENERGIA: e->data.d_value =        val; break;
                    case TYPE_SPARTAN: e->data.c_value = (char) val; break;
                    default: break;
                }
            }
            break;
        }

        /* ---- Asignación ---- */
        case NODE_ASSIGN: {
            /* lookup respeta shadowing: modifica la variable más cercana */
            SymbolEntry *e = lookup(node->name);
            if (!e) {
                fprintf(stderr, "Error Semantico: '%s' no declarada\n", node->name);
                break;
            }
            double val = ast_eval(node->left);
            switch (e->data_type) {
                case TYPE_ESCUDO:   e->data.i_value = (int)  val; break;
                case TYPE_ENERGIA:  e->data.d_value =        val; break;
                case TYPE_SPARTAN:  e->data.c_value = (char) val; break;
                case TYPE_COVENANT: e->data.b_value = (int)  val; break;
                default: break;
            }
            break;
        }

        /* ---- Transmitir ---- */
        case NODE_TRANSMITIR: {
            ASTNode *expr = node->left;
            if (!expr) break;

            if (expr->type == NODE_STRING_LIT) {
                printf("%s\n", expr->value.s_val);

            } else if (expr->type == NODE_IDENTIFIER) {
                /* lookup desde el nivel actual hacia global (shadowing) */
                SymbolEntry *e = lookup(expr->name);
                if (!e) { fprintf(stderr, "Error: '%s' no declarada\n", expr->name); break; }
                switch (e->data_type) {
                    case TYPE_ESCUDO:   printf("%d\n",   e->data.i_value); break;
                    case TYPE_ENERGIA:  printf("%f\n",   e->data.d_value); break;
                    case TYPE_SPARTAN:  printf("%c\n",   e->data.c_value); break;
                    case TYPE_MISION:   printf("%s\n",   e->data.s_value ? e->data.s_value : ""); break;
                    case TYPE_COVENANT: printf("%s\n",   e->data.b_value ? "activo" : "inactivo"); break;
                    default: break;
                }
            } else {
                /* Expresión numérica genérica */
                double v = ast_eval(expr);
                /* Imprimir como int si no tiene fracción */
                if (v == (int)v)
                    printf("%d\n", (int)v);
                else
                    printf("%g\n", v);
            }
            break;
        }

        /* ---- Condicional si/sino ---- */
        case NODE_IF: {
            double cond = ast_eval(node->left);
            if (cond != 0.0) {
                ast_exec(node->right);         /* rama then */
            } else if (node->extra) {
                ast_exec(node->extra);         /* rama else */
            }
            break;
        }

        /* ---- Bucle mientras ---- */
        case NODE_WHILE: {
            while (ast_eval(node->left) != 0.0 && !g_return_flag) {
                ast_exec(node->right);
            }
            break;
        }

        /* ---- Definición de función ---- */
        case NODE_FUNC_DEF:
            register_func(node->name, node->left);
            break;

        /* ---- Llamada a función ---- */
        case NODE_FUNC_CALL: {
            ASTNode *body = find_func(node->name);
            if (!body) {
                fprintf(stderr, "Error: funcion '%s' no definida\n", node->name);
                break;
            }
            /* Ámbito propio para la función → shadowing completo */
            push_scope();
            g_return_flag = 0;
            ast_exec(body);
            g_return_flag = 0;   /* consumir el return al salir */
            pop_scope();
            break;
        }

        /* ---- Retorno ---- */
        case NODE_RETURN:
            if (node->left) g_return_val = ast_eval(node->left);
            g_return_flag = 1;
            break;

        default:
            /* Nodo expresión suelto */
            ast_eval(node);
            break;
    }
}

/* ============================================================
 * IMPRESIÓN DEL ÁRBOL (depuración)
 * ============================================================ */
static const char* node_name(NodeType t) {
    switch (t) {
        case NODE_INT_LIT:    return "INT_LIT";
        case NODE_DOUBLE_LIT: return "DOUBLE_LIT";
        case NODE_CHAR_LIT:   return "CHAR_LIT";
        case NODE_BOOL_LIT:   return "BOOL_LIT";
        case NODE_STRING_LIT: return "STRING_LIT";
        case NODE_IDENTIFIER: return "ID";
        case NODE_ADD:        return "ADD";
        case NODE_SUB:        return "SUB";
        case NODE_MUL:        return "MUL";
        case NODE_DIV:        return "DIV";
        case NODE_EQ:         return "EQ";
        case NODE_NEQ:        return "NEQ";
        case NODE_LT:         return "LT";
        case NODE_GT:         return "GT";
        case NODE_LEQ:        return "LEQ";
        case NODE_GEQ:        return "GEQ";
        case NODE_AND:        return "AND";
        case NODE_OR:         return "OR";
        case NODE_NOT:        return "NOT";
        case NODE_DECL:       return "DECL";
        case NODE_ASSIGN:     return "ASSIGN";
        case NODE_TRANSMITIR: return "TRANSMITIR";
        case NODE_IF:         return "IF";
        case NODE_WHILE:      return "WHILE";
        case NODE_BLOCK:      return "BLOCK";
        case NODE_FUNC_DEF:   return "FUNC_DEF";
        case NODE_FUNC_CALL:  return "FUNC_CALL";
        case NODE_SEQ:        return "SEQ";
        case NODE_RETURN:     return "RETURN";
        default:              return "?";
    }
}

void ast_print(ASTNode *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");

    printf("[%s]", node_name(node->type));
    if (node->name)                      printf(" '%s'",   node->name);
    if (node->type == NODE_INT_LIT)      printf(" = %d",   node->value.i_val);
    if (node->type == NODE_DOUBLE_LIT)   printf(" = %f",   node->value.d_val);
    if (node->type == NODE_CHAR_LIT)     printf(" = '%c'", node->value.c_val);
    if (node->type == NODE_BOOL_LIT)     printf(" = %s",   node->value.b_val ? "activo":"inactivo");
    if (node->type == NODE_STRING_LIT)   printf(" = \"%s\"", node->value.s_val);
    printf("\n");

    if (node->left)  { for(int i=0;i<indent+1;i++) printf("  "); printf("(left)\n");  ast_print(node->left,  indent+2); }
    if (node->right) { for(int i=0;i<indent+1;i++) printf("  "); printf("(right)\n"); ast_print(node->right, indent+2); }
    if (node->extra) { for(int i=0;i<indent+1;i++) printf("  "); printf("(else)\n");  ast_print(node->extra, indent+2); }
    if (node->next)  ast_print(node->next, indent);
}

/* ============================================================
 * LIBERACIÓN DE MEMORIA
 * ============================================================ */
void ast_free(ASTNode *node) {
    if (!node) return;
    ast_free(node->left);
    ast_free(node->right);
    ast_free(node->extra);
    ast_free(node->next);
    if (node->name) free(node->name);
    if (node->type == NODE_STRING_LIT && node->value.s_val) free(node->value.s_val);
    free(node);
}