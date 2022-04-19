#include "Building/Cannon.hpp"
#include "Game.hpp"
#include "Bullet/CannonBall.hpp"
#include "Enemy/Enemy.hpp"

Cannon::Cannon(FieldCoord &fieldCoord_, Enemies &enemies_, Bullets &bullets, DamageCircles &damageCircles) : enemies{ enemies_ }, Building{ fieldCoord_ }, CanShoot{ NONE_VECTOR2F, NONE, NONE }, bullets{ bullets }, damageCircles{damageCircles} {
    setDamageRadius(3);
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

void Cannon::draw() {
    Building::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void Cannon::shootAim() {
    CanShoot::shootAim();
    bullets.append(new CannonBall{ getCenter(), enemies.findNearest(getCoord(), getDamageRadius<double>()).getCenter(), damage, getDamageRadius<double>(), damageCircles, enemies });
}

sf::Vector2f Cannon::getCenter() const {
    return getPosition() + sf::Vector2f{ getSize().x / 2, getSize().y / 2};
}