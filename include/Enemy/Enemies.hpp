#pragma once

#include <forward_list>

#include "ValuesAndTypes.hpp"

class Enemy;

class Enemies{
public:
    Enemies();
    Enemy *append(Enemy *enemy);
    Enemy &findNearest(FieldCoord fieldCoord, double searchRadius);
    std::vector<Enemy *> findAllInCircle(sf::Vector2f circleCenter, double searchRadius);

private:
    std::forward_list<Enemy*> enemies;

    void update();
    void draw();

    friend class GameElements;
};