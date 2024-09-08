#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"
#include "onegin.h"
#include "io_onegin.h"
#include "debug.h"

// char ** getStrs(FILE* textfile, size_t linenum)
// {
//     fseek(textfile, 0, SEEK_END);
//     size_t textsize = ftell(textfile);
//     fseek(textfile, 0, SEEK_SET);
//
//     char * text = (char *) calloc(textsize, sizeof(char));
//
//     int curChar = 0;
//     size_t index = 0;
//     while((curChar = fgetc(textfile)) != EOF){
//         switch(curChar){
//             case '\n':
//                 text[index] = '\0';
//                 (*linenum)++;
//                 break;
//             case '\r':
//                 break;
//             default:
//                 text[index] = (char) curChar;
//                 break;
//         }
//         index++;
//     }
//     textsize = index;
// }

char ** getStrs(FILE * textfile, size_t * linenum)
{
    fseek(textfile, 0, SEEK_END);
    size_t textsize = ftell(textfile);
    fseek(textfile, 0, SEEK_SET);

    char * text = (char *) calloc(textsize, sizeof(char));
    textsize = readTextFromFile(textfile, text, linenum);
    printf("linenum: %llu\n", *linenum);

    char ** strings = (char **) calloc(*linenum * 2, sizeof(char *));
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
