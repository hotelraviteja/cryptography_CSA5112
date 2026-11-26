#include <stdio.h>
#include <stdint.h>

int PC1[56] = {
57,49,41,33,25,17,9,1,58,50,42,34,26,18,
10,2,59,51,43,35,27,19,11,3,60,52,44,36,
63,55,47,39,31,23,15,7,62,54,46,38,30,22,
14,6,61,53,45,37,29,21,13,5,28,20,12,4
};

int PC2[48] = {
14,17,11,24,1,5,3,28,15,6,21,10,
23,19,12,4,26,8,16,7,27,20,13,2,
41,52,31,37,47,55,30,40,51,45,33,48,
44,49,39,56,34,53,46,42,50,36,29,32
};

int main()
{
    uint64_t key, pc1, subkey = 0;
    int i, position;

    printf("Enter 64-bit key in hexadecimal: ");
    scanf("%llx", (unsigned long long *)&key);

    for(i = 0; i < 56; i++)
    {
        pc1 <<= 1;
        pc1 |= (key >> (64-PC1[i])) & 1;
    }

    uint32_t C = (pc1 >> 28) & 0x0FFFFFFF;
    uint32_t D = pc1 & 0x0FFFFFFF;

    printf("\nFirst half C = %07X\n", C);
    printf("Second half D = %07X\n", D);

    for(i = 0; i < 48; i++)
    {
        position = PC2[i];

        if(position <= 28)
            subkey = (subkey << 1) |
                     ((C >> (28-position)) & 1);
        else
            subkey = (subkey << 1) |
                     ((D >> (56-position)) & 1);
    }

    printf("\n48-bit DES subkey = %012llX\n",
           (unsigned long long)subkey);

    return 0;
}