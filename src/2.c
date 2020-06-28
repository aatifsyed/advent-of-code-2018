#include <clist.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

CList *fget_str_list(const char *name)
{
    CList *list = NULL;
    FILE *file = NULL;

    // getline buffer
    char *buffer = NULL;
    size_t bufsize = 0;

    // strings in list
    char *string = NULL;
    size_t string_length = 0;

    file = fopen(name, "r");
    assert(file != NULL);

    list = CList_Init(sizeof(char *));
    assert(list != NULL);

    while (getline(&buffer, &bufsize, file) != -1)
    {
        // Our buffer may have to grow, but the current string may not take
        // up all of it. Find out how much memory we need to allocate
        // (including the null terminator)
        string_length = strlen(buffer) + 1;
        string = (char *)malloc(string_length);
        printf("%s", buffer);
    }

    fclose(file);
    return NULL;
}

int main()
{
    fget_str_list("input/2.input");
}