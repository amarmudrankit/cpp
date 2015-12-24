PROGNAME	= Sort
CC		= g++
CFLAGS		= 
LDFLAGS		=

all: Sort

#  $^ name of all prerequisites with duplicates removed

Sort: Sorting.o
	$(CC) -o $(PROGNAME) $^ $(LDFLAGS)

Sorting.o: Sorting.cpp
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -vf *.o Sort

