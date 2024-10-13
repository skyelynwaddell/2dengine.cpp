#pragma once

#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "imgui.h"
#include "engine.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <iostream>
#include <input.h>
using std::string;

#define TOGGLE_TIME 20

class GUI_Window {
public:
    //I used SDL_SCANCODE_F24 as the key used for windows that dont have a hotkey to open

    GUI_Window(SDL_Scancode toggleKey=SDL_SCANCODE_F24, SDL_Window* window=nullptr, SDL_Renderer* renderer=nullptr){
        m_toggleKey = toggleKey;
        m_shouldClose = false;
        m_toggleTimer = TOGGLE_TIME;

        window = Engine::GetInstance()->GetWindow();
        renderer = Engine::GetInstance()->GetRenderer();

        //create imgui window
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer2_Init(renderer);
    };

    void Destroy(){
        ImGui::DestroyContext();
    }

    void Clean(){
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        Destroy();
    }

    inline void GUI_CreateWindow(string title) {  
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin(title.c_str());
        
    }

    inline void GUI_End(){
        ImGui::End();
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), Engine::GetInstance()->GetRenderer());
    }

    virtual void Draw()=0;
    inline bool shouldClose(){ return m_shouldClose; }
    inline void ToggleOpen(){ m_shouldClose = !m_shouldClose; }

    inline void Input(){

        if (m_toggleKey == SDL_SCANCODE_F24) return;

        if (m_toggleTimer < TOGGLE_TIME) {
            m_toggleTimer++;
            return;
        }

        if (Input::GetInstance()->GetKeyDown(m_toggleKey)){
            if (m_toggleTimer >= TOGGLE_TIME){
		        ToggleOpen();
                m_toggleTimer = 0;
            }
	    }
    }

private:

protected:
    bool m_shouldClose;
    int m_toggleTimer;
    SDL_Scancode m_toggleKey;
};

#endif // GUIWINDOW_H