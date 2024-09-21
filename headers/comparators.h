#ifndef COMPARATORS_INCLUDED
#define COMPARATORS_INCLUDED

/**
 * @brief Comparator that skips no-letter symbols.
 *
 * @param firststring
 * @param secondstring
 * @return int
 */
int advancedStrCmp(const char *firststring, const char *secondstring);

/**
 * @brief Uses advancedStrCmp(), compares two string_t.
 *
 * @param firstpointer
 * @param secondpointer
 * @return int
 */
int ptrAdvancedRevStrCmp(const void * firstpointer, const void * secondpointer);

/**
 * @brief Uses strcmp, gives the strings from pointers to string_t.
 *
 * @param firstpointer
 * @param secondpointer
 * @return int
 */
int pointerStrCmp(const void * firstpointer, const void * secondpointer);

/**
 * @brief strcmp from end to begin.
 *
 * @param firststring
 * @param secondstring
 * @return int
 */
int revStrCmp(const char *firststring, const char * secondstring);

/**
 * @brief Uses revStrCmp(), gives strings from pointers to string_t.
 *
 * @param firstpointer
 * @param secondpointer
 * @return int
 */
int pointerRevStrCmp(const void *firstpointer, const void *secondpointer);

/**
 * @brief revStrcmp that skips no-letter symbols.
 *
 * @param firststring
 * @param secondstring
 * @return int
 */
int advancedRevStrCmp(const str_t * firststring, const str_t * secondstring);

/**
 * @brief Uses advancedRevStrCmp(), gives the strings from pointers to string_t.
 *
 * @param firstpointer
 * @param secondpointer
 * @return int
 */
int ptrAdvancedStrCmp(const void * firstpointer, const void * secondpointer);

#endif
