#include "common.hpp"
#include "level1.hpp"
#include <string.h>
#include <ncurses.h>

#define LEVEL_LENGTH 100

bool Floor::contains(int x, int y){
    return y<=this->y;
};

void Floor::tick(){};

Floor::Floor(int length){
    for (int i = 0; i < length; i++){
        strcat(appearance, "#");
    }
}

bool Player::contains(int x, int y){
    return (this->x == x) && (this->y == y);
};

void Player::tick(){};

void Player::move(Level l, int newX, int newY){
    for (int i = 0; i < sizeof(l.obstacles)/sizeof(l.obstacles[0]); i++) {
        if(l.obstacles[i].solid && l.obstacles[i].contains(newX, newY)){
            return;
        }
    }

    x = newX;
    y = newY;
}

void Level1::init(){
    //Init variables
    obstacles[0] = Floor(LEVEL_LENGTH);

    obstacles[0].x = 0;
    obstacles[0].y = 10;

    p.x = 0;
    p.y = 0;
    p.appearance = "@";

    //init ncurses
    initscr();
}

void Level1::loop(){
    for (int i = 0; i < sizeof(obstacles)/sizeof(obstacles[0]); i++)
    {
        obstacles[i].tick();
        mvprintw(obstacles[i].y, obstacles[i].x, obstacles[i].appearance);        
    }

    p.tick();
    mvprintw(p.y, p.x, p.appearance);
}

void Level1::end(){
    endwin();
}

Level1::Level1(){

}