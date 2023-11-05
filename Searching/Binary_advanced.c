#include <stdio.h>

int binary_1(int arr[], int num, int target) // 左闭右闭区间
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

int binary_2(int arr[], int num, int target) // 左闭右开区间
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

int binary_3(int arr[], int num, int target) // 左闭右闭区间
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
    return left; // 看条件，也可能是 return right;
}
// 思路是分为blue条件和red条件
// 比如isblue条件可以是：<=5 或者 <5 啥的