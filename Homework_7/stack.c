#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10000

int main()
{
    char content[STACK_SIZE] = {0};
    int top = 0;
    int n;
    scanf("%d", &n);
    for (int time = 1; time <= n; time++)
    {
        char str[1000] = {0};
        scanf("%s", str);
        // pop
        if (str[0] == 'p' && str[1] == 'o')
        {
            if (top == 0)
                printf("Empty\n");
            else
                top--;
        }
        // push x
        else if (str[0] == 'p' && str[1] == 'u')
        {
            getchar();
            scanf("%c", &content[top]);
            top++;
        }
        // top
        else if (str[0] == 't')
        {
            if (top == 0)
                printf("Empty\n");
            else
                printf("%c\n", content[top - 1]);
        }
        // print
        else
        {
            if (top == 0)
                printf("Empty\n");
            else
            {
                for (int i = top - 1; i >= 0; i--)
                    printf("| %c |\n", content[i]);
                printf("|===|\n");
            }
        }
    }
    return 0;
}