#pragma once

#include <SFML/Window/Event.hpp>

#include "ValuesAndTypes.hpp"

class Input{
public:
    void process(const sf::Event &event);

private:
    void processStdin();
    bool isValidBuildingPosition(const FieldCoord &position);
    void processMouseWheelScroll(const sf::Event &event);
    void processMouseClick(const sf::Event &event);
    void processKeys(const sf::Event &event);
};