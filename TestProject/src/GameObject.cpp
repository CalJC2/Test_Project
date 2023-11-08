//
// Created by cj2-cornelius on 01/11/2023.
//

#include "GameObject.h"

GameObject::GameObject()
{
    sprite = std::make_unique<sf::Sprite>();
}

GameObject::~GameObject()
{

}

bool GameObject::initSprite(sf::Texture &texture, std::string filename)
{
    if(!texture.loadFromFile(filename))
    {
        std::cout << "could not load texture" << filename << std::endl;
        return false;
    }
    sprite->setTexture(texture);
    sprite->setScale(1.0f,1.0f);
    return true;
}

std::unique_ptr<sf::Sprite>& GameObject::getSprite()
{
    return sprite;
}

int GameObject::getSpeed() const
{
    return speed;
}

void GameObject::setSpeed(int speed)
{
    GameObject::speed = speed;
}

const Vector2& GameObject::getDirection() const
{
    return direction;
}

void GameObject::setDirection(const Vector2 &direction)
{
    GameObject::direction = direction;
}