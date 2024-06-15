//
// Created by leecurrent04 on 24. 5. 27.
//

#include <iostream>
#ifdef _WIN32
    #include "header/MineGame_win.h"
#elif defined(__linux__)
    #include "header/MineGame.h"
#endif

int main()
{
    long long init_time;
    run(6,5,5);
}

