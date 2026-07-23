#include "builtin.h"
#include <unistd.h>
#include <stdio.h>

void
change_directory(char *path)
{
    if (chdir(path) != 0)
        perror("chdir() failed");
}

