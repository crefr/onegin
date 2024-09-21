#ifndef SORTING_INCLUDED
#define SORTING_INCLUDED

typedef void (*sortFunction_t)(void *, size_t, size_t, int (*cmp)(const void *, const void *));

/**
 * @brief Swaps two elements by pointers to them, need temp to be given at the arguments.
 *
 * @param el1
 * @param el2
 * @param temp
 * @param elemsize
 */
void swapByPtr(void * el1, void * el2, void * temp, size_t elemsize);

/**
 * @brief Calculates time of work of sorting functions and prints it with its error.
 *
 * @param sort
 * @param base
 * @param len
 * @param elemsize
 * @param cmp
 */
void sortTime(sortFunction_t sort, void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));

// Here are a lot of sorting functions.
void bubbleSort   (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void selectionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void insertionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void shellSort    (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void shellSort_old(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void quickSort    (void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));

#endif
