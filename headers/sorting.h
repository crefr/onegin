#ifndef SORTING_INCLUDED
#define SORTING_INCLUDED

typedef void (*sortFunction_t)(void *, size_t, size_t, int (*cmp)(const void *, const void *));

void swapByPtr(void * el1, void * el2, void * temp, size_t elemsize);
void sortTime(sortFunction_t sort, void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));

void bubbleSort   (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void selectionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void insertionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void shellSort    (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void shellSort_old(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void quickSort    (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));

#endif
