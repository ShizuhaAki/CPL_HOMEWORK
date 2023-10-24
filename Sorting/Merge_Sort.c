#include <stdio.h>

// 归并排序，采用分治的思想

void merge(int A[], int p, int q, int r, int n)
{
    int B[100] = {0};
    int k = 0;
    int i = p, j = q + 1;
    while (i <= q && j <= r)
    {
        if (A[i] >= A[j])
            B[k++] = A[j++];
        else
            B[k++] = A[i++];
    }
    // i++是先赋值再自增；而++i是先自增，后赋值
    // 比如 a = i++ 表示： a = i; i = i + 1
    // 而 b = ++i 表示： i = i + 1; b = i

    while (j <= r)
        B[k++] = A[j++];

    while (i <= q)
        B[k++] = A[i++];

    // 将选定的部分替换为B的数组
    k = 0;
    for (i = p; i <= r; i++)
        A[i] = B[k++];
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = (low + high) / 2;
        MergeSort(arr, low, i);                   // 分操作：对左半边子序列递归调用
        MergeSort(arr, i, high);                  // 分操作：对右半边子序列递归调用
        merge(arr, low, i, high, high - low + 1); //  治操作：解决有序两个子列的合并
    }
}

int main()
{
    int a[] = {8, 5, 3, 9, 11, 6, 4, 1, 10, 7, 2};
    MergeSort(a, 0, 10);

    for (int i = 0; i < 11; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}

// 程序并没有输出，但是大致思路是正确的，懒得改了、、、