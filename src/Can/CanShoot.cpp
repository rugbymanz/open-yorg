#include <SFML/System/Time.hpp>

#include "Can/CanShoot.hpp"

CanShoot::CanShoot(FieldCoord aim, double damage) : CanDamage{ aim, damage } {};

void CanShoot::shootAim() {
	clock.restart();
}

void CanShoot::findAim() {

}
bool CanShoot::isTimeToShoot() {
	if (fireRate < clock.getElapsedTime().asSeconds()) 
		return true;
	else
		return false;
}