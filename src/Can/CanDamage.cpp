#include "Can/CanDamage.hpp"
#include "Algorithms.hpp"

CanDamage::CanDamage(sf::Vector2f aim_, double damage, double damageRadius_) : damage{ damage }{
	setAimVector2f(aim_);
	setDamageRadiusd(damageRadius_);
}
CanDamage::CanDamage(FieldCoord aim_, double damage, int damageRadius_) : damage{ damage }{
	setAimFieldCoord(aim_);
	setDamageRadiusi(damageRadius_);
}

int CanDamage::getDamageRadiusi() {
	return Algorithms::doubleDamageRadiusToInt(damageRadius);
}
double CanDamage::getDamageRadiusd() {
	return damageRadius;
}
FieldCoord CanDamage::getAimFieldCoord() {
	return Algorithms::mapVector2fToFieldCoord(aim);
}
sf::Vector2f CanDamage::getAimVector2f() {
	return aim;
}

void CanDamage::setDamageRadiusi(int damageRadius_) {
	damageRadius = Algorithms::intDamageRadiusToDouble(damageRadius_);
}
void CanDamage::setDamageRadiusd(double damageRadius_) {
	damageRadius = damageRadius_;
}
void CanDamage::setAimFieldCoord(FieldCoord aim_) {
	aim = Algorithms::mapFieldCoordToVector2fCentered(aim_);
}
void CanDamage::setAimVector2f(sf::Vector2f aim_) {
	aim = aim_;
}