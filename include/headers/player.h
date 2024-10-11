#pragma once

#include "object.h"

class Player : public Object {

    public:
        Player(int x, int y, int w, int h, std::string sprite, SDL_Renderer* renderer, int health = 100);

        void Create();
        void Update();
        void Draw();

    private:
        int m_health;
};