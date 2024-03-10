#include <stdio.h>

int main() {
    int n, i, fact = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if input is valid
    if (n < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    

    // Compute the factorial
    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    // Display the result
    printf("The factorial of %d is %d\n", n, fact);

    return 0;
}
