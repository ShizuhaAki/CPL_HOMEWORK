#include <stdio.h>
#include <stdlib.h>
#define NUM 10

int cmp(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}

int main()
{
    int arr[NUM] = {5, 9, 1, 3, 4, 6, 7, 8, 2, 0};
    int key = 3;
    qsort(arr, NUM, sizeof(int), cmp);
    int *p = (int *)bsearch(&key, arr, NUM, sizeof(int), cmp);
    if (p != NULL) {
        printf("%d", p - arr + 1);
    }
    return 0;
}