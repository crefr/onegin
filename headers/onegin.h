#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

struct text_{
    FILE * textfile;
    char * text;
    size_t textlen;
    char ** strings;
    char ** endstrings;
    size_t strnum;

};
typedef struct text_ text_t;

void getStrs(const char * infilename, text_t *text);
void delStrs(text_t *text);
void getStrNum(text_t * text);
void readStrsFromFile(text_t * text);
void findStrsInText(text_t * text);
int pointerStrCmp(const void * firstpointer, const void * secondpointer);
void printStrsToFile(const char * outfilename, text_t * text);
int pointerRevStrCmp(const void *firstpointer, const void *secondpointer);
ssize_t testSorting(text_t *strs, int (*cmp)(const void *, const void *));
int advancedStrCmp(const char *firststring, const char *secondstring);
int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer);
int revStrCmp(const char *firststring, const char * secondstring);


#endif
