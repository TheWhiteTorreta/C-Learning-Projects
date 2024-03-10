#include <stdio.h>
int main() {
    int n = 10;
    do {
        printf("%d", n);
        printf(",");
        n--;
    } while (n > 0);
    printf("FIRE!");
    return 0;
}