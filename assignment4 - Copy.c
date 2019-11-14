#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameOfLifeFunc.h"


int main ( int argc, char *argv[] ) {   
    printf("Start? (y or n): ");
    char response;
    if ((response = getchar()) != 'y') {
        exit(0);
    } 
    char str1[100];
    char currentYear [ROWS][COLUMONS];
    int i, j, ctr;
    int z = 1;
    for ( i = 0; i < ROWS; i++)
    {
        for ( j = 0; j < COLUMONS; j++)
        {
            currentYear[i][j] = 'L';
        }   
    }
    

    FILE *f1;
    f1 = fopen( "diehard.seed", "r");
    if (f1 == NULL) {
        printf("Error! cannot open file\n" );
        exit(0);
    }
    
    while (fgets(str1, sizeof str1, f1)) {
        j=0; ctr=1;
        for(i=0;i<=(strlen(str1));i++) {
            if(str1[i]==' '||str1[i]=='\0') {

            } else if (str1[i] == '\n') {
                currentYear[z][ctr]= 'L';
            } else {
                currentYear[z][ctr]=str1[i];
                ctr++; 
            }
        }
        z++;
    }
    fclose(f1);

    printCurrentYear(currentYear);

    /*    system("sleep 0.25");
    *    system("clear");
    */   

    return 0;
}