#ifndef VINCENT_PLATFORMER_COMMON
#include <stdbool.h>

class Obstacle {
    public:
    int x;
    int y;
    bool solid;
    char* appearance;
    virtual bool contains(int x, int y) = 0;
    virtual void tick(){};
};

class Level {
    public:
    Obstacle* obstacles;
    virtual void init() = 0;
    virtual void loop() = 0;
    virtual void end() = 0;
};
#define VINCENT_PLATFORMER_COMMON "fuck you"
#endif