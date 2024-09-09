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
    FILE * textfile = fopen("test.txt", "r");
    FILE * outfile =  fopen("out.txt" , "w");

    size_t linenum = 0;
    char * text = NULL;
    char ** strings = getStrs(textfile, &linenum, &text);

    clock_t start = clock();
    //insforShellSort(strings, sizeof(char *), linenum, pointerStrCmp, 1, 0);
    //shellSort(strings, sizeof(char *), linenum, pointerStrCmp);
    quickSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //shellSort_old(strings, sizeof(char *), linenum, pointerStrCmp);
    //insertionSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //selectionSort(strings, sizeof(char *), linenum, pointerStrCmp);
    //bubbleSort(strings, sizeof(char *), linenum, pointerStrCmp);
    printf("time: %.2lf ms\n", (double)(clock() - start) / CLOCKS_PER_SEC * 1000);

    //printStrs (strings, linenum);
    printAtFile(outfile, strings, linenum);

    fclose(textfile);
    //delStrs(strings, text);
    free(strings);
    free(text);
    return 0;
}
