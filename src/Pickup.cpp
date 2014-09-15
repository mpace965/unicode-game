#include "Pickup.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Loader.hpp"

Pickup::Pickup()
{
    //ctor
}

Pickup::Pickup(int iType, int ix, int iy)
{
    x = ix;
    y = iy;

    sprite.setPosition(Game::enemyGrid.getCoords(ix, iy));

    switch (iType)
    {
        case 0:
            sprite.setTexture(Game::textures[Loader::SHLD]);
            typeOfSprite = Loader::SHLD;
            break;
        case 1:
            sprite.setTexture(Game::textures[Loader::SWRD]);
            typeOfSprite = Loader::SWRD;
            break;
        case 2:
            sprite.setTexture(Game::textures[Loader::HEART]);
            typeOfSprite = Loader::HEART;
            break;
    }
}

Pickup::~Pickup()
{
    //dtor
}

void Pickup::effect()
{
    switch (typeOfSprite)
    {
        case Loader::SHLD:
            Game::player.defMod += 2;
            break;
        case Loader::SWRD:
            Game::player.attackMod += 2;
            break;
        case Loader::HEART:
            Game::player.addHealth(rand() % 7 + 1);
            break;
    }
}

sf::Sprite Pickup::getSprite()
{
    return sprite;
}

void Pickup::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
