#include <stdio.h>

// �鲢���򣬲��÷��ε�˼��

void merge(int arr[], int p, int q, int r, int n)
{
    int *B = new int[n];
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = (low + high) / 2;
        MergeSort(arr, low, i);  // �ֲ����������������еݹ����
        MergeSort(arr, i, high); // �ֲ��������Ұ�������еݹ����
        merge(arr, low, i, high, high - low + 1);
    }
}