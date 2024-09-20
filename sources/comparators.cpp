#include <stdlib.h>
#include <stdio.h>

#define NDEBUG
#include <assert.h>
#include <ctype.h>

#include "mystring.h"
#include "onegin.h"
#include "comparators.h"

bool isLetter(char symbol);

int pointerStrCmp(const void * firstpointer, const void * secondpointer)
{
    const str_t * firststring  = (const str_t *) firstpointer;
    const str_t * secondstring = (const str_t *) secondpointer;
    return mystrcmp(firststring->start, secondstring->start);
}

int pointerRevStrCmp(const void *firstpointer, const void *secondpointer)
{
    const str_t * firststring  = (const str_t *) firstpointer;
    const str_t * secondstring = (const str_t *) secondpointer;
    return revStrCmp(firststring->start, secondstring->start);
}

int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer)
{
    const str_t * firststring  = (const str_t *) firstpointer;
    const str_t * secondstring = (const str_t *) secondpointer;
    return advancedStrCmp(firststring->start, secondstring->start);
}

int ptrAdvancedRevStrCmp(const void * firstpointer, const void * secondpointer)
{
    return advancedRevStrCmp((const str_t *)firstpointer, (const str_t *)secondpointer);
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

int advancedRevStrCmp(const str_t * firststring, const str_t * secondstring)
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
