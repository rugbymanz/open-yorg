#pragma once

#include <forward_list>

class Enemy;

class Enemies{
public:
    std::forward_list<Enemy*> enemies;

    Enemies();
    Enemy *append(Enemy *enemy);

private:
    void update();
    void draw();

    friend class GameElements;
};