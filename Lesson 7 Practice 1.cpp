#include <stdio.h>

int main()
{
    int a = 5, b = 6;
    int *p_ptr, *q_ptr;
    p_ptr = &a;
    printf("%d\n", *p_ptr);
    q_ptr = p_ptr;
    printf("%d\n", *q_ptr);
    *p_ptr = 10;
    printf("%d\n", a);
    q_ptr = &b;
    printf("%d, %d\n", *p_ptr, *q_ptr);

    return 0;
}
