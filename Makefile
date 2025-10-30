CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
OBJ = trie.o main.o
EXEC = trie_app

all:
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
