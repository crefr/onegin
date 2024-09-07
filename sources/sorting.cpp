#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sorting.h"
#include "mystring.h"

void swapByPtr(void * el1, void * el2, void * temp, size_t elemsize)
{
    //void * temp = calloc(1, elemsize);
    memcpy(temp, el1, elemsize);
    memcpy(el1 , el2, elemsize);
    memcpy(el2, temp, elemsize);
    //free(temp);
}

void bubbleSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *))
{
    void * temp = calloc(1, elemsize);
    for (size_t unsorted = len; unsorted > 1; unsorted--)
        for (size_t j = 0; j < unsorted - 1; j++){
            void * el1 = (char *) base + j * elemsize;
            void * el2 = (char *) base + (j + 1) * elemsize;
            if (cmp( el1, el2 ) > 0)
                swapByPtr(el1, el2, temp, elemsize);
        }
    free(temp);
}

void selectionSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *))
{
    void * temp = calloc(1, elemsize);
    size_t minindex = 0;
    for (size_t start = 0; start < len - 1; start++){
        minindex = start;
        for (size_t index = start + 1; index < len; index++){
            void * el    = (char *) base + index * elemsize;
            void * elmin = (char *) base + minindex * elemsize;
            if (cmp(elmin, el) > 0){
                minindex = index;
            }
        }
        swapByPtr((char *) base + start * elemsize, (char *) base + minindex * elemsize, temp, elemsize);
    }
    free(temp);
}

void insertionSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *))
{
    void * key  = calloc(1, elemsize);
    for(size_t current = 1; current < len; current++){

        void * curel = (char *)base + current * elemsize;
        memcpy(key, curel, elemsize);

        size_t index = current;
        void * prevel = NULL;
        while(index > 0  && cmp(key, (prevel = (char *)base + (index - 1) * elemsize)) <= 0){
            memcpy((char *) prevel + elemsize, prevel, elemsize);
            index--;
        }
        memcpy((char *) prevel, key, elemsize);
    }
    free(key);
}
