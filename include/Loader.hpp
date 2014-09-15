#ifndef LOADER_HPP
#define LOADER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Loader
{
    public:
        Loader();
        virtual ~Loader();

        std::vector<sf::SoundBuffer> getSounds();

        //Sound List
        static const int HIT = 0;
        static const int HIT2 = 1;
        static const int HIT3 = 2;
        static const int PHIT = 3;
        static const int PHIT2 = 4;
        static const int PHIT3 = 5;
        static const int POWERUP = 6;

        std::vector<sf::Texture> getTextures();

        //Row 1
        static const int WALL = 0;
        static const int FLOOR = 1;
        static const int DOOR = 2;
        static const int EYE = 3;
        static const int GOB = 4;
        static const int OGRE = 5;
        static const int SPEC = 6;
        static const int SHLD = 7;
        static const int SWRD = 8;
        static const int PLYR = 9;
        static const int FLOOR2 = 10;
        static const int FLOOR3 = 11;
        static const int HEART = 12;
    protected:
    private:
        std::vector<sf::SoundBuffer> sndVec;
        std::vector<sf::Texture> texVec;
};

#endif // LOADER_HPP
