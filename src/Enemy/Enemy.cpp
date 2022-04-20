#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"
#include "Bullet/EnemyBullet.hpp"
#include "Field/FieldCell.hpp"
#include "Building/Building.hpp"

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField, Bullets &bullets, double damage, Field &field, int damageRadius, DamageCircles &damageCircles_) : damageCircles{ damageCircles_ }, bullets { bullets }, pathSearchField{ pathSearchField }, CanShoot{ NONE_FIELD_CELL, damage, damageRadius }, field{ field } {
    setPosition(Algorithms::mapFieldCoordToVector2f(spawnPosition));
    setRadius(CELL_LENGTH / static_cast<double>(2));
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());
    nextMoveFieldCoord = Algorithms::mapVector2fToFieldCoord(getCenter());

    text.setString("E");
    renderTexture.draw(text);
}

void Enemy::draw(){
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void Enemy::move_() {
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::mapFieldCoordToVector2fCentered(nextMoveFieldCoord) );
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        FieldCoord selfCoord = Algorithms::mapVector2fToFieldCoord(getCenter());
        nextMoveFieldCoord = pathSearchField.generatePath(selfCoord);
        setMovementAzimuth(getCenter(), Algorithms::mapFieldCoordToVector2fCentered(nextMoveFieldCoord));
        if (field.get(nextMoveFieldCoord).isDestructable) {
            attacking = true;
            setAimCoord(nextMoveFieldCoord);
        }
    }
    else {
        sf::Vector2f step = getMovementVector();
        move(step);
    }
}

void Enemy::update(){
	if (getHp() <= 0){
		deleted = true;
        return;
    }
    if (!attacking)
        move_();
    else {
        if (static_cast<Building&>(field.get(getAimCoord<FieldCoord>())).getHp() > 0){
            if(isTimeToAttack())
                attack();
        }
        else
            attacking = false;
    }
}

void Enemy::shootAim() {
    CanShoot::shootAim();
    bullets.append(new EnemyBullet{ getCenter(), getAimCoord<FieldCoord>(), damage, field, getDamageRadius<int>(), damageCircles });
}

sf::Vector2f Enemy::getCenter()const{
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}