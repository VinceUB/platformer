#ifndef VINCENT_LEVEL1_HEADER_GUARD_THINGY
#include "common.hpp"

class Player : public Obstacle{
    public:
    using Obstacle::Obstacle;
    void move();
};

class Level1 : public Level {
    public:
    using Level::Level;
    Player p;
    Level1();
};

class Floor : public Obstacle{
    private:
    int length;

    public:
    using Obstacle::Obstacle;
    Floor(int length);
};

#define VINCENT_LEVEL1_HEADER_GUARD_THINGY
#endif