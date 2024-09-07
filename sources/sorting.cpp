#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sorting.h"
#include "mystring.h"

// void bubbleSort(char ** text, size_t len)
// {
//     for (size_t unsorted = len; unsorted > 1; unsorted--)
//         for (size_t j = 0; j < unsorted - 1; j++)
//             if (mystrcmp(text[j], text[j + 1]) > 0){
//                 char * temp = text[j];
//                 text[j] = text[j + 1];
//                 text[j + 1] = temp;
//             }
// }

void bubbleSort(void *base, size_t elemsize, size_t len, int (*cmp)(const void *, const void *))
{
    void * temp = (void *) calloc(1, elemsize);
    for (size_t unsorted = len; unsorted > 1; unsorted--)
        for (size_t j = 0; j < unsorted - 1; j++){
            void * el1 = (char *) base + j * elemsize;
            void * el2 = (char *) base + (j + 1) * elemsize;
            if (cmp( el1, el2 ) > 0){
                memcpy(temp, el1, elemsize);
                memcpy(el1 , el2, elemsize);
                memcpy(el2, temp, elemsize);
            }
        }
    free(temp);
}
