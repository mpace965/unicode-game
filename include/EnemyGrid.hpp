#ifndef ENEMYGRID_HPP
#define ENEMYGRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class EnemyGrid
{
    public:
        EnemyGrid();
        virtual ~EnemyGrid();

        void add(Enemy e, int x, int y);
        void damageEnemy(int index, int dmg);
        sf::Vector2f getCoords(int x, int y);
        Enemy getEnemy(int index);
        int getSize();

        void Draw(sf::RenderWindow& window);
        void Update();
    protected:
    private:
        sf::Vector2f coords[30][30];
        std::vector< Enemy > enemies;
};

#endif // ENEMYGRID_HPP
