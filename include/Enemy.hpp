#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Enemy
{
    public:
        Enemy();
        Enemy(int type, int h);
        virtual ~Enemy();

        void damage(int dmg);
        int getHealth();
        void hitSound();
        sf::Sprite getSprite();
        void setType(int type);
        void setPosition(int ix, int iy);

        void Draw(sf::RenderWindow& window);
        void Update();

        int x, y;
    protected:
    private:
        void attack();
        void idle();
        void moveY(bool overrd);
        void moveX(bool overrd);
        void seekPlayer();

        sf::Sprite sprite;
        sf::Sound sound;
        int health;
        bool alerted;
};

#endif // ENEMY_HPP
