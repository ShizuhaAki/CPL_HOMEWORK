#include <stdio.h>

//选择排序函数(从大到小选择排序)
void Selection_sort(int arr[],int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    Selection_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}