menu:
	g++ -Wall -c ./lib/Scene.cc -o out/Scene.o
	g++ -Wall -c ./lib/Table.cc -o out/Table.o
	g++ -Wall -c ./lib/ncurses.cc -o out/ncurses.o
	g++ -Wall -g ./out/*.o -o out/menu.out -lncurses
	./out/menu.out

all:
	g++ -Wall -c ./main.cpp -o out/main.o
	g++ -Wall -c ./lib/Mine.cc -o out/mine.o
	g++ -Wall -c ./lib/Table.cc -o out/Table.o
	g++ -Wall -c ./lib/ncurses.cc -o out/ncurses.o
	g++ -Wall -c ./lib/MineGame.cc -o out/MineGame.o
	g++ -Wall -c ./lib/Scene.cc -o out/Scene.o
	g++ -Wall -g ./out/*.o -o out/main.out -lncurses
	./out/main.out

all_win:
	g++ -Wall -std=c++17 -c ./main.cpp -o out/win/main.o
	g++ -Wall -std=c++17 -c ./lib/Mine.cc -o out/win/mine.o
	g++ -Wall -std=c++17 -c ./lib/Table.cc -o out/win/Table.o
	g++ -Wall -std=c++17 -c ./lib/ncurses_win.cc -o out/win/ncurses.o
	g++ -Wall -std=c++17 -c ./lib/MineGame.cc -o out/win/MineGame.o
	g++ -Wall -std=c++17 -c ./lib/Scene.cc -o out/win/Scene.o
	g++ -Wall -std=c++17 -g ./out/win/*.o -o out/win/main.exe
	./out/win/main.exe

run :
	./out/main.out
	
