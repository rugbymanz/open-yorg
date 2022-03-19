#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanMove.hpp"
#include "Drawable.hpp"
#include "Resource/Resource.hpp"

class ResourceBall: public CanMove, public Drawable, public sf::CircleShape{
public:
    bool isSupposedToBeDeleted = false;

    ResourceBall(const FieldCoord &source);
    void create(const size_t amount);

private:
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