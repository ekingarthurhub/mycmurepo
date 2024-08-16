#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_alpha(string k);
bool check_repeat(string k);
char encipher(char c, string key);

int main(int argc, string argv[])
{
    // Check that the program runs with only one argument aside the program name
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY \n");
        return 1;
    }

    // Create a variable to store KEY and key length
    string key = argv[1];
    int key_length = strlen(key);

    // Validate the KEY
    if (!check_alpha(key) || check_repeat(key) || key_length != 26)
    {
        printf("KEY must be 26 characters & alphabetical & NOT repeating a character \n");
        return 1;
    }

    // Get PLAINTEXT from user
    string plaintext = get_string("plaintext:  ");
    int length_of_plaintext = strlen(plaintext);

    // Allocating memory space for ciphertext array
    char ciphertext[length_of_plaintext + 1]; // +1 for null terminator

    for (int i = 0; i < length_of_plaintext; i++)
    {
        ciphertext[i] = encipher(plaintext[i], key);
    }

    // Null terminate the ciphertext string
    ciphertext[length_of_plaintext] = '\0';

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool check_alpha(string k)
{
    for (int i = 0, length = strlen(k); i < length; i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }
    return true;
}

bool check_repeat(string k)
{
    for (int i = 0, length = strlen(k); i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (toupper(k[i]) == toupper(k[j]))
            {
                return true;
            }
        }
    }
    return false;
}

char encipher(char c, string key)
{
    if (isupper(c))
    {
        // Map uppercase letter to the key
        return toupper(key[c - 'A']);
    }
    else if (islower(c))
    {
        // Map lowercase letter to the key
        return tolower(key[c - 'a']);
    }
    else
    {
        // Non-alphabetic characters remain unchanged
        return c;
    }
}
