#include <stdio.h>

int arr[1000000];

int bsearch(int num, int left, int right);

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (q--) {
        int num;
        scanf("%d", &num);
        printf("%d\n", bsearch(num, 0, n - 1));
    }
    return 0;
}

int bsearch(int num, int left, int right)
{
    if (left > right) {
        return -1;
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num) {
            return bsearch(num, left, mid - 1);
        } else {
            return bsearch(num, mid + 1, right);
        }
    }
}