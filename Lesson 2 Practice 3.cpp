#include <stdio.h>
#define GRAMS_PER_POUND 454
const int NEXT_CENTURY = 2000;
long weight_in_grams, weight_in_pounds;
int year_of_birth, age_in_2000;

int main()
 {
 
 /* Input data from user */
    
    printf("Enter your weight in pounds: ");
    scanf("%d", &weight_in_pounds);
    printf("Enter your year of birth: ");
    scanf("%d", &year_of_birth);

 /* Perform conversions */
    
    weight_in_grams = weight_in_pounds * GRAMS_PER_POUND;
    age_in_2000 = NEXT_CENTURY - year_of_birth;

 /* Display results on the screen */
    
    printf("\nYour weight in grams = %ld", weight_in_grams);
    printf("\nIn 2000 you will be %d years old\n", age_in_2000);
 
    return 0;
 }