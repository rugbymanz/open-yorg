#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"
#include "Bullet/EnemyBullet.hpp"

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField, Bullets &bullets) : bullets{ bullets }, pathSearchField { pathSearchField }, CanShoot{ NONE_FIELD_CELL } {
    nextMoveFieldCoord = pathSearchField.generatePath(spawnPosition);
    //skip self
    setPosition(Algorithms::mapFieldCoordToVector2f(spawnPosition));
    setRadius(CELL_LENGTH / 2);
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());
    setMovementAzimuth(getPosition(), Algorithms::mapFieldCoordToVector2f(nextMoveFieldCoord));

    text.setString("E");
    renderTexture.draw(text);
}

Enemy::~Enemy() {
}

void Enemy::draw(){
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void Enemy::move_() {
    //sf::Vector2f distance = Algorithms::calculateDistanceVector(getPosition(), Algorithms::mapFieldCoordToVector2f(nextMoveFieldCoord) );
    //if (abs(distance.x) < speed && abs(distance.y) < speed) {
    //    FieldCoord selfCoord = Algorithms::mapVector2fToFieldCoord(getPosition());
    //    nextMoveFieldCoord = pathSearchField.generatePath(selfCoord);
    //    setMovementAzimuth(getPosition(), Algorithms::mapFieldCoordToVector2f(nextMoveFieldCoord));
    //    if (nextMoveFieldCoord == selfCoord) {
    //        aim = { 0, 0 };
    //        if(isTimeToShoot())
    //            shootAim();
    //    }
    //}
    //else {
    //    sf::Vector2f step = getMovementVector();
    //    move(step);
    //}

    aim = { 0, 0 };
    if (isTimeToShoot())
        shootAim();
}

void Enemy::update(){
    move_();

    // moveSprite
}

void Enemy::shootAim() {
    CanShoot::shootAim();
    bullets.append(new EnemyBullet{ getCenter(), aim });
}

sf::Vector2f Enemy::getCenter(){
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}