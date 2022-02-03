#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <assert.h>

#include "Algorithms.hpp"
#include "Building/Base.hpp"

double Algorithms::calculateAzimuth(const FieldCoord &from, const FieldCoord &to){
    sf::Vector2f cathetuses;
    cathetuses.x = abs(from.x - to.x);
    cathetuses.y = abs(from.y - to.y);
    double tangent = cathetuses.y / cathetuses.x;
    return atan(tangent);
}

double Algorithms::calculateDistance(const FieldCoord &from, const FieldCoord &to){
    
}

// FieldCoord Algorithms::toFieldCoord(const sf::Vector2f &floatFieldCoord);

// Resource Algorithms::enumToClass(const Resource::Types type);