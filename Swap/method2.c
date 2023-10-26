#include <stdio.h>

#define SWAP(a, b)  \
    do {            \
        int t = a;  \
        a = b;      \
        b = t;      \
}while (0)

int main()
{
    int x, y;
    SWAP(x, y);
}