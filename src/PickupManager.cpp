#include "PickupManager.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pickup.hpp"

PickupManager::PickupManager()
{
    //ctor
}

PickupManager::~PickupManager()
{
    //dtor
}

void PickupManager::add(Pickup p)
{
    pickups.push_back(p);
}

Pickup PickupManager::get(int index)
{
    return pickups[index];
}

void PickupManager::place(int index)
{
    placed = true;
}

void PickupManager::reset()
{
    pickups.clear();

    placed = false;
}

int PickupManager::size()
{
    return pickups.size();
}

void PickupManager::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < pickups.size(); i++)
        pickups[i].Draw(window);
}
