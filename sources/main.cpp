#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"

int main()
{
    FILE * outfile =  fopen("out.txt" , "w");
    const char * filename = "test.txt";

    text_t strs = {};
    getStrs(filename, &strs);
    sortTime(quickSort, strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);

    //qsort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);

    //shellSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //quickSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //shellSort_old(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //insertionSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //selectionSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //bubbleSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);

    printAtFile(outfile, strs.strings, strs.strnum);

    delStrs(&strs);
    return 0;
}
