#pragma once

#include <SFML/Window/Event.hpp>

#include "ValuesAndTypes.hpp"

class Input{
public:
    void process(const sf::Event &event);

private:
    std::string getString();
    void processStdin(const std::string &stringInput);
    bool isInputEntered(const std::string &stringInput);
    bool isValidBuildingPosition(const FieldCoord &position);
    void processMouseWheel(const sf::Event &event);
    void processMouseClick(const sf::Event &event);
    void processArrows(const sf::Event &event);
};