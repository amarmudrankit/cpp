PROGNAME	= Sort
CC		= g++
CFLAGS		= 
LDFLAGS		=

all: Sort

#  $^ name of all prerequisites with duplicates removed

Sort: Sorting.o
	$(CC) -o $(PROGNAME) $^ $(LDFLAGS)

Sorting.o: Sorting.cpp Sorting.h
	$(CC) -c Sorting.cpp $(CFLAGS)

clean:
	rm -vf *.o Sort

