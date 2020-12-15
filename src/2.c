#include <clist.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <debug.h>
#include <bstrlib.h>

CList *fget_str_list(const char *name)
{
    CList *list = NULL;
    FILE *file = NULL;

    // getline buffer
    char *buffer = NULL;
    size_t bufsize = 0;

    // bstring buffer
    bstring b = {0};

    file = fopen(name, "r");
    assert(file != NULL);

    list = CList_Init(sizeof(bstring));
    assert(list != NULL);

    int num = 0;
    while (getline(&buffer, &bufsize, file) != -1)
    {
        b = bfromcstr(buffer);
        debug((void *)b);
        list->add(list, &b);
    }

    debug(list->count(list));

    for (int i = 0; i < list->count(list); i++)
    {
        b = (bstring)list->at(list, i);
        printf("%s", b->data);
    }

    fclose(file);
    return NULL;
}

int main()
{
    fget_str_list("input/2.input");
}