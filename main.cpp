//
// Created by leecurrent04 on 24. 5. 27.
//

#include <iostream>
#include <time.h>

#ifdef _WIN32
    #include "header/MineGame_win.h"
#elif defined(__linux__)
    #include "header/MineGame.h"
#endif

int main()
{
    Pos map_size;
    map_size.x = 3;
    map_size.y = 3;

    // 시간 기록
    unsigned long init_time = (unsigned long)time(NULL);
    switch(run(map_size.x, map_size.y, int(map_size.x*map_size.y*0.2)))
    {
        case -1:
            std::cout << "FAIL" << std::endl;
            break;
        case 0:
            std::cout << "TIME : " << (unsigned long)time(NULL) - init_time << std::endl;
            break;
    }
}

