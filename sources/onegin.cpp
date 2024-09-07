#include <stdio.h>
//#include <sys\stat.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "debug.h"

//const size_t MAXLINESNUM = 1000;

char ** getStrs(FILE * textfile, size_t * linenum)
{
    fseek(textfile, 0, SEEK_END);
    size_t textsize = ftell(textfile);
    fseek(textfile, 0, SEEK_SET);

   // printf("textsize: %llu\n", textsize);

    char * text = (char *) calloc(textsize, sizeof(char));
    fread(text, sizeof(char), textsize, textfile);

    *linenum = 0;
    for (size_t index = 0; index < textsize; index++){
        if (text[index] == '\n'){
            if (index > 0 && text[index - 1] == '\r')
                text[index - 1] = '\0';

            text[index] = '\0';

            (*linenum)++;
        }
    }
    printf("linenum: %llu\n", *linenum);

    char ** strings = (char **) calloc(*linenum, sizeof(char *));
    strings[0] = text;

    size_t curLine = 0;
    for(size_t index = 0; index < textsize - 1; index++){
        if (text[index] == '\0'){
            curLine++;
            strings[curLine] = text + index + 1;
        }
    }
    text[textsize - 1] = '\0';
    return strings;
}

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

void delStrs(char ** text)
{
    //free(text[0]);
    free(text);
}

int pointerStrCmp(const void * firstpointer, const void * secondpointer)
{
    const char * firststring  = *((const char **) firstpointer);
    const char * secondstring = *((const char **) secondpointer);
    return mystrcmp(firststring, secondstring);
}
