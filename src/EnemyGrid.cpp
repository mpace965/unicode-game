#include "EnemyGrid.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

EnemyGrid::EnemyGrid()
{
    float x = 0.0;
    float y = 0.0;

    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            coords[k][i] = sf::Vector2f(x, y);
            x += 20.0;
        }

        x = 0.0;
        y += 20.0;
    }
}

EnemyGrid::~EnemyGrid()
{
    //dtor
}

void EnemyGrid::add(Enemy e, int x, int y)
{
    e.setPosition(x, y);
    enemies.push_back(e);
}

void EnemyGrid::damageEnemy(int index, int dmg)
{
    enemies[index].damage(dmg);
}

sf::Vector2f EnemyGrid::getCoords(int x, int y)
{
    return coords[x][y];
}

Enemy EnemyGrid::getEnemy(int index)
{
    return enemies[index];
}

int EnemyGrid::getSize()
{
    return enemies.size();
}

void EnemyGrid::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < enemies.size(); i++)
        window.draw(enemies[i].getSprite());
}

void EnemyGrid::Update()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].getHealth() > 0)
            enemies[i].Update();
        else
            enemies.erase(enemies.begin() + i);
    }
}
