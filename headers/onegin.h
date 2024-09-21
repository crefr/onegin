#ifndef ONEGIN_INCLUDED
#define ONEGIN_INCLUDED

typedef struct str_{
    char * start;
    char * end;
} str_t;

typedef struct text_{
    FILE * textfile;
    char * text;
    size_t textlen;
    str_t * strings;
    size_t strnum;
} text_t;

enum oneginstatus{ONEGINSUCCESS = 0, ONEGINFILEERROR};

/**
 * @brief Fully fills text_t structure.
 *
 * @param infilename
 * @param text
 * @return int
 */
int getStrs(const char * infilename, text_t *text);

/**
 * @brief Deletes text_t structure.
 *
 * @param text
 */
void delStrs(text_t *text);

/**
 * @brief Function that tests if strings at text_t are sorted.
 *
 * @param strs
 * @param cmp
 * @return ssize_t
 */
ssize_t testSorting(text_t *strs, int (*cmp)(const void *, const void *));

#endif
