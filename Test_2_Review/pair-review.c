#include <stdio.h>

int n, m, t;
int a[10005], b[10005];

int find(int goal, int left, int right);

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int min = t;
    int flag = 0;
    for (int i = 0; i < m; i++) {
        int afind = find(t - b[i], 0, n - 1);
        if (afind != -1) {
            flag = 1;
            min = min < (t - b[i] - a[afind]) ? min : (t - b[i] - a[afind]);
        }
        // printf("afind = %d  a[afind] = %d  ", afind, a[afind]);
        // printf("%d\n", min);
    }
    if (flag) {
        printf("%d\n", min);
    } else {
        printf("-1\n");
    }
    return 0;
}

int find(int goal, int left, int right)
{
    if (goal < a[0])
        return -1;
    else {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] <= goal && (mid == n - 1 || a[mid + 1] > goal)) {
                return mid;
            } else if (a[mid] > goal) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
}