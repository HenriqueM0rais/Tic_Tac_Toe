#include <stdio.h>
#include <stdbool.h>

/*************DEFINES*************/
#define SIZE 3;

/************VARIABLES************/
char grid[3][3];
char player[2];
int row, col;
int matrixSize;

/************FUNCTIONS************/
extern void init(void);
extern bool isAvailable(int row, int col, char grid[3][3]);
extern bool didWin(int row, int col, char grid[3][3]);
extern void printMatrix(int row, int col, char grid[3][3]);
extern bool fillMatrix(int row, int col, char grid[3][3], char play);
extern bool readSymbol(char *player);
extern bool readCoordinates(int *row, int *col);