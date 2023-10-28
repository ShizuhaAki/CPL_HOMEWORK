#include <stdio.h>

void inverse(int arr[], int start, int end)
{
    int arr1[2005] = {0};
    for(int i = start; i <= end; i++)
    {
        arr1[i] = arr[i];
    }
    for(int i = start; i <= end; i++)
    {
        arr[i] = arr1[end + start - i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[2005] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            m = 0;
            continue;
        }
        else
        {
            m++;
        }
    }
    m += 1;
    // printf("%d\n", m);

    int s = arr[n - m - 1];
    int min = arr[n - m], min_point = 0;
    for (int i = n - m - 1; i < n; i++)
    {
        if (arr[i] > s)
        {
            min = (min < arr[i]) ? min : arr[i];
        }
    }
    for (int i = n - m - 1; i < n; i++)
    {
        if (arr[i] == min)
        {
            min_point = i;
            break;
        }
    }

    arr[min_point] = s;
    arr[n - m - 1] = min;

    inverse(arr,n - m, n - 1);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}