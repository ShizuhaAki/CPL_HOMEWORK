#include <stdio.h>

int fun(int a, int b)
{
    if (a == 0)
        return 1;
    else if (b == 0 || b == a)
        return 1;
    else
        return fun(a - 1, b - 1) + fun(a - 1, b);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", fun(a - 1, b - 1));
    return 0;
}