#include <stdio.h>
#include <stdbool.h>
#include "functions.h"


bool isAvailable(int row, int col, char grid[3][3])
{

}
void didWin(int row, int col, char grid[3][3])
{

}
void printMatrix(int row, int col, char grid[3][3])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {

        }
    }
}
bool fillMatrix(int row, int col, char grid[3][3], char play)
{
    if (isAvailable(row, col, grid))
    {
        grid[row][col] = play;
    }
    else
    {
        return false;
    }
}