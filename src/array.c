#include <array.h>
#include <assert.h>

struct array_handle
{
    array_item *array;
    unsigned int nmemb;
};

typedef struct array_item
{
    void *data;
    size_t size;
} array_item;

int array_create(array_handle **handle)
{
    *handle = (array_handle *)malloc(sizeof(array_handle));
    assert(*handle != NULL);
    return 0;
}

int array_destroy(array_handle **handle)
{
    array_item *array = (*handle)->array;
    unsigned int nmemb = (*handle)->nmemb;

    for (unsigned int i = 0; i < nmemb; i++)
    {
        free
    }

    *handle = NULL;
}

int array_append(array_handle *array_handle, const void *data, size_t size)
{
    array_item *old_array = array_handle->array;
    unsigned int old_nmemb = array_handle->nmemb;

    array_item *new_array = NULL;
    unsigned int new_nmemb = array_handle->nmemb + 1;

    new_array = (array_item *)realloc((void *)old_array, sizeof(array_item) * new_nmemb);
    assert(new_array != NULL);

    // arrays are 0 indexed, but nmemb is 1 indexed (for valid arrays)
    new_array[old_nmemb].data = data;
    new_array[old_nmemb].size = size;

    array_handle->array = new_array;
    array_handle->nmemb - new_nmemb;
}