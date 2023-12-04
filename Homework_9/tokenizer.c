#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = 1;
void judge(char *str, char ans[]);
void process(char *s, char ans[]);
char Reverse[16][10] = {"const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
char Operator[15][5] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};

int main()
{
    static char *splitch = ";";
    char s[4100] = {0};
    char ans[100000] = {0};
    while (scanf("%s", s) != EOF) {
        process(s, ans);
    }
    if (flag) {
        printf("%s", ans);
    } else {
        printf("Compile Error\n");
    }
    return 0;
}

void judge(char *str, char ans[])
{
    if (str == NULL)
        return;

    for (int i = 0; i < 16; i++) {
        if (strcmp(str, Reverse[i]) == 0) {
            strcat(ans, "reserved ");
            return;
        }
    }

    for (int i = 0; i < 11; i++) {
        if (strcmp(str, Operator[i]) == 0) {
            strcat(ans, "operator ");
            return;
        }
    }

    int flag1 = -1, cnt = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            cnt++;
        } else if (str[i] == '.') {
            flag1 = i;
        }
    }
    if (cnt == len) {
        strcat(ans, "integer ");
        return;
    } else if (cnt == len - 1 && flag1 != -1) {
        strcat(ans, "float ");
        return;
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            flag = 0;
            return;
        } else if (str[0] >= '0' && str[0] <= '9') {
            flag = 0;
            return;
        } else {
            strcat(ans, "variable ");
            return;
        }
    }

    flag = 0;
}

void process(char *s, char ans[])
{

    int len1, len2;
    char *pos = strchr(s, ';');
    len1 = strlen(s);
    if (pos == NULL) {
        judge(s, ans);
    } else {
        char s2[10005] = {0};
        char s3[10005] = {0};
        for (int i = 0; s[i] != ';'; i++) {
            s2[i] = s[i];
        }
        if (s[0] != ';') {
            judge(s2, ans);
        }
        strcat(ans, "\n");
        len2 = strlen(s2);
        for (int i = 0; i < len1 - len2 - 1; i++) {
            s3[i] = *(pos + 1 + i);
        }
        if (s3[0] != '\0')
            process(s3, ans);
    }
}