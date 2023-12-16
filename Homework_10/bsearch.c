#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000000

int n, q;
int arr[MAXLEN];

int compare(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (q--) {
        int goal;
        scanf("%d", &goal);
        int *ptr = (int *)bsearch(&goal, arr, n, sizeof(arr[0]), compare);
        if (ptr == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", ptr - arr);
        }
    }
    return 0;
}