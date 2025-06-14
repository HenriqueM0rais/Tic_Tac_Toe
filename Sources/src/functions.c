#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

/*******************************************************************
void isAvailable(void)

Inputs: 


Output:


Description:
This function initializes all the global variables
*******************************************************************/
void init()
{
    row = 0;
    col = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            strcpy(&grid[i][j], " ");   
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
        if (strcmp(&grid[row][col], " "))
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
    
    for(int i=1; i<row; i++)
    {
        aux = grid[i][0];
        for(int j=0; j<col; j++)
        {
            if (strcmp(&aux, &grid[i][j]))
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }

    /*Checks each column*/
    counter = 0;
    
    for(int i=1; i<col; i++)
    {
        aux = grid[0][i];
        for(int j=0; j<row; j++)
        {
            if (strcmp(&aux, &grid[i][j]))
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }

    /*Checks Top-left to Bottom-right*/
    counter = 0;
    for (int i=0; i<2; i++)
    {
        aux = grid[i][i];
        if (strcmp(&aux, &grid[i+1][i+1]))
        {
            counter++;
        } 
    }
    if (counter == 3)
    {
        return true;
    }

    /*Checks Bottom--left to Top-right*/
    counter = 0;
    for (int i=2; i>0; i--)
    {
        aux = grid[i][i];
        if (strcmp(&aux, &grid[i-1][i-1]))
        {
            counter++;
        } 
    }
    if (counter == 3)
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
