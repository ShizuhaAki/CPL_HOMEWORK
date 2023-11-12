#include <stdio.h>

int find(int x, int a[])
{
    if (a[x] == x)
        return x;
    else
        return find(a[x], a);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[100005] = {0};
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", find(i, a));
    }
    return 0;
}