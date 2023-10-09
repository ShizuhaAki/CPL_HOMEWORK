#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int s = 0;
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = (p * (i % 10007)) % 10007;
        s = s + (p % 10007);
    }
    s = s % 10007;
    printf("%d\n", s);
    return 0;
}