#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "SDL.h"
#include <vector2.h>
#include "engine.h"

class Camera {
public:
    void Update(float dt);

    inline static Camera* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new Camera(); }
    inline SDL_Rect GetViewbox(){ return m_viewbox; }
    inline Vector2 GetPosition(){ return m_position; }
    inline void SetTarget(Vector2* target){ m_target = target; }

private:
    Camera(){ m_viewbox = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };}
    static Camera* s_instance; 

    SDL_Rect m_viewbox;
    Vector2* m_target;
    Vector2 m_position;
};

#endif // CAMERA_H