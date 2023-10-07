#include <stdio.h>
#include <string.h>
int main()
{
    // 法一
    char str1[20] = "Hello";
    char str2[] = " World";
    char str3[] = "!";
    strcat(str1, str2);
    printf("输出连接后的字符串：%s\n", str1);
    strcat(str1, str3);
    printf("输出连接后的字符串：%s\n", str1);

    // 法二
    char a[10] = "abc";
    char b[4] = "1234";
    int n = strlen(a);
    for (int i = 0; i < 4; i++)
    {
        a[n + i] = b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%c", a[i]);
    }

    return 0;
}