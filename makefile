CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LIBS = -lreadline

SRC = src/main.c src/token.c src/lexer.c src/parser.c src/expand.c
OUT = shellforge

all:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(OUT)

clean:
	rm -f $(OUT)
