#pragma once

#if !defined(DELTA_H)
#define DELTA_H

const int TARGET_FPS = 60; //target frames per second
const float TARGET_DELTATIME = 1.5f; //1.5 ms

class Delta
{
private:
    Delta(){}
    static Delta* s_Instance; // static instance
    float m_DeltaTime;
    float m_LastTime;

public:
    void Tick();
    inline static Delta* GetInstance(){ return s_Instance = (s_Instance != nullptr)? s_Instance : new Delta(); }
    inline float GetDeltaTime(){ return m_DeltaTime; }
    ~Delta(){}
};

#endif // DELTA_H

