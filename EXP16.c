#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[500];
    char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int used[26] = {0};
    int map[26];
    int i, j, best;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i]; i++)
        if(isalpha(text[i]))
            count[toupper(text[i]) - 'A']++;

    for(i = 0; i < 26; i++)
    {
        best = -1;

        for(j = 0; j < 26; j++)
            if(!used[j] &&
               (best == -1 || count[j] > count[best]))
                best = j;

        used[best] = 1;
        map[best] = english[i];
    }

    printf("Possible plaintext: ");

    for(i = 0; text[i]; i++)
    {
        if(isalpha(text[i]))
            putchar(map[toupper(text[i]) - 'A']);
        else
            putchar(text[i]);
    }

    return 0;
}