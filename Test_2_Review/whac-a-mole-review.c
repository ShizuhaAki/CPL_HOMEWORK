#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 705
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m, d, ans;
int a[N][N], ret[N][N];

void solve();
int count(int x, int y);
bool valid(int x, int y);
void move(int x, int y, int *cur);

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    solve();
    ans = ret[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, ret[i][j]);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (ret[i][j] == ans)
                ++cnt;
        }
    printf("%d %d\n", ans, cnt);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (ret[i][j] == ans)
                printf("%d %d\n", i, j);
        }
    return 0;
}

void solve()
{
    for (int i = 1; i <= n; i++) {
        int cur = count(i, 1);
        for (int j = 1; j <= m; j++) {
            ret[i][j] = cur;
            if (j == m)
                break;
            move(i, j, &cur);
        }
    }
}

int count(int x, int y)
{
    int sum = 0;
    for (int i = x - d; i <= x + d; i++) {
        int rest = d - abs(i - x);
        for (int j = y - rest; j <= y + rest; j++) {
            if (valid(i, j))
                sum += a[i][j];
        }
    }
    return sum;
}

bool valid(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void move(int x, int y, int *cur)
{
    const static int dx[] = {1, 1, -1, -1};
    const static int dy[] = {-1, 1, 1, -1};

    int cx = x - d, cy = y;
    for (int i = 1; i <= d; i++) {
        if (valid(cx, cy))
            (*cur) -= a[cx][cy];
        cx += dx[0];
        cy += dy[0];
    }

    cx = x;
    cy = y - d;
    for (int i = 1; i <= d + 1; i++) {
        if (valid(cx, cy))
            (*cur) -= a[cx][cy];
        cx += dx[1];
        cy += dy[1];
    }

    ++y;
    cx = x + d;
    cy = y;
    for (int i = 1; i <= d; i++) {
        if (valid(cx, cy))
            (*cur) += a[cx][cy];
        cx += dx[2];
        cy += dy[2];
    }

    cx = x;
    cy = y + d;
    for (int i = 1; i <= d + 1; i++) {
        if (valid(cx, cy))
            (*cur) += a[cx][cy];
        cx += dx[3];
        cy += dy[3];
    }
}