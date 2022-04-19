#include "Can/CanDamage.hpp"
#include "Algorithms.hpp"

CanDamage::CanDamage(sf::Vector2f aim_, double damage, double damageRadius_) : damage{ damage }, aim{aim_}, damageRadius{damageRadius_}{
}
CanDamage::CanDamage(FieldCoord aim_, double damage, int damageRadius_) : damage{ damage }, aim{Algorithms::mapFieldCoordToVector2fCentered(aim_)}, damageRadius{Algorithms::intDamageRadiusToDouble(damageRadius_)} {
}

template<>
int CanDamage::getDamageRadius() {
	return Algorithms::doubleDamageRadiusToInt(damageRadius);
}

template<>
double CanDamage::getDamageRadius() {
	return damageRadius;
}

template<>
FieldCoord CanDamage::getAimCoord() {
	return Algorithms::mapVector2fToFieldCoord(aim);
}
template<>
sf::Vector2f CanDamage::getAimCoord() {
	return aim;
}

template<>
void CanDamage::setDamageRadius(int damageRadius_) {
	damageRadius = Algorithms::intDamageRadiusToDouble(damageRadius_);
}
template<>
void CanDamage::setDamageRadius(double damageRadius_) {
	damageRadius = damageRadius_;
}

template<>
void CanDamage::setAimCoord(FieldCoord aim_) {
	aim = Algorithms::mapFieldCoordToVector2fCentered(aim_);
}
template<>
void CanDamage::setAimCoord(sf::Vector2f aim_) {
	aim = aim_;
}