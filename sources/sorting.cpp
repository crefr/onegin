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
        char * currel = (char *)base + current * elemsize;
        memcpy(key, currel, elemsize);

        char * element = currel;
        if (cmp(currel, element - elemsize) < 0){
            while(element > base && cmp(key, element - elemsize) < 0){
                memcpy(element, element - elemsize, elemsize);
                element -= elemsize;
            }
            memcpy(element, key, elemsize);
        }
    }
    free(key);
}

void shellSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *))
{
    const size_t step[] = {1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913, 1050113, 4197377, 16783361, 67121153, 268460033, 1073790977, 4295065601};
    const size_t numsteps = sizeof(step) / sizeof(step[0]);

    for(long long stepindex = numsteps - 1; stepindex >= 0; stepindex--){
        if (step[stepindex] >= len)
            continue;
        size_t newlen = len / step[stepindex];
        void * newbase = calloc(newlen + 1, elemsize);
        for(size_t offset = 0; offset < step[stepindex]; offset++){
            for (size_t index = 0; index * step[stepindex] + offset < len; index++){
                void * elfrombase    = (char *)base + (offset + index * step[stepindex]) * elemsize;
                void * elfromnewbase = (char *)newbase + index * elemsize;
                memcpy(elfromnewbase, elfrombase, elemsize);
            }

            insertionSort(newbase, elemsize, newlen, cmp);

            for (size_t index = 0; index * step[stepindex] + offset < len; index++){
                void * elfrombase    = (char *)base + (offset + index * step[stepindex]) * elemsize;
                void * elfromnewbase = (char *)newbase + index * elemsize;
                memcpy(elfrombase, elfromnewbase, elemsize);
            }
        }
        free(newbase);
    }
}
