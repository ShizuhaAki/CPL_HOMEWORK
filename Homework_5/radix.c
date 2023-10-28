#include <stdio.h>

int NUM(int n, int b)
{
    int num = 0;
    num = (n % 10) + (n / 10) * b;
    return num;
}

int main()
{
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    for (int b = 2; b <= 40; b++)
    {
        int x = NUM(p, b);
        int y = NUM(q, b);
        int z = NUM(r, b);
        if (x * y == z)
        {
            printf("%d\n", b);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}