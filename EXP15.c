#include <stdio.h>
#include <string.h>
#include <ctype.h>

double freq[26] = {
    8.12,1.49,2.71,4.32,12.02,2.30,
    2.03,5.92,7.31,0.10,0.69,3.98,
    2.61,6.95,7.68,1.82,0.11,6.02,
    6.28,9.10,2.88,1.11,2.09,0.17,
    2.11,0.07
};

int main()
{
    char text[500], result[500];
    double score[26], count[26];
    int shift, i, j, n, top;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of top results: ");
    scanf("%d", &top);

    if(top < 1) top = 1;
    if(top > 26) top = 26;

    for(shift = 0; shift < 26; shift++)
    {
        for(i = 0; i < 26; i++)
            count[i] = 0;

        n = 0;

        for(i = 0; text[i]; i++)
            if(isalpha(text[i]))
            {
                j = (toupper(text[i]) - 'A' - shift + 26) % 26;
                count[j]++;
                n++;
            }

        score[shift] = 0;

        if(n == 0) n = 1;

        for(i = 0; i < 26; i++)
        {
            double observed = count[i] * 100.0 / n;
            double diff = observed - freq[i];
            score[shift] += diff * diff / freq[i];
        }
    }

    printf("\nPossible plaintexts:\n");

    for(j = 0; j < top; j++)
    {
        int best = -1;

        for(shift = 0; shift < 26; shift++)
        {
            if(best == -1 || score[shift] < score[best])
                best = shift;
        }

        printf("\nShift %d: ", best);

        for(i = 0; text[i]; i++)
        {
            if(isalpha(text[i]))
            {
                char ch = toupper(text[i]);
                putchar((ch - 'A' - best + 26) % 26 + 'A');
            }
            else
                putchar(text[i]);
        }

        score[best] = 1e9;
    }

    return 0;
}