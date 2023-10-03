#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",n/50);
    printf("%d\n",n%50/20);
    printf("%d\n",n%50%20/10);
    printf("%d\n",n%50%20%10/5);
    printf("%d\n",n%50%20%10%5);
    return 0;
}