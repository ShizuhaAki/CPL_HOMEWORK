#include <stdio.h>

// 归并排序，采用分治的思想

void merge(int arr[], int p, int q, int r, int n)
{
    int *B = new int[n];
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = (low + high) / 2;
        MergeSort(arr, low, i);  // 分操作：对左半边子序列递归调用
        MergeSort(arr, i, high); // 分操作：对右半边子序列递归调用
        merge(arr, low, i, high, high - low + 1);
    }
}