#include <stdio.h>
#include <string.h>

void sort_strings(char[][50], int);

void sort_strings(char a[][50], int elements)
{
    int i, j;
    char temp[50];

    for (i = 0; i < elements - 1; i++)
    {
        for (j = i + 1; j < elements; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
}

int main()
{
    char strings[10][50];
    printf("Enter 10 strings:\n");
    for (int i = 0; i < 10; i++)
    {
        fgets(strings[i], 50, stdin);
        if (i == 0)
            fgets(strings[i], 50, stdin); // To ignore newline from previous input
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }

    sort_strings(strings, 10);

    printf("After sorting the strings:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}