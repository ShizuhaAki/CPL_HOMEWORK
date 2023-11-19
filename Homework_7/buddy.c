#include <stdio.h>
#include <math.h>

int n, q;

int main()
{
    scanf("%d%d", &n, &q);
    getchar();
    int ID[100000] = {0};
    int size[100000] = {0};
    size[0] = pow(2, n);
    int num = 1;
    for (int time = 0; time < q; time++)
    {
        char ch;
        scanf("%c", &ch);
        if (ch == 'A')
        {
            int id, m;
            scanf("%d%d", &id, &m);
            getchar();
            int k = -1;
            for (;; k++)
            {
                if (pow(2, k) >= m)
                    break;
            }
            int sizem = pow(2, k);
            for (int i = 0;;)
            {
                if (ID[i] != 0)
                    i++;
                else if (size[i] == sizem)
                {
                    ID[i] = id;
                    break;
                }
                else if (size[i] > sizem)
                {
                    num++;
                    for (int j = num - 1; j > i; j--)
                    {
                        size[j + 1] = size[j];
                        ID[j + 1] = ID[j];
                    }
                    size[i] /= 2;
                    size[i + 1] = size[i];
                    ID[i + 1] = 0;
                }
                else
                    i++;
            }
        }
        else if (ch == 'Q')
        {
            getchar();
            printf("%d\n", num);
            for (int i = 0; i < num; i++)
            {
                printf("%d ", ID[i]);
            }
            printf("\n");
        }
    }
    return 0;
}