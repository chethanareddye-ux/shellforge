#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"
#include "token.h"

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 256

int lexer_tokenize(const char *input, Token tokens[])
{
    int count = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        while (isspace((unsigned char)input[i]))
        {
            i++;
        }

        if (input[i] == '\0')
        {
            break;
        }

        char word[MAX_WORD_LENGTH];
        int j = 0;

        while (input[i] != '\0' &&
               !isspace((unsigned char)input[i]))
        {
            word[j] = input[i];
            j++;
            i++;
        }

        word[j] = '\0';

        tokens[count] = create_token(TOKEN_WORD, word);
        count++;
    }

    tokens[count] = create_token(TOKEN_END, "END");
    count++;

    return count;
}
