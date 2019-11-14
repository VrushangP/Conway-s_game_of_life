#include <stdio.h>
#define ROWS 22
#define COLUMONS 42

void printCurrentYear(int *currentYear, int row, int col, int z) {
    int i, j;
    printf(" --------------------------------------------------------------------------------- \n");
    for ( i = 1; i < row-1; i++){
        printf("| ");
        for( j=1; j < col-1; j++) {
            printf("%d ", *(currentYear + (i*col) + j));
        }
        printf("|\n");
    }
    printf(" ---------------------------------------------------------------------------------%d\n", z);
}

