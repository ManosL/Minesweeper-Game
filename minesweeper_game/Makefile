minesweeper: minesweeper.o fillboard.o printboard.o check_win.o opening_tiles.o
	gcc minesweeper.o fillboard.o printboard.o check_win.o opening_tiles.o -o minesweeper

minesweeper.o: minesweeper.c
	gcc -c minesweeper.c

fillboard.o: fillboard.c
	gcc -c fillboard.c

printboard.o: printboard.c
	gcc -c printboard.c

check_win.o: check_win.c
	gcc -c check_win.c

opening_tiles.o: opening_tiles.c
	gcc -c opening_tiles.c

.PHONY: clean

clean:
	rm -f minesweeper minesweeper.o fillboard.o printboard.o check_win.o opening_tiles.o
