#include "../header/Mine.h"

/*
bool initializeSrand()
{
    srand((unsigned long)time(NULL));
    return 1;
}
*/


Mine::Mine(int x, int y, int num)
:table(x,y,0), grid(x,y,0), opened(x,y,0), flag(x,y,-1)
{
    srand((unsigned long)time(NULL));
    num_mines = num;
    map_size.x = x;
    map_size.y = y;
}

void Mine::SetTable()
{
    Pos temp;

    do{
        temp.x = rand()%map_size.x;
        temp.y = rand()%map_size.y;
    }while(table.getNum(temp.x, temp.y));

    table.setNum(temp.x, temp.y, 1);
    // 중복 검사
}

void Mine::SetGrid()
{
    for(int y = 0; y < map_size.y; y++){
        for(int x = 0; x < map_size.x; x++){

            if(!table.getNum(x,y)) continue;

            // (x, y)를 중심으로 주변 8개의 좌표를 순회
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    // 현재 좌표는 무시
                    if (i == 0 && j == 0) continue;

                    int newX = x + i;
                    int newY = y + j;

                    // 새로운 좌표가 유효한지 검사
                    if (newX >= 0 && newX < map_size.x && newY >= 0 && newY < map_size.y) {
                        grid.setNum(newX, newY, grid.getNum(newX,newY)+1);
                        //mine_table.table_n[newY][newX]++;
                    }
                }
            }
        }
    }
}

// 열지 않은 타일의 수를 알려준다.
int Mine::RemainCells()
{
    int sum=0;
    for(int j=0; j<map_size.y; j++)
    {
        for(int i=0; i<map_size.x; i++)
        {
            if(opened.getNum(i,j)) sum++;
        }
    }
    return (map_size.x*map_size.y-sum);
}

bool Mine::IsMine(int x, int y)
{
    if(table.getNum(x,y)) return 1;
    return 0;
}
