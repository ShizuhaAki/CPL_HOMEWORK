#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char rule[], char ch);

int main()
{
    char rule[150] = {0};
    scanf("%s", rule);
    char *arr[1050] = {0};
    char s[1050] = {0};
    int num = 0;
    while (scanf("%s", s) != EOF) {
        arr[num] = malloc(strlen(s) + 1);
        strcpy(arr[num++], s);
    }

    for (int i = 1; i < num; i++) {
        if (arr[i][0] == '-' /* && arr[i][1] != '-'*/) {
            if (find(rule, arr[i][1]) == -1) {
                printf("%s: invalid option -- '%c'\n", arr[0], arr[i][1]);
                return 0;
            } else if (rule[find(rule, arr[i][1]) + 1] == ':') {
                i++;
            }
        }
    }

    int temp = num - 1;
    if (num > 1 && rule[find(rule, arr[num - 1][1]) + 1] == ':') {
        int cnt = 1;
        while (arr[temp - cnt][0] == '-' && rule[find(rule, arr[temp - cnt][1]) + 1] == ':') {
            cnt++;
        }
        cnt--;
        if (cnt % 2 == 0) {
            printf("%s: option requires an argument -- '%c'\n", arr[0], arr[num - 1][1]);
            return 0;
        }
    }

    printf("%s\n", arr[0]);
    for (int i = 1; i < num; i++) {
        if (arr[i][0] == '-' && rule[find(rule, arr[i][1]) + 1] != ':') {
            printf("%c\n", arr[i][1]);
        } else if (arr[i][0] != '-') {
            continue;
        } else if (arr[i][0] == '-' && rule[find(rule, arr[i][1]) + 1] == ':') {
            printf("%c=%s\n", arr[i][1], arr[i + 1]);
            i++;
        }
    }

    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    return 0;
}

int find(char rule[], char ch)
{
    int len = strlen(rule);
    for (int i = 0; i < len; i++) {
        if (ch == rule[i])
            return i;
    }
    return -1;
}