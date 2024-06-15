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

    /*
    int ch;
    while ((ch = getch()) != 'q') { // 'q' 키를 누르면 종료
        mvprintw(y, x, " "); // 현재 위치의 표시를 지웁니다.
        switch (ch) {
            case KEY_UP:
                if (y > 0) y--;
                break;
            case KEY_DOWN:
                if (y < LINES - 1) y++;
                break;
            case KEY_LEFT:
                if (x > 0) x--;
                break;
            case KEY_RIGHT:
                if (x < COLS - 1) x++;
                break;
        }
        mvprintw(y, x, "X"); // 새로운 위치에 표시
		if(ch == ' ') mvprintw(y, x, "O");
        refresh();
    }
*/
