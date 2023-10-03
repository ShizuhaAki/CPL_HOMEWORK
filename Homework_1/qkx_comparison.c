#include <stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                int k;
                k=a[j-1];
                a[j-1]=a[j];
                a[j]=k;
            }
        }
    }
    printf("%d %d\n",a[1],a[n-2]);
    return 0;
}