#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    static char *splitch = ";";
    int T;
    scanf("%d", &T);
    while (T--) {
        char str[1005] = {0};
        scanf("%s", str);
        char *token;
        int i = 0;
        char arr[5][1005] = {0};
        for (token = strtok(str, splitch); token != NULL; token = strtok(NULL, splitch)) {
            strcpy(arr[i++], token);
        }
        int d1, d2, size;
        d1 = atoi(arr[2]);
        d2 = atoi(arr[3]);
        size = atoi(arr[4]);
        char *p, *q, *r;
        p = arr[0];
        q = arr[1];
        char s3[2500] = {0};
        r = s3;
        while (*p != '\0' && *q != '\0') {
            for (int i = d1; i > 0 && *p != '\0' && *q != '\0'; i--) {
                *r++ = *p++;
            }
            for (int j = d2; j > 0 && *p != '\0' && *q != '\0'; j--) {
                *r++ = *q++;
            }
            // printf("%s\n", s3);
        }
        while (*p != '\0') {
            *r++ = *p++;
        }
        while (*q != '\0') {
            *r++ = *q++;
        }
        *r = '\0';
        *(s3 + size - 1) = '\0';
        printf("%s\n", s3);
    }
    return 0;
}
