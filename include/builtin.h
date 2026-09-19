#ifndef BUILTIN_H
#define BUILTIN_H

int builtin_cd(char **argv);
int builtin_pwd(char **argv);
int builtin_echo(char **argv);
int builtin_exit(char **argv);
int is_builtin(char *command);

#endif
