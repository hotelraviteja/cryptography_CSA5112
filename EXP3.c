#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateKey(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

void encrypt(char text[])
{
    int i, r1, c1, r2, c2, j;
    char a, b;

    for (i = 0; text[i] != '\0'; i++)
        text[i] = toupper(text[i]) == 'J' ? 'I' : toupper(text[i]);

    char clean[200];
    j = 0;

    for (i = 0; text[i] != '\0'; i++)
        if (isalpha(text[i]))
            clean[j++] = text[i];

    clean[j] = '\0';

    char result[400];
    int n = 0;

    for (i = 0; i < j;)
    {
        a = clean[i++];
        b = (i < j) ? clean[i] : 'X';

        if (a == b)
            b = 'X';
        else if (i < j)
            i++;

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (matrix[r1][c1] == a)
                    goto found1;

        found1:
        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (matrix[r2][c2] == b)
                    goto found2;

        found2:
        if (r1 == r2)
        {
            result[n++] = matrix[r1][(c1 + 1) % 5];
            result[n++] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            result[n++] = matrix[(r1 + 1) % 5][c1];
            result[n++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[n++] = matrix[r1][c2];
            result[n++] = matrix[r2][c1];
        }
    }

    result[n] = '\0';
    printf("Encrypted text: %s\n", result);
}

int main()
{
    char key[100], text[200];

    printf("Enter keyword: ");
    scanf("%99s", key);

    generateKey(key);

    printf("Playfair Matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    getchar();
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    encrypt(text);

    return 0;
}