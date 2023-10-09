#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[200000] = {0};
    for (int i = 0; i < (2 * n - 1); i++)
    {
        scanf("%d", &a[i]);
    }
    int b[1000001] = {0};
    for (int i = 0; i < (2 * n - 1); i++)
    {
        b[a[i]]++;
    }
    for (long int i = 0; i < 1000001; i++)
    {
        if (b[i] == 1)
            printf("%d\n", i);
    }
    return 0;
}