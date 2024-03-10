#include <stdio.h>
#include <conio.h> 

void sort(int[], int);

void sort(int a[], int elements)
{
    int i, j, temp;
    i = 0;
    while (i < (elements - 1))
    {
        j = i + 1;
        while (j < elements)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int numbers[] = {10, 9, 8, 23, 19, 11, 2, 7, 1, 13, 12};
    int loop;
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before the sort the array was\n");
    for (loop = 0; loop < array_size; loop++)
        printf(" %d ", numbers[loop]);

    sort(numbers, array_size);

    printf("\nAfter the sort the array was\n");
    for (loop = 0; loop < array_size; loop++)
        printf(" %d ", numbers[loop]);

    return 0;
}
