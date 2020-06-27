// Chronal Calibration
#include <file.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    long *larr = NULL;
    unsigned int nmemb = 0;

    long running = 0;

    long *running_larr = NULL;
    unsigned int running_nmemb = 0;

    fgetlarr("input/1.input", &larr, &nmemb);

    while (true)
    {
        for (int i = 0; i < nmemb; i++)
        {
            running += larr[i];
            if (larr_containsl(running_larr, running_nmemb, running))
            {
                goto FOUND_DUPLICATE;
            }
            larr_append(&running_larr, &running_nmemb, running);
        }
    }

FOUND_DUPLICATE:
    free(larr);
    free(running_larr);

    printf("%ld\n", running);

    return 0;
}
