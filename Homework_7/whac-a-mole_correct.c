#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n, m, d;
int board[900][900];
int ans[900][900];
int test[900][900];

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1 + d; i <= n + d; i++)
    {
        for (int j = 1 + d; j <= m + d; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = -d; i <= d; i++)
    {
        for (int j = -d; j <= d; j++)
        {
            if (abs(i) + abs(j) <= d)
                ans[1 + d][1 + d] += board[1 + d + i][1 + d + j];
        }
    }
    int maxValue = ans[1 + d][1 + d], ansN = 1;
    int flag = 1;
    test[1 + d][1 + d] = 1;

    for (int i = 1 + d; i <= n + d; i++)
    {
        if ((i - d) % 2 == 1)
        {
            for (int j = 1 + d; j <= m + d; j++)
            {
                if (j < m + d)
                {
                    int dif = 0;
                    for (int s = -d; s <= d; s++)
                    {
                        dif += board[i + s][j + 1 + d - abs(s)];
                        dif -= board[i + s][j - d + abs(s)];
                    }
                    ans[i][j + 1] = ans[i][j] + dif;
                    if (ans[i][j + 1] > maxValue)
                    {
                        maxValue = ans[i][j + 1];
                        flag++;
                        ansN = 1;
                        test[i][j + 1] = flag;
                    }
                    else if (ans[i][j + 1] == maxValue)
                    {
                        ansN++;
                        test[i][j + 1] = flag;
                    }
                }
                else if (j == m + d && i != n + d)
                {
                    int dif = 0;
                    for (int s = -d; s <= d; s++)
                    {
                        dif -= board[i - d + abs(s)][j + s];
                        dif += board[i + 1 + d - abs(s)][j + s];
                    }
                    ans[i + 1][m + d] = ans[i][m + d] + dif;
                    if (ans[i + 1][m + d] > maxValue)
                    {
                        maxValue = ans[i + 1][m + d];
                        flag++;
                        ansN = 1;
                        test[i + 1][m + d] = flag;
                    }
                    else if (ans[i + 1][m + d] == maxValue)
                    {
                        ansN++;
                        test[i + 1][m + d] = flag;
                    }
                }
            }
        }
        else
        {
            for (int j = m + d; j >= 1 + d; j--)
            {
                if (j > 1 + d)
                {
                    int dif = 0;
                    for (int s = -d; s <= d; s++)
                    {
                        dif -= board[i + s][j + d - abs(s)];
                        dif += board[i + s][j - 1 - d + abs(s)];
                    }
                    ans[i][j - 1] = ans[i][j] + dif;
                    if (ans[i][j - 1] > maxValue)
                    {
                        maxValue = ans[i][j - 1];
                        flag++;
                        ansN = 1;
                        test[i][j - 1] = flag;
                    }
                    else if (ans[i][j - 1] == maxValue)
                    {
                        ansN++;
                        test[i][j - 1] = flag;
                    }
                }
                else if (j == 1 + d && i != n + d)
                {
                    int dif = 0;
                    for (int s = -d; s <= d; s++)
                    {
                        dif -= board[i - d + abs(s)][j + s];
                        dif += board[i + 1 + d - abs(s)][j + s];
                    }
                    ans[i + 1][1 + d] = ans[i][1 + d] + dif;
                    if (ans[i + 1][1 + d] > maxValue)
                    {
                        maxValue = ans[i + 1][1 + d];
                        flag++;
                        ansN = 1;
                        test[i + 1][1 + d] = flag;
                    }
                    else if (ans[i + 1][1 + d] == maxValue)
                    {
                        ansN++;
                        test[i + 1][1 + d] = flag;
                    }
                }
            }
        }
    }

    printf("%d %d\n", maxValue, ansN);
    for (int i = 1 + d; i <= d + n; i++)
    {
        for (int j = 1 + d; j <= m + d; j++)
        {
            if (test[i][j] == flag)
                printf("%d %d\n", i - d, j - d);
        }
    }
}