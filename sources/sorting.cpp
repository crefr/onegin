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
        for (size_t j = 0; j < unsorted - 1; j++)
            if (cmp( (char *) base + j * elemsize, (char *) base + (j + 1) * elemsize ) > 0){
                memcpy(temp, (char *) base + j * elemsize, elemsize);
                memcpy((char *) base + j * elemsize, (char *) base + (j + 1) * elemsize, elemsize);
                memcpy((char *) base + (j + 1) * elemsize, temp, elemsize);
            }
    free(temp);
}
