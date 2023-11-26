#include <stdio.h>

int main()
{
    int num;
    scanf("%x", &num);
    printf("%d\n", (int)num);
    printf("%u\n", (unsigned int)num);
    printf("%.6f\n", *(float *)&num);
    printf("%.3e\n", *(float *)&num);
    return 0;
}