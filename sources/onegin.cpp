#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"

#define NDEBUG
#include <assert.h>
#include "debug.h"

// #define MAX(a,b) ((a) > (b)) ? (a) : (b)

bool isLetter(char symbol);
void getStrNum(text_t * text);
void findStrsInText(text_t * text);

int getStrs(const char * infilename, text_t * text)
{
    text->textfile = fopen(infilename, "r");
    if (text->textfile == NULL)
        return ONEGINFILEERROR;

    readStrsFromFile(text);
    getStrNum(text);
    printf("strnum: %llu\n", text->strnum);
    findStrsInText(text);
    return ONEGINSUCCESS;
}

void delStrs(text_t * text)
{
    free(text->text - 1);
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

void findStrsInText(text_t * text)
{
    text->strings = (str_t *)calloc(text->strnum, sizeof(str_t));
    text->strings[0].start = text->text;

    size_t strindex = 1;
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
                    text->strings[strindex - 1].end = ptr;
                    strindex++;
                }
                break;
            default:
                break;
        }
        ptr++;
    }
    text->strings[text->strnum - 1].end = ptr - 1;
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
    str_t * firststring  = (str_t *) firstpointer;
    str_t * secondstring = (str_t *) secondpointer;
    return advancedStrCmp(firststring->start, secondstring->start);
}

int ptrAdvancedRevStrCmp(const void * firstpointer, const void * secondpointer)
{
    return advancedRevStrCmp((str_t *)firstpointer, (str_t *)secondpointer);
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
            if (*nowfirst == '\0')
                break;
            nowfirst++;
        }
        while (!isLetter(*nowsecond)){
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

int advancedRevStrCmp(str_t *firststring, str_t *secondstring)
{
    assert(firststring  != NULL);
    assert(secondstring != NULL);

    const char * nowfirst  = firststring ->end - 1;
    const char * nowsecond = secondstring->end - 1;

    while(nowfirst >= firststring->start && nowsecond >= secondstring->start && (*nowfirst != '\0' || *nowsecond != '\0'))
    {
        while (!isLetter(*nowfirst)){
            if (*nowfirst == '\0')
                break;
            nowfirst--;
        }
        while (!isLetter(*nowsecond)){
            if (*nowsecond == '\0')
                break;
            nowsecond--;
        }

        if (*nowsecond == '\0' || *nowfirst == '\0'){
            break;
        }

        if (isLetter(*nowfirst) && isLetter(*nowsecond)){
            if (toupper(*nowfirst) != toupper(*nowsecond))
                break;
            nowfirst--;
            nowsecond--;
        }
    }
    return toupper(*nowfirst) - toupper(*nowsecond);
}

bool isLetter(char symbol)
{
    return (isalpha(symbol)) || (symbol == ' ');
}
