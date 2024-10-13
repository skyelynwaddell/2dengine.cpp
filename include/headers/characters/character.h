#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

/**
 * Character Class - This is the object all Players, NPC's and beings should use.
 * 
 */

//Character State Machine
enum STATE
{
    //States all characters have
    IDLE,
    WALK,

    //Player specific states
    BIKE,
};

enum DIRECTION
{
    DOWN,
    LEFT,
    RIGHT,
    UP,
};

//Character Object
class Character : public Object {
public:
    Character(Properties* props) : Object(props) {};

    virtual void Create()=0;
    virtual void Update(float dt)=0;
    virtual void Draw()=0;
    virtual void DrawGUI()=0;
    virtual void Clean()=0;

private:
protected:
    string m_name;
    int m_spd;
    int m_dirx;
    int m_diry;
    int m_xspd;
    int m_yspd;
};

#endif // CHARACTER_H