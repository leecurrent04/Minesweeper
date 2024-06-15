//
// Created by leecurrent04 on 24. 5. 27.
//

#include "../header/MineGame.h"

int run(int map_x, int map_y, int num_mines)
{
    Mine::MineInit(map_x, map_y, num_mines);
    Mine mine[num_mines];
    Table table(map_x, map_y);
    table.clear("□");

    Table mine_table(map_x, map_y, 0);      // 타일 주변의 지뢰 갯수를 저장함
    Table mine_opened(map_x, map_y, 0);     // 타일의 개방 여부를 저장함

    // 지뢰 설정
    for(int k=0; k<num_mines; k++)
    {
        mine[k].SetPos();
        Mine::CountMines(mine_table.table_n, Mine::pos_x_mine[k], Mine::pos_y_mine[k], 6,5 );
        // table.set(Mine::pos_x_mine[k], Mine::pos_y_mine[k], "M");
    }

    Pos Cur;
    Cur.x=0;
    Cur.y=0;
    cursor_set(Cur.x, Cur.y, "X");
    table.draw();
    while(mine_opened.RemainCells()!=num_mines)
    {
        if(mine_opened.table_n[Cur.y][Cur.x]){
            table.set(Cur.x, Cur.y, std::to_string(mine_table.table_n[Cur.y][Cur.x]));
        }
        else table.set(Cur.x, Cur.y, "□");

        cursor_init();
        switch (KeyEvent())
        {
        case 'h':
            if(Cur.x>0) --Cur.x;
            table.set(Cur.x, Cur.y, "X");
            break;
        case 'j':
            if(Cur.y<map_y-1) ++Cur.y;
            table.set(Cur.x, Cur.y, "X");
            break;
        case 'k':
            if(Cur.y>0) --Cur.y;
            table.set(Cur.x, Cur.y, "X");
            break;
        case 'l':
            if(Cur.x<map_x-1) ++Cur.x;
            table.set(Cur.x, Cur.y, "X");
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

