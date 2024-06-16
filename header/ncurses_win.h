#ifndef NCURSES_WIN_H
#define NCURSES_WIN_H

#include <conio.h>
#include <string>
#include <iostream>

void cursor_init();
void cursor_set(int x, int y, const char *value);
void cursor_exit();
void cursor_refresh();
char KeyEvent();

#define CMD_CLEAR_SCREEN "cls"

#endif
