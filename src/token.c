#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"

Token create_token(TokenType type, const char *value)
{
    Token token;

    token.type = type;

    token.value = malloc(strlen(value) + 1);

    if (token.value == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(token.value, value);

    return token;
}

void print_token(Token token, int index)
{
    const char *type_name;

    if (token.type == TOKEN_WORD)
    {
        type_name = "WORD";
    }
    else if (token.type == TOKEN_END)
    {
        type_name = "END";
    }
    else
    {
        type_name = "UNKNOWN";
    }

    printf("%d : %-12s %s\n", index, type_name, token.value);
}

void free_token(Token *token)
{
    free(token->value);
    token->value = NULL;
}
