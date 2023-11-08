//
// Created by cj2-cornelius on 25/10/2023.
//

#ifndef TESTPROJECT_VECTOR2_H
#define TESTPROJECT_VECTOR2_H


struct Vector2
{
    Vector2(float x_, float y_);
    Vector2(const Vector2& rhs);

    Vector2 operator*(float scalar);
    Vector2& operator=(const Vector2& rhs);
    void normalise();

    float x = 0;
    float y = 0;
};


#endif //TESTPROJECT_VECTOR2_H
