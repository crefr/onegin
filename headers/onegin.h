#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

char ** getStrs(FILE * textfile, size_t * linenum, char ** text);
void delStrs(char ** text);
int pointerStrCmp(const void * firstpointer, const void * secondpointer);

#endif
