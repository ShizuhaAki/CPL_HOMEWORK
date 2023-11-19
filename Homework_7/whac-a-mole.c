#include <stdio.h>
#include <math.h>

int n, m, d;
int board[600][600];
// 要开大数组

int value(int x, int y);
int max(int a, int b);
int min(int a, int b);

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    int maxValue = 0, ansN = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maxValue < value(i, j))
            {
                maxValue = value(i, j);
                ansN = 1;
            }
            else if(maxValue == value(i, j))
                ansN++;
        }
    }
    printf("%d %d\n", maxValue, ansN);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(maxValue == value(i, j))
                printf("%d %d\n", i, j);
        }
    }

    // printf("%d ", value(1, 1));
    // printf("%d ", value(1, 2));
    // printf("%d ", value(2, 2));

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //     {
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}

int value(int x, int y)
{
    int value = 0;
    for (int i = max(1, x - d); i <= min(n, x + d); i++)
    {
        for (int j = max(1, y - d); j <= min(m, y + d); j++)
        {
            if ((abs(i - x) + abs(j - y)) <= d)
                value += board[i][j];
        }
    }
    return value;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
}