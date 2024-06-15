#ifndef MINEGAME_WIN_H
#define MINEGAME_WIN_H


#include <iostream>

#include "Table.h"
#include "Mine.h"
#include "ncurses_win.h"

#define CMD_CLEAR_SCREEN "cls"

int run(int map_x, int map_y, int num_mines);

#endif
