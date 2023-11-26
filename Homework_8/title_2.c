#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s = malloc(sizeof(char) * 4099);
    while (scanf("%s", s) != EOF)
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (!i)
            {
                if (*(s + i) <= 'z' && *(s + i) >= 'a')
                {
                    *(s + i) = *(s + i) - 'a' + 'A';
                }
            }
            else
            {
                if (*(s + i) <= 'Z' && *(s + i) >= 'A')
                {
                    *(s + i) = *(s + i) + 'a' - 'A';
                }
            }
        }
        printf("%s ", s);
    }
    free(s);
    return 0;
}