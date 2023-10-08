#include <stdio.h>
#include <string.h>

void fun(char s[],int k)
{
    char copy[1000001];
    strcpy(copy,s);
    for(int i = 0; i < k; i++)
    {
        s[i] = copy[k-1-i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    char str[10000001];
    for(int i = 0; i < n-1; i++)
    {
        scanf("%c",&str[i]);
    }
    int k;
    scanf("%d",&k);

    char s1[10000001],s2[10000001];
    for(int i = 0; i < k; i++)
    {
        s1[i] = str[i];
    }
    for(int i = k; i < n; i++)
    {
        s2[i-k] = str[i];
    }
    fun(s1,k);
    fun(s2,n-k);
    strcat(s1,s2);
    printf("%s",s1);
    return 0;
}