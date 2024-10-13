#include "timer.h" 
#include "SDL.h" 

Timer* Timer::s_instance = nullptr;

void Timer::Tick(){
	const int TARGET_FPS = 60;
	const float TARGET_DELTA = 1.5f;
	const float MILLISECOND = 1000.0f;

	m_deltaTime = m_deltaTime > TARGET_DELTA ? TARGET_DELTA : (SDL_GetTicks() - m_lastTime) * (TARGET_FPS / MILLISECOND);
	m_lastTime = SDL_GetTicks();
}