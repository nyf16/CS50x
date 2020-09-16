#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollar;
    int cents, coins;
    do
    {
        dollar = get_float("Change: ");
    }

    while (dollar <= 0);

    cents = round(dollar * 100);
    coins = 0;

    while (cents >= 25) // 25 cents
    {
        cents = cents -25;
        coins++;
    }

    while (cents >= 10) // 10 cents
    {
        cents = cents -10;
        coins++;
    }

    while (cents >= 5) // 5 cents
    {
        cents = cents -5;
        coins++;
    }

    while (cents >= 1) // 1 cents
    {
        cents = cents -1;
        coins++;
    }

    printf("%i coins needed\n", coins);

}
