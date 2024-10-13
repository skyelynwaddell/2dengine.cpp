#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <SDL_render.h>
using std::string;

class Animation {
public:
    Animation(){};

    void Update();
    void Draw(float x, float y, int spriteWidth, int spriteHeight);
    void SetProps(string textureID, int spriteRow, int frameCount, int animSpd, SDL_RendererFlip flip=SDL_FLIP_NONE);
private:
    int m_spriteRow;
    int m_spriteFrame;
    int m_animSpd;
    int m_frameCount;
    string m_textureID;
    SDL_RendererFlip m_flip;

protected:
};

#endif // ANIMATION_H