PROGNAME	= Sort
CC		= g++
CFLAGS		= 
LDFLAGS		=

all: Sort

Sort: Sorting.o
	$(CC) -o $(PROGNAME) $^ $(LDFLAGS)

Sorting.o: Sorting.cpp
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -vf *.o Sort

