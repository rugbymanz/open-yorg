#pragma once

#include "InputState.hpp"

class InputStateNormal:public InputState{
public:
	InputStateNormal(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_, ResourceBalls &resourceBalls_, Road &road_, Input &input);
	void process(const sf::Event &event) override;

private:
    bool isValidBuildingPosition(const FieldCoord &position);
    void processMouseWheelScroll(const sf::Event::MouseWheelScrollEvent &mouseWheelScroll);
    void processMouseClick(const sf::Event::MouseButtonEvent  &mouseButton);
    void processKeys(const sf::Event::KeyEvent &key) override;
    void processMouseLeftClick(const sf::Vector2i &clickPosition);
    void build(const sf::Keyboard::Key &key);
};