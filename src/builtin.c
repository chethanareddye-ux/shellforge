#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "builtin.h"

int builtin_cd(char **argv)
{
    char *dir;

    if (argv[1] == NULL)
    {
        dir = getenv("HOME");

        if (dir == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }
    }
    else if (argv[2] != NULL)
    {
        fprintf(stderr, "cd: too many arguments\n");
        return 1;
    }
    else
    {
        dir = argv[1];
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return 1;
    }

    return 0;
}

int builtin_pwd(char **argv)
{
    char cwd[4096];

    (void)argv;

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("pwd");
        return 1;
    }

    printf("%s\n", cwd);

    return 0;
}

int builtin_echo(char **argv)
{
    int i = 1;

    while (argv[i] != NULL)
    {
        printf("%s", argv[i]);

        if (argv[i + 1] != NULL)
        {
            printf(" ");
        }

        i++;
    }

    printf("\n");

    return 0;
}

int builtin_exit(char **argv)
{
    (void)argv;

    exit(0);
}

int is_builtin(char *command)
{
    if (command == NULL)
    {
        return 0;
    }

    if (strcmp(command, "cd") == 0 ||
        strcmp(command, "pwd") == 0 ||
        strcmp(command, "echo") == 0 ||
        strcmp(command, "exit") == 0)
    {
        return 1;
    }

    return 0;
}
