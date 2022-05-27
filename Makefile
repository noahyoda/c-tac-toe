CC = gcc
CFLAGS = -fsanitize=address -g
OBJ = board.o game.o

rebuild: clean game

game : $(OBJ)
	$(CC) $(CFLAGS) -o game $(OBJ)

game.o: game.c board.h
	$(CC) $(CFLAGS) -c game.c

board.o: board.c
	$(CC) $(CFLAGS) -c board.c

clean:
	rm -f *.o game