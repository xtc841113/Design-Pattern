.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/midterm2

$(BIN)/midterm2: $(TEST)/ut_shape.cpp  $(OBJ)/triangle.o $(OBJ)/triangle_factory.o
	g++ -std=c++11 $< $(OBJ)/triangle.o $(OBJ)/triangle_factory.o  -o $@ $(LIBS)

$(OBJ)/triangle.o: $(SRC)/triangle.cpp $(SRC)/triangle.h
	g++ -std=c++11 -c $< -o $@

$(OBJ)/triangle_factory.o: $(SRC)/triangle_factory.cpp $(SRC)/triangle_factory.h
	g++ -std=c++11 -c $< -o $@


dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
