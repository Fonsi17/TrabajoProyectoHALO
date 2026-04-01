CC      = gcc
CFLAGS  = -Wall -g
TARGET  = halo
SRCS    = y.tab.c lex.yy.c symbols.c ast.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lfl

y.tab.c y.tab.h: parser.y
	bison -dy parser.y

lex.yy.c: lexer.l y.tab.h
	flex lexer.l

clean:
	rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c *.o

# ---- Targets de prueba ----
run: $(TARGET)
	./$(TARGET) ejemplo.halo

run-scope: $(TARGET)
	./$(TARGET) prueba_scope.halo

run-ast: $(TARGET)
	./$(TARGET) --ast prueba_scope.halo

run-todo: $(TARGET)
	./$(TARGET) --ast --tabla prueba_fuego.halo
