#if !defined(LIST_INCLUDED)
#define LIST_INCLUDED
#include <stdlib.h>

typedef struct list_header list_header;

typedef struct list_handle list_handle;

typedef struct list_item
{
    list_header *header;
    void *data;
    size_t size;
#ifdef DEBUG
    char tag[32];
#endif
} list_item;

#endif // LIST_INCLUDED
