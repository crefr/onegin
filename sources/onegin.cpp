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
        //printf("now: <%c>\n", text[index]);
        if (text[index] == '\n'){
            (*linenum)++;
            text[index] = '\0';
        }
    }
    //printf("linenum: %llu\n", *linenum);

    char ** strings= (char **) calloc (*linenum, sizeof(char *));
    strings[0] = text;

    size_t curLine = 0;
    for(size_t index = 0; index < textsize; index++)
    {
        if (text[index] == '\0'){
            curLine++;
            strings[curLine] = text + index + 1;
        }
    }
    return strings;
}

void printStrs(char ** strings, size_t linenum)
{
    for (size_t index = 0; index < linenum; index++){
        printf("%s\n", strings[index]);
        //debugPrint(strings[index]);
    }
}

void delStrs(char ** text)
{
    //free(text[0]);
    free(text);
}
