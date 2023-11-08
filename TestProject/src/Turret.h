//
// Created by cj2-cornelius on 08/11/2023.
//

#ifndef TESTPROJECT_TURRET_H
#define TESTPROJECT_TURRET_H
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"

class Turret : public GameObject{
public:
    Turret();
    ~Turret();
    void init(Player& playerSprite, Bullet& bulletSprite);
    void update(Player& playerSprite, Bullet& bulletSprite);



private:
    sf::Texture turretTexture;

};


#endif //TESTPROJECT_TURRET_H
