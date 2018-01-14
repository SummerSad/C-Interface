CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = arith.c
TAG = ctags

all:
	$(CC) $(CFLAGS) $(SRCS) -o program.out

tag:
	$(TAG) .

mem:
	valgrind --leak-check=yes ./program.out

clean:
	rm -f *.out *.o
