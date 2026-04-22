# Configuración de Compilador y Flags
CC      = gcc
CFLAGS  = -Wall -g -Iinclude
TARGET  = halo

# Directorios
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
OBJ_DIR = obj

# Archivos Fuente (Rutas actualizadas)
# Nota: y.tab.c y lex.yy.c se generarán dentro de src/
SRCS    = $(SRC_DIR)/y.tab.c $(SRC_DIR)/lex.yy.c $(SRC_DIR)/symbols.c $(SRC_DIR)/ast.c

all: $(TARGET)

# Vinculación del ejecutable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lfl

# Generación del Parser (Bison)
# Se usa -o para especificar que el output vaya a src/
$(SRC_DIR)/y.tab.c $(INC_DIR)/y.tab.h: $(SRC_DIR)/parser.y
	bison -dy $(SRC_DIR)/parser.y -o $(SRC_DIR)/y.tab.c
	mv $(SRC_DIR)/y.tab.h $(INC_DIR)/y.tab.h 2>/dev/null || true

# Generación del Lexer (Flex)
$(SRC_DIR)/lex.yy.c: $(SRC_DIR)/lexer.l $(INC_DIR)/y.tab.h
	flex -o $(SRC_DIR)/lex.yy.c $(SRC_DIR)/lexer.l

# Limpieza de archivos generados
clean:
	rm -f $(TARGET) $(SRC_DIR)/y.tab.c $(INC_DIR)/y.tab.h $(SRC_DIR)/lex.yy.c *.o

# ---- Targets de prueba (Buscando en la carpeta tests) ----
run: $(TARGET)
	./$(TARGET) $(TEST_DIR)/ejemplo.halo

run-scope: $(TARGET)
	./$(TARGET) $(TEST_DIR)/prueba_scope.halo

run-ast: $(TARGET)
	./$(TARGET) --ast $(TEST_DIR)/prueba_scope.halo

run-todo: $(TARGET)
	./$(TARGET) --ast --tabla $(TEST_DIR)/prueba_fuego.halo