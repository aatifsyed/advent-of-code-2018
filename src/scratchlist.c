#include <stdio.h>
#include <assert.h>
#include <clist.h>
#include <stdlib.h>
#include <debug.h>

int main()
{
    char strbuf[30];
    char hello[] = "hello my name is Aatif";
    char goodbye[] = "goodbye Aatif";

    CList *list = CList_Init(sizeof(void *));

    debug((void *)hello);
    debug((void *)goodbye);

    list->add(list, &hello);
    list->add(list, &goodbye);

    list->print(list, 2, "string");
    list->print(list, 2, NULL);
    list->free(list);
}