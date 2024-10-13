#pragma once

#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    void Tick();
    inline float GetDeltaTime() { return m_deltaTime; } 
    inline static Timer* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new Timer(); }

private:
    Timer(){};
    static Timer* s_instance;
    float m_deltaTime;
    float m_lastTime;


protected:
};
#undef Time
#endif // TIME_H