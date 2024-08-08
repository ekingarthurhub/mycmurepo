#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_digit(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Check that the program runs with only one argument aside the program name
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check that the argument inputted is a digit and nothing else
    if (!check_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert ARGV[1] to int
    int key = atoi(argv[1]);

    // Get plaintext
    string plaintext = get_string("plaintext:  ");
    int length = strlen(plaintext);

    // Allocate memory for ciphertext
    char ciphertext[length + 1]; // +1 for the null terminator

    for (int i = 0; i < length; i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
    }

    // Null terminate the ciphertext string
    ciphertext[length] = '\0';

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool check_digit(string s)
{
    // Check if every character in argv[1] is a digit or not
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    int newchar = 0;

    if (isupper(c))
    {
        newchar = ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        newchar = ((c - 'a' + key) % 26) + 'a';
    }
    else
    {
        newchar = c;
    }

    return (char) newchar;
}
