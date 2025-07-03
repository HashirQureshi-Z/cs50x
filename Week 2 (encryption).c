#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Prototypes
bool isUnique(string s);

// Constants
const int ALPHABET_LENGTH = 26;


int main(int argc, string argv[])
{

    string key = argv[1];


    // Check for errors in the key
    if (argc != 2)
    {
        printf("Key has incorrect number of arguments (should not have spaces)\n");
        return 1;
    }

    if (strlen(key) != ALPHABET_LENGTH)
    {
        printf("Key should be 26 characters\n");
        return 1;
    }

    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key should be alphabetic\n");
            return 1;
        }
    }


    // Make key UPPERCASE
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        key[i] = toupper(key[i]);
    }


    if (!isUnique(key))
    {
        printf("You can't repeat letters in your key.\n");
        return 1;
    }
    // CHECKING FOR ERRORS IN KEY ---------- COMPLETE


    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // kinda like a hashmap
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // capital encryption
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", key[plaintext[i] - 'A']);
        }

        // lowercase encryption
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", key[plaintext[i] - 'a'] + 32);
        }
        // do not encrypt numbers
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}





bool isUnique(string s)
{
    bool checks[ALPHABET_LENGTH];

    // start all values in check to be false
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        checks[i] = false;
    }

    // set value to true in checks[]. if its already true, then we know there is a dupe. use UPPER()
    int index = 0;
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        index = s[i] - 'A';
        if (checks[index] == true)
        {
            return false;
        }
        else
        {
            checks[index] = true;
        }
    }

    return true;
}
