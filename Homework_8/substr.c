#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s = malloc(sizeof(char) * 100005);
    char *t = malloc(sizeof(char) * 100005);
    scanf("%s", s);
    scanf("%s", t);
    int lens = strlen(s);
    int lent = strlen(t);
    for (int i = 0; i <= lens - lent; i++)
    {
        char *s1 = malloc(sizeof(char) * lent);
        char *s2 = s1;
        for (int j = 0; j < lent; j++)
            *(s2 + j) = *(s + i + j);
        // if (strcmp(s1, t) == 0)
        //     printf("%d ", i + 1);
        int flag = 0;
        for (int j = 0; j < lent; j++)
        {
            if (*(s2 + j) == *(t + j))
                flag += 1;
        }
        if (flag == lent)
            printf("%d ", i);
        free(s1);
    }
    printf("\n");
    free(s);
    free(t);
    return 0;
}