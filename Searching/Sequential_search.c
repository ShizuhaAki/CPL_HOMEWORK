#include <stdio.h>

// À≥–Ú≤È’“
int Sequential_Search(int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}