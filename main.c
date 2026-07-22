#include <stdio.h>

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
printf("type 'help' to get started\n");
}

int
main(int argc, char* argv[])
{
    print_banner();
    return 0;
}
