#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int get_score(string s);

const int scoreMap[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8 };

int main(void)
{
    int score1 = get_score(get_string("Player 1: "));
    int score2 = get_score(get_string("Player 2: "));

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string s)
{
    int score = 0;
    char upperChar;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // (toupper(s[i]) - 'A') is the index we want. If it is 'A' - 'A', we get 0, which means the user needs scoreMap[0] points. That's correct.
        upperChar = toupper(s[i]);
        if (upperChar >= 'A' && upperChar <= 'Z')
        {
            score += scoreMap[(upperChar - 'A')];
        }
    }

    return score;
}
