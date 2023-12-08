#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s = malloc(100005);
    char *t = malloc(100005);
    scanf("%s%s", s, t);
    char *find = s;
    // printf("%x\n", find);
    while ((find = strstr(find, t)) != NULL) {
        printf("%d ", find - s);
        // printf("%x\n", find);

        // int len = strlen(t);
        // find += len;
        // 这样做不行，不然 mymymya mymy 的样例过不了，少了一个！
        // printf("%x\n", find);
        find++;
    }
    free(s);
    free(t);
    return 0;
}