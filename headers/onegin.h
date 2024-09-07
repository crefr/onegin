#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

char ** getStrs(FILE * textfile, size_t * linenum);
void delStrs(char ** text);
void printStrs(char ** strings, size_t linenum);
int pointerStrCmp(const void * firstpointer, const void * secondpointer);
void printAtFile(FILE * outfile, char ** strings, size_t linenum);

#endif
