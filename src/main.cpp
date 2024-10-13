//main.cpp
#include "engine.h"
#include "timer.h"
#undef main

//MAIN GAME LOOP
int main(int argc, char* argv[]) {

    //Create Event
    Engine::GetInstance()->Create();

    //Game Loop (60fps)
    while(Engine::GetInstance()->IsRunning()){
        Engine::GetInstance()->Input();         //Controls & Inputs
        Engine::GetInstance()->Update();     //Update Event
        Engine::GetInstance()->Draw();          //Draw Event
        Engine::GetInstance()->DrawGUI();       //Draw GUI Event
        Timer::GetInstance()->Tick();
    }

    Engine::GetInstance()->Clean(); //Clean-Up Event
    return 0;
}