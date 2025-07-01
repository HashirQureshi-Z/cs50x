#include <stdio.h>
#include <cs50.h>

int get_dgt(long credit_card, int digitPlace);

int main()
{

    // Sample credit card: 4003600000000014
    #define CARD_LENGTH 16
    long credit_card = get_long("Enter your credit card number: ");

    // Loop 8 times because we need every other digit and a credit card is 16 digits
    int checksum = 0;
    int addIt;
    for (int i = 1; i <= CARD_LENGTH; i++)
    {
        addIt = get_dgt(credit_card, i);
        if (i % 2 == 0)
        {
            addIt *= 2;

            // addIt can only be 10 if it is multiplied by 2
            if (addIt >= 10)
            {
            checksum += get_dgt(addIt, 1);
            checksum += get_dgt(addIt, 2);
            }
            else
            {
                checksum += addIt;
            }
        }

        else
        {
            checksum += addIt;
        }
    }


    if (get_dgt(checksum, 1) == 0)
    {
        printf("VALID CARD\n");
        // Now from here i could check which type of card it is...
        // But i would just be using get_dgt function and checking the last to digits.
    }
    else
    {
        printf("INVALID\n");
    }
}




int get_dgt(long num, int digitPlace)
{
    // Count digits backwards. So digitPlace = 1 returns the last digit
    int lastDgt;
    for (int i = 0; i < digitPlace; i++)
    {
        lastDgt = num % 10;
        num = (num - lastDgt) / 10;
    }

    return lastDgt;
}
