#include <stdio.h>

int n, a[2005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int p = n;
    while (a[p - 1] > a[p])
        p--;
    for (int i = n; i >= p; i--) {
        if (a[p - 1] < a[i]) {
            int t = a[p - 1];
            a[p - 1] = a[i];
            a[i] = t;
            break;
        }
    }
    for (int i = p, j = n; i < j; i++, j--) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}