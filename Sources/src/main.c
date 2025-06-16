#include <stdio.h>
#include "functions.h"

/*
TODO:
- Loop to ask for the player's coordinates
*/

int main()
{   
    init();
    
    printf("Welcome to Tic Tac Toe!\n A two player game, played in a 3x3 grid.\n");
    printf("Please choose where you want to play (x,y):");
    scanf("%d%*[,]%d", &row, &col);
    
    play = 'X';
    if(isAvailable(row,col,grid))
    {
        fillMatrix(row,col,grid,play);
    }
    printMatrix(row, col, grid);
    
}