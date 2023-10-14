#include <stdio.h>
int main()
{
    int T;
    int s[100001] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        long int a[50005] = {0};
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        int max = 0;
        for (int k = 0; k < n - 1; k++)
        {
            if (a[k] > max)
                max = a[k];
        }
        if (max <= a[n - 1])
        {
            s[i] = 0;
        }
        else
        {
            s[i] = 1;
        }
    }
    for (int i = 0; i < T; i++)
    {
        if (s[i] == 0)
            printf("YES\n");
        else if (s[i] == 1)
            printf("NO\n");
    }
    return 0;
}