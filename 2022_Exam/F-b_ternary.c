#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(int n, char s[]);
void reverse(char s[], int len);

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        char size;
        getchar();
        scanf("%c", &size);
        if (size == 't') {
            char s[20];
            scanf("%s", s);
            int num = 0;
            int len = strlen(s);
            int flag = 0;
            for (int i = 0; i < len; i++) {
                if (s[i] != 'Z' && s[i] != '0' && s[i] != '1') {
                    flag = 1;
                }
            }
            if (flag) {
                printf("Radix Error\n");
            } else {
                for (int i = 0; i < len; i++) {
                    if (s[i] == 'Z') {
                        num += -1 * pow(3, len - i - 1);
                    } else if (s[i] == '1') {
                        num += 1 * pow(3, len - 1 - i);
                    }
                }
                printf("%d %s\n", num, s);
            }
        } else if (size == 'd') {
            int n, flag = 0;
            char input[20] = {0};
            scanf("%s", input);
            char s[25] = {0};
            for (int i = 0; i < strlen(input); i++) {
                if (input[i] != '-' && !isdigit(input[i])) {
                    flag = 1;
                }
            }
            if (flag) {
                printf("Radix Error\n");
            } else {
                n = atoi(input);
                if (n > 0) {
                    change(n, s);
                    printf("%d %s\n", n, s);
                } else if (n == 0) {
                    printf("0 0\n");
                } else {
                    change(-n, s);
                    int len = strlen(s);
                    for (int i = 0; i < len; i++) {
                        if (s[i] == '1') {
                            s[i] = 'Z';
                        } else if (s[i] == 'Z') {
                            s[i] = '1';
                        }
                    }
                    printf("%d %s\n", n, s);
                }
            }
        }
    }
    return 0;
}

void change(int n, char s[])
{
    int k = 0;
    int arr[25] = {0};
    while (n) {
        arr[k++] = n % 3;
        n /= 3;
    }
    // for (int i = 0; i < k; i++) {
    //     printf("%d", arr[i]);
    // }
    // printf("\n");
    for (int i = 0; i < k; i++) {
        if (arr[i] == 0) {
            s[i] = '0';
        } else if (arr[i] == 1) {
            s[i] = '1';
        } else if (arr[i] == 2) {
            s[i] = 'Z';
            arr[i + 1] += 1;
        } else {
            s[i] = '0';
            arr[i + 1] += 1;
        }
    }
    if (arr[k] != 0) {
        s[k] = '1';
        k += 1;
    }
    // for (int i = k; i >= 0; i--) {
    //     printf("%c", s[i]);
    // }
    // printf("\n");
    reverse(s, k);
}

void reverse(char s[], int len)
{
    char temp[25] = {0};
    for (int i = 0; i < len; i++) {
        temp[i] = s[i];
    }
    for (int i = len - 1; i >= 0; i--) {
        s[i] = temp[len - 1 - i];
    }
}