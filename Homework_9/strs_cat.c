#include <stdio.h>
#include <string.h>

void mystrcat(char *s1, char *s2);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        char s1[2005] = {0}, s2[1005] = {0};
        scanf("%s", s1);
        scanf("%s", s2);
        mystrcat(s1, s2);
    }
    return 0;
}

void mystrcat(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int k = (len2 > len1) ? len1 : len2;
    char *p, *q;
    p = s1 + len1 - k;
    q = s2;
    int flag = 0;
    while (k > 0) {
        if (strncmp(p, q, k) == 0) {
            flag = 1;
            for (; *q != '\0';) {
                *p++ = *q++;
            }
            break;
        } else {
            p++;
            k--;
        }
    }
    if (!flag) {
        strcat(s1, s2);
    }
    printf("%s\n", s1);
}