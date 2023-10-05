#include <stdio.h>

// 二分查找，又称折半查找
/*
二分查找步骤：
1、将查找元素序列按大小进行排序
2、取中间元素进行比较
3、根据大/小，向左/右继续进行查找
4、重复步骤2和步骤3，直至找到目标元素或目标元素不存在
*/

// 二分查找的递归代码实现
// 递归实现使用函数调用栈来保存中间结果，但存在栈溢出的问题
int Binary_search1(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return Binary_search1(arr, mid + 1, high, key);
        }
        else
        {
            return Binary_search1(arr, low, mid - 1, key);
        }
    }
    return -1;
}

// 二分查找的非递归代码实现
// 非递归实现的代码相对比较复杂，但可以避免栈溢出的问题
int Binary_search2(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}