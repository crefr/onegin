#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "sorting.h"

int main()
{
    FILE * textfile = fopen("test.txt", "r");
    size_t linenum = 0;
    char ** strings = getStrs(textfile, &linenum);

    bubbleSort(strings, linenum);
    printStrs (strings, linenum);

    fclose(textfile);
    delStrs(strings);
    return 0;
}
