#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>

#define NDEBUG
#include <assert.h>

#include "sorting.h"
#include "mystring.h"
#include "debug.h"

void swapByPtr(void * el1, void * el2, void * temp, size_t elemsize)
{
    //void * temp = calloc(1, elemsize);
    memcpy(temp, el1, elemsize);
    memcpy(el1 , el2, elemsize);
    memcpy(el2, temp, elemsize);
    //free(temp);
}

void bubbleSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    assert(base != NULL);
    assert(cmp  != NULL);
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

void selectionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    assert(base != NULL);
    assert(cmp  != NULL);
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

void insertionSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    assert(base != NULL);
    assert(cmp  != NULL);
    void * key  = calloc(1, elemsize);
    for(size_t current = 1; current < len; current++){
        char * currel = (char *)base + current * elemsize;
        char * element = currel;
        if (cmp(currel, element - elemsize) < 0){
            memcpy(key, currel, elemsize);
            while(element - elemsize >= base && cmp(key, element - elemsize) < 0){
                memcpy(element, element - elemsize, elemsize);
                element -= elemsize;
            }
            memcpy(element, key, elemsize);
        }
    }
    free(key);
}

static void insforShellSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *), size_t step, size_t offset, void * temp);
void shellSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    void * temp = calloc(1, elemsize);
    assert(base != NULL);
    assert(cmp  != NULL);
    const size_t step[] = {1, 8, 23, 77, 281, 1073, 4193, 16577, 65921, 262913, 1050113, 4197377, 16783361, 67121153, 268460033, 1073790977, 4295065601};
    const size_t numsteps = sizeof(step) / sizeof(step[0]);

    for(long long stepindex = numsteps - 1; stepindex >= 0; stepindex--){
        if (step[stepindex] >= len)
            continue;
        for(size_t offset = 0; offset < step[stepindex]; offset++){
            insforShellSort(base, elemsize, len, cmp, step[stepindex], offset, temp);
        }
    }
    free(temp);
}

static void insforShellSort(void * base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *), size_t step, size_t offset, void * temp)
{
    assert(base != NULL);
    assert(cmp  != NULL);

    //void * key  = calloc(1, elemsize);
    size_t onemove = step * elemsize;
    for(size_t current = offset + step; current < len; current += step){
        char * currel = (char *)base + current * elemsize;
        char * element = currel;
        if (cmp(currel, element - elemsize) < 0){
            memcpy(temp, currel, elemsize);
            while(element - onemove >= ((char *)base) + offset * elemsize && cmp(temp, element - onemove) < 0){
                memcpy(element, element - onemove, elemsize);
                element -= onemove;
            }
            memcpy(element, temp, elemsize);
        }
    }
    //free(key);
}

void shellSort_old(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
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

            insertionSort(newbase, newlen, elemsize, cmp);

            for (size_t index = 0; index * step[stepindex] + offset < len; index++){
                void * elfrombase    = (char *)base + (offset + index * step[stepindex]) * elemsize;
                void * elfromnewbase = (char *)newbase + index * elemsize;
                memcpy(elfrombase, elfromnewbase, elemsize);
            }
        }
        free(newbase);
    }
}

size_t qsortPartition(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *));
void quickSort(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    if (len <= 1)
        return;


    if (len == 2){
        if (cmp(base, (char *) base + elemsize) > 0){
            void * temp = calloc(1, elemsize);
            swapByPtr(base,(char *) base + elemsize, temp, elemsize);
            free(temp);
        }
        return;
    }

    dprintf("len: %lu\n", len);
    size_t sepindex = qsortPartition(base, len, elemsize, cmp);
    dprintf("sepindex: %lu\n", sepindex);
    quickSort(base, sepindex + 1, elemsize, cmp);
    dprintf("first!\n");
    quickSort((char *)base + (sepindex + 1) * elemsize, len - sepindex - 1, elemsize, cmp);
    dprintf("second!\n");
}

size_t qsortPartition(void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    void * temp    = calloc(1, elemsize);
    void * septemp = calloc(1, elemsize);

    void * sepelem = (char *)base + ((len - 1) / 2) * elemsize;
    memcpy(septemp, sepelem, elemsize);

    char * leftelem  = (char *)base;
    char * rightelem = (char *)base + (len - 1) * elemsize;
    while(1){
        while(cmp(leftelem, septemp) < 0)
            leftelem += elemsize;
        while(cmp(rightelem, septemp) > 0)
            rightelem -= elemsize;
        if (leftelem >= rightelem){
            free(septemp);
            free(temp);
            return ((size_t)rightelem - (size_t)base) / elemsize;
        }
        swapByPtr(leftelem, rightelem, temp, elemsize);
        rightelem -= elemsize;
        leftelem  += elemsize;
    }
}

void sortTime(sortFunction_t sort, void * base, size_t len, size_t elemsize, int (*cmp)(const void *, const void *))
{
    const clock_t TESTTIME = 10 * CLOCKS_PER_SEC;
    double sumofSqT = 0;
    double sumofT   = 0;

    void * newbase = calloc(len, elemsize);

    size_t numofsorts = 0;
    clock_t start_testing = clock();
    while(clock() - start_testing < TESTTIME){
        memcpy(newbase, base, elemsize * len);
        clock_t start = clock();
        sort(newbase, len, elemsize, cmp);
        clock_t end = clock();
        double sorttime = (double)(end - start) / CLOCKS_PER_SEC * 1000;
        //printf(">>sorttime: %lg\n", sorttime);

        sumofSqT += sorttime * sorttime;
        sumofT += sorttime;
        numofsorts++;
    }
    free(newbase);
    double averageSqT = sumofSqT / (double)numofsorts;
    double averageT = sumofT / (double)numofsorts;
    double sigmaT = sqrt((averageSqT - averageT * averageT) / (double)numofsorts);
    double percentSigmaT = sigmaT / averageT * 100;

    printf("sorting time is %lg +- %lg ms (%.1lf%%) (average of %lu measures)\n", averageT, sigmaT, percentSigmaT, numofsorts);
}
