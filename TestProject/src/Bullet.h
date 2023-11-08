//
// Created by cj2-cornelius on 08/11/2023.
//

#ifndef TESTPROJECT_BULLET_H
#define TESTPROJECT_BULLET_H
#include "GameObject.h"
#include "Player.h"
#include <cmath>
#define PI 3.14159265


class Bullet : public GameObject{
public:
    Bullet(sf::RenderWindow& window);
    ~Bullet();
    void init();
    void update(float dt);
    void move(float dt);
    void setAngle(Player& playerSprite);


private:
    sf::RenderWindow& window;
    sf::Texture bulletTexture;
    float x;
    float y;
    float shootingX;
    float shootingY;
    float rotation;

    float magnitude;


};


#endif //TESTPROJECT_BULLET_H
