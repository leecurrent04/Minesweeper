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
    Mine::MineInit(map_x, map_y, num_mines);
    Mine mine[num_mines];
    Table table(map_x, map_y);
    table.clear("O");

    Table mine_table(map_x, map_y, 0);      // 타일 주변의 지뢰 갯수를 저장함
    Table mine_opened(map_x, map_y, 0);     // 타일의 개방 여부를 저장함
    Table mine_flag(map_x, map_y, -1);     // 타일의 개방 여부를 저장함

    // 지뢰 설정
    for(int k=0; k<num_mines; k++)
    {
        mine[k].SetPos();
        Mine::CountMines(mine_table.table_n, Mine::pos_x_mine[k], Mine::pos_y_mine[k], map_x,map_y );
        // table.set(Mine::pos_x_mine[k], Mine::pos_y_mine[k], "M");
    }

    Pos Cur;
    Cur.x=0;
    Cur.y=0;
    
    // 지뢰를 제외한 모든 셀을 열때까지
    while(mine_opened.RemainCells()!=num_mines)
    {
        // 커서를 움직이기 전에 원래 타일 문자로 바꾼다.
        if(mine_opened.table_n[Cur.y][Cur.x]){
            table.set(Cur.x, Cur.y, std::to_string(mine_table.table_n[Cur.y][Cur.x]));
        }
        else if(mine_flag.table_n[Cur.y][Cur.x]==1) table.set(Cur.x, Cur.y, "P");
        else table.set(Cur.x, Cur.y, "O");

        // 커서 초기화(Linux)
        cursor_init();
        switch (table.move(Cur.x, Cur.y, KeyEvent()))
        {
        case 'p':
            // 열린 타일이면 플래그를 세우지 않는다.
            if(mine_opened.table_n[Cur.y][Cur.x]) break;
            
            // 플래그에 따라 커서의 표시를 다르게 한다.
            if(mine_flag.table_n[Cur.y][Cur.x]==1) table.set(Cur.x, Cur.y, "O");
            else table.set(Cur.x, Cur.y, "P");

            // 상태를 반전한다.
            mine_flag.table_n[Cur.y][Cur.x]*=-1;
            break;
        case ' ':
            if(Mine::IsMine(Cur.x, Cur.y))
            {
                cursor_exit();
                return -1;
            } 
            mine_opened.table_n[Cur.y][Cur.x] = 1;
            table.set(Cur.x, Cur.y, std::to_string(mine_table.table_n[Cur.y][Cur.x]));
            break;
        };
            
        cursor_refresh(); 
        cursor_exit();

        system(CMD_CLEAR_SCREEN);
        table.draw();
    }

    return 0;
}

