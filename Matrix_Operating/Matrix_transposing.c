#include <stdio.h>

#define ROW 3
#define COL 4

void Transpose(int arr[][COL], int result[][ROW])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[j][i] = arr[i][j];
        }
    }
}

void Print(int result[][ROW])
{
    for(int i = 0; i < COL; i++)
    {
        for(int j = 0; j < ROW; j++)
        {
            printf("%d",result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[ROW][COL] = {
        {1 , 2 , 3 , 1},
        {4 , 5 , 6 , 2},
        {7 , 8 , 9 , 3},
    };
    int result[COL][ROW] = {0};
    Transpose(arr,result);
    Print(result);
    return 0;
}