#include <stdio.h>

#define f(x, y, z)                       \
    if (x == 1 && y == 1 && z == 1)      \
    {                                    \
        printf("0");                     \
    }                                    \
    else if (x == 1 && y == 1 && z == 0) \
    {                                    \
        printf("1");                     \
    }                                    \
    else if (x == 1 && y == 0 && z == 1) \
    {                                    \
        printf("1");                     \
    }                                    \
    else if (x == 1 && y == 0 && z == 0) \
    {                                    \
        printf("0");                     \
    }                                    \
    else if (x == 0 && y == 1 && z == 1) \
    {                                    \
        printf("1");                     \
    }                                    \
    else if (x == 0 && y == 1 && z == 0) \
    {                                    \
        printf("1");                     \
    }                                    \
    else if (x == 0 && y == 0 && z == 1) \
    {                                    \
        printf("1");                     \
    }                                    \
    else if (x == 0 && y == 0 && z == 0) \
    {                                    \
        printf("0");                     \
    }

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    char s[2001] = {0};
    scanf("%s", s);
    int str[2005] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        str[i] = (int)s[i] + 1 - '1';
        str[i + 1] = str[i];
    }
    str[0] = 0;
    str[n + 1] = 0;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f(str[j - 1], str[j], str[j + 1]);
        }
        printf("\n");
    }
    return 0;
}

// ������ʵ�����������
// ��Ϊһֱ���ظ����str��ת�����
// ����Ϊ���Կ��Ǻ궨��������Ը�Ϊ��ֵ��䣬Ȼ�����str����Ĳ��ϸ���