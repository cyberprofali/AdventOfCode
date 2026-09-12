CC = gcc 

CFLAGS = -g -Wall -lm -O3 

all: part1.c part2.c  
		$(CC) $(CFLAGS) part1.c -o part1.o 
	    $(CC) $(CFLAGS) part2.c -o part2.o 
part1: 
	./part1.o

part2:
	./part2.o

clean: 
	$(RM) -rf answer-part1.txt answer-part2.txt *.o *.~ *.dSYM *.out
