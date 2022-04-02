#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanMove.hpp"
#include "Graphical.hpp"

class ResourceBalls;
class Road;

class ResourceBall: public CanMove, public Graphical, public sf::CircleShape{
public:
    bool isSupposedToBeDeleted = false;

    ResourceBall(Road &road, const FieldCoord &source);
    void create(ResourceBalls &resourceBalls, const size_t amount);

private:
    Road &road;
    FieldCoord source = NONE_FIELD_CELL;
    FieldCoord sourceNode = NONE_FIELD_CELL;
    FieldCoord destination = NONE_FIELD_CELL;
    FieldCoord nextNode = NONE_FIELD_CELL;
    FieldCoord destinationNode = NONE_FIELD_CELL;
    FieldCoord currentNode = NONE_FIELD_CELL;
    Azimuth movementAzimuth = NONE;

    void findDestinationNode();
    void findDestination();
    void increaseResource();
    void erase();
    void update();
    void updatePosition();
};