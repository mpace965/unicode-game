#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Loader.hpp"
#include "WorldGrid.hpp"
#include "EnemyGrid.hpp"
#include "Player.hpp"
#include "PickupManager.hpp"

class Game
{
    public:
        Game();
        virtual ~Game();

        void eventHandle(sf::Event event);
        void Draw(sf::RenderWindow& window);
        void Update();

        static Loader loader;
        static std::vector<sf::SoundBuffer> sounds;
        static std::vector<sf::Texture> textures;
        static EnemyGrid enemyGrid;
        static WorldGrid world;
        static PickupManager pickupManager;
        static Player player;
    protected:
    private:
        void dropItems(time_t curTime);

        bool dropReady;
        time_t timer;
        time_t dropTime;
        int nextDrop;
};

#endif // GAME_HPP
