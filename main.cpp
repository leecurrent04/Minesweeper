//
// Created by leecurrent04 on 24. 5. 27.
//

#include "header/Common.h"
#include "header/Scene.h"


int main()
{
    while (1)
    {
        Pos map_size;
        switch (start_scene())
        {
        case OFFLINE:
            if(map_size_sel_scene(map_size)) break;
            run_scene(map_size);
            break;
        case ONLINE:
            break;
        case EXIT:
            return 0;
        };
    };


    return 0;
}

