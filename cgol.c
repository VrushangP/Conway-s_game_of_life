#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameOfLifeFunc.h"
#define ROWS 22
#define COLUMONS 42


int main ( int argc, char *argv[] ) {   
    
    char response;   
    int ticks = 50;

    char str1[100];
    int currentYear[ROWS][COLUMONS], newYear[ROWS][COLUMONS], futureYear[ROWS][COLUMONS];
    int i, j, ctr, tempInput;
    int z = 1;

    int row = 22, col = 42;
    int generation = 0;
    int breakOut;

    char cont = 'y';

    if (argc < 2 || argc > 3)
    {
        printf("improper usage, ./cgol FILENAME.seed NUMBEROFTICKS[optional] \n");
        exit(0);
    }
	if (argc > 2) {
        ticks = atoi(argv[2]);

        char* p = argv[2];
        while (*p != '\0')
        {
            if (*p<'0' || *p>'9')
            {
                printf("%s is not a number, please enter an integer as the third argument", argv[2]);
                return 0;
            }
            p++;
        }
        /* found a way to see if an input is an integer from this site
         *
         * https://stackoverflow.com/questions/29248585/c-checking-command-line-argument-is-integer-or-not
         */
	}

    for ( i = 0; i < ROWS; i++)
    {
        for ( j = 0; j < COLUMONS; j++)
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
    
    while (fgets(str1, sizeof str1, f1)) {
        j=0; ctr=1;
        for(i=0;i<=(strlen(str1));i++) {
            if(str1[i]==' '||str1[i]=='\0') {
            } else if (str1[i] == '\n') {
                currentYear[z][ctr]= 0;
            } else {
                tempInput = atoi(&str1[i]);
                currentYear[z][ctr] = tempInput;
                ctr++; 
                if (ctr > 41)
                {
                    printf("error, seed file colomuns surpass 40.\n");
                    exit(0);
                }
                
            }
        }
        z++;
        if (z > 21)
        {
            printf("error, seed file rows surpass 40.\n");
            exit(0);
        }
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
