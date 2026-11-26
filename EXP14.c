#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char p[] = "SEND MORE MONEY";
    char target[] = "CASH NOT NEEDED";
    int key[] = {9,0,1,7,23,15,21,14,11,11,2,8,9};

    char cipher[100];
    int i, j = 0, x, y;

    printf("Encrypted text: ");

    for(i = 0; p[i]; i++)
    {
        if(isalpha(p[i]))
        {
            x = toupper(p[i]) - 'A';
            cipher[j] = (x + key[j]) % 26 + 'A';
            printf("%c", cipher[j]);
            j++;
        }
        else
            printf("%c", p[i]);
    }

    cipher[j] = '\0';

    printf("\nKey for target plaintext:\n");

    j = 0;

    for(i = 0; target[i]; i++)
    {
        if(isalpha(target[i]))
        {
            x = cipher[j] - 'A';
            y = toupper(target[i]) - 'A';

            printf("%d ", (x - y + 26) % 26);
            j++;
        }
        else
            printf("  ");
    }

    return 0;
}