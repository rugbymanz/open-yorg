#pragma once

#include "ValuesAndTypes.hpp"

namespace Algorithms{
    double calculateAzimuth(const FieldCoord &from, const FieldCoord &to);
    double calculateDistance(const FieldCoord &from, const FieldCoord &to);
    FieldCoord mapVector2fToFieldCoord(const sf::Vector2f &floatFieldCoord);
}