#include <stdio.h>

// �鲢���򣬲��÷��ε�˼��

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
    // i++���ȸ�ֵ����������++i������������ֵ
    // ���� a = i++ ��ʾ�� a = i; i = i + 1
    // �� b = ++i ��ʾ�� i = i + 1; b = i

    while (j <= r)
        B[k++] = A[j++];

    while (i <= q)
        B[k++] = A[i++];

    // ��ѡ���Ĳ����滻ΪB������
    k = 0;
    for (i = p; i <= r; i++)
        A[i] = B[k++];
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i = (low + high) / 2;
        MergeSort(arr, low, i);                   // �ֲ����������������еݹ����
        MergeSort(arr, i, high);                  // �ֲ��������Ұ�������еݹ����
        merge(arr, low, i, high, high - low + 1); //  �β�������������������еĺϲ�
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

// ����û����������Ǵ���˼·����ȷ�ģ����ø��ˡ�����