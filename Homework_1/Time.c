#include <stdio.h>
int main()
{
    char month[10];
    char weekday[10];
    int day, year, hour, minute, second;
    scanf("%s%d%d%s%d%d%d",&month,&day,&year,&weekday,&hour,&minute,&second);
    for(int i=0;i<3;i++)
    {
        printf("%c",weekday[i]);
    }
    printf(" ");
    for(int i=0;i<3;i++)
    {
        printf("%c",month[i]);
    }
    printf(" ");
    printf("%02d %02d:%02d:%02d %04d\n",day,hour,minute,second,year);
    return 0;
}