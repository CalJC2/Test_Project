//
// Created by cj2-cornelius on 08/11/2023.
//

#ifndef TESTPROJECT_CAMERA_H
#define TESTPROJECT_CAMERA_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

class Camera {
public:
    Camera();
    ~Camera();
    void init();
    void playerCamera(Player& playerSprite);
    void applyCamera();

private:

    sf::View camera;
    sf::Texture backgroundTexture;
    GameObject background;
};


#endif //TESTPROJECT_CAMERA_H
