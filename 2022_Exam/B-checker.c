#include <stdio.h>
#include <string.h>

int check(char s[], char t[]);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[200005], t[200005];
        scanf("%s%s", s, t);
        if (check(s, t)) {
            printf("Correct.\n");
        } else {
            printf("Wrong Answer!\n");
        }
    }
    return 0;
}

int check(char s[], char t[])
{
    int flag[100] = {0};
    int cnt = 0;
    char *ps1 = s, *ps2 = s + (int)strlen(s) - 1;
    char *pt1 = t, *pt2 = t + (int)strlen(t) - 1;
    while (ps1 < ps2 && pt1 < pt2) {
        if (*ps1 == '?' && *ps2 != '?') {
            if (*pt1++ != *ps2 || *pt2-- != *ps2) {
                return 0;
            }
        } else if (*ps2 == '?' && *ps1 != '?') {
            if (*pt1++ != *ps1 || *pt2-- != *ps1) {
                return 0;
            }
        } else if (*ps1 != '?' && *ps2 != '?') {
            if (*pt1++ != *ps1 || *pt2-- != *ps1) {
                return 0;
            }
        } else {
            cnt++;
            int num1 = 10 * ((*pt1) - '1' + 1) + (*(pt1 + 1)) - '1' + 1;
            pt1 += 2;
            int num2 = 10 * ((*pt2) - '1' + 1) + (*(pt2 - 1)) - '1' + 1;
            pt2 -= 2;
            if (num1 != num2)
                return 0;
            if (flag[num1] != 0 && flag[10 * (num1 % 10) + (num1 / 10)] != 0) {
                return 0;
            }
            flag[num1] = 1;
        }
        ps1++;
        ps2--;
    }
    if (strlen(t) - strlen(s) != 2 * cnt) {
        return 0;
    }
    return 1;
}