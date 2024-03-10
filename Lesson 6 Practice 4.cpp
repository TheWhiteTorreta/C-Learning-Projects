#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (is_palindrome(input))
    {
        printf("The string '%s' is a palindrome.\n", input);
    }
    else
    {
        printf("The string '%s' is not a palindrome.\n", input);
    }

    return 0;
}
