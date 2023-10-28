#include <stdio.h>

int binary_search(int arr[], int n, int t, int b);

int main()
{
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    int a[1005] = {0}; // 修改数组大小
    int b[1005] = {0}; // 修改数组大小
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int ans = -1;
    for (int i = 0; i < m; i++)
    {
        int tb = t - b[i];
        if (tb < 0)
            continue;
        else
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int middle = (left + right) / 2;
                if (a[middle] > tb)
                {
                    right = middle - 1;
                }
                else if (a[middle] < tb)
                {
                    left = middle + 1;
                    if (ans == -1 || ans > tb - a[middle])
                        ans = (tb - a[middle]);
                }
                else
                {
                    ans = 0;
                    break;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}