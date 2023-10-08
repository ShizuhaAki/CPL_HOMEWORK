#include <stdio.h>
#include <string.h>
int main()
{
    char arr1[20] = "abcdefg";
    char arr2[] = "abcd";
    int result = strcmp(arr1,arr2);
    if(result == 0)
        printf("arr1 = arr2");
    else if(result > 0)
        printf("arr1 > arr2");
    else
        printf("arr1 < arr2");
    return 0;
}