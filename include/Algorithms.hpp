#pragma once

#include "ValuesAndTypes.hpp"
#include "Resource/Resource.hpp"
#include "Building/Building.hpp"
#include "Resource/Resource.hpp"
#include "Building/Building.hpp"

namespace Algorithms{
    double calculateAzimuth(const FieldCoord &from, const FieldCoord &to);
    double calculateDistance(const FieldCoord &from, const FieldCoord &to);
    FieldCoord toFieldCoord(const sf::Vector2f &floatFieldCoord);
    Resource enumToClass(const Resource::Types type);
    Building enumToClass(const Building::Types type);
}