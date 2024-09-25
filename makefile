CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++17 -O2 -lSDL2
LDFLAGS = -lSDL2

all: maze

maze: main.o maze_render.o maze_input.o maze_utils.o
	$(CC) $(LDFLAGS) main.o maze_render.o maze_input.o maze_utils.o -o maze

main.o: main.c++ maze.h
	$(CC) $(CFLAGS) -c main.c++

maze_render.o: maze_render.c++ maze.h
	$(CC) $(CFLAGS) -c maze_render.c++

maze_input.o: maze_input.c++ maze.h
	$(CC) $(CFLAGS) -c maze_input.c++

maze_utils.o: maze_utils.c++ maze.h
	$(CC) $(CFLAGS) -c maze_utils.c++

clean:
	rm -f maze *.o

run: maze
	./maze

