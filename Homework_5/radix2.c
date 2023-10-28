#include <stdio.h>

int main()
{
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    int max = 0;
    int a[6] = {0};
    a[0] = p / 10;
    a[1] = p % 10;
    a[2] = q / 10;
    a[3] = q % 10;
    a[4] = r / 10;
    a[5] = r % 10;
    for (int i = 0; i < 6; i++)
    {
        max = (max > a[i]) ? max : a[i];
    }

    for (int b = max + 1; b <= 40; b++)
    {
        if ((p / 10 * b + p % 10) * (q / 10 * b + q % 10) == (r / 10 * b + r % 10))
        {
            printf("%d\n", b);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}