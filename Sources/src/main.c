#include <stdio.h>
#include "functions.h"



int main()
{   
    init();
    
    printf("Welcome to Tic Tac Toe!\n A two player game, played in a 3x3 grid.\n");
    printf("Please choose where you want to play (x,y):");
    scanf("%d%*[,]%d", &row, &col);
    printf("Scan Complete\n");
    
    play = 'X';
    if(isAvailable(row,col,grid))
    {
        fillMatrix(row,col,grid,play);
    }

    printf("Test: %c\n", grid[row][col]);
}