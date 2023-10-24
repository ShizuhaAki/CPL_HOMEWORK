#include <stdio.h>
#include <math.h>

// int LEN(int k)
// {
//     int count = 0;
//     while(k > 0)
//     {
//         k = k / 10;
//         count++;
//     }
//     return count;
// }

int main()
{
    long int len;
    scanf("%ld", &len);
    for (long int n = pow(10, len - 1); n < pow(10, len); n++)
    {
        int old = n;
        int new = 0;
        int scale = pow(10, len);

        int temp_scale = scale;
        int k = 1;
        while (temp_scale)
        {
            int a = (n % temp_scale) * (n / k % 10) % temp_scale * (scale / temp_scale);
            new += a;
            temp_scale /= 10;
            k *= 10;
        }

        new %= scale;
        if (old == new)
            printf("%d\n", n);
    }
    return 0;
}