#include <stdio.h>
#include <unistd.h>

#define MAX_INPUT 1024

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

int
main(int argc, char* argv[])
{
    char input[MAX_INPUT];

    print_banner();
    int i = 1;
    while (i == 1)
    {
        print_cwd();
        get_user_input(input);
        i = 0;
    }
    return 0;
}
