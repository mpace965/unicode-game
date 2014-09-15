#ifndef WORLDGRID_HPP
#define WORLDGRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "WorldTile.hpp"

class WorldGrid
{
    public:
        WorldGrid();
        WorldGrid(int w[900]);
        virtual ~WorldGrid();

        WorldTile getTile(int x, int y);
        void setGrid(int w[900]);
        void Draw(sf::RenderWindow& window);
    protected:
    private:
        WorldTile world[900];
};

#endif // WORLDGRID_HPP
