main : ./main.cpp
	g++ -Wall -c ./main.cpp -o out/main.o

lib : ./lib/Mine.cc
	g++ -Wall -c ./lib/Mine.cc -o out/mine.o

link :
	g++ -Wall -g ./out/*.o -o out/main.out

all:
	g++ -Wall -c ./main.cpp -o out/main.o
	g++ -Wall -c ./lib/Mine.cc -o out/mine.o
	g++ -Wall -c ./lib/Table.cc -o out/Table.o
	g++ -Wall -c ./lib/ncurses.cc -o out/ncurses.o
	g++ -Wall -c ./lib/MineGame.cc -o out/MineGame.o
	g++ -Wall -g ./out/*.o -o out/main.out -lncurses
	./out/main.out

run :
	./out/main.out
	