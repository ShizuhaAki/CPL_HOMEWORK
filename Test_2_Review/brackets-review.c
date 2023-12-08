#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[100005] = {0};
        scanf("%s", s);
        char stack[100005] = {0};
        int top = 0;
        char *p = s;
        int flag = 1;
        while (*p != '\0') {
            if (*p == '[' || *p == '{' || *p == '(') {
                stack[top++] = *p;
            } else {
                if (top > 0 && ((*p == '}' && stack[top - 1] == '{') || (*p == ']' && stack[top - 1] == '[') || (*p == ')' && stack[top - 1] == '('))) {
                    top--;
                } else {
                    flag = 0;
                }
            }
            p++;
        }
        if (top != 0)
            flag = 0;

        if (flag) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}