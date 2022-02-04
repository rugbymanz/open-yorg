#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

using FieldCoord = sf::Vector2i;
using Azimuth = double;

struct ValuesAndTypes{
    static constexpr int none = -1;
    static const FieldCoord noneFieldCell;
    static const sf::Vector2f noneVector2f;

    struct Field{
        static const int fieldLength = 20;
        static const int fieldWidth = 20;

        static const int cellLength = 20;
        static const int cellWidth = 20;

        static const int cellOutlineThickness = 1;
    };

    struct Colors{
        static const sf::Color selected;
        static const sf::Color normal;
    };

    struct Clock{
        static constexpr double dayDuration = none;
        static constexpr double nightDuration = none;
    };

    static constexpr double speed = 1;
    static const double zoomSpeed;
    static const double viewMoveSpeed;
};