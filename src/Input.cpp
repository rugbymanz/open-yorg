#include <sstream>
#include <assert.h>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Input.hpp"
#include "Game.hpp"
#include "Algorithms.hpp"

void Input::process(const sf::Event &event){
    if(std::string stringInput = getString(); isInputEntered(stringInput)){
        processStdin(stringInput);
    }
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

std::string Input::getString(){
    std::string input;
    std::cin >> input;
    return input;

}

bool Input::isInputEntered(const std::string &stringInput){
        return stringInput.length();
}

void Input::processStdin(const std::string &stringInput){
    std::stringstream input = std::stringstream(stringInput);

    const FieldCoord &position = Game::interface.selectedCell;

    if (!isValidBuildingPosition(position)){
        assert(0 && "Invalid building postion");
    }

    std::string operation;
    input >> operation;
    
    std::string parameter;
    input >> parameter;

    if(operation == "build"){
        if(parameter == "base")
            Game::gameElements.field.set(position, Algorithms::enumToClass(Building::Types::base));
    }
}

bool Input::isValidBuildingPosition(const FieldCoord &position){
    return (Game::gameElements.field.get(position).type ==  FieldCell::Types::none);
}

void Input::processMouseClick(const sf::Event &event){
    // Game.interface.selectCell(toFieldCoord(Mose::getPosition()));
}

//must be reworked
// void processMouseWheel(const sf::Event &event){
//     operations += Operation(OperationType::zoom, zoom);
// }

//must be reworked
// void processArrows(const sf::Event &event);
//     operations += Operation(OperationType::moveView, Vector2f())
// }

