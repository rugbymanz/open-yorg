#pragma once

#include <SFML/Window/Event.hpp>

#include "ValuesAndTypes.hpp"

class Input{
public:
    void process(const sf::Event &event);

private:
    void processStdin();
    bool isValidBuildingPosition(const FieldCoord &position);
    void processMouseWheel(const sf::Event &event);
    void processMouseClick(const sf::Event &event);
    void processArrows(const sf::Event &event);
};