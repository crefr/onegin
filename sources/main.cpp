#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"
//#include "debug.h"

int main()
{
    const char *outfilename = "out.txt";
    const char *infilename  = "test.txt";

    text_t strs = {};
    getStrs(infilename, &strs);
    quickSort(strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //sortTime(quickSort, strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //printf("reverse sorted? - %ld\n", testSorting(&strs, pointerRevStrCmp));

    printStrsToFile(outfilename, &strs);

    delStrs(&strs);
    return 0;
}
