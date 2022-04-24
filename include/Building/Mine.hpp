#pragma once

#include "Building/Building.hpp"
#include "SFML/System/Clock.hpp"
#include "ValuesAndTypes.hpp"

class Field;
class ResourceBalls;
class Road;

class Mine: public Building{
public:
    Mine(Field &field, const FieldCoord &fieldCoord, double miningRate, ResourceBalls &resourceBalls, Road &road);
    void draw() override;
    void update() override;
private:
    sf::Clock miningRateClock;

    bool isTimeToMine();

protected:
    double miningRate = NONE;
    ResourceBalls &resourceBalls;
    Road &road;
    Field &field;

    virtual void mine();
};