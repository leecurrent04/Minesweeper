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
}

void cursor_refresh()
{
    refresh();
}

char KeyEvent()
{
    return getch();
}

char GetCharAtCursor(int x, int y) {
    getyx(stdscr, y, x);  // 현재 커서 위치를 가져옴
    return mvinch(y, x) & A_CHARTEXT;  // 현재 위치의 문자를 가져옴
}
