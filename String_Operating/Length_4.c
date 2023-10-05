#include <stdio.h>

//指针减指针，求字符串长度
int my_len(char *str)
{
    char *start = str;
    while(*str)
    {
        str++;
    }
    return str-start;
}

int main()
{
    char s[] = "abds";
    int len = my_len(s);
    printf("%d\n", len);
    return 0;
}