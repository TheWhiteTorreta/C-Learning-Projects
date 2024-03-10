#include <stdio.h>

void fibonacci_series(int n)
{
    long long int first = 0, second = 1, next;
    printf("Fibonacci series up to %d:\n", n);

    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%lld ", next);
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    fibonacci_series(number);

    return 0;
}
