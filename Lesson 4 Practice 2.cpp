#include <stdio.h>
#include <conio.h>

float reg_fare, stud, senior;
int x;

int main() {
    reg_fare = 220;
    printf("Enter Type of Passenger:\n\n");
    printf("(1) Student \n");
    printf("(2) Senior \n");
    printf("(3) Regular \n\n");
    printf(" Please Enter Number [1-3]: ");
    scanf("%d", &x);

    if (x == 1) {
        printf("\nThe regular fare is = %.2f\n", reg_fare);
        printf("Student's discount is 15%\n");
        stud = reg_fare * 0.85;
        printf("The amount to be paid : P ");
        printf("%.2f\n", stud);
    } else if (x == 2) {
        printf("The regular fare is = %.2f\n", reg_fare);
        printf("Senior Citizen's discount is 25%\n");
        senior = reg_fare * 0.75;
        printf("The amount to be paid : P %.2f\n", senior);
    } else if (x == 3) {
        printf("The regular fare is = %.2f\n", reg_fare);
        printf("Since you're a regular passenger, then\n");
        printf("The amount to be paid : P %.2f\n", reg_fare);
    } else {
        printf("Unrecognized format");
    }

    getch();
    return 0;
}