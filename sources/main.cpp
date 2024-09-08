#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"

int main()
{
    FILE * textfile = fopen("test.txt", "r");
    FILE * outfile =  fopen("out.txt" , "w");

    size_t linenum = 0;
    char ** strings = getStrs(textfile, &linenum);

    clock_t start = clock();
    //shellSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //insertionSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //selectionSort(strings, sizeof(char *), linenum, pointerStrCmp);
    bubbleSort(strings, sizeof(char *), linenum, pointerStrCmp);
    printf("time: %.1lf ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000);

    //printStrs (strings, linenum);
    printAtFile(outfile, strings, linenum);

    fclose(textfile);
    delStrs(strings);
    return 0;
}
