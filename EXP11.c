#include <stdio.h>
#include <math.h>

int main()
{
    long double total = 0;
    int i;

    for(i = 1; i <= 25; i++)
        total += log2l(i);

    printf("Total possible keys = 25!\n");
    printf("Approximate total keys = 2^%.2Lf\n", total);

    printf("Effectively unique keys = 25! / 50\n");
    printf("Approximate unique keys = 2^%.2Lf\n",
           total - log2l(50));

    return 0;
}