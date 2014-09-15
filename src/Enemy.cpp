#include "Enemy.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Loader.hpp"

Enemy::Enemy()
{
    alerted = false;
}

Enemy::Enemy(int type, int h)
{
    setType(type);
    health = h;
    alerted = false;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::attack()
{
    if (abs(Game::player.x - x) <= 1 && abs(Game::player.y - y) <= 1)
    {
        hitSound();
        Game::player.damage(rand() % 2 + 1);
    }
}

bool Enemy::checkWallX(int x1, int x2)
{
    bool wallInWay = false;
    int range = abs(x1 - x2);

    for (int i = 0; i < range; i++)
    {

    }

    return wallInWay;
}

void Enemy::damage(int dmg)
{
    health -= dmg;
    sprite.setColor(sf::Color(sprite.getColor().r - 25, sprite.getColor().g - 25, sprite.getColor().b - 25));
}

int Enemy::getHealth()
{
    return health;
}

sf::Sprite Enemy::getSprite()
{
    return sprite;
}

void Enemy::hitSound()
{
    sound.setBuffer(Game::sounds[rand() % 3 + 3]);
    sound.play();
}

void Enemy::idle()
{
    int direction = rand() % 5;

    switch (direction)
    {
        case 0:
            if (x + 1 != Game::player.x && Game::world.getTile(x + 1, y).isWalkable()) setPosition(x + 1, y); //Idle rightward
            break;
        case 1:
            if (x - 1 != Game::player.x && Game::world.getTile(x - 1, y).isWalkable()) setPosition(x - 1, y); //Idle leftward
            break;
        case 2:
            if (y + 1 != Game::player.y && Game::world.getTile(x, y + 1).isWalkable()) setPosition(x, y + 1);
            break;
        case 3:
            if (y - 1 != Game::player.y && Game::world.getTile(x, y - 1).isWalkable()) setPosition(x, y - 1);
            break;
    }
}

void Enemy::moveX(bool overrd)
{
    if (Game::player.x - x > 0 && x + 1 != Game::player.x && Game::world.getTile(x + 1, y).isWalkable() && !overrd) //Move right to get closer
        setPosition(x + 1, y);
    else if (Game::player.x - x > 0 && !Game::world.getTile(x + 1, y).isWalkable()) //There's a wall to your right
        moveY(true); //So try to move vertically
    else if (Game::player.x - x < 0 && x - 1 != Game::player.x && Game::world.getTile(x - 1, y).isWalkable() && !overrd) //Move left to get closer
        setPosition(x - 1, y);
    else if (Game::player.x - x < 0 && !Game::world.getTile(x - 1, y).isWalkable()) //There's a wall to your left
        moveY(true); //So try to move vertically

    if (overrd) //Houston, we have a problem (wall above or below)
    {
        if (Game::player.x - x > 0 && Game::world.getTile(x + 1, y).isWalkable())
            setPosition(x + 1, y);
        else if (Game::player.x - x < 0 && Game::world.getTile(x - 1, y).isWalkable())
            setPosition(x - 1, y);
    }
}

void Enemy::moveY(bool overrd)
{
    if (Game::player.y - y > 0 && y + 1 != Game::player.y && Game::world.getTile(x, y + 1).isWalkable() && !overrd) //Move down to get closer
        setPosition(x, y + 1);
    else if (Game::player.y - y > 0 && !Game::world.getTile(x, y + 1).isWalkable()) //There's a wall below you
        moveX(true); //So try to move horizontally
    else if (Game::player.y - y < 0 && y - 1 != Game::player.y && Game::world.getTile(x, y - 1).isWalkable() && !overrd) //Move up to get closer
        setPosition(x, y - 1);
    else if (Game::player.y - y < 0 && !Game::world.getTile(x, y - 1).isWalkable()) //There's a wall above you
        moveX(true); //So try to move horizontally

    if (overrd) //Houston, we have a problem (wall left or right)
    {
        if (Game::player.y - y > 0 && Game::world.getTile(x, y + 1).isWalkable())
            setPosition(x, y + 1);
        else if (Game::player.y - y < 0 && Game::world.getTile(x, y - 1).isWalkable())
            setPosition(x, y - 1);
    }
}

void Enemy::seekPlayer()
{
    int xDist = std::abs(Game::player.x - x);
    int yDist = std::abs(Game::player.y - y);

    //Further away on x axis than y, move closer x
    if (xDist > yDist)
        moveX(false);
    else if (yDist > xDist) //Further away on y axis than x, move closer y
        moveY(false);
    else if (xDist == yDist)
        if (rand() % 10 < 5)
            moveX(false);
        else
            moveY(false);
}

void Enemy::setType(int type)
{
    switch (type)
    {
        case 0:
            sprite.setTexture(Game::textures[Loader::EYE]);
            break;
        case 1:
            sprite.setTexture(Game::textures[Loader::GOB]);
            break;
        case 2:
            sprite.setTexture(Game::textures[Loader::OGRE]);
            break;
        case 3:
            sprite.setTexture(Game::textures[Loader::SPEC]);
            break;
    }
}

void Enemy::setPosition(int ix, int iy)
{
    x = ix;
    y = iy;

    sprite.setPosition(Game::enemyGrid.getCoords(ix, iy).x, Game::enemyGrid.getCoords(ix, iy).y);
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Enemy::Update()
{
    if (Game::player.moved)
    {
        if (!alerted)
        {

        }


        if (alerted)
        {
            seekPlayer();
            attack();
        }
        else
            idle();
    }

    if (Game::player.getHealth() <= 0)
        alerted = false;
}
