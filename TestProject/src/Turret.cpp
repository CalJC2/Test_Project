//
// Created by cj2-cornelius on 08/11/2023.
//

#include "Turret.h"

Turret::Turret() {}

Turret::~Turret() {}

void Turret::init(Player& playerSprite, Bullet& bulletSprite)
{
    initSprite(turretTexture, "Data/Images/Kenny_tanks/Default size/specialBarrel3_outline.png");
    getSprite()->setPosition(playerSprite.getSprite()->getPosition().x/2,
                                    playerSprite.getSprite()->getPosition().y/2);
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width/2,
                                  (getSprite()->getGlobalBounds().height/getSprite()->getGlobalBounds().height) + 6);
    getSprite()->setScale(0.8f, 0.8f);

}

void Turret::update(Player& playerSprite, Bullet& bulletSprite)
{
    getSprite()->setPosition(playerSprite.getSprite()->getPosition().x,
                                    playerSprite.getSprite()->getPosition().y);

    getSprite()->setRotation(bulletSprite.getSprite()->getRotation() - 180);
}