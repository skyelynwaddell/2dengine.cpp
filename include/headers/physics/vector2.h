#pragma once
#include <iostream>

#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
    float X, Y;

    //Vector2(float x=0, float y=0)
    Vector2(float x=0, float y=0) : X(x), Y(y) {}

    //Addition +
    inline Vector2 operator+(const Vector2& vec2) const {
        return Vector2(X + vec2.X, Y + vec2.Y);
    }

    //Subtraction -
    inline Vector2 operator-(const Vector2& vec2) const  {
        return Vector2(X - vec2.X, Y - vec2.Y);
    }

    //Multiplication
    inline Vector2 operator*(const float scalar) const {
        return Vector2(X*scalar, Y*scalar);
    }

    //Division
    inline Vector2 operator/(const float scalar) const {
        return Vector2(X/scalar, Y/scalar);
    }

    //Console log to view the vector2
    void Log(std::string msg=""){
        std::cout << msg << "VEC2 - X:" << X << " Y:" << Y << "\n";
    }

private:

protected:
};

#endif // VECTOR2_H