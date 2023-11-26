#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = malloc(sizeof(char) * 4096);
    char *str = ptr;
    char ch;
    int index = 0;
    while ((ch = getchar()) != '\n')
    {
        *(str++) = ch;
        index++;
    }
    str = ptr;
    // for (int i = 0; i < index; i++)
    //     printf("%c", *(str + i));

    int flag = 1;
    for (int i = 0; i < index; i++)
    {
        if (*(str + i) == ' ')
            flag = 1;
        else
        {
            if (flag)
            {
                *(str + i) = (*(str + i) >= 'a' && *(str + i) <= 'z' ? *(str + i) - 'a' + 'A' : *(str + i));
                flag = 0;
            }
            else
            {
                *(str + i) = (*(str + i) >= 'A' && *(str + i) <= 'Z' ? *(str + i) - 'A' + 'a' : *(str + i));
            }
        }

        printf("%c", *(str + i));
    }
    free(ptr);
    return 0;
}