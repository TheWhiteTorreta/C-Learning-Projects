#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
    system("clear");
}

int main() {
    int choice;
    do {
        printf("MENU\n");
        printf("(1) Addition\n");
        printf("(2) Subtraction\n");
        printf("(3) Multiplication\n");
        printf("(4) Division\n");
        printf("(5) Quit\n");
        printf("Enter choice[1-5]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Addition code goes here
                printf("You chose addition.\n");
                break;
            case 2:
                // Subtraction code goes here
                printf("You chose subtraction.\n");
                break;
            case 3:
                // Multiplication code goes here
                printf("You chose multiplication.\n");
                break;
            case 4:
                // Division code goes here
                printf("You chose division.\n");
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("Press any key to continue...");
        getchar();
        getchar();
    } while (choice != 5);
    return 0;
}
