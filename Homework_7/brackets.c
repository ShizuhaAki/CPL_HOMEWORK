#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T > 0)
    {
        T--;
        char s[100005];
        scanf("%s", s);
        int len = strlen(s);
        int top = 0;
        int flag = 1;
        char content[100005] = {0};
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                content[++top] = s[i];
                continue;
            }
            if ((s[i] == '}' && content[top] == '{') || (s[i] == ')' && content[top] == '(') || (s[i] == ']' && content[top] == '['))
            {
                top--;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (top > 0)
            flag = 0;

        if (flag == 1)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}