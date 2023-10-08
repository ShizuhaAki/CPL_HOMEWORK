#include <stdio.h>

int fun(int n, int k)
{
    while (n % k == 0)
    {
        n = n / k;
    }
    return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    n = fun(n, 5);
    printf("%d\n", n);
    n = fun(n, 3);
    printf("%d\n", n);
    n = fun(n, 2);
    printf("%d\n", n);
    if (n == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}