#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    printf("Before swap:\nx = %d\ny = %d\n", x, y);

    swap(&x, &y);

    printf("After swap:\nx = %d\ny = %d\n", x, y);

    return 0;
}
