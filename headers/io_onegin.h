#ifndef IO_ONEGIN_INCLUDED
#define IO_ONEGIN_INCLUDED

/**
 * @brief Reads text from file.
 *
 * @param text
 */
void readStrsFromFile(text_t * text);

/**
 * @brief Prints strs from struct text_t at file.
 *
 * @param outfile
 * @param text
 */
void printStrsToFile(FILE * outfile, text_t * text);

/**
 * @brief Prints original text to file.
 *
 * @param outfile
 * @param text
 */
void printOriginTextToFile(FILE * outfile, text_t * text);

#endif
