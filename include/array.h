#if !defined(ARRAY_INCLUDED)
#define ARRAY_INCLUDED
#include <stdlib.h>

typedef struct array_handle array_handle;

int array_append(const array_handle *array_handle, const void *data, size_t size);

#endif // ARRAY_INCLUDED
