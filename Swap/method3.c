#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int x, y;
    swap(&x, &y);  //参数是变量的地址!!!
}