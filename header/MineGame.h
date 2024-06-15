#ifndef MINEGAME_H
#define MINEGAME_H


#include <iostream>

#include "Table.h"
#include "Mine.h"
#include "ncurses.h"

#define CMD_CLEAR_SCREEN "clear"

int run(int map_x, int map_y, int num_mines);

#endif