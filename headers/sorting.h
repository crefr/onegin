#ifndef SORTING_INCLUDED
#define SORTING_INCLUDED

void swapByPtr(void * el1, void * el2, void * temp, size_t elemsize);

void bubbleSort(void *base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *));
void selectionSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *));

#endif
