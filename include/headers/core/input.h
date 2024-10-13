#pragma once
#include <SDL_scancode.h>

#ifndef INPUT_H
#define INPUT_H

class Input {
public:
    inline static Input* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new Input(); }

    void Listen();
    bool GetKeyDown(SDL_Scancode key);

private:
    Input();
    void KeyUp();
    void KeyDown();

    const Uint8* m_keystates;
    static Input* s_instance;
protected:
};

#endif // INPUT_H