//engine.h
#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 854
#define SCREEN_HEIGHT 480 

class Engine
{
public:
    bool Create();
    bool Clean();
    void Quit();

    void Input();
    void Update();
    void Draw();
    void DrawGUI();
    
    //When we ask for the instance of the engine, it will check if its a null pointer, if it is, it will make a new Engine object, else it will return the existing engine object
    inline static Engine* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new Engine(); }

    inline bool IsRunning(){ return m_isRunning; }
    inline SDL_Renderer* GetRenderer(){ return m_renderer; }
    inline SDL_Window* GetWindow(){ return m_window; }

private:
    Engine(){}
    bool m_isRunning;
    static Engine* s_instance; 

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

};

#endif // ENGINE_H