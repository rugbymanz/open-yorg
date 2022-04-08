#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Input.hpp"
#include "Game.hpp"
#include "Algorithms.hpp"
#include "Building/Base.hpp"
#include "Resource/Crystal.hpp"
#include "Enemy/CasualEnemy.hpp"
#include "Building/Mine.hpp"

Input::Input(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_) : interface {interface}, 
                                                                                                                                                        pathSearchField {pathSearchField},
                                                                                                                                                        field{field},
                                                                                                                                                        enemies{ enemies },
                                                                                                                                                        bullets{bullets},
                                                                                                                                                        damageCircles{damageCircles_} {}

void Input::process(const sf::Event &event){
    if (event.type == sf::Event::Closed)
        Game::window->close();

    if (event.type == sf::Event::EventType::MouseWheelScrolled)
        processMouseWheelScroll(event.mouseWheelScroll);

    if (event.type == sf::Event::EventType::KeyPressed)
        processKeys(event.key);

    if (event.type == sf::Event::EventType::MouseButtonReleased)
        processMouseClick(event.mouseButton);
}

bool Input::isValidBuildingPosition(const FieldCoord &position){
    return field.get(position).isEmpty;
}

void Input::processMouseClick(const sf::Event::MouseButtonEvent  &mouseButton){
    if (mouseButton.button == sf::Mouse::Button::Left)
        processMouseLeftClick({mouseButton.x, mouseButton.y});
}

void Input::processMouseWheelScroll(const sf::Event::MouseWheelScrollEvent &mouseWheelScroll){
    double zoom = - mouseWheelScroll.delta * ZOOM_SPEED;
    sf::View view = Game::window->getView();
    view.zoom(1 + zoom);
    Game::window->setView(view);
}

void Input::build(const sf::Keyboard::Key &key){
    const FieldCoord &position = interface.selectedCell;

    if (!isValidBuildingPosition(position)){
        std::cout << "Invalid building postion" << std::endl;
        return;
    }
    if (interface.selectedCell != NONE_FIELD_CELL)
        switch (key) {
        case sf::Keyboard::B:
            field.set(new Base{ field, interface.selectedCell });
            break;
        case sf::Keyboard::C:
            field.set(new Crystal{ interface.selectedCell });
            break;
        case sf::Keyboard::E:
            new CasualEnemy{ interface.selectedCell, enemies, pathSearchField, bullets, field, damageCircles};
            break;
        case sf::Keyboard::M:
            field.set(new Mine{ field, interface.selectedCell });
        }
}

void Input::processKeys(const sf::Event::KeyEvent &key){
    sf::View view = Game::window->getView();

    switch(key.code){
    case sf::Keyboard::Key::Left:
        view.move(-VIEW_MOVE_SPEED, 0);
        break;
    case sf::Keyboard::Key::Right:
        view.move(VIEW_MOVE_SPEED, 0);
        break;
    case sf::Keyboard::Key::Down:
        view.move(0, VIEW_MOVE_SPEED);
        break;
    case sf::Keyboard::Key::Up:
        view.move(0, -VIEW_MOVE_SPEED);
        break;
    case sf::Keyboard::Key::B:
    //fall-through
    case sf::Keyboard::Key::C:
    case sf::Keyboard::Key::E:
    case sf::Keyboard::Key::M:
        build(key.code);
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

    if( (fieldCell.x < FIELD_LENGTH && floatCoord.x >= 0) && (fieldCell.y < FIELD_WIDTH && floatCoord.y >= 0) )
        interface.selectCell(fieldCell); 
    else
        std::cerr << "out of field bounds" << std::endl;
}

