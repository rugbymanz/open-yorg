#include "Bullet/DamageCircle.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"

DamageCircle::DamageCircle(FieldCoord aim, double damage, double damageRadius) : CanDamage{ aim, damage, damageRadius } {
    setRadius(damageRadius);
    setPosition(Algorithms::mapFieldCoordToVector2fCentered(aim) - sf::Vector2f{ getRadius(), getRadius() });
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setFillColor(sf::Color::Red);
};

void DamageCircle::draw() {
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void DamageCircle::update() {

}

sf::Vector2f DamageCircle::getCenter() {
    return { getPosition().x + getRadius(), getPosition().y + getRadius() };
}