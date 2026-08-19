#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expand.h"
#include "token.h"

void expand_tokens(Token tokens[], int token_count)
{
    printf("\n--------- EXPAND ---------\n\n");

    for (int i = 0; i < token_count; i++)
    {
        if (tokens[i].type == TOKEN_END)
        {
            break;
        }

        if (tokens[i].value[0] == '$')
        {
            char *variable = tokens[i].value + 1;
            char *value = getenv(variable);

            if (value != NULL)
            {
                printf("$%s expanded to: %s\n",
                       variable,
                       value);

                char *new_value = malloc(strlen(value) + 1);

                if (new_value == NULL)
                {
                    printf("Memory allocation failed\n");
                    exit(1);
                }

                strcpy(new_value, value);

                free(tokens[i].value);
                tokens[i].value = new_value;
            }
            else
            {
                printf("$%s not found\n", variable);
            }
        }
        else
        {
            printf("%s\n", tokens[i].value);
        }
    }

    printf("\n--------------------------\n");
}
