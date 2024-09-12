#ifndef DEBUG_INCLUDED
#define DEBUG_INCLUDED

#include <stdio.h>
#include <stdarg.h>

#ifdef NDEBUG
    #define dprintf(...) ((void) 0)
#else
    #define dprintf(...) printf(__VA_ARGS__)
#endif

#endif
