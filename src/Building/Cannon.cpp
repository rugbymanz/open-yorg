#include "Building/Cannon.hpp"
#include "Game.hpp"
#include "Enemy/Enemy.hpp"

Cannon::Cannon(FieldCoord &fieldCoord_, Enemies &enemies_) : enemies{ enemies_ }, Building{ fieldCoord_ }, CanShoot{ NONE_VECTOR2F, NONE, NONE } {
    setDamageRadiusi(3);
    text.setString("C");
    renderTexture.draw(text);

    
}

void Cannon::update() {
    if (attacking) {
        if (aim->getHp() > 0)
            attack();
        else
            attacking = false;
    }
}

void Cannon::shootAim(){

}

void Cannon::draw() {
    Building::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void Enemy::shootAim() {
    CanShoot::shootAim();
    bullets.append(new EnemyBullet{ getCenter(), getAimFieldCoord(), damage, field, getDamageRadiusi(), damageCircles });
}

sf::Vector2f Enemy::getCenter() {
    return getPosition() + sf::Vector2f{ getRadius(), getRadius() };
}