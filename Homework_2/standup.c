#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[100001] = {0};
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int num = 0;
    int count = a[0];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0 && num + count < i)
        {
            num += i - count;
        }
        count += a[i];
    }
    printf("%d\n", num);
    return 0;
}