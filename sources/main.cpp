#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"
#include "argvprocessing.h"

int main(int argc, char ** argv)
{
    fvals_t flagvalues[ARGVNUM] = {};
    argvReceive(argc, argv, flagvalues);

    const char *infilename  = flagvalues[I_flag].str;
    const char *outfilename = flagvalues[O_flag].str;

    text_t strs = {};
    getStrs(infilename, &strs);
    quickSort(strs.strings, strs.strnum, sizeof(str_t), ptrAdvancedStrCmp);
    //quickSort(strs.strings, strs.strnum, sizeof(str_t), pointerStrCmp);
    //sortTime(quickSort, strs.strings, strs.strnum, sizeof(char *), pointerStrCmp);
    //printf("reverse sorted? - %ld\n", testSorting(&strs, pointerRevStrCmp));

    printStrsToFile(outfilename, &strs);

    delStrs(&strs);
    return 0;
}
