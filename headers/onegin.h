#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED


typedef struct str_{
    char * start;
    char * end;
} str_t;

typedef struct text_{
    FILE * textfile;
    char * text;
    size_t textlen;
    str_t * strings;
    size_t strnum;
} text_t;

enum oneginstatus{ONEGINSUCCESS = 0, ONEGINFILEERROR};
//typedef struct text_ text_t;

int getStrs(const char * infilename, text_t *text);
void delStrs(text_t *text);
ssize_t testSorting(text_t *strs, int (*cmp)(const void *, const void *));

int advancedStrCmp(const char *firststring, const char *secondstring);
int ptrAdvancedRevStrCmp(const void * firstpointer, const void * secondpointer);

int pointerStrCmp(const void * firstpointer, const void * secondpointer);

int revStrCmp(const char *firststring, const char * secondstring);
int pointerRevStrCmp(const void *firstpointer, const void *secondpointer);

int advancedRevStrCmp(str_t * firststring, str_t * secondstring);
int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer);

#endif
