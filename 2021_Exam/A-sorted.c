#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int arr[1010] = {0};
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        while (m--) {
            int pos = 0;
            scanf("%d", &pos);
            arr[0] = arr[pos];
            for (int j = pos; j >= 1; j--) {
                arr[j] = arr[j - 1];
            }
        }
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                flag = 1;
            }
        }
        if (flag) {
            printf("mayi is a good teacher\n");
        } else {
            printf("I love C programming language\n");
        }
    }
    return 0;
}