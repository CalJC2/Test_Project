//
// Created by cj2-cornelius on 25/10/2023.
//

#ifndef TESTPROJECT_GAME_H
#define TESTPROJECT_GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Turret.h"
#include "Bullet.h"
#include "Camera.h"
#define PI 3.14159265



class Game {
public:
    Game(sf::RenderWindow& window);
    ~Game();
    bool init();
    void update(float dt);
    void render();
    void mouseClicked(sf::Event event);
    void mouseMoved(sf::Event event);
    void keyPressed(sf::Event event, float dt);
    void keyReleased(sf::Event event, float dt);


private:
    sf::RenderWindow& window;
    sf::Cursor cursor;

    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture turretTexture;
    float reloadTimer = 3;
    bool visibility;

    float angle[16] = {22.5, 45.0, 67.5, 90.0, 112.5, 135.0,157.5, 180.0, 202.5, 225.0, 247.5, 270.0, 292.5, 315.0, 337.5, 0.0};
    //45,90,135,180,225,270,315,0

    /*Player player;
    Player bullet;
    Player turret;*/


    Camera camera;
    Player player;

    Bullet bullet;
    Turret turret;
};


#endif //TESTPROJECT_GAME_H
