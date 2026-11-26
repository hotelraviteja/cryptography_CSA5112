#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main()
{
    char text[100];
    int a,b,i;

    printf("Enter plaintext: ");
    fgets(text,sizeof(text),stdin);

    printf("Enter a: ");
    scanf("%d",&a);

    printf("Enter b: ");
    scanf("%d",&b);

    a=(a%26+26)%26;
    b=(b%26+26)%26;

    if(gcd(a,26)!=1)
    {
        printf("Invalid a. Choose 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23 or 25.");
        return 1;
    }

    for(i=0;text[i]!='\0';i++)
    {
        if(text[i]>='A' && text[i]<='Z')
            text[i]=(a*(text[i]-'A')+b)%26+'A';

        else if(text[i]>='a' && text[i]<='z')
            text[i]=(a*(text[i]-'a')+b)%26+'a';
    }

    printf("Encrypted text: %s",text);

    return 0;
}