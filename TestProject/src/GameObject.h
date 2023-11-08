//
// Created by cj2-cornelius on 01/11/2023.
//

#ifndef TESTPROJECT_GAMEOBJECT_H
#define TESTPROJECT_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class GameObject {
public:
    GameObject();
    ~GameObject();
    bool initSprite(sf::Texture& texture, std::string filename);
    std::unique_ptr<sf::Sprite>& getSprite();
    int getSpeed() const;
    void setSpeed(int speed);
    const Vector2& getDirection() const;
    void setDirection(const Vector2& direction);


private:
    std::unique_ptr<sf::Sprite> sprite;
    int speed = 0;
    Vector2 direction = {0, 0};


};


#endif //TESTPROJECT_GAMEOBJECT_H
