#include <stdlib.h>
#include <string.h>
#include <debug.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Pointer to our pointer array.
    void **parr = NULL;

    // Allocate our array to hold n elements.
    parr = (void **)malloc(sizeof(void *) * 0);

    for (int i = 0; i < 50; i++)
    {
        // Resize our array
        // Leaky if realloc fails. Fix
        parr = realloc(parr, sizeof(void *) * (i + 1));
        parr[i] = (void *)i;
        // memcpy(&parr[i], &i, sizeof(void *));
    }

    for (int i = 0; i < 50; i++)
    {
        printf("%d\n", (int)parr[i]);
    }

    return 0;
}
