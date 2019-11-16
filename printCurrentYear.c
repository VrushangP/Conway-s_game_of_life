#include <stdio.h>
#define ROWS 22
#define COLUMONS 42

void printCurrentYear(int *currentYear, int row, int col, int z) {
    int i, j;
    printf(" ");
    for ( i = 0; i < col - 2; i++)
    {
        printf("-");
    }
    printf("  \n");
    
    for ( i = 1; i < row-1; i++){
        printf("|");
        for( j=1; j < col-1; j++) {
            if (*(currentYear + (i*col) + j) == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf(" ");
    for ( i = 0; i < col - 2; i++)
    {
        printf("-");
    }
    printf("%d\n", z);
}

