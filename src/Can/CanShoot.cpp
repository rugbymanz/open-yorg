#include <SFML/System/Time.hpp>

#include "Can/CanShoot.hpp"
#include "ValuesAndTypes.hpp"
#include "Algorithms.hpp"

CanShoot::CanShoot(FieldCoord aim, double damage, int damageRadius) : CanDamage{ aim, damage, damageRadius } {};
CanShoot::CanShoot(sf::Vector2f aim, double damage, double damageRadius) : CanDamage{ aim, damage, damageRadius } {};

void CanShoot::shootAim() {
	fireRateClock.restart();
}

void CanShoot::findAim() {

}
bool CanShoot::isTimeToAttack() {
	if (fireRate < fireRateClock.getElapsedTime().asSeconds()) 
		return true;
	else
		return false;
}

void CanShoot::attack() {
	shootAim();
}

template<>
void CanShoot::setAttackRadius(int attackRadius_){
	attackRadius = Algorithms::intRadiusToDouble(attackRadius_);
}

template<>
void CanShoot::setAttackRadius(double attackRadius_){
	attackRadius = attackRadius_;
}

template<>
int CanShoot::getAttackRadius(){
	return Algorithms::doubleRadiusToInt(attackRadius);
}

template<>
double CanShoot::getAttackRadius(){
	return attackRadius;
}