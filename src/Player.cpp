#include "Player.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Loader.hpp"
#include "Enemy.hpp"

Player::Player()
{
    sprite.setPosition(Game::enemyGrid.getCoords(10, 12));
    x = 10;
    y = 12;
    sprite.setTexture(Game::textures[Loader::PLYR]);

    health = 75;
    attackMod = 0;
    defMod = 0;
    moved = false;
}

Player::Player(int ix, int iy)
{
    sprite.setPosition(Game::enemyGrid.getCoords(ix, iy).x, Game::enemyGrid.getCoords(ix, iy).y);
    x = ix;
    y = iy;
    sprite.setTexture(Game::textures[Loader::PLYR]);

    health = 75;
    attackMod = 0;
    defMod = 0;
    moved = false;
}

Player::~Player()
{
    //dtor
}

void Player::attack()
{
    for (int i = 0; i < Game::enemyGrid.getSize(); i++)
    {
        Enemy e = Game::enemyGrid.getEnemy(i);

        if (abs(e.x - x) <= 1 && abs(e.y - y) <= 1)
        {
            hitSound();
            Game::enemyGrid.damageEnemy(i, rand() % 4 + 1 + attackMod);
            break;
        }
    }
}

void Player::addHealth(int amt)
{
    health += amt;
    sprite.setColor(sf::Color(sprite.getColor().r + 10, sprite.getColor().g - 10, sprite.getColor().b - 10));
}

void Player::collect(int direction)
{
    switch (direction)
    {
        case 0:
            if (y - 1 == Game::pickupManager.get(0).y && x == Game::pickupManager.get(0).x)
            {
                sound.setBuffer(Game::sounds[Loader::POWERUP]);
                sound.play();
                Game::pickupManager.get(0).effect();
                Game::pickupManager.reset();
            }
            break;
        case 1:
            if (y + 1 == Game::pickupManager.get(0).y && x == Game::pickupManager.get(0).x)
            {
                sound.setBuffer(Game::sounds[Loader::POWERUP]);
                sound.play();
                Game::pickupManager.get(0).effect();
                Game::pickupManager.reset();
            }
            break;
        case 2:
            if (x - 1 == Game::pickupManager.get(0).x && y == Game::pickupManager.get(0).y)
            {
                sound.setBuffer(Game::sounds[Loader::POWERUP]);
                sound.play();
                Game::pickupManager.get(0).effect();
                Game::pickupManager.reset();
            }
            break;
        case 3:
            if (x + 1 == Game::pickupManager.get(0).x && y == Game::pickupManager.get(0).y)
            {
                sound.setBuffer(Game::sounds[Loader::POWERUP]);
                sound.play();
                Game::pickupManager.get(0).effect();
                Game::pickupManager.reset();
            }
            break;
    }
}

void Player::damage(int dmg)
{
    health -= (dmg - defMod);
    sprite.setColor(sf::Color(sprite.getColor().r - 5, sprite.getColor().g - 5, sprite.getColor().b - 5));
}

void Player::eventHandle(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            go(0);
            moved = true;
        }

        if (event.key.code == sf::Keyboard::Down)
        {
            go(1);
            moved = true;
        }

        if (event.key.code == sf::Keyboard::Left)
        {
            go(2);
            moved = true;
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            go(3);
            moved = true;
        }

        if (event.key.code == sf::Keyboard::Space)
        {
            attack();
            moved = true;
        }
    }
}

void Player::hitSound()
{
    sound.setBuffer(Game::sounds[rand() % 3]);
    sound.play();
}

int Player::getHealth()
{
    return health;
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

void Player::go(int direction)
{
   std::vector<int> closeEnemies;

    for (int i = 0; i < Game::enemyGrid.getSize(); i++)
    {
        Enemy e = Game::enemyGrid.getEnemy(i);

        if (abs(e.x - x) <= 1 && abs(e.y - y) <= 1)
            closeEnemies.push_back(i);
    }

    switch (direction)
    {
        //Up
        case 0:
            if (Game::world.getTile(x, y - 1).isWalkable() && !matchCoords(closeEnemies, x, y - 1))
            {
                setPosition(x, y - 1);
                collect(0);
                y -= 1;
            }
            break;

        //Down
        case 1:
            if (Game::world.getTile(x, y + 1).isWalkable() && !matchCoords(closeEnemies, x, y + 1))
            {
                setPosition(x, y + 1);
                collect(1);
                y += 1;
            }
            break;

        //Left
        case 2:
            if (Game::world.getTile(x - 1, y).isWalkable() && !matchCoords(closeEnemies, x - 1, y))
            {
                setPosition(x - 1, y);
                collect(2);
                x -= 1;
            }
            break;

        //Right
        case 3:
            if (Game::world.getTile(x + 1, y).isWalkable() && !matchCoords(closeEnemies, x + 1, y))
            {
                setPosition(x + 1, y);
                collect(3);
                x += 1;
            }
            break;
    }
}

bool Player::matchCoords(std::vector<int> enemyList, int ix, int iy)
{
    for (int i = 0; i < enemyList.size(); i++)
    {
        Enemy e = Game::enemyGrid.getEnemy(enemyList[i]);

        if (e.x == ix && e.y == iy)
        {
            return true;
            break;
        }
    }

    return false;
}

void Player::setPosition(int ix, int iy)
{
    sprite.setPosition(Game::enemyGrid.getCoords(ix, iy).x, Game::enemyGrid.getCoords(ix, iy).y);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
