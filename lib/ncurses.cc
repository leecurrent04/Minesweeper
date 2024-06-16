#include "../header/ncurses.h"

void cursor_init()
{
    // ncurses 초기화
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

	// 커서를 숨깁니다.
    curs_set(0); 
}

void cursor_set(int x, int y, const char *value)
{
    mvprintw(y, x, value); // 초기 위치에 표시
}


void cursor_exit()
{
    // ncurses 종료
    endwin();
    system(CMD_CLEAR_SCREEN);
}

void cursor_refresh()
{
    refresh();
}

char KeyEvent()
{
    return getch();
}
