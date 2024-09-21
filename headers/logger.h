#ifndef LOGGER_INCLUDED
#define LOGGER_INCLUDED

#define LOGPRINT(loglevel, ...) \
        logPrint(loglevel, __VA_ARGS__)

void logStart(FILE * logfile, int loglevel);
void logPrint(int loglevel, const char * fmt, ...);
void logPrintTime(void);


/// @brief different levels of logging, IT IS NECESSARY TO WRITE THEM IN ASCENDING ORDER
enum loglevels{LOG_RELEASE, LOG_DEBUG, LOG_DEBUG_PLUS};

#endif
