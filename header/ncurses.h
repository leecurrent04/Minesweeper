#ifndef NCURSES_H
#define NCURSES_H

#include <ncurses.h>
#include <string>
#include <iostream>

void cursor_init();
void cursor_set(int x, int y, const char *value);
void cursor_exit();
void cursor_refresh();
char KeyEvent();

#endif