#include <stdio.h>

int binary_1(int arr[], int num, int target) // ����ұ�����
{
    int left = 0;
    int right = num - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] > target)
            right = middle - 1;
        else if (arr[middle] < target)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int binary_2(int arr[], int num, int target) // ����ҿ�����
{
    int left = 0;
    int right = num;
    while (left < right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] > target)
            right = middle;
        else if (arr[middle] < target)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int binary_3(int arr[], int num, int target) // ����ұ�����
{
    int left = -1;
    int right = num;
    while (left + 1 != right)
    {
        int middle = (left + right) / 2;
        if (isblue(middle))
            left = middle;
        else
            right = middle;
    }
    return left; // ��������Ҳ������ return right;
}
// ˼·�Ƿ�Ϊblue������red����
// ����isblue���������ǣ�<=5 ���� <5 ɶ��