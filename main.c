#include <stdio.h>
#include <unistd.h>

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

int
main(int argc, char* argv[])
{
    print_banner();
    int i = 0;
    while (i == 0)
    {
        print_cwd();
        i = 1;
    }
    return 0;
}
