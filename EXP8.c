#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[100];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i, x;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted text: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            x = toupper(text[i]) - 'A';
            putchar(key[x]);
        }
        else
            putchar(text[i]);
    }

    return 0;
}