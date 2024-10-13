#pragma once
#include <SDL_scancode.h>

#ifndef INPUT_H
#define INPUT_H

//keybinding for the game
struct Buttons {
    SDL_Scancode up    = SDL_SCANCODE_UP;
    SDL_Scancode down  = SDL_SCANCODE_DOWN;
    SDL_Scancode left  = SDL_SCANCODE_LEFT;
    SDL_Scancode right = SDL_SCANCODE_RIGHT;
};

class Input {
public:
    inline static Input* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new Input(); }

    void Listen();
    bool GetKeyDown(SDL_Scancode key);

    Buttons btn;

private:
    Input();
    void KeyUp();
    void KeyDown();

    const Uint8* m_keystates;
    static Input* s_instance;
protected:
};

#endif // INPUT_H