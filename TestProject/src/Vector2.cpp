//
// Created by cj2-cornelius on 25/10/2023.
//

#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {}

Vector2::Vector2(const Vector2& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;

}

Vector2& Vector2::operator=(const Vector2& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;

    return *this;
}

void Vector2::normalise()
{
    float magnitude = std::sqrt((x * x) + (y * y));

    if (!magnitude)
        return;

    x /= magnitude;
    y /= magnitude;
}

Vector2 Vector2::operator*(float scalar)
{
    Vector2 vec(*this);
    vec.x *= scalar;
    vec.y *= scalar;
    return vec;
}
