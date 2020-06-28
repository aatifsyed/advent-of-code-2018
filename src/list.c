#include <list.h>
#include <assert.h>

struct list_header
{
    list_handle *handle;
    list_item *tailward;
    list_item *headward;
};

struct list_handle
{
    list_item *head;
    list_item *tail;
    unsigned int nmemb;
};

int list_header_create(list_header **header)
{
    assert(*header == NULL);
    *header = (list_header *)malloc(sizeof(list_header));
    assert(*header != NULL);
    (*header)->handle = NULL;
    (*header)->tailward = NULL;
    (*header)->headward = NULL;
    return 0;
}

int list_header_destroy(list_header **header)
{
    assert(*header != NULL);
    free((void *)*header);
    *header = NULL;
    return 0;
}

int list_print(const list_handle *handle)
{
    return 0;
}

int list_item_create(list_item **item)
{
    assert(*item == NULL);
    *item = (list_item *)malloc(sizeof(list_item));
    assert(*item != NULL);
    (*item)->header = NULL;
    (*item)->data = NULL;
    (*item)->size = 0;
    list_header_create(&((*item)->header));
    return 0;
}

int list_item_destroy(list_item **item)
{
    assert(*item != NULL);
    list_header_destroy(&((*item)->header));
    free((void *)*item);
    *item = NULL;
    return 0;
}

int list_handle_create(list_handle **handle)
{
    assert(*handle == NULL);
    *handle = (list_handle *)malloc(sizeof(list_handle));
    assert(*handle != NULL);
    (*handle)->head = NULL;
    (*handle)->tail = NULL;
    (*handle)->nmemb = 0;
    return 0;
}

int list_handle_destroy(list_handle **handle)
{
    assert(*handle != NULL);
    free((void *)*handle);
    *handle = NULL;
    return 0;
}

int list_create(list_handle **handle)
{
    list_handle_create(handle);
    return 0;
}

int list_unappend(list_handle *handle, void **data, size_t *size)
{
    assert(handle->tail != NULL);
    *data = handle->tail->data;
    *size = handle->tail->size;

    handle->tail = handle->tail->header->headward;

    list_item_destroy(&(handle->tail));

    return 0;
}

int list_append(list_handle *handle, void *data, size_t size)
{
    list_item *item = NULL;

    assert(handle != NULL);
    list_item_create(&item);

    item->data = data;
    item->size = size;
    item->header->handle = handle;

    item->header->tailward = NULL;
    item->header->headward = handle->tail;

    if (handle->tail != NULL)
    {
        handle->tail->header->tailward = item;
    }
    handle->tail = item;

    return 0;
}

#include <stdio.h>

int main()
{
    list_handle *handle = NULL;
    list_handle_create(&handle);

    list_append(handle, NULL, 1);
    list_append(handle, NULL, 2);

    void *data = NULL;
    size_t size = 0;

    list_unappend(handle, &data, &size);
    printf("%p, %lu", data, size);
    list_unappend(handle, &data, &size);
    printf("%p, %lu", data, size);

    list_handle_destroy(&handle);
}