#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(600, 600), "UnicodeGame");

    Game game;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            game.eventHandle(event);
        }

        window.clear();
        game.Update();
        game.Draw(window);
        window.display();
    }

    return 0;
}
