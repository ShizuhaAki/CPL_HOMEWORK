#include <stdio.h>
int judge1(int ar[][9])
{
    for (int i = 0; i < 9; i++)
    {
        int plus = 0;
        for (int j = 0; j < 9; j++)
        {
            plus += ar[i][j] * ar[i][j];
        }
        if (plus != 285)
            return 1;
    }
    return 0;
}
int judge2(int ar[][9])
{
    for (int j = 0; j < 9; j++)
    {
        int plus = 0;
        for (int i = 0; i < 9; i++)
        {
            plus += ar[i][j] * ar[i][j];
        }
        if (plus != 285)
            return 1;
    }
    return 0;
}
int judge9(int ar[][9], int row, int line)
{
    int plus = 0;
    for (int i = row; i < 3 + row; i++)
    {
        for (int j = line; j < 3 + line; j++)
        {
            plus += ar[i][j] * ar[i][j];
        }
    }
    if (plus != 285)
        return 1;
    else
        return 0;
}
int judge3(int ar[][9])
{
    int flag1 = 0;
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            flag1 += judge9(ar, i, j);
        }
    }
    if (flag1 == 0)
        return 0;
    else
        return 1;
}
int main()
{
    int ar[9][9], flag = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &ar[i][j]);
    flag += judge1(ar);
    flag += judge2(ar);
    flag += judge3(ar);
    if (flag == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}

// 这个方法真的对吗？？？
// 似乎是不对的！！！