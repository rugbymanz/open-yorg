#pragma once

#include "ValuesAndTypes.hpp"

namespace Algorithms {
    double calculateAzimuth(const sf::Vector2f &from, const sf::Vector2f &to);
    double calculateAzimuth(const FieldCoord &from, const FieldCoord &to);

    sf::Vector2f calculateDistanceVector(const FieldCoord &from, const FieldCoord &to);
    sf::Vector2f calculateDistanceVector(const sf::Vector2f &from, const sf::Vector2f &to);

    int mapFieldCoordToFlatIndex(const FieldCoord &fieldCoord);
    FieldCoord mapFlatIndexToFieldCoord(const int index);

    FieldCoord mapVector2fToFieldCoord(const sf::Vector2f &floatFieldCoord);
    sf::Vector2f mapFieldCoordToVector2f(const FieldCoord &fieldCoord);
    sf::Vector2f mapFieldCoordToVector2fCentered(const FieldCoord &fieldCoord);
}