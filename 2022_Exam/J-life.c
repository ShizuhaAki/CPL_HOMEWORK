#include <stdio.h>
#include <string.h>

int n;
char s[1005];

void change();

int main()
{
    scanf("%d%s", &n, s);
    while (n--) {
        change();
    }
    printf("%s\n", s);
    return 0;
}

void change()
{
    int len = strlen(s);
    int flag[1005] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            if (i - 1 >= 0 && i + 1 < len && s[i - 1] == 'I' && s[i + 1] == 'I') {
                s[i] = '#';
            } else {
                flag[i] = 1;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (flag[i] == 1) {
            if (i - 1 >= 0 && (s[i - 1] == '#' || s[i - 1] == 'E')) {
                s[i - 1] = 'A';
            }
            if (i + 1 < len && (s[i + 1] == '#' || s[i + 1] == 'E')) {
                s[i + 1] = 'A';
            }
        }
    }
}