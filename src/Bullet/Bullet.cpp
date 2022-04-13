#include <SFML/Graphics/Sprite.hpp>

#include "Bullet/Bullet.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"

Bullet::Bullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, int damageRadius) : CanDamage{ aim, damage, damageRadius } {
    init(spawnPosition);
}

Bullet::Bullet(sf::Vector2f spawnPosition, sf::Vector2f aim, double damage, double damageRadius) : CanDamage{ aim, damage, damageRadius } {
    init(spawnPosition);
}

void Bullet::init(sf::Vector2f spawnPosition) {
    setRadius(CELL_LENGTH / 4.);
    setPosition(spawnPosition - sf::Vector2f{ getRadius(), getRadius() });
    setMovementAzimuth(this->getCenter(), getAimVector2f());
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());

    renderTexture.draw(text);
    sf::Image image;
    image.create(CELL_LENGTH, CELL_WIDTH, sf::Color::Red);
    backgroundTexture.loadFromImage(image);
    renderTexture.draw(sf::Sprite(backgroundTexture));
}

void Bullet::draw(){
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void Bullet::move_() {
    sf::Vector2f step = getMovementVector();
    move(step);
}

void Bullet::update() {
    move_();
}

sf::Vector2f Bullet::getCenter() const {
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}