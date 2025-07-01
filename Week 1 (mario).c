#include <stdio.h>
#include <cs50.h>
void print_whitespace(int n);
void print_hash(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Choose a height between 1 and 8: ");
    } while (height < 1 || height > 8);

    for (int i = 0; i < height + 1; i++)
    {
        print_whitespace(height - i);
        print_hash(i);
        printf("  ");
        print_hash(i);
        printf("\n");
    }
}

void print_whitespace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_hash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}


