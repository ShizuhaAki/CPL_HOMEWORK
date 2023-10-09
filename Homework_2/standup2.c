#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[100005] = {0};
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int num = 0;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (sum < i)
        {
            num += i - sum;
            sum = i;
        }
        sum += a[i];
    }
    printf("%d\n", num);
    return 0;
}