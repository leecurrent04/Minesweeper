//
// Created by leecurrent04 on 24. 5. 27.
//


#ifdef _WIN32
    #include "../header/MineGame_win.h"
#elif defined(__linux__)
    #include "../header/MineGame.h"
#endif

int run(Pos map_size, int num_mines)
{
    Mine mine(map_size, num_mines);
    Table table(map_size);
    table.clear(" ");

    // 지뢰 설정
    mine.SetTable();
    mine.SetGrid();

    std::string title = "Mine "+std::to_string(mine.GetMines());
    Pos Cur(0,0);
    
    cursor_init();
    cursor_refresh(); 
    cursor_exit();
    table.draw(title);

    // 지뢰를 제외한 모든 셀을 열때까지
    while(mine.RemainCells()!=num_mines)
    {
        // 커서를 움직이기 전에 원래 타일 문자로 바꾼다.
        if(mine.opened.getNum(Cur)){
            table.set(Cur, std::to_string(mine.grid.getNum(Cur)));
        }
        else if(mine.flag.getNum(Cur)==1) table.set(Cur, "P");
        else table.set(Cur, " ");

        // 커서 초기화(Linux)
        cursor_init();
        switch (table.move(Cur, KeyEvent()))
        {
        case 'p':
            // 열린 타일이면 플래그를 세우지 않는다.
            if(mine.opened.getNum(Cur)) break;
            
            // 플래그에 따라 커서의 표시를 다르게 한다.
            if(mine.flag.getNum(Cur)==1) table.set(Cur, "O");
            else table.set(Cur, "P");

            // 상태를 반전한다.
            mine.flag.setNum(Cur, mine.flag.getNum(Cur)*-1);
            break;
        case ' ':
            if(mine.IsMine(Cur))
            {
                cursor_exit();
                table.draw(title);
                return -1;
            } 
            mine.opened.setNum(Cur, 1);
            table.set(Cur, std::to_string(mine.grid.getNum(Cur)));
            break;
        };
            
        cursor_refresh(); 
        cursor_exit();

        table.draw(title);
    }

    return 0;
}

