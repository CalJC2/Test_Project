//
// Created by cj2-cornelius on 25/10/2023.
//

#include "Player.h"

Player::Player(sf::RenderWindow& window) : window(window)
{

}

Player::~Player()
{

}

void Player::init()
{
    initSprite(playerTexture,"Data/Images/Kenny_tanks/Default size/tankBody_blue.png");
    getSprite()->setPosition(window.getSize().x/2 - getSprite()->getGlobalBounds().width/2,
                             window.getSize().y/2 - getSprite()->getGlobalBounds().height/2);
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width/2,
                           getSprite()->getGlobalBounds().height/2);
    setDirection(Vector2(0.0f, -1.0f));
    getSprite()->setScale(0.6f,0.6f);
    setSpeed(50);
    getSprite()->setRotation(0.0f);
}

void Player::update(float dt)
{
    if(!turningRight && !turningLeft)
    {
        if(forward)
        {
            getSprite()->move(getDirection().x * getSpeed() * dt,
                              getDirection().y * getSpeed() * dt);
        }
        if(backward)
        {
            getSprite()->move(-getDirection().x * getSpeed() * dt,
                              -getDirection().y * getSpeed() * dt);
        }
    }

    while(turningRight)
    {
        getSprite()->rotate(4.5f);
        turning();
    }
    while(turningLeft)
    {
        getSprite()->rotate(-4.5f);
        turning();
    }
}

void Player::move(sf::Event& event)
{
    if(event.key.code == sf::Keyboard::D)
    {
        rightTurn();
        turningRight = true;
    }
    if(event.key.code == sf::Keyboard::A)
    {
        leftTurn();
        turningLeft = true;
    }
    if(event.key.code == sf::Keyboard::W)
    {
        forward = true;
    }
    if(event.key.code == sf::Keyboard::S)
    {
        backward = true;
    }
}

void Player::stop(sf::Event& event)
{
    if(event.key.code == sf::Keyboard::W)
    {
        forward = false;
    }
    if(event.key.code == sf::Keyboard::S)
    {
        backward = false;
    }
}

void Player::turning()
{
    for(int i = 0; i < 16; i++)
    {
        if(turningLeft || turningRight)
        {
            if(getSprite()->getRotation() == angle[i])
            {
                turningRight = false;
                turningLeft = false;
            }
        }
    }
}

void Player::leftTurn()
{
    if ((getDirection().x == 1) && (getDirection().y == -1))
    {
        if(getSprite()->getRotation() != 45)
        {
            getSprite()->setRotation(45);
        }
        setDirection(Vector2(getDirection().x - 0.5, -1));

    }
    else if ((getDirection().x == 1) && (getDirection().y == 1))
    {
        if(getSprite()->getRotation() != 135)
        {
            getSprite()->setRotation(135);
        }
        setDirection(Vector2(1, getDirection().y - 0.5));

    }
    else if((getDirection().x == -1) && (getDirection().y == 1))
    {
        if(getSprite()->getRotation() != 225)
        {
            getSprite()->setRotation(225);
        }
        setDirection(Vector2(getDirection().x + 0.5, 1));

    }
    else if((getDirection().x == -1) && (getDirection().y == -1))
    {
        if(getSprite()->getRotation() != 315)
        {
            getSprite()->setRotation(315);
        }
        setDirection(Vector2(-1, getDirection().y + 0.5));
    }
    else if((-1 <= getDirection().x <= 1) && (getDirection().y == -1))
    {
        setDirection(Vector2(getDirection().x - 0.5, -1.0));
    }
    else if((-1 <= getDirection().x <= 1) && (getDirection().y == 1))
    {
        setDirection(Vector2(getDirection().x + 0.5, 1));
    }
    else if((-1 <= getDirection().y <= 1) && (getDirection().x == -1))
    {
        setDirection(Vector2(-1.0, getDirection().y + 0.5));
    }
    else if((-1 <= getDirection().y <= 1) && (getDirection().x == 1))
    {
        setDirection(Vector2(1.0, getDirection().y - 0.5));
    }
}

void Player::rightTurn()
{
    if ((getDirection().x == 1) && (getDirection().y == -1))
    {
        if(getSprite()->getRotation() != 45)
        {
            getSprite()->setRotation(45);
        }
        setDirection(Vector2(1, getDirection().y + 0.5));
    }
    else if ((getDirection().x == 1) && (getDirection().y == 1))
    {
        if(getSprite()->getRotation() != 135)
        {
            getSprite()->setRotation(135);
        }
        setDirection(Vector2(getDirection().x - 0.5, 1));

    }
    else if((getDirection().x == -1) && (getDirection().y == 1))
    {
        if(getSprite()->getRotation() != 225)
        {
            getSprite()->setRotation(225);
        }
        setDirection(Vector2(-1, getDirection().y - 0.5));

    }
    else if((getDirection().x == -1) && (getDirection().y == -1))
    {
        if(getSprite()->getRotation() != 315)
        {
            getSprite()->setRotation(315);
        }
        setDirection(Vector2(getDirection().x + 0.5, -1));
    }
    else if((-1 <= getDirection().x <= 1) && (getDirection().y == -1))
    {
        setDirection(Vector2(getDirection().x + 0.5, -1.0));
    }
    else if((-1 <= getDirection().x <= 1) && (getDirection().y == 1))
    {
        setDirection(Vector2(getDirection().x - 0.5, 1));
    }
    else if((-1 <= getDirection().y <= 1) && (getDirection().x == -1))
    {
        setDirection(Vector2(-1.0, getDirection().y - 0.5));
    }
    else if((-1 <= getDirection().y <= 1) && (getDirection().x == 1))
    {
        setDirection(Vector2(1.0, getDirection().y + 0.5));
    }

}

void Player::shoot() {}