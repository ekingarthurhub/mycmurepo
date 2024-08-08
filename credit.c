#include <cs50.h>
#include <stdio.h>

long get_second_to_last_digit(long num);
long get_last_digit(long num);
long get_card_number_length(long num);
long get_first_two_digit(long num);
long get_first_one_digit(long num);

int main(void)

{
    long num = get_long("Number: ");
    long sum_second_digits = get_second_to_last_digit(num);
    long sum_last_digits = get_last_digit(num);
    long length_of_number = get_card_number_length(num);
    long first_two_digits = get_first_two_digit(num);
    long first_one_digit = get_first_one_digit(num);
    // printf("Sum of all second digit: %li \n",sum_second_digits);
    // printf("Sum of all last digit: %li \n",sum_last_digits);
    // printf("The length of card number is: %li \n",length_of_number);

    if (((sum_second_digits + sum_last_digits) % 10 == 0) && (length_of_number == 15) &&
        (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (((sum_second_digits + sum_last_digits) % 10 == 0) && (length_of_number == 16) &&
             (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 ||
              first_two_digits == 54 || first_two_digits == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (((sum_second_digits + sum_last_digits) % 10 == 0) &&
             (length_of_number == 13 || length_of_number == 16) && (first_one_digit == 4))

    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// get all the second to last digit from a number and sum
long get_second_to_last_digit(long num)
{
    long temp = 0;
    long result = 0;
    long multiply = 0;
    long sum = 0;

    while (num > 1)
    {
        num /= 10;
        temp = num / 10;
        result = num %= 10;
        // printf("%li ",result);
        multiply = result * 2;
        while (multiply > 0)
        {
            sum = sum + (multiply % 10);
            multiply /= 10;
        }
        num = temp;
    }
    return sum;
}

// Find last digit that were'nt multiply by 2 and sum all

long get_last_digit(long num)
{
    long position = 0;
    long result = 0;

    while (num > 0)
    {

        result = result + (num % 10);
        // printf("%li \n", result);
        position = num / 100;
        num = position;
    }
    return result;
}

// Get the length of the credit card number
long get_card_number_length(long num)
{
    long num_of_digit = 0;
    while (num > 0)
    {
        num /= 10;
        num_of_digit++;
    }
    return num_of_digit;
}

// Get the starting two digits of the card number
long get_first_two_digit(long num)
{
    while (num >= 100)
    {
        num /= 10;
    }
    return num;
}

// Get the starting one digit of the card number
long get_first_one_digit(long num)
{
    while (num >= 10)
    {
        num /= 10;
    }
    return num;
}
