#include <stdio.h>
#include <stdbool.h>

char grid[3][3];
bool isAvailable(int row, int col, char grid[3][3]);
void didWin(int row, int col, char grid[3][3]);
void printMatrix(int row, int col, char grid[3][3]);
bool fillMatrix(int row, int col, char grid[3][3], char play);