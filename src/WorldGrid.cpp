#include "WorldGrid.hpp"
#include <SFML/Graphics.hpp>
#include "WorldTile.hpp"

using namespace std;
using namespace sf;

WorldGrid::WorldGrid()
{

}

WorldGrid::WorldGrid(int w[900])
{
    setGrid(w);
}

WorldGrid::~WorldGrid()
{
    //dtor
}

WorldTile WorldGrid::getTile(int x, int y)
{
    return world[y * 30 + x]; //Okay..?
}

void WorldGrid::setGrid(int w[900])
{
    float x = 0.0;
    float y = 0.0;

    for (int i = 0; i < 900; i++)
    {
        WorldTile add(w[i], x, y);
        world[i] = add;

        if (x == 580.0)
        {
            y += 20.0;
            x = 0.0;
        }
        else
        {
            x += 20.0;
        }
    }
}

void WorldGrid::Draw(RenderWindow& window)
{
    for (int i = 0; i < 900; i++)
        window.draw(world[i].getSprite());
}
