#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <debug.h>
#include <clist.h>

int main()
{
    CList *list = NULL;
    void *p = NULL;
    void **pp = &p;
    list = CList_Init(sizeof(void *));

    for (int i = 0; i < 5; i++)
    {
        p = malloc(256);
        pp = &p;
        debug(p);
        debug((void *)pp);

        list->add(list, (void *)&pp);
    }
    p = NULL;

    list->print(list, 5, NULL);

    for (int i = 0; i < 5; i++)
    {
        pp = list->at(list, i);
        debug(pp);
        free(pp);
    }
    list->clear(list);
}