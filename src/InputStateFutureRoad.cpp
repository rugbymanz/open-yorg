#include "InputStateFutureRoad.hpp"
#include "Field/Road.hpp"
#include "InputState.hpp"
#include "Input.hpp"
#include "InputStateNormal.hpp"

InputStateFutureRoad::InputStateFutureRoad(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_, ResourceBalls &resourceBalls_, Road &road_, Input &input): InputState(field, interface, pathSearchField, enemies, bullets, damageCircles_, resourceBalls_, road_, input){}

void InputStateFutureRoad::process(const sf::Event &event){
    if (event.type == sf::Event::EventType::KeyPressed)
        processKeys(event.key);
}

void InputStateFutureRoad::processKeys(const sf::Event::KeyEvent &key){
    switch(key.code){
    case sf::Keyboard::Key::Enter:
        road.showRealRoad(false);
        input.state = new InputStateNormal{field, interface, pathSearchField, enemies, bullets, damageCircles, resourceBalls, road, input};
        break;
    case sf::Keyboard::Key::Escape:
        road.showRealRoad(true);
        input.state = new InputStateNormal{field, interface, pathSearchField, enemies, bullets, damageCircles, resourceBalls, road, input};
        break;
	}
}