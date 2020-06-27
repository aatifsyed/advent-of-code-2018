// Chronal Calibration
#include <file.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    long *larr = NULL;
    unsigned int nmemb = 0;
    long running = 0;

    fgetlarr("input/1.input", &larr, &nmemb);

    for (int i = 0; i < nmemb; i++)
    {
        running += larr[i];
    }

    free(larr);

    printf("%ld\n", running);

    return 0;
}
