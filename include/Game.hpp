#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Input.hpp"
#include "GameElements.hpp"
#include "Interface.hpp"
#include "ValuesAndTypes.hpp"
#include "Clock.hpp"

class Game{
public:
    Input input;
    static sf::RenderWindow *window;
    GameElements gameElements;
    Interface interface;
    Clock clock;

    Game(sf::RenderWindow *const renderWindow);
    void tick();

private:
    void draw();
    void update();
};




