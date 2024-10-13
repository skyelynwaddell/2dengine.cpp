#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <string>

//Player(Properties* props)
class Player : public Character {
public:
    Player(Properties* props);

    void Create(){};
    void Update(float dt);
    void Draw();
    void DrawGUI(){};
    void Input(){};
    void Clean();

private:
    
protected:
};

#endif // PLAYER_H