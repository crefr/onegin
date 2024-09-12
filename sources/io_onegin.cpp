#include <stdio.h>
#include <stdlib.h>

#include "io_onegin.h"
#include "debug.h"

void printStrs(char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        printf("%s\n", strings[index]);
    }
}

void printAtFile(FILE * outfile, char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        fprintf(outfile, "%s\n", strings[index]);
    }
}
