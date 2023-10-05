#include <stdio.h>

// 写冒泡排序的函数(从小到大冒泡排序)
void Bubble_sort(int arr[], int size)
{
    int i, j, tem;
    for (i = 0; i < size - 1; i++) // size-1的原因是不用跟自己比较
    {
        int count = 0;
        for (j = 0; j < size - 1 - i; j++) // size-1-i的原因是每一趟都会少一个数比较
        {
            if (arr[j] > arr[j + 1])
            {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
                count = 1;
            }
        }
        if (count == 0)
            break;
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
    Bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}