#pragma once

#include "InputState.hpp"

class InputStateFutureRoad: public InputState{
public:
	InputStateFutureRoad(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_, ResourceBalls &resourceBalls_, Road &road_, Input &input);
	void process(const sf::Event &event) override;
private:
    void processKeys(const sf::Event::KeyEvent &key) override;
};