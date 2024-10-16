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
    inline float GetZoom(){return m_zoom;}
    inline void SetZoom(float zoom){m_zoom = zoom;}

    inline static int TranslateX(int x){ 
        int pos = Camera::GetInstance()->GetPosition().X;
        float zoom = Camera::GetInstance()->GetZoom();
        return (x - pos) * zoom; 
    }

    inline static int TranslateY(int y){ 
        int pos = Camera::GetInstance()->GetPosition().Y;
        float zoom = Camera::GetInstance()->GetZoom();
        return (y - pos) * zoom; 
    }

    inline static int TranslateZoom(int sizeToTranslate){ 
        float zoom = Camera::GetInstance()->GetZoom();
        return sizeToTranslate * zoom; 
    }


private:
    Camera() : m_target(nullptr), m_zoom(4.0f), m_position(0,0) { m_viewbox = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };}
    static Camera* s_instance; 

    SDL_Rect m_viewbox;
    Vector2* m_target;
    Vector2 m_position;
    float m_zoom;
};

#endif // CAMERA_H