#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#include "logger.h"

static int LOGlevel = 0;
static FILE * LOGfile = NULL;

// void setLogLevel(int level)
// {
//     logLevel = level;
// }

void logStart(FILE * logfile, int loglevel)
{
    LOGlevel = loglevel;
    LOGfile = logfile;

}

void logPrint(int loglevel, const char * fmt, ...)
{
    if (loglevel <= LOGlevel){
        logPrintTime();
        va_list va = {};
        va_start(va, fmt);
        vfprintf(LOGfile, fmt, va);
        va_end(va);
    }
}

void logPrintTime()
{
    time_t time_0= time(NULL);
    struct tm *calctime = localtime(&time_0);

    const size_t timestrlen = 100;
    char timestr[timestrlen] = {};

    strftime(timestr, timestrlen, "[%d.%m.%G %H:%M:%S] ", calctime);
    fprintf(LOGfile, "%s", timestr);
}
