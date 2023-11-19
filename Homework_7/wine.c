#include <stdio.h>

int n, L;
int value[10005];
int contain[10005];

void sort(int *arr, int len, int *arr1);

int main()
{
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &contain[i]);

    int ans = 0;
    sort(value, n, contain);

    int k = 0;
    int left = L;
    while (left > 0)
    {
        if (left <= contain[k])
        {
            ans += left * value[k];
            break;
        }
        else
        {
            ans += contain[k] * value[k];
            left -= contain[k];
            k++;
        }
    }
    printf("%d\n", ans);

    // for (int i = 0; i < n; i++)
    //     printf("%d ", value[i]);
    // printf("\n");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", contain[i]);
    return 0;
}

void sort(int *arr, int len, int *arr1)
{
    for (int i = 0; i < len - 1; i++)
    {
        int cnt = 1;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                int temp1 = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp1;
                cnt = 0;
            }
        }
        if (cnt)
            break;
    }
}