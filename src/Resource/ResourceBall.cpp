#include "Resource/ResourceBall.hpp"
#include "Graphical.hpp"
#include "Resource/ResourceBalls.hpp"
#include "Algorithms.hpp"
#include "Field/Road.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ValuesAndTypes.hpp"
#include "Game.hpp"
#include "Field/FieldCell.hpp"
#include "Building/Building.hpp"

ResourceBall::ResourceBall(Field &field_, Road &road, const FieldCoord &source, ResourceType type_) : field{field_}, road{road}, source { source }, destination{ source }, destinationNode{ source }, type{type_}{
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

void ResourceBall::fade(){
    std::cout << "fading" << std::endl;
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
    if(fading)
		fade();
	else
        moveToNextNode();
}

bool ResourceBall::reachedDestination(FieldCoord &fieldCoord){
    return fieldCoord == Algorithms::vector2fToFieldCoord(getCenter());
}

sf::Vector2f ResourceBall::getCenter()const{
    return getPosition() + sf::Vector2f{getRadius(), getRadius()};
}

void ResourceBall::moveToNextNode(){
    sf::Vector2f distance = Algorithms::calculateDistanceVector(getCenter(), Algorithms::fieldCoordToVector2fCentered(nextMoveFieldCoord) );
    if (abs(distance.x) < speed && abs(distance.y) < speed) {
        FieldCoord selfCoord = Algorithms::vector2fToFieldCoord(getCenter());
        bool reached = false;
        std::tie(nextMoveFieldCoord, reached) = road.generatePath(selfCoord, type);
        if(!reached)
            fading = true;
		else if(reachedDestination(nextMoveFieldCoord)){
            std::cout << "destination" << std::endl;
            
        }
        else{
            setMovementAzimuth(getCenter(), Algorithms::fieldCoordToVector2fCentered(nextMoveFieldCoord));
        }
    }
    else {
        sf::Vector2f step = getMovementVector();
        move(step);
    }
}