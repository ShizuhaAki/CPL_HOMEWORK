#include <stdio.h>

int main()
{
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    int a[101][101] = {0};
    int b[101][101] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int c[101][101] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            for(int k = 0; k < n; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}