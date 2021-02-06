#include <unistd.h>
#include "common.hpp"
#include "level1.hpp"

int main(int argc, char** argv){
    Level1 level1();

    level1.init();
    for (int i = 0; i < 100; i++)
    {
        level1.loop();
        sleep(1);
    }
    level1.end();
    
}