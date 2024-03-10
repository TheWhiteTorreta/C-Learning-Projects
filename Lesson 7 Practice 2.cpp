#include <stdio.h>

void compute_circumference(float *r, float *c)
{
    *c = 2 * 3.14 * (*r);
}

void compute_area(float *r, float *a)
{
    *a = 3.14 * (*r) * (*r);
}

int main()
{
    float radius, circumference, area;
    printf("Enter radius: ");
    scanf("%f", &radius);
    compute_circumference(&radius, &circumference);
    printf("Circumference = %f\n", circumference);
    compute_area(&radius, &area);
    printf("Area = %f\n", area);

    return 0;
}
