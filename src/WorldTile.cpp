#include "WorldTile.hpp"
#include <SFML/Graphics.hpp>
#include "Loader.hpp"
#include "Game.hpp"

WorldTile::WorldTile()
{
    //ctor
}

WorldTile::WorldTile(int type, float x, float y)
{
    sprite.setPosition(x, y);
    setType(type);
}

WorldTile::~WorldTile()
{
    //dtor
}

sf::Sprite WorldTile::getSprite()
{
    return sprite;
}

bool WorldTile::isWalkable()
{
    return walkable;
}

void WorldTile::setType(int type)
{
    switch (type)
    {
        case 0:
            sprite.setTexture(Game::textures[Loader::WALL]);
            walkable = false;
            break;
        case 1:
            switch (rand() % 3)
            {
                case 0:
                    sprite.setTexture(Game::textures[Loader::FLOOR]);
                    break;
                case 1:
                    sprite.setTexture(Game::textures[Loader::FLOOR2]);
                    break;
                case 2:
                    sprite.setTexture(Game::textures[Loader::FLOOR3]);
                    break;
            }

            walkable = true;
            break;
        case 2:
            sprite.setTexture(Game::textures[Loader::DOOR]);
            walkable = false;
            break;
    }
}

void WorldTile::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
