#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "debug.h"

void getStrs(const char * infilename, text_t * text)
{
    text->textfile = fopen(infilename, "r");

    readStrsFromFile(text);
    getStrNum(text);
    printf("strnum: %llu\n", text->strnum);
    findStrsInText(text);
}

void delStrs(text_t * text)
{
    free(text->text);
    free(text->strings);
}

int pointerStrCmp(const void * firstpointer, const void * secondpointer)
{
    const char * firststring  = *((const char * const *) firstpointer);
    const char * secondstring = *((const char * const *) secondpointer);
    return mystrcmp(firststring, secondstring);
}

void getStrNum(text_t * text)
{
    char * ptr = text->text;
    while(*ptr != '\0'){
        if (*ptr == '\n')
            if (*(ptr + 1) != '\0')
                text->strnum++;
        ptr++;
    }
    text->strnum++;
}

void readStrsFromFile(text_t * text)
{
    fseek(text->textfile, 0, SEEK_END);
    text->textlen = (size_t) ftell(text->textfile) + 1;
    fseek(text->textfile, 0, SEEK_SET);

    text->text = (char *)calloc(text->textlen, sizeof(char));
    text->textlen = fread(text->text, sizeof(char), text->textlen, text->textfile) + 1;
    text->text[text->textlen - 1] = '\0';
    fclose(text->textfile);
}

void findStrsInText(text_t * text)
{
    text->strings = (char **)calloc(text->strnum, sizeof(char *));
    text->strings[0] = text->text;

    size_t strindex = 1;
    char * ptr = text->text;
    while(*ptr != '\0'){
        switch(*ptr){
            case '\r':
                *ptr = '\0';
                break;
            case '\n':
                *ptr = '\0';
                if(strindex < text->strnum)
                    text->strings[strindex++] = ptr + 1;
                break;
            default:
                break;
        }
        ptr++;
    }
}

void printStrsToFile(const char * outfilename, text_t * text)
{
    FILE * outfile = fopen(outfilename, "w");
    for (size_t index = 0; index < text->strnum; index++){
        fprintf(outfile, "%s\n", text->strings[index]);
    }
    fclose(outfile);
}
