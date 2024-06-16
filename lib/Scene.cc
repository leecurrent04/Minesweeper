#include "../header/Scene.h"

int start_scene()
{
    List menu(3);
    menu.setLabel(str_menu_sel);
    int num = 0;

    menu.set(num, "x");
    cursor_init();
    cursor_refresh(); 
    cursor_exit();
    menu.draw("MINESWEEPER ]\n[ w-UP | a-LEFT | s-DOWN | d-RIGHT | Space-SELECT | p-Flag");
    while(1)
    {
        menu.set(num, " ");
        cursor_init();
        switch (menu.move(num, KeyEvent()))
        {
        case ' ':
            cursor_exit();
            return num;
        default:
            menu.set(num, "x");
            break;
        };
        cursor_refresh(); 
        cursor_exit();

        menu.draw("MINESWEEPER ]\n[ w-UP | a-LEFT | s-DOWN | d-RIGHT | Space-SELECT | p-Flag");
    }
    return -1;
}

int map_size_sel_scene(Pos& map_size)
{
    List menu(4);
    menu.setLabel(str_map_size_sel);
    int num = 0;

    menu.set(num, "x");
    cursor_init();
    cursor_refresh(); 
    cursor_exit();
    menu.draw("MINESWEEPER ]\n[ w-UP | a-LEFT | s-DOWN | d-RIGHT | Space-SELECT | p-Flag");
    while(1)
    {
        menu.set(num, " ");
        cursor_init();
        switch (menu.move(num, KeyEvent()))
        {
        case ' ':
            cursor_exit();
            switch (num)
            {
            case 0:
                map_size.x=3;
                map_size.y=4;
                break;
            case 1:
                map_size.x=5;
                map_size.y=5;
                break;
            case 2:
                map_size.x=11;
                map_size.y=11;
                break;
            case 3:
                return 1;
            }
            return 0;
        default:
            menu.set(num, "x");
            break;
        };
        cursor_refresh(); 
        cursor_exit();

        menu.draw("MINESWEEPER ]\n[ w-UP | a-LEFT | s-DOWN | d-RIGHT | Space-SELECT | p-Flag");
    }
    return 0;
}
void run_scene(Pos map_size)
{
    // 시간 기록
    unsigned long init_time = (unsigned long)time(NULL);
    switch(run(map_size, int(map_size.x*map_size.y*0.2)))
    {
        case -1:
            std::cout << "FAIL" << std::endl;
            break;
        case 0:
            std::cout << "TIME : " << (unsigned long)time(NULL) - init_time << std::endl;
            break;
    }

    cursor_init();
    KeyEvent();
    cursor_exit();
}