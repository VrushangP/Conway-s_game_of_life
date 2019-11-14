#include <stdio.h>

void liveOrDead(int *newYear, int *currentYear,int *futureYear, int row, int col) {
    int i, j;
    for ( i = 1; i < row - 1; i++) {
        for ( j = 0; j < col - 1; j++) {
            if (*(currentYear + (i*col) + j) == 1) {
                if ( *(newYear +(i*col) + j) < 2) {
                    *(futureYear + (i*col) + j) = 0;
                } else if ( *(newYear +(i*col) + j) == 2 ||  *(newYear +(i*col) + j) == 3) {
                    *(futureYear + (i*col) + j) = 1;
                } else if ( *(newYear +(i*col) + j) > 3) {
                    *(futureYear + (i*col) + j) = 0;
                } 
            } else if (*(currentYear + (i*col) + j) == 0) {
                if ( *(newYear +(i*col) + j) == 3) {
                    *(futureYear + (i*col) + j) = 1;
                }
            }
        }
    }
}