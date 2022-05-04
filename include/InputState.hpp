#pragma once
#include "SFML/Window/Event.hpp"
#include "ValuesAndTypes.hpp"

class Input;
class Field;
class Interface;
class Enemies;
class PathSearchField;
class Bullets;
class DamageCircles;
class Road;
class ResourceBalls;


class InputState{
public:
	InputState(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_, ResourceBalls &resourceBalls_, Road &road_, Input &input);
	virtual void process(const sf::Event &event) = 0;
private:
    virtual void processKeys(const sf::Event::KeyEvent &key) = 0;
protected:
	Input &input;
    Field &field;
    Interface &interface;
    Enemies &enemies;
    PathSearchField &pathSearchField;
    Bullets &bullets;
    DamageCircles &damageCircles;
    ResourceBalls &resourceBalls;
    Road &road;
};