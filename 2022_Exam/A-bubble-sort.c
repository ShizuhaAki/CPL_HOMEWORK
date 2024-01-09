#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[60000] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            max = (max > arr[i]) ? max : arr[i];
        }
        if (max == arr[n - 1]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}