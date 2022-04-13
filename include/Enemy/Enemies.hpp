#pragma once

#include <forward_list>

#include "ValuesAndTypes.hpp"

class Enemy;

class Enemies{
public:
    std::forward_list<Enemy*> enemies;

    Enemies();
    Enemy *append(Enemy *enemy);
    Enemy &findNearest(FieldCoord fieldCoord, double searchRadius);
    std::vector<Enemy*> findAllInCircle(sf::Vector2f circleCenter, double searchRadius);

private:
    void update();
    void draw();

    friend class GameElements;
};