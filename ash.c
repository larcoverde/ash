#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "builtin.h"

#define MAX_INPUT 1024
#define MAX_ARGS 64

void
print_banner()
{
printf("    Welcome to\n\n");
printf("           _ \n");
printf("  __ _ ___| |__ \n");
printf(" / _` / __| '_ \\ \n");
printf("| (_| \\__ \\ | | | \n");
printf(" \\__,_|___/_| |_| \n\n");
printf("    - a shell -\n\n");
printf("type 'help' to get started\n\n");
}

void
print_cwd()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("cwd: %s\n", cwd);
}

void
get_user_input(char *input)
{
    printf("-> ");
    if (fgets(input, MAX_INPUT, stdin) == NULL)
        printf("exiting...\n");

    input[strcspn(input, "\n")] = 0;
}

void
tokenize_input(char *input, char **args)
{
    int i = 0;
    
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS-1)
    {
        ++i;
        args[i] = strtok(NULL, " ");
    }
}

int
execute_builtin_cmd(char **args)
{
    if (strcmp(args[0], "exit") == 0)
    {
        printf("exiting...\n");
        exit(0);
        return 1;
    }

    if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "go") == 0)
    {
        change_directory(args[1]);
        return 1;
    }

    if (strcmp(args[0], "help") == 0)
    {
        print_help();
        return 1;
    }
    return 0;
}

void
execute_external_cmd(char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        if (execvp(args[0], args) < 0)
        {
            perror("command failed");
        }
        exit(1);
    }
    else
    {
        wait(NULL);
    }
}

int
main(int argc, char* argv[])
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    print_banner();
    int i = 1;
    while (i == 1)
    {
        print_cwd();
        get_user_input(input);

        if (strlen(input) == 0) continue;

        tokenize_input(input, args);

        if (execute_builtin_cmd(args)) continue;

        execute_external_cmd(args);

    }
    return 0;
}
