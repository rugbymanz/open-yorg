#pragma once

#include "ValuesAndTypes.hpp"

namespace Algorithms{
    double calculateAzimuth(const FieldCoord &from, const FieldCoord &to);
    double calculateDistance(const FieldCoord &from, const FieldCoord &to);
    FieldCoord mapVector2fToFieldCoord(const sf::Vector2f &floatFieldCoord);
    sf::Vector2f mapFieldCoordToVector2f(const FieldCoord &fieldCoord);
    int mapFieldCoordToFlatIndex(const FieldCoord &fieldCoord);
    FieldCoord mapFlatIndexToFieldCoord(const int index);
}