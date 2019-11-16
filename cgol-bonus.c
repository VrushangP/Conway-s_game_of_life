#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameOfLifeFunc.h"


int main ( int argc, char *argv[] ) {   
    
    char response;   
    int ticks = 50;

    char str1[100];
    int row = atoi(argv[3]) + 2;
    int col = atoi(argv[4]) + 2;
    int currentYear [row][col], newYear [row][col], futureYear [row][col];
    int i, j, ctr, tempInput;
    int z = 1;

    
    int generation = 0;
    int breakOut;
    char cont = 'y';


	if (argc == 3) {
        ticks = atoi(argv[2]);
	}

    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            currentYear[i][j] = 0;
            newYear[i][j] = 0;
            futureYear[i][j] = 0;
        }   
    }

    FILE *f1;
    f1 = fopen( argv[1], "r");
    if (f1 == NULL) {
        printf("Error! cannot open file\n" );
        exit(0);
    }
    j = 1;
    while (fgets(str1, sizeof str1, f1) && j < row - 1) {
        ctr=1;
        for(i=0;ctr < col - 1;i++) {
            if(str1[i]==' '||str1[i]=='\0') {
            } else if (str1[i] == '\n') {
                currentYear[z][ctr]= 0;
            } else {
                tempInput = atoi(&str1[i]);
                currentYear[z][ctr] = tempInput;
                ctr++; 
            }
        }
        j++;
        z++;
    }
    fclose(f1);

    system("clear");
    printCurrentYear(&currentYear[0][0], row, col, generation);
    system("sleep 0.1");

    do {
        printf("Start? (y or n): ");
        if ((response = getchar()) == 'n') {
            exit(0);
        } else if (response != 'y') {
            printf("Only the single characters y or n are acceptable.\n");
        }
        getchar();
    } while (response != 'y');

    do {
        i = 0;
        do {
            getNeighbours(&newYear[0][0], &currentYear[0][0], row, col);
            liveOrDead(&newYear[0][0], &currentYear[0][0], &futureYear[0][0], row, col);
            breakOut = seedChange(&futureYear[0][0], &currentYear[0][0], row, col);
            copyFutCur(&currentYear[0][0], &futureYear[0][0], row, col);
            i++;
            generation++;
            if (breakOut != 0)
            {
                system("clear");
                printCurrentYear(&currentYear[0][0], row, col, generation);
                system("sleep 0.1");
            }
        } while (i < ticks && breakOut != 0);
        if (breakOut != 0) {
            printf("Continue? (y or n): ");
            cont = getchar();
            getchar();
        }
    } while (cont == 'y' && breakOut != 0);
    return 0;
}