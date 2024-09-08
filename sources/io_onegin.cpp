#include <stdio.h>
#include <stdlib.h>

#include "io_onegin.h"
#include "debug.h"


void printStrs(char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        printf("%s\n", strings[index]);
    }
}

void printAtFile(FILE * outfile, char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        fprintf(outfile, "%s\n", strings[index]);
    }
}

size_t readTextFromFile(FILE * textfile, char * text, size_t * linenum)
{
    int curChar = 0;
    size_t index = 0;
    *linenum = 0;
    while((curChar = fgetc(textfile)) != EOF){
        switch(curChar){
            case '\n':
                text[index] = '\0';
                index++;
                (*linenum)++;
                break;
            case '\r':
                break;
            default:
                text[index] = (char) curChar;
                index++;
                break;
        }
    }
    return index;
}
