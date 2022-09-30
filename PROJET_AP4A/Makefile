CC = gcc
FLAGS = -W -Wall -ansi -pedantic -lm -std=c99
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)


main: $(OBJ)
	@$(CC) -o $@ $^ $(FLAGS)
	@cp $@ ~/Bureau/$@

%.o: %.c *.h
	@$(CC) -o $@ -c $<  $(FLAGS)

clean:
	@rm -rf *.o
