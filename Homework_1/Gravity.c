#include <stdio.h>
#include <math.h>
#define G 6.674e-11
#define M 77.15
int main()
{
    double m,r;
    scanf("%lf%lf",&m,&r);
    printf("%.3e\n",(G*M*m)/(pow(r,2)));
    return 0;
}