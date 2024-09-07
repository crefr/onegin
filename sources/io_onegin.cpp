#include <stdio.h>
#include <stdlib.h>

#include "io_onegin.h"


void printStrs(char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        printf("%s\n", strings[index]);
    }
}

void printAtFile(FILE * outfile, char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++)
        fprintf(outfile, "%s\n", strings[index]);
}

size_t readTextFromFile(FILE * textfile, char * text)
{
    int curChar = 0;
    size_t index = 0;
    while((curChar = fgetc(textfile)) != EOF){
        switch(curChar){
            case '\r':
                break;
            case '\n':
                text[index] = '\n';
                break;
            default:
                text[index] = (char) curChar;
        }
        index++;
    }
    return index;
}
