#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"

#define NDEBUG
#include <assert.h>
#include "debug.h"

/**
 * @brief Returns number of strings in text.
 *
 * @param text
 */
void getStrNum(text_t * text);

/**
 * @brief Fills strings array in text_t with pointes to beginnings and endings of strings.
 *
 * @param text
 */
void findStrsInText(text_t * text);

int getStrs(const char * infilename, text_t * text)
{
    text->textfile = fopen(infilename, "r");
    if (text->textfile == NULL)
        return ONEGINFILEERROR;

    readStrsFromFile(text);

    fclose(text->textfile);
    getStrNum(text);
    printf("strnum: %lu\n", text->strnum);
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
            return (ssize_t) strindex; // failed
    }
    return -1; // success
}
