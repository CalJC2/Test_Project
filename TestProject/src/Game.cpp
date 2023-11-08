//
// Created by cj2-cornelius on 25/10/2023.
//

#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
        : window(game_window), bullet(game_window), player(game_window)
{
    srand(time(NULL));
}
//------------------------------------------------------------------------------
Game::~Game()
{

}
//------------------------------------------------------------------------------
bool Game::init()
{
    if(!backgroundTexture.loadFromFile("Data/Images/tankTileMap.png"))
    {
        std::cout << "background did not load\n";
    }

    cursor.loadFromSystem(sf::Cursor::Cross);
    window.setMouseCursor(cursor);

    background.setTexture(backgroundTexture);
    player.init();
    bullet.init();
    turret.init(player,bullet);



    return true;
}
//------------------------------------------------------------------------------
void Game::update(float dt)
{
    reloadTimer += dt;

    turret.update(player, bullet);
    player.update(dt);
    if(visibility) {
        bullet.move(dt);
    }

    if((0 > bullet.getSprite()->getPosition().x >= window.getSize().x) ||
    (0 > bullet.getSprite()->getPosition().y >= window.getSize().y ))
    {
        visibility = false;
    }


}
//------------------------------------------------------------------------------
void Game::render()
{

    window.draw(background);
    window.draw(*player.getSprite());
    window.draw(*turret.getSprite());
    if(visibility)
    {
        window.draw(*bullet.getSprite());
    }

}
//------------------------------------------------------------------------------
void Game::keyPressed(sf::Event event, float dt)
{
    player.move(event);
}
//------------------------------------------------------------------------------
void Game::keyReleased(sf::Event event, float dt)
{
    player.stop(event);

}
//------------------------------------------------------------------------------
void Game::mouseClicked(sf::Event event)
{
    if(reloadTimer >= 1)
    {
        bullet.setAngle(player);
        reloadTimer = 0;
        visibility = true;
    }

}
//------------------------------------------------------------------------------
void Game::mouseMoved(sf::Event event)
{

}
//------------------------------------------------------------------------------
