#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
    int p,q;
    scanf("%d%d",&p,&q);
    double x;
    double a,b,c;
    a = pow((-0.5*q + sqrt((0.5*q)*(0.5*q) + pow((1.0/3*p),3))),1.0/3);
    b = -0.5*q - sqrt((0.5*q)*(0.5*q) + pow((1.0/3*p),3));
    if(b<0)
    {
        c = -pow(-b,1.0/3);
    }
    else
    {
        c = pow(b,1.0/3);
    }
    x = a + c;
    printf("%.3lf",x);
    return 0;
}