all: assignment4 printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

printCurrentYear.o: printCurrentYear.c
	gcc -ansi -Wall -c printCurrentYear.c

getNeighbours.o: getNeighbours.c
	gcc -ansi -Wall -c getNeighbours.c

liveOrDead.o: liveOrDead.c
	gcc -ansi -Wall -c liveOrDead.c

seedChange.o: seedChange.c
	gcc -ansi -Wall -c seedChange.c

copyFutCur.o: copyFutCur.c
	gcc -ansi -Wall -c copyFutCur.c

assignment4.o: assignment4.c
	gcc -ansi -Wall -c assignment4.c

assignment4: assignment4.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o
	gcc -ansi -Wall -o assignment4 assignment4.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

clean: 
	rm assignment4 assignment4.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o