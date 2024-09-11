#ifndef IO_ONEGIN_INCLUDED
#define IO_ONEGIN_INCLUDED

void printStrs(char ** strings, size_t linenum);
void printAtFile(FILE * outfile, char ** strings, size_t linenum);
size_t readTextFromFile(FILE * textfile, char * text, size_t * linenum);

#endif
