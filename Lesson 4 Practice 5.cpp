#include <stdio.h>

int main() {
    int duration, total;
    const int rate1 = 20; // Rate for the first three minutes
    const int rate2 = 4; // Rate for succeeding minutes

    printf("Enter the duration of the call in minutes: ");
    scanf("%d", &duration);

    if (duration <= 0) {
        printf("Invalid duration. Please enter a positive integer.\n");
        return 0;
    } else if (duration <= 3) {
        total = duration * rate1;
    } else {
        total = 3 * rate1 + (duration - 3) * rate2;
    }

    printf("Your phone bill is: %d pesos\n", total);

    return 0;
}
