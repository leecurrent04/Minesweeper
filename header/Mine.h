#ifndef MINE_H
#define MINE_H

#include <iostream>
#include <time.h>
#include <vector>

typedef struct Pos{
    int x;
    int y;
};

class Mine
{
    private:
        // static
        static int map_wide;
        static int map_height;
        static bool initializeSrand();

        Pos position;
        Pos GetRandomPos();

    public:
        // 지뢰의 위치를 저장하는 변수
        static std::vector<int> pos_x_mine;
        static std::vector<int> pos_y_mine;
        static int num_mines;
        static void MineInit(int w, int h, int num_mines);
        static void CountMines(std::vector<std::vector<int>>& table, int m, int n, int x_max, int y_max);
        static bool IsMine(int x, int y);
        int RemainMines(std::vector<std::vector<int>>& table);

        void SetPos();
};

#endif