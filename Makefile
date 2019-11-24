all: cgol dynCGOL printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

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

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

dynCGOL.o: dynCGOL.c
	gcc -ansi -Wall -c dynCGOL.c

cgol: cgol.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o
	gcc -ansi -Wall -o cgol cgol.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

dynCGOL: dynCGOL.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

clean: 
	rm cgol cgol.o dynCGOL dynCGOL.o printCurrentYear.o getNeighbours.o liveOrDead.o seedChange.o copyFutCur.o

