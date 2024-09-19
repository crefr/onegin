#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"

//#define NDEBUG
#include <assert.h>
#include "debug.h"

bool isLetter(char symbol);

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
    text->strings = (str_t *)calloc(text->strnum, sizeof(str_t));
    text->strings[0].start = text->text;

    size_t strindex = 0;
    char * ptr = text->text;
    while(*ptr != '\0'){
        switch(*ptr){
            case '\r':
                *ptr = '\0';
                break;
            case '\n':
                *ptr = '\0';
                if(strindex < text->strnum){
                    text->strings[strindex].start = ptr + 1;
                    text->strings[text->strnum - 1 - strindex].end = ptr - 1;
                    strindex++;
                }
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
        fprintf(outfile, "%s\n", text->strings[index].start);
    }
    fclose(outfile);
}

ssize_t testSorting(text_t *strs, int (*cmp)(const void *, const void *))
{
    for(size_t strindex = 0; strindex < strs->strnum - 1; strindex++){
        if (cmp(strs->strings + strindex, strs->strings + strindex + 1) > 0)
            return strindex; // failed
    }
    return -1; // success
}


int pointerStrCmp(const void * firstpointer, const void * secondpointer)
{
    str_t firststring  = *((str_t *) firstpointer);
    str_t secondstring = *((str_t *) secondpointer);
    return mystrcmp(firststring.start, secondstring.start);
}

int pointerRevStrCmp(const void *firstpointer, const void *secondpointer)
{
    str_t firststring  = *((str_t *) firstpointer);
    str_t secondstring = *((str_t *) secondpointer);
    return revStrCmp(firststring.start, secondstring.start);
}

int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer)
{
    str_t firststring  = *((str_t *) firstpointer);
    str_t secondstring = *((str_t *) secondpointer);
    return advancedStrCmp(firststring.start, secondstring.start);
}

int revStrCmp(const char *firststring, const char * secondstring)
{
    const char * nowfirst  = firststring;
    const char * nowsecond = secondstring;

    while (*nowfirst  != '\0') nowfirst++;
    while (*nowsecond != '\0') nowsecond++;

    if (nowfirst  - firststring  != 0) nowfirst--;
    if (nowsecond - secondstring != 0) nowsecond--;

    while ((nowfirst >= firststring && nowsecond >= secondstring) && *nowfirst == *nowsecond){
        nowfirst--;
        nowsecond--;
    }

    if (nowfirst < firststring || nowsecond < secondstring)
        return (int)((nowfirst - firststring) - (nowsecond - secondstring));

    dprintf("result: %d\n", *nowfirst - *nowsecond);
    return *nowfirst - *nowsecond;
}


int advancedStrCmp(const char *firststring, const char *secondstring)
{
    assert(firststring  != NULL);
    assert(secondstring != NULL);

    const char * nowfirst  = firststring;
    const char * nowsecond = secondstring;

    while(*nowfirst != '\0' && *nowsecond != '\0')
    {
        while (!isLetter(*nowfirst)){
            //dprintf("%c(%d)", *nowfirst, *nowfirst);
            if (*nowfirst == '\0')
                break;
            nowfirst++;
        }
        while (!isLetter(*nowsecond)){
            //dprintf("%c(%d)", *nowsecond, *nowsecond);
            if (*nowsecond == '\0')
                break;
            nowsecond++;
        }


        if (isLetter(*nowfirst) && isLetter(*nowsecond)){
            if (*nowfirst != *nowsecond)
                break;
            nowfirst++;
            nowsecond++;
        }
    }
    return toupper(*nowfirst) - toupper(*nowsecond);
}

bool isLetter(char symbol)
{
    return (isalpha(symbol)) || (symbol == ' ');
}
