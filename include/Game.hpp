#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Input.hpp"
#include "GameElements.hpp"
#include "Interface.hpp"
#include "ValuesAndTypes.hpp"
#include "Clock.hpp"

class Game{
public:
    static Input input;
    static sf::RenderWindow *window;
    static GameElements gameElements;
    static Interface interface;
    static ValuesAndTypes valuesAndTypes;
    static Clock clock;

    Game(sf::RenderWindow *const renderWindow);
    void tick();

private:
    void draw();
    void update();
};




