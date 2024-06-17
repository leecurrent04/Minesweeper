#ifndef SCENE_H
#define SCENE_H

#include "Common.h"
#include "Table.h"
#include "time.h"

#include "StringR.h"

#ifdef _WIN32
    #include "MineGame_win.h"
    #include "ncurses_win.h"
#elif defined(__linux__)
    #include "MineGame.h"
    #include "ncurses.h"
#endif

enum start_scene_list{
    OFFLINE,
    ONLINE,
    EXIT
};

int start_scene();
int map_size_sel_scene(Pos& map_size);
void run_scene(Pos map_size);

#endif