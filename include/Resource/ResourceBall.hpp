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
    FieldCoord source = ValuesAndTypes::noneFieldCell;
    FieldCoord sourceNode = ValuesAndTypes::noneFieldCell;
    FieldCoord destination = ValuesAndTypes::noneFieldCell;
    FieldCoord nextNode = ValuesAndTypes::noneFieldCell;
    FieldCoord destinationNode = ValuesAndTypes::noneFieldCell;
    FieldCoord currentNode = ValuesAndTypes::noneFieldCell;
    Azimuth movementAzimuth = ValuesAndTypes::none;

    void findDestinationNode();
    void findDestination();
    void increaseResource();
    void erase();
    void update();
    void updatePosition();
};