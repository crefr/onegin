#include <stdio.h>
#include <stdarg.h>

#include "debug.h"

void debugPrint(const char * str)
{
    while(*str != '\0'){
        printf("(%d)", *str, *str);
        str++;
    }
    printf("\\0(0)\n");
}

