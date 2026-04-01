#ifndef SYMBOLS_H
#define SYMBOLS_H

/* ============================================================
 *  TIPOS DE DATOS del lenguaje HALO
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
 *  ENTRADA DE LA TABLA DE SÍMBOLOS
 * ============================================================ */
typedef struct SymbolEntry {
    char     *name;
    DataType  data_type;
    int       is_function;   /* 1 si es una función declarada */
    union {
        int    i_value;
        double d_value;
        char   c_value;
        char  *s_value;
        int    b_value;
    } data;
    struct SymbolEntry *next;  /* lista enlazada dentro de la tabla del nivel */
} SymbolEntry;

/* ============================================================
 *  NODO DE LA PILA DE ÁMBITOS  (Scope Stack)
 *  Cada nodo contiene una tabla hash sencilla (lista de entradas).
 * ============================================================ */
typedef struct ScopeNode {
    SymbolEntry    *table;      /* lista de símbolos de este nivel */
    int             level;      /* número de nivel (0 = global)   */
    struct ScopeNode *prev;     /* nodo inferior de la pila        */
} ScopeNode;

/* ============================================================
 *  API PÚBLICA DE LA TABLA DE SÍMBOLOS
 * ============================================================ */

/* Inicializa la pila con el ámbito global */
void  init_symbol_table(void);

/* Abre un nuevo ámbito (push) */
void  push_scope(void);

/* Cierra el ámbito actual (pop) – las variables mueren aquí */
void  pop_scope(void);

/* Nivel actual de la pila */
int   current_level(void);

/* Inserta en el ámbito actual; devuelve NULL si ya existe en ESTE nivel */
SymbolEntry* insert_entry(char *name, DataType type);

/* Busca desde el tope hacia la base (respeta shadowing) */
SymbolEntry* lookup(char *name);

/* Busca SOLO en el ámbito actual (para detectar redeclaración) */
SymbolEntry* lookup_current(char *name);

/* Imprime el contenido de toda la pila (depuración) */
void  dump_scopes(void);

#endif /* SYMBOLS_H */
