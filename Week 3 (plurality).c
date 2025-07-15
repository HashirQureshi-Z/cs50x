#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    int votes_recieved;
} candidate;


int validate_vote(int num_of_candidates, candidate candidates[], string vote);


int main(int argc, string argv[])
{

    // Create candidates
    candidate candidates[argc];
    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1].name = argv[i];
        candidates[i - 1].votes_recieved = 0;
    }


    // Get votes
    string vote;
    int max = 0;
    int voteCount;
    const int NUM_OF_VOTES = get_int("Number of voters: ");

    for (int i = 0; i < NUM_OF_VOTES; i++)
    {
        vote = get_string("Vote %i: ", i + 1);
        // Check if the vote is valid, and if it is add it to the votes recieved
        voteCount = validate_vote(argc - 1, candidates, vote);
        if (voteCount != 0)
        {
            if (voteCount > max)
            {
                max = voteCount;
            }
        }
    }


    // Print winners by checking who has equal to max votes
    printf("\nWinners:\n");
    for (int i = 0; i < argc - 1; i++)
    {
        if (candidates[i].votes_recieved == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    printf("\n");


}


// Returns 0 if invalid, else returns the candidates total votes
int validate_vote(int num_of_candidates, candidate candidates[], string vote)
{
    for (int i = 0; i < num_of_candidates; i++)
    {
        if (strcmp(candidates[i].name, vote) == 0)
        {
            candidates[i].votes_recieved++;
            return candidates[i].votes_recieved;
        }
    }
    printf("That candidate doesn't exist\n");
    return 0;
}

