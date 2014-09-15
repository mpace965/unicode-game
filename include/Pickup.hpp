#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics.hpp>

class Pickup
{
    public:
        Pickup();
        Pickup(int iType, int ix, int iy);
        virtual ~Pickup();

        void effect();
        sf::Sprite getSprite();
        void Draw(sf::RenderWindow& window);

        int x, y;
    protected:
    private:
        int typeOfSprite;
        sf::Sprite sprite;
};

#endif // PICKUP_HPP
