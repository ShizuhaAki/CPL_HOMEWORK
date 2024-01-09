#include <stdio.h>
#include <stdlib.h>

int n1, n2, arr1[200000], arr2[200000];
int ans[400000];

void merge1(int p1left, int p1right, int p2left, int p2right, int start);
void merge2(int p1left, int p1right, int p2left, int p2right, int start);

int main()
{
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int pos1 = 0, pos2 = 0; // pos为最大值所在的地方
    for (int i = 0; i < n1 - 1; i++) {
        if (arr1[i] > arr1[i + 1]) {
            pos1 = i;
            break;
        }
    }
    for (int i = 0; i < n2 - 1; i++) {
        if (arr2[i] > arr2[i + 1]) {
            pos2 = i;
            break;
        }
    }
    if (pos1 == 0 && n1 > 1 && arr1[0] < arr1[1]) {
        pos1 = n1 - 1;
    }
    if (pos2 == 0 && n2 > 1 && arr2[0] < arr2[1]) {
        pos2 = n2 - 1;
    }
    // printf("%d  %d\n", pos1, pos2);
    merge1(0, pos1, 0, pos2, 0);
    merge2(pos1 + 1, n1 - 1, pos2 + 1, n2 - 1, pos1 + pos2 + 2);
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

void merge1(int p1left, int p1right, int p2left, int p2right, int start)
{
    int p1 = p1left, p2 = p2left, k = start;
    while (p1 <= p1right && p2 <= p2right) {
        if (arr1[p1] < arr2[p2]) {
            ans[k++] = arr1[p1++];
        } else {
            ans[k++] = arr2[p2++];
        }
    }
    while (p1 <= p1right) {
        ans[k++] = arr1[p1++];
    }
    while (p2 <= p2right) {
        ans[k++] = arr2[p2++];
    }
}

void merge2(int p1left, int p1right, int p2left, int p2right, int start)
{
    int p1 = p1left, p2 = p2left, k = start;
    while (p1 <= p1right && p2 <= p2right) {
        if (arr1[p1] > arr2[p2]) {
            ans[k++] = arr1[p1++];
        } else {
            ans[k++] = arr2[p2++];
        }
    }
    while (p1 <= p1right) {
        ans[k++] = arr1[p1++];
    }
    while (p2 <= p2right) {
        ans[k++] = arr2[p2++];
    }
}