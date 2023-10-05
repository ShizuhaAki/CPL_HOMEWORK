#include <stdio.h>

// 递归法求字符串长度
int my_len(char *str)
{
    if (*str != '\0')
    {
        return 1 + my_len(str + 1);
    }
    else
        return 0;
}

int main()
{
    char s[] = "abds";
    int len = my_len(s);
    printf("%d\n", len);
    return 0;
}