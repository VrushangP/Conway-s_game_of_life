#include <stdio.h>

void copyFutCur( int *currentYear,int *futureYear, int row, int col) {
    int i, j;
    for ( i = 1; i < row - 1; i++)
    {
        for ( j = 1; j < col - 1; j++)
        {
            *(currentYear + (i*col) + j) = *(futureYear + (i*col) + j);
        }
    }
}