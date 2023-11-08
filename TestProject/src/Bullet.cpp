//
// Created by cj2-cornelius on 08/11/2023.
//

#include "Bullet.h"


Bullet::Bullet(sf::RenderWindow& window) : window(window){}

Bullet::~Bullet() {}

void Bullet::init()
{
    initSprite(bulletTexture, "Data/Images/Kenny_tanks/Default size/bulletBlue1.png");
    getSprite()->setScale(1.5f,1.5f);
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width/getSprite()->getGlobalBounds().width,
                           getSprite()->getGlobalBounds().height);
    getSprite()->setPosition(-10,-10);
    setSpeed(50);
    getSprite()->setRotation(0);
}

void Bullet::update(float dt)
{

}

void Bullet::move(float dt)
{
    getSprite()->move(-getDirection().x * getSpeed() * dt,
                      -getDirection().y * getSpeed() * dt);
}

void Bullet::setAngle(Player& playerSprite)
{

    sf::Vector2<int> click = sf::Mouse::getPosition(window);


    getSprite()->setPosition(playerSprite.getSprite()->getPosition().x,
                             playerSprite.getSprite()->getPosition().y);

    //click relative to player
    shootingX = playerSprite.getSprite()->getPosition().x - click.x;
    shootingY = playerSprite.getSprite()->getPosition().y - click.y;

    x = shootingX/10;
    y = shootingY/10;

    rotation = atan2(y,x) * (180/PI);

    setDirection(Vector2(x,y));
    getSprite()->setRotation(rotation - 90);
}




