#include <stdio.h>
#include <string.h>
int k = 0, flag = 1;
char s2[10005][20] = {'\0'};
char pp[20][10] = {"const", "int", "float", "return", "double", "long", "static", "void", "char", "extern", "break", "enum", "struct", "typedef", "union", "goto"};
char pq[20][10] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};

void process(char s1[10005])
{
    int l1, count = 0;
    l1 = strlen(s1);
    if (s1 == NULL) {
        k++;
        return;
    }
    for (int i = 0; i < 16; i++) {
        if (strcmp(s1, pp[i]) == 0) {
            strcat(s2[k], "reserved ");
            k++;
            return;
        }
    }
    for (int i = 0; i < 11; i++) {
        if (strcmp(s1, pq[i]) == 0) {
            strcat(s2[k], "operator ");
            k++;
            return;
        }
    }
    if (s1[0] >= '0' && s1[0] <= '9' || s1[0] == '.') {
        for (int i = 0; i < l1; i++) {
            if (s1[i] >= '0' && s1[i] <= '9' || s1[i] == '.') {
                if (s1[i] == '.') {
                    count++;
                }
            } else {
                flag = 0;
                return;
            }
        }
        if (count == 0) {
            strcat(s2[k], "integer ");
            k++;
            return;
        } else if (count == 1) {
            strcat(s2[k], "float ");
            k++;
            return;
        } else {
            flag = 0;
            return;
        }
    } else if ((s1[0] >= 'A' && s1[0] <= 'Z') || (s1[0] == '_') || (s1[0] >= 'a' && s1[0] <= 'z')) {
        for (int i = 0; i < l1; i++) {
            if (!((s1[0] >= 'A' && s1[0] <= 'Z') || (s1[0] == '_') || (s1[0] >= 'a' && s1[0] <= 'z') || (s1[0] >= '0' && s1[0] <= '9'))) {
                flag = 0;
                return;
            }
        }
        if (flag) {
            strcat(s2[k], "variable ");
            k++;
            return;
        }
    } else {
        flag = 0;
        return;
    }
}
void pprocess(char s1[10005])
{
    char s[10005] = {0};
    char ss[10005] = {0};
    char *ss1 = strchr(s1, ';');
    int l1, l2;
    l1 = strlen(s1);
    if (ss1 == NULL) {
        process(s1);
        return;
    } else {
        for (int i = 0; s1[i] != ';'; i++) {
            ss[i] = s1[i];
        }
        if (ss[0] != '\0') {
            process(ss);
        }
        l2 = strlen(ss);
        strcat(s2[k], "\n");
        for (int i = 0; i < l1 - l2 - 1; i++) {
            s[i] = *(ss1 + i + 1);
        }
        if (s[0] != '\000') {
            pprocess(s);
        }
    }
}
int main()
{
    char s[10005];
    while (scanf("%s", s) != EOF) {
        pprocess(s);
    next:
        for (int i = 0; i < 10005; i++) {
            s[i] = '0';
        }
    }
    if (flag == 0) {
        printf("Compile Error");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%s", s2[i]);
        }
    }
    return 0;
}