#include <stdlib.h>
#include <stdio.h>

void bubbleSort(const char ** text, size_t len)
{
    for (size_t unsorted = len; unsorted > 1; unsorted--)
        for (size_t j = 0; j < unsorted - 1; j++)
            if (strcmp(text[j], text[j + 1]) > 0){
                const char * temp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = temp;
            }
}
