CC = gcc
CFLAGS = -Wall -g
EXE = llist

all: main.c linked_list.o
	$(CC) $(CFLAGS) main.c linked_list.o -o $(EXE)

linked_list.o: linked_list.h linked_list.c
	$(CC) $(CFLAGS) linked_list.c -c

clean:
	rm $(EXE)

