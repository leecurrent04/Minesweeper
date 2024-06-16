#include "../header/Mine.h"

Mine::Mine(Pos size, int num)
:table(size,0), grid(size,0), opened(size,0), flag(size,-1)
{
    srand((unsigned long)time(NULL));
    num_mines = num;
    map_size.x = size.x;
    map_size.y = size.y;
}

void Mine::SetTable()
{
    Pos temp;
    for(int n=0; n<num_mines; n++)
    {
        do{
            temp.x = rand()%map_size.x;
            temp.y = rand()%map_size.y;
        }while(table.getNum(temp));

        table.setNum(temp, 1);
    }
    // 중복 검사
}

void Mine::SetGrid()
{
    for(int y = 0; y < map_size.y; y++){
        for(int x = 0; x < map_size.x; x++){

            if(!table.getNum(Pos(x,y))) continue;

            // (x, y)를 중심으로 주변 8개의 좌표를 순회
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    // 현재 좌표는 무시
                    if (i == 0 && j == 0) continue;

                    int newX = x + i;
                    int newY = y + j;

                    // 새로운 좌표가 유효한지 검사
                    if (newX >= 0 && newX < map_size.x && newY >= 0 && newY < map_size.y) {
                        grid.setNum(Pos(newX, newY), grid.getNum(Pos(newX,newY))+1);
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
            if(opened.getNum(Pos(i,j))) sum++;
        }
    }
    return (map_size.x*map_size.y-sum);
}

bool Mine::IsMine(Pos position)
{
    if(table.getNum(position)) return 1;
    return 0;
}

int Mine::GetMines()
{
    return this->num_mines;
}
