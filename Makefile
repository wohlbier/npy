CC=gcc

all:
	$(CC) main.c

.PHONY : clean

clean :
	-$(RM) *~ *.o a.out
