#include <sstream>
#include <assert.h>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Input.hpp"
#include "Game.hpp"
#include "Algorithms.hpp"
#include "Building/Base.hpp"

void Input::process(const sf::Event &event){
    if (event.type == sf::Event::Closed)
        Game::window->close();

    if (event.type == sf::Event::EventType::MouseWheelScrolled)
        Game::input.processMouseWheelScroll(event.mouseWheelScroll);

    if (event.type == sf::Event::EventType::KeyPressed)
        Game::input.processKeys(event.key);

    if (event.type == sf::Event::EventType::MouseButtonReleased)
        processMouseClick(event.mouseButton);
}

bool Input::isValidBuildingPosition(const FieldCoord &position){
    return Game::gameElements.field.get(position).isEmpty;
}

void Input::processMouseClick(const sf::Event::MouseButtonEvent  &mouseButton){
    if (mouseButton.button == sf::Mouse::Button::Left)
        Game::input.processMouseLeftClick({mouseButton.x, mouseButton.y});
}

void Input::processMouseWheelScroll(const sf::Event::MouseWheelScrollEvent &mouseWheelScroll){
    double zoom = - mouseWheelScroll.delta * ValuesAndTypes::zoomSpeed;
    sf::View view = Game::window->getView();
    view.zoom(1 + zoom);
    Game::window->setView(view);
}

void Input::build(const sf::Event::KeyEvent &key){
    const FieldCoord &position = Game::interface.selectedCell;

    if (!isValidBuildingPosition(position)){
        assert(0 && "Invalid building postion");
    }
    if(Game::interface.selectedCell != ValuesAndTypes::noneFieldCell)
        Game::gameElements.field.set(new Base{Game::interface.selectedCell});
}

void Input::processKeys(const sf::Event::KeyEvent &key){
    sf::View view = Game::window->getView();

    switch(key.code){
    case sf::Keyboard::Key::Left:
        view.move(-ValuesAndTypes::viewMoveSpeed, 0);
        break;
    case sf::Keyboard::Key::Right:
        view.move(ValuesAndTypes::viewMoveSpeed, 0);
        break;
    case sf::Keyboard::Key::Down:
        view.move(0, ValuesAndTypes::viewMoveSpeed);
        break;
    case sf::Keyboard::Key::Up:
        view.move(0, -ValuesAndTypes::viewMoveSpeed);
        break;
    case sf::Keyboard::Key::B:
        build(key);
        break;
    default:
        std::cerr << std::endl << "detected unrecognized Key event" << std::endl;
    }

    Game::window->setView(view);
}

void Input::processMouseLeftClick(const sf::Vector2i &clickPosition){
    sf::Vector2f floatCoord = Game::window->mapPixelToCoords(clickPosition);
    FieldCoord fieldCell = Algorithms::mapVector2fToFieldCoord(floatCoord);
    std::cerr << std::endl << fieldCell.x << ' ' << fieldCell.y << ' ';

    if( (fieldCell.x < ValuesAndTypes::Field::fieldLength && floatCoord.x >= 0) && (fieldCell.y < ValuesAndTypes::Field::fieldWidth && floatCoord.y >= 0) )
        Game::interface.selectCell(fieldCell); 
    else
        std::cerr << "out of field bounds" << std::endl;
}

