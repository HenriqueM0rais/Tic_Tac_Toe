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
    readSymbol(player);
    readCoordinates(&row, &col);
    play++;
    fillMatrix(row,col,grid,player);
    printMatrix(row, col, grid);
    
    while(!didWin(row, col, grid))
    {
        readCoordinates(&row, &col);
        play++;
        fillMatrix(row,col,grid,player);
        printMatrix(row, col, grid);
    }
}