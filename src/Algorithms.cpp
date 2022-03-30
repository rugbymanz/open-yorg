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
    return -1;
}

FieldCoord Algorithms::mapVector2fToFieldCoord(const sf::Vector2f &floatFieldCoord){
    int x = floatFieldCoord.x / CELL_LENGTH;
    int y = floatFieldCoord.y / CELL_WIDTH;

    return FieldCoord(x, y);
}

sf::Vector2f Algorithms::mapFieldCoordToVector2f(const FieldCoord &fieldCoord) {
    int x = fieldCoord.x * CELL_LENGTH;
    int y = fieldCoord.y * CELL_WIDTH;

    return sf::Vector2f(x, y);
}

int Algorithms::mapFieldCoordToFlatIndex(const FieldCoord &fieldCoord) {
    return fieldCoord.x + fieldCoord.y * FIELD_LENGTH;
}

FieldCoord Algorithms::mapFlatIndexToFieldCoord(const int index) {
    return FieldCoord(index % FIELD_LENGTH, index / FIELD_LENGTH);
}
// Resource Algorithms::enumToClass(const Resource::Types type);