#pragma once
#include "vector2.h"

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform {
public:
    float X, Y;
    Transform(float x=0, float y=0) : X(x), Y(y) {};
    inline void TranslateX(float x){ X += x; }
    inline void TranslateY(float y){ Y += y; }

    void Log(){ std::cout << "TRANSFORM - X:" << X << " Y:" << Y << "\n"; }

private:

    inline void Translate(Vector2 vec2){ X += vec2.X; Y += vec2.Y; }
    inline void SetX(float x) { X = x; }
    inline void SetY(float y) { Y = y; }

protected:
};

#endif // TRANSFORM_H