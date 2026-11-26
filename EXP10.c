#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void findPos(char ch, int *r, int *c)
{
    int i, j;

    if(ch == 'J') ch = 'I';

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            if(mat[i][j] == ch)
            {
                *r = i;
                *c = j;
                return;
            }
}

int main()
{
    char text[200], p[200];
    int i, j = 0, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i]; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            if(ch == 'J') ch = 'I';
            p[j++] = ch;
        }
    }

    if(j % 2 != 0)
        p[j++] = 'X';

    p[j] = '\0';

    printf("Encrypted text: ");

    for(i = 0; i < j; i += 2)
    {
        findPos(p[i], &r1, &c1);
        findPos(p[i+1], &r2, &c2);

        if(r1 == r2)
            printf("%c%c",
                mat[r1][(c1+1)%5],
                mat[r2][(c2+1)%5]);

        else if(c1 == c2)
            printf("%c%c",
                mat[(r1+1)%5][c1],
                mat[(r2+1)%5][c2]);

        else
            printf("%c%c",
                mat[r1][c2],
                mat[r2][c1]);
    }

    return 0;
}