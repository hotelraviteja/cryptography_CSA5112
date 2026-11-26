#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void makeMatrix(char key[])
{
    char s[26] = "";
    int i, j, k = 0, used[26] = {0};

    for(i = 0; key[i]; i++)
    {
        char c = toupper(key[i]);
        if(c == 'J') c = 'I';

        if(c >= 'A' && c <= 'Z' && !used[c-'A'])
        {
            s[k++] = c;
            used[c-'A'] = 1;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(i == 9) continue;

        if(!used[i])
            s[k++] = 'A' + i;
    }

    k = 0;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            mat[i][j] = s[k++];
}

void findPos(char c, int *r, int *col)
{
    int i, j;

    if(c == 'J') c = 'I';

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            if(mat[i][j] == c)
            {
                *r = i;
                *col = j;
                return;
            }
}

int main()
{
    char key[100], text[500];
    int i, r1, c1, r2, c2;

    printf("Enter key: ");
    scanf("%99s", key);

    printf("Enter ciphertext: ");
    scanf("%499s", text);

    makeMatrix(key);

    printf("Decrypted text: ");

    for(i = 0; text[i] && text[i+1]; i += 2)
    {
        findPos(toupper(text[i]), &r1, &c1);
        findPos(toupper(text[i+1]), &r2, &c2);

        if(r1 == r2)
            printf("%c%c",
                mat[r1][(c1+4)%5],
                mat[r2][(c2+4)%5]);

        else if(c1 == c2)
            printf("%c%c",
                mat[(r1+4)%5][c1],
                mat[(r2+4)%5][c2]);

        else
            printf("%c%c",
                mat[r1][c2],
                mat[r2][c1]);
    }

    return 0;
}