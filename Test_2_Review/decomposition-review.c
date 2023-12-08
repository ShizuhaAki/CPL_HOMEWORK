#include <stdio.h>

int ans[35];

void find(int n, int min, int cnt);

int main()
{
    int n;
    scanf("%d", &n);
    find(n, 1, 0);
    return 0;
}

void find(int n, int min, int cnt)
{
    if (n == 0) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    if (n < min)
        return;
    else {
        for (int i = min; i <= n; i++) {
            ans[cnt] = i;
            find(n - i, i, cnt + 1);
        }
    }
}