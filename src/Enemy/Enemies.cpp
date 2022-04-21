#include "Enemy/Enemies.hpp"
#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"

Enemies::Enemies() {
}

Enemy *Enemies::append(Enemy *enemy) {
    enemies.push_front(enemy);
    return enemy;
}

void Enemies::update() {
    for (auto &enemy : enemies) {
        if(enemy->deleted){
            delete enemy;
            enemy = nullptr;
            continue;
        }
        enemy->update();
    }
    enemies.remove(nullptr);
}

void Enemies::draw() {
    for (auto &el : enemies)
        el->draw();
}

Enemy &Enemies::findNearest(FieldCoord fieldCoord, double searchRadius) {

    return **std::min_element(enemies.begin(), enemies.end(), [fieldCoord](const Enemy *lhs, const Enemy *rhs) {
        sf::Vector2f distanceLhs = Algorithms::calculateDistanceVector(lhs->getCenter(), Algorithms::fieldCoordToVector2fCentered(fieldCoord));
        distanceLhs = { abs(distanceLhs.x), abs(distanceLhs.y) };
        sf::Vector2f distanceRhs = Algorithms::calculateDistanceVector(rhs->getCenter(), Algorithms::fieldCoordToVector2fCentered(fieldCoord));
        distanceRhs = { abs(distanceRhs.x), abs(distanceRhs.y) };
        return (distanceLhs.x < distanceRhs.x) && (distanceLhs.y < distanceRhs.y);
        });

    //Enemy *min_enemy = (*enemies.begin());
    //sf::Vector2f min = (*enemies.begin())->getCenter();
    //min = { abs(min.x), abs(min.y) };
    //for (auto &enemy : enemies) {
    //    sf::Vector2f distance = Algorithms::calculateDistanceVector(enemy->getCenter(), Algorithms::mapFieldCoordToVector2fCentered(fieldCoord));
    //    distance = { abs(distance.x), abs(distance.y) };
    //    if(distance.x < searchRadius && distance.x < searchRadius)
    //        if (distance.x < min.x && distance.y < min.y) {
    //            min = distance;
    //            min_enemy = enemy;
    //        }
    //}

    //return *min_enemy;
}

std::vector<Enemy *> Enemies::findAllInCircle(sf::Vector2f circleCenter, double searchRadius) {
    std::vector<Enemy *> enemiesInCircle;
    for(auto &enemy: enemies){
        sf::Vector2f distance = Algorithms::calculateDistanceVector(enemy->getCenter(), circleCenter);
        distance = { abs(distance.x), abs(distance.y) };
        if((distance.x < searchRadius) && (distance.y < searchRadius))
            enemiesInCircle.push_back(enemy);
    }

    return enemiesInCircle;
}