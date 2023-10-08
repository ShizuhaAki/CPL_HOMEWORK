#include <stdio.h>

void Substring(char str[], int i, int j)
{
    int k = i;
    while(k <= j)
    {
        printf("%c",str[k]);
        k++;
    }
}

int main()
{
    char str[100] = {0};
    for(int i = 0; i < 10; i++)
    {
        scanf("%c",&str[i]);
    }
    int start,finish;
    scanf("%d%d",&start,&finish);
    Substring(str, start-1, finish-1);
    return 0;
}