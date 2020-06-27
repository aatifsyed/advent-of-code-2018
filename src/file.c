#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

/**
 * @brief Print array
 * 
 * @param larr 
 * @param nmemb 
 * @return int 0
 */
int larr_print(const long *larr, unsigned int nmemb)
{
    fprintf(stdout, "[");
    for (int i = 0; i < nmemb; i++)
    {
        fprintf(stdout, "%3ld", larr[i]);

        if (i != nmemb - 1)
        {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
    return 0;
}

/**
 * @brief Appends a long to an array of longs
 * 
 * @param[in, out] larr The array. Must be dynamically allocated if not NULL
 * @param[in, out] nmemb Number of items in the array.
 * @param[in] i long to append
 * @return int non-zero on error
 */
int larr_append(long **larr, unsigned int *nmemb, long i)
{
    long *new = NULL;
    new = (long *)realloc(*larr, sizeof(long) * (*nmemb + 1));
    if (new == NULL)
    {
        // Failed to realloc.
        return -1;
    }
    else
    {
        // There's now one more element, but the last element's INDEX is
        // equal to the previous NUMBER OF MEMBERS.
        new[*nmemb] = i;
        *larr = new;
        *nmemb += 1;
        return 0;
    }
}

/**
 * @brief Append a long read from each line in a file to an array
 * 
 * @param name[in] filename
 * @param larr[in/out] Array. Must be dynamically allocated if non NULL
 * @param nmemb[int/out] Number of items in the array
 * @return int 0, asserts on error
 */
int fgetlarr(const char *name, long **larr, unsigned int *nmemb)
{
    FILE *file = NULL;
    long num_to_append = 0;

    int ret;

    // strol buffer
    char *buffer = NULL;
    char *strtolend = NULL;
    size_t bufsize = 0;

    file = fopen(name, "r");
    assert(file != NULL);

    while (getline(&buffer, &bufsize, file) != -1)
    {
        num_to_append = strtol(buffer, &strtolend, 10);

        // Ensure we actually read a valid number
        assert(buffer != strtolend);
        assert(num_to_append != LONG_MIN &&
               num_to_append != LONG_MAX);

        ret = larr_append(larr, nmemb, num_to_append);
        assert(ret == 0);
    }

    fclose(file);
    return 0;
}
