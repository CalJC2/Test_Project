//
// Created by cj2-cornelius on 08/11/2023.
//

#include "Camera.h"

Camera::Camera() {}

Camera::~Camera() {}

void Camera::init()
{
    background.initSprite(backgroundTexture, "Data/Images/tankTileMap.png");
  //  camera.setSize(window.getSize().x, window.getSize().y);
    camera.zoom(0.5f);
}

void Camera::playerCamera(Player& playerSprite)
{
    camera.setCenter(playerSprite.getSprite()->getPosition().x,
                     playerSprite.getSprite()->getPosition().y);

}

void Camera::applyCamera()
{
   // window.draw(*background.getSprite());
    //window.setView(camera);
}
