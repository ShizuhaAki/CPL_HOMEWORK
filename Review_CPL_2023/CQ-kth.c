#include <stdio.h>
#include <string.h>

int arr[1000];
int cnt;
int q, num;

int find(int k);

int main()
{
    scanf("%d%d", &q, &num);
    while (q--) {
        char s[15] = {0};
        scanf("%s", s);
        if (strcmp(s, "Add") == 0) {
            int n;
            scanf("%d", &n);
            arr[n - num]++;
            cnt++;
        } else if (strcmp(s, "Query") == 0) {
            int k;
            scanf("%d", &k);
            if (k > cnt) {
                printf("No Answer\n");
            } else {
                printf("%d\n", find(k));
            }
        } else {
            int x;
            scanf("%d", &x);
            printf("%s\n", s);
        }
    }
    return 0;
}

int find(int k)
{
    int count = 0;
    for (int i = 999; i >= 0; i--) {
        count += arr[i];
        if (count >= k) {
            return (i + num);
        }
    }
}