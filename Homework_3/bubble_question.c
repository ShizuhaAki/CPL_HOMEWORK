#include <stdio.h>
int main()
{
    int T;
    int s[100001] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        int a[50005] = {0};
        scanf("%d", &n);
        int max = 0;
        for (int j = 0; j < n - 1; j++)
        {
            scanf("%d", &a[j]);
            if (a[j] > max)
                max = a[j];
        }
        scanf("%d", &a[n - 1]);
        if (max <= a[n - 1])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}