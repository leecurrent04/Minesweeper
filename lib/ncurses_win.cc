#include "../header/ncurses_win.h"

void cursor_init()
{
}

void cursor_set(int x, int y, const char *value)
{
}


void cursor_exit()
{
    system(CMD_CLEAR_SCREEN);
}

void cursor_refresh()
{
}

char KeyEvent()
{
    return _getch();
}

