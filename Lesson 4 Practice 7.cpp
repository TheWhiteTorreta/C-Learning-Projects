#include <stdio.h>

int main() {
    int n, i, sum;
    char choice;

    do {
        printf("Enter 1st number: ");
        scanf("%d", &n);
        printf("Enter 2nd number: ");
        scanf("%d", &i);

        sum = n + i;
        printf("Sum: %d\n", sum);

        if (sum < 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            return 0;
        }

        printf("Proceed another operation[Y/N]?: ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}