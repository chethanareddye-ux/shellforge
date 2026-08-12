#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "token.h"
#include "lexer.h"

#define MAX_TOKENS 100

int main()
{
    char *input;

    printf("================================\n");
    printf("           Shellforge\n");
    printf("     A Unix Style Shell written in C\n");
    printf("================================\n");

    while (1)
    {
        input = readline("shellforge$ ");

        if (input == NULL)
        {
            break;
        }

        /* Check for exit command */
        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting ShellForge...\n");
            free(input);
            break;
        }

        /* Ignore empty input */
        if (input[0] == '\0')
        {
            free(input);
            continue;
        }

        Token tokens[MAX_TOKENS];

        int token_count = lexer_tokenize(input, tokens);

        printf("\n");
        printf("--------- TOKENS ---------\n\n");

        for (int i = 0; i < token_count; i++)
        {
            print_token(tokens[i], i);
        }

        printf("\n");
        printf("--------------------------\n");

        /* Free token memory */
        for (int i = 0; i < token_count; i++)
        {
            free_token(&tokens[i]);
        }

        free(input);
    }

    return 0;
}
