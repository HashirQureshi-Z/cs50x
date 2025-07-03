// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int myRound(float n);

int main(void)
{
    const string text = get_string("Enter text: ");

    float letterCount = 0;
    float wordCount = 0;
    float sentenceCount = 0;

    // Sentences will be tracked by the number of periods, exclamations, or question marks
    // Words will be tracked by spaces

    for (int i = 0, len = strlen(text); i < len; i++)
    {

        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterCount++;
        }

        if (text[i] == ' ')
        {
            wordCount++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentenceCount++;
        }

    }

    // To count the last word, add 1.
    wordCount++;

    // index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float L = letterCount / (wordCount / 100);
    float S = sentenceCount / (wordCount / 100);

    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Grade %i\n", myRound(index));
}


// rounds positive numbers:
// 1. truncates the float by casting it as an int
// 2. n = 1.6, truncated = 1,
// 3. (1.6 - 1 = 0.6) which is >= than 0.5, so we need to round up
// 4. else round down
int myRound(float n)
{
    int truncated = (int) n;

    if (n - truncated >= 0.5)
    {
        return (truncated + 1);
    }
    else
    {
        return truncated;
    }
}
