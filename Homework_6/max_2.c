#include <stdio.h>

int main()
{
    int n;
    int arr[100005] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int j = i, k = i;
        while (j > 1 && arr[j - 1] < arr[i])
            j--;
        while (k < n && arr[k + 1] < arr[i])
            k++;
        printf("%d %d\n", j, k);
    }
    return 0;
}