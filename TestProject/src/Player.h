//
// Created by cj2-cornelius on 25/10/2023.
//

#ifndef TESTPROJECT_PLAYER_H
#define TESTPROJECT_PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"
#include "GameObject.h"


class Player  : public GameObject{
public:
    Player(sf::RenderWindow& window);
    ~Player();
    void init();
    void update(float dt);
    void move(sf::Event& event);
    void stop(sf::Event& event);
    void turning();
    void leftTurn();
    void rightTurn();
    void shoot();

private:
    sf::Texture playerTexture;
    sf::RenderWindow& window;

    bool turningRight = false;
    bool turningLeft = false;
    bool forward = false;
    bool backward = false;
    float angle[16] = {22.5, 45.0, 67.5, 90.0, 112.5, 135.0,157.5, 180.0, 202.5, 225.0, 247.5, 270.0, 292.5, 315.0, 337.5, 0.0};

};


#endif //TESTPROJECT_PLAYER_H
