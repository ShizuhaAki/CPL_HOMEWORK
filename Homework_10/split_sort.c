#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100000];
char split[5];
char **ans;

int cmp(const void *p1, const void *p2)
{
    return (strcmp(*(char **)p1, *(char **)p2));
}

int main()
{
    scanf("%s", s);
    getchar();
    scanf("%s", split);
    ans = malloc(sizeof(char *) * 100);
    int sum = 0;
    char *p = strtok(s, split);
    while (p != NULL) {
        ans[sum] = malloc(strlen(p) + 1);
        strcpy(ans[sum], p);
        p = strtok(NULL, split);
        sum++;
    }
    // printf("%d\n", sum);
    qsort(ans, sum, sizeof(ans[0]), cmp);
    for (int i = 0; i < sum; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}