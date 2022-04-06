#pragma once

#include "ValuesAndTypes.hpp"

class CanMove{
private:
    Azimuth movementAzimuth = NONE;
protected:
    virtual void move_() = 0;
    sf::Vector2f getMovementVector();

    void setMovementAzimuth(const FieldCoord spawnPosition, const FieldCoord aim);
    void setMovementAzimuth(const sf::Vector2f spawnPosition, const sf::Vector2f aim);

    double speed = NONE;
};