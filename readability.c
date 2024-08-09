#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compute_letters(string letters);
int compute_words(string words);
int compute_sentences(string sentences);

int main(void)

{
    // Prompt for users TEXT

    string text = get_string("Please Enter TEXT: ");

    // Check number of letters
    int letters = compute_letters(text);

    // Check number of Words
    int words = compute_words(text);

    // Check number of Sentences
    int sentences = compute_sentences(text);

    // Compute the average of L and S
    float average_letters = (((float) letters) / words) * 100;
    float average_sentences = (((float) sentences) / words) * 100;

    // Compute Index to be used for grading Level
    float index = (0.0588 * average_letters - 0.296 * average_sentences - 15.8);
    int result = round(index);

    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
    // printf("\n");
    // printf("index result: %i \n", result);
    // printf("index: %f \n", index);
    // Print out the number of Letters, Words, Sentences etc.
    // printf("numbert of Letters: %i\n", letters);
    // printf("numbert of Words: %i\n", words);
    // printf("numbert of Sentences: %i\n", sentences);
    // printf("average_letters: %f \n", average_letters);
    // printf("average_sentences: %f \n", average_sentences);
}

// Calculate total number of letters in the TEXT.
int compute_letters(string letters)
{
    int counter = 0;
    for (int i = 0, length = strlen(letters); i < length; i++)
    {
        // if (isupper(letters[i]) || islower(letters[i]))
        if (isalpha(letters[i]))
        {
            counter += 1;
        }
    }
    return counter;
}

// Calculate total number of Words in TEXT.
int compute_words(string words)
{
    int counter = 1;
    for (int i = 0, length = strlen(words); i < length; i++)
    {
        if (isspace((char) words[i]))
        {
            counter += 1;
        }
    }
    return counter;
}

// Calculate total number of Sentences in the TEXT.
int compute_sentences(string sentences)
{
    int counter = 0;
    for (int i = 0, length = strlen(sentences); i < length; i++)
    {
        if (ispunct((char) sentences[i]) &&
            (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?'))
        {
            counter += 1;
        }
    }
    return counter;
}
