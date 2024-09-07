#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "sorting.h"

int main()
{
    FILE * textfile = fopen("test.txt", "r");
    FILE * outfile =  fopen("out.txt" , "w");

    size_t linenum = 0;
    char ** strings = getStrs(textfile, &linenum);

    bubbleSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //printStrs (strings, linenum);
    printAtFile(outfile, strings, linenum);

    fclose(textfile);
    delStrs(strings);
    return 0;
}
