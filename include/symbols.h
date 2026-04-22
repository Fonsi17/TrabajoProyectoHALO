#ifndef SYMBOLS_H
#define SYMBOLS_H

/* ============================================================
 * TIPOS DE DATOS del lenguaje HALO
 * ============================================================ */
typedef enum {
    TYPE_ESCUDO,    /* int    */
    TYPE_ENERGIA,   /* double */
    TYPE_SPARTAN,   /* char   */
    TYPE_MISION,    /* string */
    TYPE_COVENANT,  /* bool   */
    TYPE_VOID       /* para funciones sin retorno */
} DataType;

/* ============================================================
 * ENTRADA DE LA TABLA DE SÍMBOLOS
 * ============================================================ */
typedef struct SymbolEntry {
    char     *name;
    DataType  data_type;
    int       is_function;   /* 1 si es una función declarada */
    
    union {
        int    i_value;
        double d_value;
        char   c_value;
        char  *s_value;      /* Para el tipo mision (string) */
        int    b_value;      /* Para el tipo covenant (bool) */
    } data;

    struct SymbolEntry *next;  /* Lista enlazada para colisiones en el mismo nivel */
} SymbolEntry;

/* ============================================================
 * NODO DE LA PILA DE ÁMBITOS (Scope Stack)
 * ============================================================ */
typedef struct ScopeNode {
    SymbolEntry      *table;    /* Lista de símbolos de este nivel */
    int               level;    /* Nivel de profundidad (0 = global) */
    struct ScopeNode *prev;     /* Puntero al ámbito padre */
} ScopeNode;

/* ============================================================
 * API PÚBLICA DE LA TABLA DE SÍMBOLOS
 * ============================================================ */

/* Inicializa la pila con el ámbito global */
void init_symbol_table(void);

/* Abre un nuevo ámbito (por ejemplo, al entrar en un bloque { }) */
void push_scope(void);

/* Cierra el ámbito actual y libera la memoria de sus variables */
void pop_scope(void);

/* Devuelve el nivel de profundidad actual */
int current_level(void);

/* Inserta una variable en el ámbito actual. Retorna NULL si ya existe en este nivel. */
SymbolEntry* insert_entry(char *name, DataType type);

/* Busca una variable desde el ámbito actual hacia arriba (permite shadowing) */
SymbolEntry* lookup(char *name);

/* Busca una variable SOLO en el ámbito actual (para detectar redeclaraciones) */
SymbolEntry* lookup_current(char *name);

/* Imprime el contenido de todos los ámbitos activos (útil para depuración) */
void dump_scopes(void);

#endif /* SYMBOLS_H */