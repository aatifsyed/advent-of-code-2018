#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char *string;

int sarr_print(const string *sarr, unsigned int nmemb)
{
    fprintf(stdout, "[");
    for (unsigned int i = 0; i < nmemb; i++)
    {
        fprintf(stdout, "%s", sarr[i]);

        if (i != nmemb - 1)
        {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
    return 0;
}

int sarr_append(string **sarr, unsigned int *nmemb, const string s)
{
    string *new = NULL;
    new = realloc(*sarr, sizeof(string) * (*nmemb + 1));
    assert(new != NULL);

    new[*nmemb] = s;
    *sarr = new;
    *nmemb += 1;
    return 0;
}

int sarr_destroy(string **sarr, unsigned int *nmemb)
{
    for (unsigned int i = 0; i < *nmemb; i++)
    {
        free((void *)*sarr[i]);
    }

    *sarr = NULL;
    *nmemb = 0;
    return 0;
}

int main()
{
    // String array
    string *sarr = NULL;
    unsigned int nmemb = 0;

    // string
    char *strbuf = NULL;
    size_t strbufsize = 0;

    FILE *file = NULL;

    // buffers for getline.
    char *buffer = NULL;
    size_t bufsize = 0;

    file = fopen("input/2.input", "r");
    assert(file != NULL);

    while (getline(&buffer, &bufsize, file) != -1)
    {
        // include null terminator
        strbufsize = strlen(buffer) + 0;
        strbuf = malloc(strbufsize * sizeof(char));
        memcpy(strbuf, buffer, strbufsize);
        sarr_append(&sarr, &nmemb, (string)strbuf);
    }

    free(buffer);

    sarr_print(sarr, nmemb);
    sarr_destroy(&sarr, &nmemb);

    fclose(file);
    return 0;
}
