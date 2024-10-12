#include <thread>
#include <chrono>
#include <windows.h>
#include "delta.h"
#include <SDL_timer.h>
using namespace std;
using namespace chrono;

Delta* Delta::s_Instance = nullptr;

void Delta::Tick()
{
    m_DeltaTime = ((SDL_GetTicks() - m_LastTime) * (TARGET_FPS/1000.0f));

    //cap fps to 1.5ms
    if (m_DeltaTime > TARGET_DELTATIME){
        m_DeltaTime = TARGET_DELTATIME;
    }

    m_LastTime = SDL_GetTicks();
}
