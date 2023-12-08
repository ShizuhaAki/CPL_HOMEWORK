#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str = (char *)malloc(5000);
    while (scanf("%s", str) != EOF) {
        char *s = str;
        *s = toupper(*s);
        s++;
        while (*s != '\0') {
            *s = tolower(*s);
            s++;
        }
        printf("%s ", str);
    }
    free(str);
    return 0;
}