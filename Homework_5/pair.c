#include <stdio.h>

int Split(int arr[], int first, int last)
{
    int split_point, pivot;
    pivot = arr[first];
    split_point = first;
    for (int i = first + 1; i <= last; i++)
    {
        if (arr[i] < pivot)
        {
            split_point++;
            int t = arr[split_point];
            arr[split_point] = arr[i];
            arr[i] = t;
        }
    }
    arr[first] = arr[split_point];
    arr[split_point] = pivot;
    return split_point;
}

void QuickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int split_point;
        split_point = Split(arr, first, last);
        QuickSort(arr, first, split_point - 1);
        QuickSort(arr, split_point + 1, last);
    }
}

int main()
{
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    int a[1005] = {0}; // 修改数组大小
    int b[1005] = {0}; // 修改数组大小
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    QuickSort(b, 0, m - 1);

    if (a[0] + b[0] > t)
        printf("-1\n");
    else
    {
        int x = 0;
        while (a[x] <= t && x <= n - 1)
            x++;
        x -= 1;
        int y = 0;
        while (b[y] <= t && y <= m - 1)
            y++;
        y -= 1;

        int answer = t;
        for (int i = x; i >= 0; i--)
        {
            int min = 0;
            for (int j = y; j >= 0; j--)
            {
                if (a[i] + b[j] <= t)
                {
                    min = t - a[i] - b[j];
                    break;
                }
            }
            answer = (answer < min) ? answer : min;
        }
        printf("%d\n", answer);
    }
    return 0;
}