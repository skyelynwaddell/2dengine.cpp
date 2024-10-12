#pragma once

#include "object.h"

class Player : public Object {

    public:
        Player(SDL_Renderer *renderer, string sprite, int x, int y, int w, int h, int health);

        void Create();
        void Input(const SDL_Event& event);
        void Update(float delta_time);
        void Draw();

    private:
        int m_health;
};