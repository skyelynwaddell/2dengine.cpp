//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player : Object {

    public:

    Player(int x, int y);
    int getX();
    int setX();                     // x pos
    int getY();     int setY();     //y pos
    int getDirX();  int setDirX();  //dirx
    int getDirY();  int setDirY();  //diry
    int getSpd();   int setSpd();   //spd  
    int getGrvty(); int setGrvty(); //grvty

    private:
        int mX;
        int mY;
        int mDirX;
        int mDirY;
        int mSpd;
        int mGrvty;

};

#endif //PLAYER_H