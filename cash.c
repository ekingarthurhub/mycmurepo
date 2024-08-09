#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickles(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Please enter change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters customers need and also subtract the value of those from cents
    int quaters = calculate_quarters(cents);
    cents = cents - (quaters * 25);

    // Calculate how many dimes customers need and also subtract the value of those from cents
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // Calculate how many nickles customers need and also subtract the value of those from cents
    int nickles = calculate_nickles(cents);
    cents = cents - (nickles * 5);

    // Calculate how many pennies customers need and also subtract the value of those from cents
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Sum all coins to be given to customer
    int sumall = quaters + dimes + nickles + pennies;

    // Print total number of coins to be given to customer
    printf("%i\n", sumall);
}

// Calculate how many quarters customers need and also subtract the value of those from cents
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}
// Calculate how many dimes customer needs and also subtract the value of those from cents
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}
// Calculate how many nickles customer needs and also subtract the value of those from cents
int calculate_nickles(int cents)
{
    int nickles = 0;
    while (cents >= 5)
    {
        nickles++;
        cents = cents - 5;
    }
    return nickles;
}
// Calculate how many pennies customer needs and also subtract the value of those from cents
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
