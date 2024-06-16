//
// Created by leecurrent04 on 24. 5. 27.
//


#ifdef _WIN32
    #include "../header/MineGame_win.h"
#elif defined(__linux__)
    #include "../header/MineGame.h"
#endif

int run(int map_x, int map_y, int num_mines)
{
    Mine mine(map_x, map_y, num_mines);
    Table table(map_x, map_y);
    table.clear("O");

    // 지뢰 설정
    mine.SetTable();
    mine.SetGrid();

    Pos Cur;
    Cur.x=0;
    Cur.y=0;
    
    // 지뢰를 제외한 모든 셀을 열때까지
    while(mine.RemainCells()!=num_mines)
    {
        // 커서를 움직이기 전에 원래 타일 문자로 바꾼다.
        if(mine.opened.getNum(Cur.x, Cur.y)){
            table.set(Cur.x, Cur.y, std::to_string(mine.grid.getNum(Cur.x, Cur.y)));
        }
        else if(mine.flag.getNum(Cur.x, Cur.y)==1) table.set(Cur.x, Cur.y, "P");
        else table.set(Cur.x, Cur.y, "O");

        // 커서 초기화(Linux)
        cursor_init();
        switch (table.move(Cur.x, Cur.y, KeyEvent()))
        {
        case 'p':
            // 열린 타일이면 플래그를 세우지 않는다.
            if(mine.opened.getNum(Cur.x, Cur.y)) break;
            
            // 플래그에 따라 커서의 표시를 다르게 한다.
            if(mine.flag.getNum(Cur.x, Cur.y)==1) table.set(Cur.x, Cur.y, "O");
            else table.set(Cur.x, Cur.y, "P");

            // 상태를 반전한다.
            mine.flag.setNum(Cur.x, Cur.y, mine.flag.getNum(Cur.x, Cur.y)*-1);
            break;
        case ' ':
            if(mine.IsMine(Cur.x, Cur.y))
            {
                cursor_exit();
                return -1;
            } 
            mine.opened.setNum(Cur.x, Cur.y, 1);
            table.set(Cur.x, Cur.y, std::to_string(mine.grid.getNum(Cur.x, Cur.y)));
            break;
        };
            
        cursor_refresh(); 
        cursor_exit();

        system(CMD_CLEAR_SCREEN);
        table.draw();
    }

    return 0;
}

