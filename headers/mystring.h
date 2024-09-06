#ifndef MYSTRING_INCLUDED
#define MYSTRING_INCLUDED

// #ifndef size_t
//     typedef unsigned long long int size_t;
// #endif

/**
 * @brief Функция копирует Си-строку srcptr, включая завершающий нулевой символ в строку назначения, на которую ссылается указатель destptr
 *
 * @param destptr   [OUT]   Указатель на строку назначения, куда будет скопирована строка-источник
 * @param srcptr    [IN]    Указатель на копируемую строку
 * @return char*    Указатель на строку назначения
 */
char *strcpy( char *destptr, const char *srcptr );

/**
 * @brief Функция копирует первые num символов из строки srcptr в строку destptr. Если конец строки srcptr (символ конца строки ) достигнут прежде, чем были скопированы num символов, к скопированным символам в конец строки destptr добавляется нуль-символ, после чего, строка считается скопированной.
 *
 * @param   destptr     [OUT]   Указатель на строку назначения (куда будут копироваться символы).
 * @param   srcptr      [IN]    Копируемая строка — строка из которой будут копироваться символы.
 * @param   num         [IN]    Максимальное количество копируемых символов строки srcptr.
 * @return char*    Указатель на строку назначения.
 */
char * strncpy( char * destptr, const char * srcptr, size_t num );
char * strcat( char * destptr, const char * srcptr );
const char * strchr( const char * string, int symbol );
char * strncat( char * destptr, char * srcptr, size_t num );
size_t strlen( const char * string );
char* strdup (const char *src);
int myputs(const char *str);
char *myfgets(char *str, int num, FILE *stream);
int getline(char str[], int lim);
const char * strstr( const char * string1, const char * string2 );
int strcmp(const char * firststring, const char * secondstring);

unsigned int * prefixFunction(const char * str, size_t len);
const char * strstr_kmp( const char * text, const char * sample );

#endif
