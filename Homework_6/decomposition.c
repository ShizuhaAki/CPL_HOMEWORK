#include <stdio.h>

int ans[35];

void find(int n, int min, int nfound)
{
    if (n == 0)
    {
        for (int i = 0; i < nfound; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    if (n < min)
        return;
    else
    {
        for (int j = min; j <= n; j++)
        {
            ans[nfound] = j;
            find(n - j, j, nfound + 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    find(n, 1, 0);
    return 0;
}