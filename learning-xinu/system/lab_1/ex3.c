#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char **p;
    for (p = argv; *p != NULL; p++)
        puts(*p);
    exit(EXIT_SUCCESS);
}
