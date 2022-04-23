#include "Resource/ResourceBall.hpp"
#include "Graphical.hpp"
#include "Resource/ResourceBalls.hpp"
#include "Algorithms.hpp"
#include "Field/Road.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ValuesAndTypes.hpp"
#include "Game.hpp"

ResourceBall::ResourceBall(Road &road, const FieldCoord &source, ResourceType type) : road{road}, source { source }, destination{ source }, destinationNode{ source }{
    findDestination();
    speed = 0.01 * CELL_LENGTH ;
    setRadius(CELL_LENGTH / 4.);
    setPosition(Algorithms::fieldCoordToVector2fCentered(source) - sf::Vector2f{ getRadius(), getRadius() });
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());
    nextMoveFieldCoord = Algorithms::vector2fToFieldCoord(getCenter());

    renderTexture.draw(text);
    sf::Image image;
    image.create(CELL_LENGTH, CELL_WIDTH, sf::Color::Magenta);
    backgroundTexture.loadFromImage(image);
    renderTexture.draw(sf::Sprite(backgroundTexture));
}

void ResourceBall::update(){
    move_();
}

void ResourceBall::draw(){
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void ResourceBall::findDestinationNode(){
}

void ResourceBall::findDestination(){
}

void ResourceBall::increaseResource(){
}

void ResourceBall::erase(){
}

void ResourceBall::updatePosition(){
}

void ResourceBall::move_(){
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::fieldCoordToVector2fCentered(nextMoveFieldCoord) );
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        FieldCoord selfCoord = Algorithms::vector2fToFieldCoord(getCenter());
        nextMoveFieldCoord = road.generatePath(selfCoord);
        setMovementAzimuth(getCenter(), Algorithms::fieldCoordToVector2fCentered(nextMoveFieldCoord));
    }
    else {
        sf::Vector2f step = getMovementVector();
        move(step);
    }
}

sf::Vector2f ResourceBall::getCenter()const{
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}