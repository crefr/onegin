#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "sorting.h"
#include "argvprocessing.h"
#include "comparators.h"

enum mainstatus{HELPEXIT = 0, SORTTIMEEXIT = 0, INPUTFILEERROR, OUTPUTFILEERROR, CMDARGSERROR};

int main(int argc, char ** argv)
{
    fvals_t flagvalues[ARGVNUM] = {};
    if (argvReceive(argc, argv, flagvalues) == ARGBAD){
        printf("cmd args error\n");
        return CMDARGSERROR;
    }

    if (flagvalues[H_flag].bl || flagvalues[HELP_flag].bl){
        printHelp();
        return HELPEXIT;
    }

    const char *infilename  = flagvalues[I_flag].str;

    const char * terminator = "__________________________________________________________________________________________\n\n";
    text_t strs = {};
    if (getStrs(infilename, &strs) == ONEGINFILEERROR){
        printf("inputfile ERROR\n");
        return INPUTFILEERROR;
    }

    if (flagvalues[T_flag].bl){
        sortTime(quickSort, strs.strings, strs.strnum, sizeof(str_t), ptrAdvancedStrCmp);
        delStrs(&strs);
        return SORTTIMEEXIT;
    }

    FILE * outfile = fopen(flagvalues[O_flag].str, "w");
    if (outfile == NULL){
        printf("outfile ERROR\n");
        return OUTPUTFILEERROR;
    }

    qsort(strs.strings, strs.strnum, sizeof(str_t), ptrAdvancedStrCmp);
    printStrsToFile(outfile, &strs);

    fprintf(outfile, "%s", terminator);

    quickSort(strs.strings, strs.strnum, sizeof(str_t), ptrAdvancedRevStrCmp);
    printf("reverse sorted? - %ld\n", testSorting(&strs, ptrAdvancedRevStrCmp));
    printStrsToFile(outfile, &strs);

    fprintf(outfile, "%s", terminator);

    printOriginTextToFile(outfile, &strs);

    delStrs(&strs);
    fclose(outfile);
    return 0;
}
