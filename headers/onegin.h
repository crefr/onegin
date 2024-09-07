#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

char ** getStrs(FILE * textfile, size_t * linenum);
void delStrs(char ** text);
int pointerStrCmp(const void * firstpointer, const void * secondpointer);

#endif
