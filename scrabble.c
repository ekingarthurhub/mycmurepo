#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int word_score(string words);

int main(void)
{
    string players[2];
    // Prompt the players for their respective words
    players[0] = get_string("Player 1: ");
    players[1] = get_string("Player 2: ");

    // Compute the score for each word from players
    int player1_score = word_score(players[0]);
    int player2_score = word_score(players[1]);
    // printf("Player 1 scores: %i\n", player1_score);
    // printf("Player 2 scores: %i\n", player2_score);

    // Print Winer or Tie
    if (player1_score > player2_score)
    {
        printf("Player 1 Wins! \n");
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 Wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }

    return 0;
}

// Compute the scores of the words entered by both players
int word_score(string words)
{
    int scores = 0;
    for (int i = 0, length = strlen(words); i < length; i++)
    {
        if (isupper(words[i]))
        {
            scores += POINTS[words[i] - 'A'];
        }
        else if (islower(words[i]))
        {
            scores += POINTS[words[i] - 'a'];
        }
    }
    return scores;
}
