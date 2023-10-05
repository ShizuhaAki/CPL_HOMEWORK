#include <stdio.h>
#include <string.h>

// 使用内置函数，需要调用<string.h>库
int main()
{
    char str[] = "abcde";
    int len = strlen(str);
    printf("%d", len);
    return 0;
}