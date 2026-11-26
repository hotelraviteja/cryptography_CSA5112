#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[500], key[27];
    int i, x;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter 26-letter decryption key: ");
    scanf("%26s", key);

    if(strlen(key) != 26)
    {
        printf("Invalid key!");
        return 0;
    }

    for(i = 0; i < 26; i++)
        key[i] = toupper(key[i]);

    printf("Plaintext: ");

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
        {
            x = toupper(cipher[i]) - 'A';
            putchar(key[x]);
        }
        else
            putchar(cipher[i]);
    }

    return 0;
}