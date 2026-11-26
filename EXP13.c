#include <stdio.h>

int mod(int n)
{
    return (n % 26 + 26) % 26;
}

int main()
{
    char p[5], c[5];
    int a,b,d,e,det,inv;
    int k11,k12,k21,k22;

    printf("Enter 4 plaintext letters: ");
    scanf("%4s", p);

    printf("Enter corresponding 4 ciphertext letters: ");
    scanf("%4s", c);

    a = p[0]-'A';
    b = p[2]-'A';
    d = p[1]-'A';
    e = p[3]-'A';

    det = mod(a*e - b*d);

    inv = -1;

    for(int i = 0; i < 26; i++)
        if(mod(det*i) == 1)
            inv = i;

    if(inv == -1)
    {
        printf("Cannot find key: plaintext matrix is not invertible.");
        return 0;
    }

    int c1 = c[0]-'A';
    int c2 = c[1]-'A';
    int c3 = c[2]-'A';
    int c4 = c[3]-'A';

    k11 = mod((c1*e - c3*d)*inv);
    k12 = mod((-c1*b + c3*a)*inv);
    k21 = mod((c2*e - c4*d)*inv);
    k22 = mod((-c2*b + c4*a)*inv);

    printf("\nRecovered key matrix:\n");
    printf("%d %d\n", k11, k12);
    printf("%d %d\n", k21, k22);

    return 0;
}