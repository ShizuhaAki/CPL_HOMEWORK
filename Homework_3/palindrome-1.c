#include <stdio.h>

int main()
{
    int n;
    char str[2001];
    scanf("%d%s",&n,str);
    char str1[2001];
    for(int i = 0; i < n; i++)
    {
        str1[i] = str[n - i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '?')
        {
            str[i] = str1[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}