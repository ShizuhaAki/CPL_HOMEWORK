#include <stdio.h>

void swap(int a, int b)
{
    int t;
    t = b;
    b = a;
    a = t;
}

void quicksort(int arr[], int k, int n)
{
    int pivot = arr[k - 1];
    int l = 0, r = n - 1;
    while(l < r)
    {
        while(arr[l] <= pivot)
            l++;
        while(arr[r] >= pivot)
            r--;
        if(l < r)
        {
            swap(arr[l], arr[r]);
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[1000005] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, k, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}