#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"

/* ============================================================
 *  Estado interno: tope de la pila de ámbitos
 * ============================================================ */
static ScopeNode *scope_stack = NULL;

/* ------------------------------------------------------------
 *  init_symbol_table
 *  Crea el ámbito global (nivel 0).
 * ------------------------------------------------------------ */
void init_symbol_table(void) {
    scope_stack = NULL;
    push_scope();   /* nivel 0 = global */
}

/* ------------------------------------------------------------
 *  push_scope  –  abre un nuevo bloque { }
 * ------------------------------------------------------------ */
void push_scope(void) {
    ScopeNode *node = (ScopeNode*) malloc(sizeof(ScopeNode));
    if (!node) { fprintf(stderr, "Error: sin memoria para scope\n"); exit(1); }
    node->table = NULL;
    node->level = scope_stack ? scope_stack->level + 1 : 0;
    node->prev  = scope_stack;
    scope_stack  = node;
}

/* ------------------------------------------------------------
 *  pop_scope  –  cierra el bloque actual, libera memoria
 * ------------------------------------------------------------ */
void pop_scope(void) {
    if (!scope_stack) { fprintf(stderr, "Error: pila de ámbitos vacía\n"); return; }

    ScopeNode *dying = scope_stack;
    scope_stack = dying->prev;

    /* Liberar todas las entradas del nivel que muere */
    SymbolEntry *e = dying->table;
    while (e) {
        SymbolEntry *next = e->next;
        free(e->name);
        if (e->data_type == TYPE_MISION && e->data.s_value)
            free(e->data.s_value);
        free(e);
        e = next;
    }
    free(dying);
}

/* ------------------------------------------------------------
 *  current_level
 * ------------------------------------------------------------ */
int current_level(void) {
    return scope_stack ? scope_stack->level : -1;
}

/* ------------------------------------------------------------
 *  lookup_current  –  solo en el nivel superior
 * ------------------------------------------------------------ */
SymbolEntry* lookup_current(char *name) {
    if (!scope_stack) return NULL;
    SymbolEntry *e = scope_stack->table;
    while (e) {
        if (strcmp(e->name, name) == 0) return e;
        e = e->next;
    }
    return NULL;
}

/* ------------------------------------------------------------
 *  lookup  –  desde el tope hacia abajo (shadowing)
 * ------------------------------------------------------------ */
SymbolEntry* lookup(char *name) {
    ScopeNode *scope = scope_stack;
    while (scope) {
        SymbolEntry *e = scope->table;
        while (e) {
            if (strcmp(e->name, name) == 0) return e;
            e = e->next;
        }
        scope = scope->prev;
    }
    return NULL;   /* no existe en ningún ámbito */
}

/* ------------------------------------------------------------
 *  insert_entry  –  inserta en el nivel actual
 *  Devuelve NULL si ya existe en ESTE nivel (redeclaración).
 * ------------------------------------------------------------ */
SymbolEntry* insert_entry(char *name, DataType type) {
    if (!scope_stack) { fprintf(stderr, "Error: no hay ámbito activo\n"); return NULL; }

    /* Verificar colisión en el nivel actual */
    if (lookup_current(name)) return NULL;

    SymbolEntry *entry = (SymbolEntry*) malloc(sizeof(SymbolEntry));
    if (!entry) { fprintf(stderr, "Error: sin memoria\n"); exit(1); }

    entry->name        = strdup(name);
    entry->data_type   = type;
    entry->is_function = 0;
    memset(&entry->data, 0, sizeof(entry->data));

    /* Insertar al inicio de la lista del nivel actual */
    entry->next         = scope_stack->table;
    scope_stack->table  = entry;
    return entry;
}

/* ------------------------------------------------------------
 *  dump_scopes  –  imprime la pila completa (depuración)
 * ------------------------------------------------------------ */
void dump_scopes(void) {
    static const char *type_names[] = {
        "escudo","energia","spartan","mision","covenant","void"
    };
    ScopeNode *scope = scope_stack;
    printf("\n===== TABLA DE SÍMBOLOS POR NIVELES =====\n");
    while (scope) {
        printf("  [Nivel %d]\n", scope->level);
        SymbolEntry *e = scope->table;
        if (!e) printf("    (vacío)\n");
        while (e) {
            printf("    %-16s : %s", e->name, type_names[e->data_type]);
            switch (e->data_type) {
                case TYPE_ESCUDO:   printf(" = %d",  e->data.i_value); break;
                case TYPE_ENERGIA:  printf(" = %f",  e->data.d_value); break;
                case TYPE_SPARTAN:  printf(" = '%c'",e->data.c_value); break;
                case TYPE_MISION:   printf(" = \"%s\"", e->data.s_value ? e->data.s_value : ""); break;
                case TYPE_COVENANT: printf(" = %s",  e->data.b_value ? "activo" : "inactivo"); break;
                default: break;
            }
            printf("\n");
            e = e->next;
        }
        scope = scope->prev;
    }
    printf("==========================================\n\n");
}
