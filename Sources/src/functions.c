#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

/*******************************************************************
void init(void)

Inputs: 


Output:


Description:
This function initializes all the global variables
*******************************************************************/
void init()
{
    row = 0;
    col = 0;
    matrixSize = SIZE;
    player[0] = ' ';
    player[1] = ' ';

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            grid[i][j] = ' ';  
        } 
    }

    return;
}
/*******************************************************************
bool isAvailable(int row, int col, char grid[3][3])

Inputs: 

row - Coordinate for the row where the player wants to play 
col - Coordinate for the column where the player wants to play 
grid - Matrix that represents the playing field 

Output:
TRUE if coordinates are available
FALSE if coordinates aren't available

Description:
This function checks if the coordinates chosen by the player are 
available to place the player's icon or not 
*******************************************************************/

bool isAvailable(int row, int col, char grid[3][3])
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3)
    {
        if (grid[row][col]==' ')
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
}

/*******************************************************************
void didWin(int row, int col, char grid[3][3])

Inputs: 

row - Coordinate for the row where the player wants to play 
col - Coordinate for the column where the player wants to play 
grid - Matrix that represents the playing field

Output:
TRUE if one of the players won
FALSE if none of the players won

Description:
This function checks if one of the players has won the game
*******************************************************************/

bool didWin(int row, int col, char grid[3][3])
{
    int counter;
    char aux; 

    /*Checks each row*/
    counter = 0;
    
    for(int i=0; i<matrixSize; i++)
    {
        aux = grid[i][0];
        for(int j=1; j<matrixSize; j++)
        {   
            if ((aux == grid[i][j]) && (grid[i][j] == 'X' || grid[i][j] == 'O'))
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            return true;
        }
        else
        {
            counter = 0;
        }    
    }

    /*Checks each column*/
    counter = 0;
    
    for(int i=0; i<matrixSize; i++)
    {
        aux = grid[0][i];
        for(int j=1; j<matrixSize; j++)
        {
            if ((aux == grid[j][i]) && (grid[j][i] == 'X' || grid[j][i] == 'O'))
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            return true;
        }
        else
        {
            counter = 0;
        }   
    }

    /*Checks Top-left to Bottom-right*/
    counter = 0;
    for (int i=0; i<(matrixSize-1); i++)
    {
        aux = grid[i][i];
        if ((aux == grid[i+1][i+1]) && (grid[i+1][i+1] == 'X' || grid[i+1][i+1] == 'O'))
        {
            counter++;
        } 
    }
    if (counter == 2)
    {
        return true;
    }

    /*Checks Bottom--left to Top-right*/
    counter = 0;
    for (int i=(matrixSize-1); i>0; i--)
    {
        aux = grid[i][i];
        if ((aux == grid[i-1][i-1]) && (grid[i-1][i-1] == 'X' || grid[i-1][i-1] == 'O'))
        {
            counter++;
        } 
    }
    if (counter == 2)
    {
        return true;
    }

    return false;
}

/*******************************************************************
void printMatrix(int row, int col, char grid[3][3])

Inputs: 

row - Coordinate for the row where the player wants to play 
col - Coordinate for the column where the player wants to play 
grid - Matrix that represents the playing field

Output:

Description:
This function prints the playing field 
*******************************************************************/

void printMatrix(int row, int col, char grid[3][3])
{
    for (int c=0;c<matrixSize;c++)
    {
        for (int d=0;d<matrixSize;d++)
        {
            printf("%c",grid[c][d]);
            if (d<(matrixSize-1))
            {
                printf("|");
            }
        }
        printf("\n");
        if (c<(matrixSize-1))
        {
            printf("- - - \n"); 
        }
    }
    return;
}

/*******************************************************************
bool fillMatrix(int row, int col, char grid[3][3], char play)

Inputs: 

row - Coordinate for the row where the player wants to play 
col - Coordinate for the column where the player wants to play 
grid - Matrix that represents the playing field
play - Type of char being placed in the Matrix (either 'X' or 'O')

Output:
TRUE if icon was placed successfully 
FALSE if icon wasn't placed successfully 

Description:
This function places the player's icon on the desired coordinates
if they are available
*******************************************************************/

bool fillMatrix(int row, int col, char grid[3][3], char play)
{
    if (isAvailable(row, col, grid))
    {
        grid[row][col] = play;
        return true;
    }
    else
    {
        return false;
    }
}

bool readSymbol(char *player)
{
    printf("Please choose which symbol you want (X or O):");
    scanf("%c", &player[0]);

    if(player[0] == 'X' || player[0] == 'x')
    {
        player[0] = 'X';
        player[1] = 'O';
        return true;
    }
    else if(player[0] == 'O' || player[0] == 'o')
    {
        player[0] = 'O';
        player[1] = 'X';
        return true;
    }
    else
    {
        printf("The symbol you chose is not available.\n");
        readSymbol(player);
    }
    return false;  
}

bool readCoordinates(int *row, int *col)
{
    printf("Please choose where you want to play (x,y):");
    scanf("%d%*[,]%d", row, col);
    if (*row <= 0 || *row >3)
    {
        printf ("The row you chose is out of bounds.\n");
        readCoordinates(row, col);
    }
    else if (*col <= 0 || *col >3)
    {
        printf ("The column you chose is out of bounds.\n");
        readCoordinates(row, col);
    }
    else
    {
        *row -=1;
        *col -=1;
        return true;
    }
    return false;
}
