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
    int arr[10];
    printf("请输入十个数\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("输入的数组为：");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    printf("输出的数组为：");
    QuickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}