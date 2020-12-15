#include <bstrlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <debug.h>

int main()
{
    bstring b = bfromcstr("hello");
    debug(blength(b));
    debug(b->mlen);
    debug(b->slen);
    printf("%s", b->data);
}