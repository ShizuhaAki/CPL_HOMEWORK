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
    swap(&x, &y);  //�����Ǳ����ĵ�ַ!!!
}