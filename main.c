#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
}

void
tokenize_input(char *input, char **args)
{
    int i = 0;
    
    agrs[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS-1)
    {
        ++i;
        agrs[i] = strtok(NULL, " ");
    }
}

int
main(int argc, char* argv[])
{
    char input[MAX_INPUT];
    char args[MAX_ARGS];

    print_banner();
    int i = 1;
    while (i == 1)
    {
        print_cwd();
        get_user_input(input);

        if (strlen(input) == 0) continue;

        tokenize_input(input, args);

        i = 0;
    }
    return 0;
}
