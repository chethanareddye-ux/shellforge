CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/main.c src/lexer.c src/token.c

shellforge:
	$(CC) $(CFLAGS) $(SRC) -lreadline -o shellforge

clean:
	rm -f shellforge
