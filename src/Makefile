BIN = parser
OBJ = yacc.tab.c lex.yy.c SymbolType.cpp SymbolTable.cpp List.cpp Error.cpp
parser: lex.l yacc.y SymbolTable.h SymbolType.h List.h Error.h
	bison -d yacc.y
	flex lex.l
	g++ -o $(BIN) $(OBJ) -std=c++11

.PHONY: clean

clean:
	@- $(RM) *.tab.c *.tab.h *.yy.c $(BIN) $(OBJ)