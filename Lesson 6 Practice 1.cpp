#include <stdio.h>
#include <string.h>

int main()
{
    char string1[80], string2[80];
    
    printf("Enter string1: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Enter string2: ");
    fgets(string2, sizeof(string2), stdin);

    printf("The length of string1 and string2 are: %lu %lu\n", strlen(string1) - 1, strlen(string2) - 1);

    if (!strcmp(string1, string2))
        printf("The strings are equal!!!\n");

    strncat(string1, string2, sizeof(string1) - strlen(string1) - 1);
    printf("The word using strncat : %s", string1);

    strncpy(string1, string2, sizeof(string1) - 1);
    string1[sizeof(string1) - 1] = '\0';
    printf("The word using strncpy : %s", string1);

    return 0;
}
