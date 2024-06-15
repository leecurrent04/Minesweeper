#include "../header/Mine.h"

int Mine::map_wide;
int Mine::map_height;

std::vector<int> Mine::pos_x_mine;
std::vector<int> Mine::pos_y_mine;

int Mine::num_mines;

void Mine::MineInit(int w, int h, int num_mines)
{
    Mine::map_height = h;
    Mine::map_wide = w;
    Mine::num_mines = num_mines;

    Mine::pos_x_mine.resize(num_mines, -1);
    Mine::pos_y_mine.resize(num_mines, -1);

    static bool srand_inited = initializeSrand();
};

bool Mine::initializeSrand()
{
    srand((unsigned long)time(NULL));
    return 1;
}

Pos Mine::GetRandomPos()
{
    Pos temp;
    temp.x = rand()%map_wide;
    temp.y = rand()%map_height;

    int n=0;
    // 중복 검사
    while(n<num_mines && pos_x_mine[n]!=-1&&pos_y_mine[n]!=-1)
    {
        // 만약 중복될 경우
        if(temp.x == pos_x_mine[n] && temp.y == pos_y_mine[n]){
            temp.x = rand()%map_wide;
            temp.y = rand()%map_wide;
            n = 0;
            continue;
        }
        n++;
    }
    
    // 다음 중복 검사를 위해 저장
    pos_x_mine[n] = temp.x;
    pos_y_mine[n] = temp.y;

    return temp;
}

void Mine::SetPos()
{
    Pos temp = GetRandomPos();
    this->position.x = temp.x;
    this->position.y = temp.y;
}

void Mine::CountMines(std::vector<std::vector<int>>& table, int x, int y, int x_max, int y_max)
{
    // (x, y)를 중심으로 주변 8개의 좌표를 순회
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // 현재 좌표는 무시
            if (i == 0 && j == 0) continue;

            int newX = x + i;
            int newY = y + j;

            // 새로운 좌표가 유효한지 검사
            if (newX >= 0 && newX < x_max && newY >= 0 && newY < y_max) {
                table[newY][newX]++;
            }
        }
    }
}

bool Mine::IsMine(int x, int y)
{
    for(int i=0; i<num_mines; i++)
    {
        if(pos_x_mine[i]==x&&pos_y_mine[i]==y) return 1;
    }
    return 0;
}
