#include <stdio.h>
#include <stdbool.h>

/************VARIABLES************/
char grid[3][3];
char play;
int row, col;
/************FUNCTIONS************/
extern void init(void);
extern bool isAvailable(int row, int col, char grid[3][3]);
extern bool didWin(int row, int col, char grid[3][3]);
extern void printMatrix(int row, int col, char grid[3][3]);
extern bool fillMatrix(int row, int col, char grid[3][3], char play);