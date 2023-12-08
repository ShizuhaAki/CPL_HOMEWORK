#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 600050

int n, q, total, size[N], id[N];
// 下标为 1...total, size[i]表示空间链第i块的大小，id[i]表示第i块的代表项目，0表示free

int fit_size(int m)
{
    // 对输入的m 求出需要分配的内存大小
    int k = 0;
    while (pow(2, k) < m) {
        k++;
    }
    return k;
}

void query()
{
    // 输出当前的空间链
    printf("%d\n", total);
    for (int i = 1; i <= total; i++) {
        printf("%d", id[i]);
        printf(i != total ? " " : "\n");
    }
}

int find_free(int s)
{
    // 寻找当前最合适的节点
    for (int i = 1; i <= total; i++) {
        if (id[i] != 0)
            continue;
        if (size[i] >= s)
            return i;
    }
}

void allocate(int cur_id, int s)
{
    while (1) {
        int pos = find_free(s);
        if (size[pos] == s) {
            id[pos] = cur_id;
            return;
        } else {
            for (int i = total + 1; i > pos + 1; i--) {
                id[i] = id[i - 1];
                size[i] = size[i - 1];
            }
            ++total;
            --size[pos];
            size[pos + 1] = size[pos];
            id[pos + 1] = 0;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    total = 1;
    size[1] = n;
    id[1] = 0;
    for (int i = 0; i < q; i++) {
        char op[3] = {0};
        scanf("%s", op);
        if (op[0] == 'A') {
            int id, m;
            scanf("%d%d", &id, &m);
            allocate(id, fit_size(m));
        } else {
            query();
        }
    }
    return 0;
}