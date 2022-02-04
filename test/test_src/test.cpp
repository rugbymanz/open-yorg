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



TEST_CASE("main") {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "open yorg");
    Game game(&window);

    for (auto row = game.gameElements.field.field.begin(); row < game.gameElements.field.field.end(); row++)
    {
        for (auto col = row->begin(); col < row->end(); col++)
        {
            *col = new EmptyFieldCell;
            (*col)->setCoord({int(row - game.gameElements.field.field.begin()), int(col - row->begin() )});
            // sf::Vector2f coord = (*col)->getPosition();
            // cout << coord.x << ' ' << coord.y << endl;
        }
    }

    for(int i = 0; i < ValuesAndTypes::Field::fieldLength; i++){
        for(int j = 0; j < ValuesAndTypes::Field::fieldWidth; j++){
            FieldCoord fieldCell(i, j);

                REQUIRE(game.input.isValidBuildingPosition(fieldCell) == true);


                REQUIRE(game.gameElements.field.get(fieldCell).isEmpty == true);
        }
    }

    for (auto row = game.gameElements.field.field.begin(); row < game.gameElements.field.field.end(); row++)
    {
        for (auto col = row->begin(); col < row->end(); col++)
        {
            FieldCoord fieldCoord = (*col)->getCoord();

            REQUIRE(fieldCoord == FieldCoord(int(row - game.gameElements.field.field.begin()), int(col - row->begin() )));
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
                game.input.processMouseWheelScroll(event);

            if(event.type == sf::Event::EventType::KeyPressed)
                game.input.processArrows(event);
        }

        window.clear(sf::Color::White);
        Game::gameElements.field.draw();
        window.display();
    }

}