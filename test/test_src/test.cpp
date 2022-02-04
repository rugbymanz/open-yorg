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
    {
        for (auto col = row->begin(); col < row->end(); col++)
        {
            *col = new EmptyFieldCell;
            (*col)->setCoord({int(row - game.gameElements.field.field.begin()), int(col - row->begin() )});
        }
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::EventType::MouseWheelScrolled)
                game.input.processMouseWheelScroll(event.mouseWheelScroll);

            if(event.type == sf::Event::EventType::KeyPressed)
                game.input.processKeys(event.key);

            if(event.type == sf::Event::EventType::MouseButtonReleased)
                if(event.mouseButton.button == Mouse::Button::Left)
                    game.input.processMouseLeftClick({event.mouseButton.x, event.mouseButton.y});
        }

        window.clear(sf::Color::White);
        Game::gameElements.field.draw();
        window.display();
    }

}