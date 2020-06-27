#ifndef FILE_INCLUDED
#define FILE_INCLUDED
#include <stdbool.h>

/**
 * @brief Does long l exist in array larr?
 * 
 * @param larr 
 * @param nmemb 
 * @param l 
 * @return true 
 * @return false 
 */
bool larr_containsl(const long *larr, unsigned int nmemb, long l);

/**
 * @brief Print array
 * 
 * @param larr 
 * @param nmemb 
 * @return int 0
 */
int larr_print(const long *larr, unsigned int nmemb);

/**
 * @brief Appends a long to an array of longs
 * 
 * @param[in, out] larr The array. Must be dynamically allocated if not NULL
 * @param[in, out] nmemb Number of items in the array.
 * @param[in] i long to append
 * @return int non-zero on error
 */
int larr_append(long **larr, unsigned int *nmemb, long i);

/**
 * @brief Append a long read from each line in a file to an array. Will dynamically allocate if necessary.
 * 
 * @param name[in] filename
 * @param larr[in/out] Array. Must be dynamically allocated if non NULL
 * @param nmemb[int/out] Number of items in the array
 * @return int 0, asserts on error
 */
int fgetlarr(const char *name, long **larr, unsigned int *nmemb);

#endif // FILE_INCLUDED