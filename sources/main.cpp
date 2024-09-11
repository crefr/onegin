#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"

//void insforShellSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *), size_t step, size_t offset);

int main()
{
    FILE * outfile =  fopen("out.txt" , "w");
    const char * filename = "test.txt";

    text_t strs = {};
    getStrs(filename, &strs);

    clock_t start = clock();
    //qsort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);

    //shellSort(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    //quickSort(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    shellSort_old(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    //insertionSort(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    //selectionSort(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    //bubbleSort(strs.strings, sizeof(char *), strs.strnum, pointerStrCmp);
    double sorttime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
    printf("time: %.2lf ms\n", sorttime);

    //printStrs (strings, linenum);
    printAtFile(outfile, strs.strings, strs.strnum);

    delStrs(&strs);
    return 0;
}
