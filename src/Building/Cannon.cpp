#include "Building/Cannon.hpp"
#include "Game.hpp"
#include "Bullet/CannonBall.hpp"
#include "Enemy/Enemy.hpp"
#include "ValuesAndTypes.hpp"

Cannon::Cannon(FieldCoord &fieldCoord_, Enemies &enemies_, Bullets &bullets, DamageCircles &damageCircles) : enemies{ enemies_ }, CanStore{ fieldCoord_, 3 }, CanShoot{ NONE_VECTOR2F, NONE, NONE }, bullets{ bullets }, damageCircles{damageCircles} {
    setDamageRadius(3);
    text.setString("CA");
    renderTexture.draw(text);
	fireRate = 2;
    damage = 4;
    setAttackRadius(10);
}

void Cannon::update() {
	if (getHp() <= 0){
		deleted = true;
        return;
    }
    if(storage <= 0)
        return;
    std::vector<Enemy*> enemiesInDamageCircle = enemies.findAllInCircle(getCenter(), getAttackRadius<double>());
    if(enemiesInDamageCircle.size())
        if( isTimeToAttack() )
            attack();
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