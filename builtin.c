#include "builtin.h"
#include <unistd.h>
#include <stdio.h>

void
change_directory(char *path)
{
    if (chdir(path) != 0)
        perror("chdir() failed");
}

void
print_help()
{
    printf("ASH - a shell, version 1.0. By Lucas Arcoverde Melo.\n\n");
    printf("List of built-in commands:\n");
    printf("help             print this help message\n");
    printf("cd  go <path>    change directory\n\n");
    printf("Use any other command from your utility binaries package.\n");
    printf("You can try my own binaries! Search for smutils on my github.\n");
    printf("https://www.github.com/larcoverde/smutils\n\n");
}

