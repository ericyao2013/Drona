#include "World.h"
#include <math.h>


int main(){

    char* const fileName = "/home/tommaso/src/Firmware/Tools/sitl_gazebo/worlds/iris.world";
    World *w = new World(fileName);


    coord c1 = {2,2,0};
    coord c2 = {-5,-3,0};

    w->AddBox(c1,2,3,1);
    w->AddBox(c2,1,5,2);






    w->CloseWorld();

}

