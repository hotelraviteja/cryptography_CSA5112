#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100],key[100];
    int i,j=0,len,shift;

    printf("Enter plaintext: ");
    fgets(text,sizeof(text),stdin);

    printf("Enter key: ");
    scanf("%99s",key);

    len=strlen(key);

    if(len==0)
        return 1;

    for(i=0;text[i]!='\0';i++)
    {
        if(isalpha(text[i]))
        {
            shift=toupper(key[j%len])-'A';

            if(isupper(text[i]))
                text[i]=(text[i]-'A'+shift)%26+'A';
            else
                text[i]=(text[i]-'a'+shift)%26+'a';

            j++;
        }
    }

    printf("Encrypted text: %s",text);

    return 0;
}