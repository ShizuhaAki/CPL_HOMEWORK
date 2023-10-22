#include <stdio.h>

int main()
{
    int n, m, x0, y0;
    scanf("%d%d%d%d", &n, &m, &x0, &y0);
    char arr[55][55] = {0};
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", arr[i]);
        for (int j = m - 1; j >= 0; j--)
        {
            arr[i][j + 1] = arr[i][j];
        }
        arr[i][0] = '_';
    }

    int vis[55][55] = {0};
    int vectors[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == '#')
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    int count = 0;
    int x = x0, y = y0;
    int newi = x0;
    int newj = y0;
    while (count < ans - 1)
    {
        for (int k = 0; k < 4; k++)
        {
            newi = x + vectors[k][0];
            newj = y + vectors[k][1];
            if ((arr[newi][newj] == '#') && (vis[newi][newj] == 0))
            {
                printf("%d %d\n", x, y);
                vis[x][y] = 1;
                x = newi;
                y = newj;
                count++;
            }
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}