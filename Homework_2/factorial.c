#include <stdio.h>
#define m 10007

int fun(int n)
{
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        s *= (i % m);
    }
    s = s % m;
    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;
    int b[25] = {0};
    for (int i = 1; i <= n; i++)
    {
        b[i] = fun(i);
        printf("%d\n",b[i]);
    }
    
    return 0;
}