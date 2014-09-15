#ifndef WORLDTILE_HPP
#define WORLDTILE_HPP

#include <SFML/Graphics.hpp>

class WorldTile
{
    public:
        WorldTile();
        WorldTile(int type, float x, float y);
        virtual ~WorldTile();

        sf::Sprite getSprite();
        bool isWalkable();
        void setType(int type);
        void Draw(sf::RenderWindow& window);
    protected:
    private:
        sf::Sprite sprite;
        bool walkable;
};

#endif // WORLDTILE_HPP
