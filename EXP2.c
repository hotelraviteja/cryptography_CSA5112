#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[200];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, index;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                index = text[i] - 'A';
                text[i] = key[index];
            }
            else
            {
                index = text[i] - 'a';
                text[i] = tolower(key[index]);
            }
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}