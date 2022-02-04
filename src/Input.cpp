#include <sstream>
#include <assert.h>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Input.hpp"
#include "Game.hpp"
#include "Algorithms.hpp"
#include "Building/Base.hpp"

void Input::process(const sf::Event &event){
    // if(std::string stringInput = getString(); isInputEntered(stringInput))
    processStdin();
    // else if(MouseWheel scroll){
    //     processMouseWheel(event)
    // }
    // else if(arrowKey pressed){
    //     processArrows(event)
    // }
    // else if(event.type == sf::Event::MouseButtonReleased){
    //     processMouseClick(event);
    // }
}

// std::string Input::getString(){
//     std::string input;
//     std::cin >> input;
//     return input;

// }

// bool Input::isInputEntered(const std::string &stringInput){
//         return stringInput.length();
// }

void Input::processStdin(){
    const FieldCoord &position = Game::interface.selectedCell;

    if (!isValidBuildingPosition(position)){
        assert(0 && "Invalid building postion");
    }

    std::string operation;
    std::cin >> operation;
    
    std::string parameter;
    std::cin >> parameter;

    if(operation == "build"){
        if(parameter == "base")
            Game::gameElements.field.set(position, new Base);
    }
}

bool Input::isValidBuildingPosition(const FieldCoord &position){
    return Game::gameElements.field.get(position).isEmpty;
}

void Input::processMouseClick(const sf::Event &event){
    // Game.interface.selectCell(toFieldCoord(Mose::getPosition()));
}

void Input::processMouseWheelScroll(const sf::Event &event){
    double zoom = event.mouseWheelScroll.delta * ValuesAndTypes::zoomSpeed;
    sf::View view = Game::window->getView();
    view.zoom(1 + zoom);
    Game::window->setView(view);
}

// must be reworked
void Input::processKeys(const sf::Event &event){
    sf::View view = Game::window->getView();

    switch(event.key.code){
    case sf::Keyboard::Key::Left:
        view.move(-ValuesAndTypes::viewMoveSpeed, 0);
        break;
    case sf::Keyboard::Key::Right:

    }
}

