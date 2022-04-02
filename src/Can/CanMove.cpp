#include "Can/CanMove.hpp"
#include "Algorithms.hpp"

void CanMove::setMovementAzimuth(const sf::Vector2f spawnPosition, const sf::Vector2f aim) {
	movementAzimuth = Algorithms::calculateAzimuth(spawnPosition, aim);
}

void CanMove::setMovementAzimuth(const FieldCoord spawnPosition, const FieldCoord aim) {
	setMovementAzimuth(Algorithms::mapFieldCoordToVector2fCentered(spawnPosition), Algorithms::mapFieldCoordToVector2fCentered(aim));
}

sf::Vector2f CanMove::getMovementVector() {
	return { static_cast<float>(cos(movementAzimuth) * speed), static_cast<float>(sin(movementAzimuth) * speed) };
}