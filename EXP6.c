#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[100], plain[100];
    int i, c, p;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
        {
            c = toupper(cipher[i]) - 'A';
            p = (9 * (c - 15 + 26)) % 26;
            plain[i] = p + 'A';
        }
        else
            plain[i] = cipher[i];
    }

    plain[i] = '\0';

    printf("Decrypted text: %s", plain);

    return 0;
}