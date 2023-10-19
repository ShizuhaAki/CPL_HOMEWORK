#include <stdio.h>

void quicksort(int arr[], int k, int n)
{
    int pivot = arr[k - 1];
    int l = 0, r = n - 1;
    while (l != r)
    {
        while (arr[l] < pivot && l < r)
            l++;
        while (arr[r] >= pivot && l < r)
            r--;

        if (l < r)
        {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
        }
    }

    int record = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == pivot)
        {
            record = i;
            break;
        }
    }

    if (arr[l] > arr[record] && l < record)
    {
        int h = arr[record];
        arr[record] = arr[l];
        arr[l] = h;
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[1000005] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, k, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}