#include "input.h"
#include <SDL_events.h>
#include <SDL.h>
#include "engine.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

Input::Input()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
}

//Listens for key, controller, and mouse events
void Input::Listen()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT: Engine::GetInstance()->Quit(); break;
            case SDL_KEYDOWN: KeyDown(); break;
            case SDL_KEYUP: KeyUp(); default: break;
        }

        //get imgui inputs
        ImGui_ImplSDL2_ProcessEvent(&e);
    }
}

void Input::KeyUp()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
}

bool Input::GetKeyDown(SDL_Scancode key)
{
    return m_keystates[key] == 1 ? true : false;
}
