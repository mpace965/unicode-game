#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player
{
    public:
        Player();
        Player(int ix, int iy);
        virtual ~Player();

        void attack();
        void addHealth(int amt);
        void collect(int direction);
        void damage(int dmg);
        void eventHandle(sf::Event event);
        void hitSound();
        int getHealth();
        sf::Sprite getSprite();
        void setPosition(int ix, int iy);

        void Draw(sf::RenderWindow& window);

        int x, y;
        int attackMod, defMod;
        bool moved;
    protected:
    private:
        void go(int direction);
        bool matchCoords(std::vector<int> enemyList, int ix, int iy);

        int health;
        sf::Sprite sprite;
        sf::Sound sound;
};

#endif // PLAYER_HPP
