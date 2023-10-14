#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[501] = {0};
    int x = -1;
    for(int i = 0; i < n-1; i++)
    {
        if((x + k) <= n-1)
        {
            arr[x + k] = 1;
            x += k;
        }
        else
        {
            arr[x + k - n] = 1;
            x = x + k - n;
        }
    }
    for(int j = 0; j < n; j++)
    {
        if(arr[j] == 0)
            printf("%d\n",j);
    }
    return 0;
}