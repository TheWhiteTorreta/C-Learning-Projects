#include <stdio.h>

void input(char *conversion_type, float *amount, float *exchange_rate)
{
    printf("Select the type of conversion you desire:\n");
    printf("(a) Peso to Dollars\n");
    printf("(b) Dollars to Pesos\n");
    printf("Enter the corresponding letter: ");
    scanf(" %c", conversion_type);

    printf("Input Amount: ");
    scanf("%f", amount);

    printf("Input exchange rate(peso/dollar): ");
    scanf("%f", exchange_rate);
}

float convert_pesos_to_dollars(float pesos, float exchange_rate)
{
    return pesos / exchange_rate;
}

float convert_dollars_to_pesos(float dollars, float exchange_rate)
{
    return dollars * exchange_rate;
}

void output(char conversion_type, float amount, float converted_amount)
{
    if (conversion_type == 'a')
    {
        printf("%.2f pesos is %.2f dollars\n", amount, converted_amount);
    }
    else if (conversion_type == 'b')
    {
        printf("%.2f dollars is %.2f pesos\n", amount, converted_amount);
    }
    else
    {
        printf("Invalid conversion type\n");
    }
}

int main()
{
    char conversion_type;
    float amount, exchange_rate, converted_amount;

    input(&conversion_type, &amount, &exchange_rate);

    if (conversion_type == 'a')
    {
        converted_amount = convert_pesos_to_dollars(amount, exchange_rate);
    }
    else if (conversion_type == 'b')
    {
        converted_amount = convert_dollars_to_pesos(amount, exchange_rate);
    }

    output(conversion_type, amount, converted_amount);

    return 0;
}
