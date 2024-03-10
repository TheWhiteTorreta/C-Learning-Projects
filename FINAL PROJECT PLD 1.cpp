#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

void clearScreen() {
    printf("\n\n\n\n\n\n\n\n\n\n");
}

struct nameType {
    char name[40];
};

struct contact {
    char phone[20];
    char email[30];
};

struct addressType {
    char address[30];
    char city[30];
    char zip[20];
};

struct education {
    char primary[50];
    char secondary[50];
    char college[80];
};

struct experience {
    char exp1[30];
    char exp2[30];
    char exp3[30];
};

struct resume {
    struct nameType name;
    struct contact contact;
    struct addressType address;
    struct education education;
    struct experience experience;
};

int main() {
    printf("ResumePro: Crafting Your Professional Resume with Ease\n");

    struct resume res;

    printf("\n---------Provide the details below------\n\n");
    printf("Enter your name: ");
    fgets(res.name.name, 40, stdin);
    res.name.name[strlen(res.name.name) - 1] = '\0';

    printf("\nEnter contact details\n");
    printf("Phone: ");
    scanf("%s", res.contact.phone);
    printf("Email: ");
    scanf("%s", res.contact.email);

    printf("\nEnter address details\n");
    printf("Address: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(res.address.address, 30, stdin);
    res.address.address[strlen(res.address.address) - 1] = '\0';
    printf("City: ");
    fgets(res.address.city, 30, stdin);
    res.address.city[strlen(res.address.city) - 1] = '\0';
    printf("ZIP: ");
    fgets(res.address.zip, 20, stdin);
    res.address.zip[strlen(res.address.zip) - 1] = '\0';

    printf("\nEnter education details\n");
    printf("Primary education: ");
    fgets(res.education.primary, 50, stdin);
    res.education.primary[strlen(res.education.primary) - 1] = '\0';
    printf("Secondary education: ");
    fgets(res.education.secondary, 50, stdin);
    res.education.secondary[strlen(res.education.secondary) - 1] = '\0';
    printf("College education: ");
    fgets(res.education.college, 80, stdin);
    res.education.college[strlen(res.education.college) - 1] = '\0';

    printf("\nEnter your experience details\n");
    printf("Experience 1: ");
    fgets(res.experience.exp1, 30, stdin);
    res.experience.exp1[strlen(res.experience.exp1) - 1] = '\0';
    printf("Experience 2: ");
    fgets(res.experience.exp2, 30, stdin);
    res.experience.exp2[strlen(res.experience.exp2) - 1] = '\0';
    printf("Experience 3: ");
    fgets(res.experience.exp3, 30, stdin);
    res.experience.exp3[strlen(res.experience.exp3) - 1] = '\0';
    clearScreen();

    // Displaying all the information
    printf("\n--------Resume Information--------\n");
    printf("%s\n", res.name.name);
    printf("\nContact\n");
    printf("%s\n", res.contact.phone);
    printf("%s\n", res.contact.email);
    printf("\nAddress\n");
    printf("Address: %s\n", res.address.address);
    printf("City: %s\n", res.address.city);
    printf("ZIP: %s\n", res.address.zip);
    printf("\nEducation\n");
    printf("Primary Education: %s\n\n", res.education.primary);
    printf("Secondary Education: %s\n\n", res.education.secondary);
    printf("College Education: %s\n\n", res.education.college);
    printf("\nExperience\n");
    printf("%s\n", res.experience.exp1);
    printf("%s\n", res.experience.exp2);
    printf("%s\n", res.experience.exp3);

    return 0;
}
