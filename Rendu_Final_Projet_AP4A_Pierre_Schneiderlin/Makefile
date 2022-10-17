
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=


CC=g++
EXEC=ProjetAP4A_Executable
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all:$(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^

%.o: %.hpp

%.o: %.cpp
	@$(CC) -o $@ -c $<

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	
mrproper: clean
	@rm -rf $(EXEC)
