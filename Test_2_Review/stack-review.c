#include <stdio.h>

char stack[1000];
char s[10];
int p = 0;

void push(char m)
{
    stack[p++] = m;
}

void pop()
{
    if (p == 0) {
        printf("Empty\n");
    } else {
        p--;
    }
}

void top()
{
    if (p == 0) {
        printf("Empty\n");
    } else {
        printf("%c\n", stack[p - 1]);
    }
}

void print()
{
    if (p == 0) {
        printf("Empty\n");
    } else {
        for (int i = p - 1; i >= 0; i--) {
            printf("| %c |\n", stack[i]);
        }
        printf("|===|\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (s[0] == 't')
            top();
        else if (s[1] == 'u') {
            char ch;
            getchar();
            ch = getchar();
            push(ch);
        } else if (s[1] == 'o') {
            pop();
        } else if (s[1] == 'r') {
            print();
        }
    }
    return 0;
}