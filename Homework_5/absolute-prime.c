#include <stdio.h>
#include <math.h>

int is_prime(int x)
{
    int flag = 1;
    for (int i = 2; i <= sqrt(x + 0.5); i++)
    {
        if (x % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int inverse(int k)
{
    int x = 0;
    int num = 0;
    int l = k;
    while (l > 0)
    {
        l /= 10;
        num++;
    }
    if (num == 1)
        x = k;
    else if (num == 4)
        x = 1;
    else if (num == 2)
        x = k % 10 * 10 + k / 10;
    else
        x = ((k % 10) * 100) + ((k % 100) / 10 * 10) + (k / 100);
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        int temp = is_prime(i);
        int x = 0;
        x = inverse(i);
        int temp2 = is_prime(x);
        if (temp == 1 && temp2 == 1)
            sum++;
    }
    printf("%d", sum);
    return 0;
}