#include "Resource/ResourceBall.hpp"
#include "Resource/ResourceBalls.hpp"
#include "Algorithms.hpp"
#include "Field/Road.hpp"

ResourceBall::ResourceBall(Road &road, const FieldCoord &source) : road{road}, source { source }, destination{ source }, destinationNode{ source }{
    findDestination();
}

void ResourceBall::update(){
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