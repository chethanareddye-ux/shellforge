#include <stdio.h>

#include "parser.h"
#include "token.h"

void parse_tokens(Token tokens[], int token_count)
{
    printf("\n--------- PARSER ---------\n\n");

    printf("Command: ");

    for (int i = 0; i < token_count; i++)
    {
        if (tokens[i].type == TOKEN_END)
        {
            break;
        }

        printf("%s ", tokens[i].value);
    }

    printf("\n\n");

    if (token_count > 1)
    {
        printf("Parsing successful\n");
    }
    else
    {
        printf("No command found\n");
    }

    printf("\n--------------------------\n");
}
