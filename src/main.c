#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "expand.h"
#include "builtin.h"

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

        if (input[0] == '\0')
        {
            free(input);
            continue;
        }

        Token tokens[MAX_TOKENS];

        int token_count = lexer_tokenize(input, tokens);

        expand_tokens(tokens, token_count);

        parse_tokens(tokens, token_count);

        /*
         * Built-in commands
         */
        if (token_count > 0)
        {
            char *argv[MAX_TOKENS];
            int argc = 0;

            for (int i = 0; i < token_count; i++)
            {
                argv[argc++] = tokens[i].value;
            }

            argv[argc] = NULL;

            if (is_builtin(argv[0]))
            {
                if (strcmp(argv[0], "cd") == 0)
                {
                    builtin_cd(argv);
                }
                else if (strcmp(argv[0], "pwd") == 0)
                {
                    builtin_pwd(argv);
                }
                else if (strcmp(argv[0], "echo") == 0)
                {
                    builtin_echo(argv);
                }
                else if (strcmp(argv[0], "exit") == 0)
                {
                    for (int i = 0; i < token_count; i++)
                    {
                        free_token(&tokens[i]);
                    }

                    free(input);

                    builtin_exit(argv);
                }
            }
        }

        for (int i = 0; i < token_count; i++)
        {
            free_token(&tokens[i]);
        }

        free(input);
    }

    return 0;
}
