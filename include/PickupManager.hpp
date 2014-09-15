#ifndef PICKUPMANAGER_HPP
#define PICKUPMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Pickup.hpp"

class PickupManager
{
    public:
        PickupManager();
        virtual ~PickupManager();

        void add(Pickup p);
        Pickup get(int index);
        void place(int index);
        void reset();
        int size();

        void Draw(sf::RenderWindow& window);

        bool placed = false;
    protected:
    private:
        std::vector< Pickup > pickups;
};

#endif // PICKUPMANAGER_HPP
