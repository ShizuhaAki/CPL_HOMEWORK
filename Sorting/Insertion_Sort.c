#include <stdio.h>

// 插入排序函数(从小到大选择排序)
void Insertion_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int end = i;
        int temp = arr[end];
        while (end > 0)
        {
            if (arr[end - 1] > temp)
            {
                arr[end] = arr[end - 1];
                end--;
            }
            else
                break;
        }
        arr[end] = temp;
    }
}

// 二分法插入排序
void Binary_InsertSort(int arr[], int size)
{
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[i] > arr[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        int temp = arr[i];
        for (int right = i; right > left; right--)
        {
            arr[right] = arr[right - 1];
        }
        arr[left] = temp;
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
    Insertion_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    Binary_InsertSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}