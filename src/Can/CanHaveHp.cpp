#include "Can/CanHaveHp.hpp"

double CanHaveHp::getHp() const {
	return hp;
}

void CanHaveHp::setHp(double hp_) {
	hp = hp_;
}

void CanHaveHp::decreaseHp(const double hp_) {
	hp -= hp_;
}