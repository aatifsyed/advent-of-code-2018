#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <clist.h>

int main()
{
    void *obj = NULL;
    int i = 0;
    int n = 0;

    /******************************************************* CHAR LIST */

    n = sizeof(char);
    CList *lst = CList_Init(n);

    for (i = 33; i < 123; i++)
    {
        obj = &i;
        lst->add(lst, obj); /* Adding obj items to the end of array */
    }
    lst->print(lst, 150, "char");

    n = 32;
    char ch = 'A';
    obj = lst->at(lst, n); /* Get 32nd item of array */
    printf("Position %i contains symbol \'%c\'\n", n, *((char *)obj));

    ch = '!';
    obj = &ch;
    n = lst->firstIndex(lst, obj); /* Find first index of '!' char */
    printf("Index of \'%c\' is %i\n", ch, n);

    ch = '+';
    n = lst->firstIndex(lst, obj);
    printf("Index of \'%c\' is %i\n", ch, n);

    n = 0;
    for (i = 15; i > 0; i--)
        lst->remove(lst, 0); /* Remove item at index 0 from array 15 times */

    lst->print(lst, 150, "char");
    lst->free(lst);
}