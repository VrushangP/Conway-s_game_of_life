#include <stdio.h>
#define ROWS 22
#define COLUMONS 42

void getNeighbours(int *newYear, int *currentYear, int row, int col) {
    int i, j, ii, jj, tempVal, tempCounter;
    for ( ii = 1; ii < row-1; ii++) {
        for ( jj = 1; jj < col-1; jj++) {
            *(newYear +(ii*col) + jj) = 0;
            tempCounter = 0;
            for ( i = ii - 1; i < ii + 2; i++) {
                for ( j = jj - 1; j < jj + 2; j++) {
                    if (i != ii || j != jj) {
                        tempVal = *(currentYear + (i*col) + j);
                        tempCounter += tempVal;
                    }

                }
                
            }
            *(newYear +(ii*col) + jj) = tempCounter;
        
        }
    }
}