#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[20000] = {0};
    int q;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[1000001] = {0};
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (b[a[i]] == 0)
            b[a[i]] = 1;
        else if (b[a[i]] == 1)
            b[a[i]] = 2;
    }
    for (int i = 0; i < 1000001; i++)
    {
        if (b[i] == 1)
            q = i;
    }
    printf("%d\n", q);
    return 0;
}