#include <SFML/Graphics/Sprite.hpp>

#include "Bullet/Bullet.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"

// Bullet::Bullet(aim, damage): aim{aim}, damage{damage}{
//     Game::gameElements.ammunitions.add(*this)
//     movementAzimuth = Algorithms::calculateAzimuth(getCenter(), aim)
// }

// update(){
//     if(!aim.contains(getCenter())
//         move(movementAzimuth * speed, movementAzimuth * speed
//     else{
//         damage()
//         erase()
//     }
// }

// damage(){
//     foreach i in creatures
//         if(distance(i.getCenter(), getCenter()) < radius){
//             i.hp -= damage;
//         }
// }

// erase(){
//     erased = true;
// }

Bullet::Bullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, double damageRadius) : CanDamage{ aim, damage, damageRadius } {
    setRadius(CELL_LENGTH / 4.);
    setPosition(spawnPosition - sf::Vector2f{getRadius(), getRadius()});
    setMovementAzimuth(this->getCenter(), Algorithms::mapFieldCoordToVector2fCentered(aim) );
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

sf::Vector2f Bullet::getCenter() {
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}