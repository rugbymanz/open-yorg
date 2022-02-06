#define CATCH_CONFIG_MAIN

//it is needed to include sstream before define private 
#include <sstream> 

#define private public

#include <SFML/Window/Event.hpp>

#include "catch.hpp"

#include "Input.hpp"
#include "Game.hpp"
#include "Field/EmptyFieldCell.hpp"

using namespace std;
using namespace sf;



TEST_CASE("main") {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "open yorg");
    Game game(&window);

    for (auto row = game.gameElements.field.field.begin(); row < game.gameElements.field.field.end(); row++)
        for (auto col = row->begin(); col < row->end(); col++)
            *col = new EmptyFieldCell({int(row - game.gameElements.field.field.begin()), int(col - row->begin() )});
    
    REQUIRE(ValuesAndTypes::noneFieldCell.x == -1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            game.input.process(event);

        window.clear(sf::Color::White);
        Game::gameElements.field.draw();
        window.display();
    }

}