#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1005][1005] = {0};
    arr[1][((n + 1) / 2)] = 1;
    int cnt = 1;
    int flag[1005][1005] = {0};
    flag[1][((n + 1) / 2)] = 1;
    int x = 1, y = ((n + 1) / 2);
    while (cnt < n * n)
    {
        cnt++;
        int newx = x - 1;
        int newy = y + 1;
        if (newx == 0)
            newx = n;
        if (newy == n + 1)
            newy = 1;
        if (flag[newx][newy] == 0)
        {
            arr[newx][newy] = cnt;
            flag[newx][newy] = 1;
            x = newx;
            y = newy;
        }
        else
        {
            x++;
            if (x == 0)
                x = n;
            arr[x][y] = cnt;
            flag[x][y] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}