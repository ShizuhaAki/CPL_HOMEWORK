#include <stdio.h>

#define ROW 3
#define COL 4

void Transpose(int arr[][COL], int result[][ROW])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            result[i][j] = arr[j][i];
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
        {1 , 2 , 3 , 4},
        {4 , 5 , 6 , 7},
        {7 , 8 , 9 , 0},
    };
    int result[][ROW] = {0};
    Transpose(arr,result);
    Print(result);
    return 0;
}