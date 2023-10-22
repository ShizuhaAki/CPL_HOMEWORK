#include <stdio.h>

int main()
{
    int n, m, x0, y0;
    scanf("%d%d%d%d", &n, &m, &x0, &y0);
    char arr[55][55] = {0};
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", arr[i]);
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
        for (int j = 0; j < m; j++)
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
    while (count < ans)
    {
        if (y >= 0)
        {
            for (int k = 0; k < 4; k++)
            {
                int newi = x + vectors[k][0];
                int newj = y + vectors[k][1];
                if ((arr[newi][newj] == '#') && (vis[newi][newj] == 0))
                {
                    printf("%d %d\n", newi, newj + 1);
                    vis[x][y] = 1;
                    x = newi;
                    y = newj;
                    count++;
                    continue;
                }
            }
        }
        else
        {
            for (int k = 0; k < 3; k++)
            {
                int newi = x + vectors[k][0];
                int newj = y + vectors[k][1];
                if ((arr[newi][newj] == '#') && (vis[newi][newj] == 0))
                {
                    int temp = newj + 1;
                    printf("%d %d\n", newi, temp);
                    vis[x][y] = 1;
                    x = newi;
                    y = newj;
                    count++;
                    continue;
                }
            }
        }
    }
    return 0;
}

// ÎªÉ¶»á³¬Ê±¡¢¡¢¡¢