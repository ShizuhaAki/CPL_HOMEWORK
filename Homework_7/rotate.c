#include <stdio.h>
#include <string.h>

int rotate1(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k);
int rotate2(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k);
int rotate3(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k);
int rotate4(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k);

int main()
{
    int a, b, c;
    char str[1005];
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", str);
    int lx = a, ly = b, lz = c;
    int x1 = 0, x2 = a, y1 = 0, y2 = b;
    int ans1 = rotate1(str, lx, ly, lz, x1, x2, y1, y2, 0);
    int ans2 = rotate2(str, lx, ly, lz, x1, x2, y1, y2, 0);
    int ans3 = rotate3(str, lx, ly, lz, x1, x2, y1, y2, 0);
    int ans4 = rotate4(str, lx, ly, lz, x1, x2, y1, y2, 0);
    printf("%d %d %d %d\n", ans1, ans2, ans3, ans4);
    return 0;
}

int rotate1(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k)
{
    int times = strlen(str);
    if (k < times)
    {
        char ch = str[k];
        switch (ch)
        {
        case 'W':
            x2 = x1;
            x1 -= lz;
            int temp = lx;
            lx = lz;
            lz = temp;
            break;
        case 'S':
            x1 = x2;
            x2 += lz;
            int temp1 = lx;
            lx = lz;
            lz = temp1;
            break;
        case 'A':
            y2 = y1;
            y1 -= lz;
            int temp2 = lz;
            lz = ly;
            ly = temp2;
            break;
        case 'D':
            y1 = y2;
            y2 += lz;
            int temp3 = lz;
            lz = ly;
            ly = temp3;
            break;
        default:
            break;
        }
        rotate1(str, lx, ly, lz, x1, x2, y1, y2, k + 1);
    }
    else
        return x1;
}

int rotate2(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k)
{
    int times = strlen(str);
    if (k < times)
    {
        char ch = str[k];
        switch (ch)
        {
        case 'W':
            x2 = x1;
            x1 -= lz;
            int temp = lx;
            lx = lz;
            lz = temp;
            break;
        case 'S':
            x1 = x2;
            x2 += lz;
            int temp1 = lx;
            lx = lz;
            lz = temp1;
            break;
        case 'A':
            y2 = y1;
            y1 -= lz;
            int temp2 = lz;
            lz = ly;
            ly = temp2;
            break;
        case 'D':
            y1 = y2;
            y2 += lz;
            int temp3 = lz;
            lz = ly;
            ly = temp3;
            break;
        default:
            break;
        }
        rotate2(str, lx, ly, lz, x1, x2, y1, y2, k + 1);
    }
    else
        return x2;
}

int rotate3(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k)
{
    int times = strlen(str);
    if (k < times)
    {
        char ch = str[k];
        switch (ch)
        {
        case 'W':
            x2 = x1;
            x1 -= lz;
            int temp = lx;
            lx = lz;
            lz = temp;
            break;
        case 'S':
            x1 = x2;
            x2 += lz;
            int temp1 = lx;
            lx = lz;
            lz = temp1;
            break;
        case 'A':
            y2 = y1;
            y1 -= lz;
            int temp2 = lz;
            lz = ly;
            ly = temp2;
            break;
        case 'D':
            y1 = y2;
            y2 += lz;
            int temp3 = lz;
            lz = ly;
            ly = temp3;
            break;
        default:
            break;
        }
        rotate3(str, lx, ly, lz, x1, x2, y1, y2, k + 1);
    }
    else
        return y1;
}

int rotate4(char *str, int lx, int ly, int lz, int x1, int x2, int y1, int y2, int k)
{
    int times = strlen(str);
    if (k < times)
    {
        char ch = str[k];
        switch (ch)
        {
        case 'W':
            x2 = x1;
            x1 -= lz;
            int temp = lx;
            lx = lz;
            lz = temp;
            break;
        case 'S':
            x1 = x2;
            x2 += lz;
            int temp1 = lx;
            lx = lz;
            lz = temp1;
            break;
        case 'A':
            y2 = y1;
            y1 -= lz;
            int temp2 = lz;
            lz = ly;
            ly = temp2;
            break;
        case 'D':
            y1 = y2;
            y2 += lz;
            int temp3 = lz;
            lz = ly;
            ly = temp3;
            break;
        default:
            break;
        }
        rotate4(str, lx, ly, lz, x1, x2, y1, y2, k + 1);
    }
    else
        return y2;
}