#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

struct text_{
    FILE * textfile;
    char ** strings;
    size_t strnum;
    char * text;
    size_t textlen;
};
typedef struct text_ text_t;

// char ** getStrs(FILE * textfile, size_t * linenum, char ** text);
void getStrs(const char * infilename, text_t *text);
void delStrs(text_t *text);
int pointerStrCmp(const void * firstpointer, const void * secondpointer);
void getStrNum(text_t * text);
void readStrsFromFile(text_t * text);


#endif
