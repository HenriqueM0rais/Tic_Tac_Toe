#include <stdio.h>
//#include "functions.h"

int main()
{
    int row = 0, col = 0;
    
    printf("Welcome to Tic Tac Toe!\n A two player game, played in a 3x3 grid.\n");
    printf("Please choose where you want to play (x,y):");
    scanf("%d%*[,]%d", &row, &col);
    printf("Coordenates: %d, %d\n", row, col);
}