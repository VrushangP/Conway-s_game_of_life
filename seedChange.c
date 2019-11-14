#include <stdio.h>

int seedChange(int *newYear, int *currentYear, int row, int col) {
    
    int i,j;
    int change = 0;
    for ( i = 1; i < row - 1; i++) {
        for ( j = 1; j < col - 1; j++) {
            if (*(currentYear + (i*col) + j) != *(newYear +(i*col) + j)) {
                change++;
            }
        }
    }
    return change;
}
