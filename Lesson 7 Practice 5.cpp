#include <stdio.h>

int main()
{
    int list[10], *p, i;
    p = list;

    for (i = 0; i < 10; i++)
    {
        *(p + i) = 2 * i;
    }

    *p = 5;

    for (i = 0; i < 10; i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}
