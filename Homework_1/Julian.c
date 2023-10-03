#include <stdio.h>
#include <math.h>
int main()
{
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    int a;
    a = floor((14-month)/12.0);
    int y;
    y = year + 4800 - a;
    int m;
    m = month + 12*a -3;
    long int JDN;
    JDN = day + floor((153*m+2)/5.0) + 365*y + floor(y/4.0) - floor(y/100.0) + floor(y/400.0) - 32045;
    printf("%d\n",JDN);
    return 0;
}