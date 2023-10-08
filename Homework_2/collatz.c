#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int max = n,count = 0;
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        count++;
        if(n > max)
            max = n;
    }
    printf("%d %d",count,max);
    return 0;
}