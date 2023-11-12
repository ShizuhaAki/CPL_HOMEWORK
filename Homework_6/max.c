#include <stdio.h>

void maxseg(int l, int r, int arr[], int ans[][2])
{
    int max = arr[l];
    int max_point = l;
    if (l > r)
        return;
    if (l == r)
    {
        ans[max_point][0] = l;
        ans[max_point][1] = l;
    }
    else
    {
        for (int i = l + 1; i <= r; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                max_point = i;
            }
        }
        ans[max_point][0] = l;
        ans[max_point][1] = r;
        maxseg(l, max_point - 1, arr, ans);
        maxseg(max_point + 1, r, arr, ans);
    }
}

int main()
{
    int n;
    int arr[100005] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans[100005][2] = {0};
    maxseg(1, n, arr, ans);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}