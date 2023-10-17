#include <stdio.h>

int jojo(int n, int k, int i)
{
    if (i == 1)
        return (n - 1 + k) % n;
    else
    {
        return (jojo(n - 1, k, i - 1) + k) % n;
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    /*for (int i = 1; i <= n; i++)
    {
        printf("%d\n", jojo(n, k, i) + 1);
    }*/
    printf("%d\n", jojo(n, k, n) + 1);
    return 0;
}