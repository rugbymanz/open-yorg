#pragma once

#include <SFML/Window/Event.hpp>

#include "ValuesAndTypes.hpp"

class Input{
public:
    void process(const sf::Event &event);

private:
    void processStdin();
    bool isValidBuildingPosition(const FieldCoord &position);
    void processMouseWheelScroll(const sf::Event::MouseWheelScrollEvent &mouseWheelScroll);
    void processMouseClick(const sf::Event::MouseButtonEvent  &mouseButton);
    void processKeys(const sf::Event::KeyEvent &key);
    void processMouseLeftClick(const sf::Vector2i &clickPosition);
};