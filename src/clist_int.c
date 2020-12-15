#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <debug.h>
#include <clist.h>

int main()
{
    CList *list = NULL;
    int p = 0;
    list = CList_Init(sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        p = i;
        debug(p);
        list->add(list, (void *)&p);
    }
    p = NULL;

    list->print(list, 5, NULL);

    for (int i = 0; i < 5; i++)
    {
        p = list->at(list, i);
        debug(p);
    }
    list->clear(list);
}