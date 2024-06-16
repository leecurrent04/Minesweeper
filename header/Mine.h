#ifndef MINE_H
#define MINE_H

#include <iostream>
#include <time.h>
#include "Table.h"

typedef struct Pos{
    int x;
    int y;
};

class Mine
{
    private:
        int num_mines;
        Pos map_size;

    public:
        Table table;      
        Table grid;        // 타일 주변의 지뢰 갯수를 저장함
        Table opened;     // 타일의 개방 여부를 저장함
        Table flag;     // 타일의 개방 여부를 저장함

        Mine(int x, int y, int num);

        void SetTable();
        void SetGrid();
        int RemainCells();
        bool IsMine(int x, int y);

};

#endif