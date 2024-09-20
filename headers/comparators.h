#ifndef COMPARATORS_INCLUDED
#define COMPARATORS_INCLUDED

int advancedStrCmp(const char *firststring, const char *secondstring);
int ptrAdvancedRevStrCmp(const void * firstpointer, const void * secondpointer);

int pointerStrCmp(const void * firstpointer, const void * secondpointer);

int revStrCmp(const char *firststring, const char * secondstring);
int pointerRevStrCmp(const void *firstpointer, const void *secondpointer);

int advancedRevStrCmp(const str_t * firststring, const str_t * secondstring);
int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer);

#endif
