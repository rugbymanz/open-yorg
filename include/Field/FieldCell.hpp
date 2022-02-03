#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ValuesAndTypes.hpp"

class FieldCell: public sf::RectangleShape{
public:
    enum class Types{
        resource,
        buidling,
        none,
        N
    } type = Types::none;

    FieldCell();
    void setBorderColor(const sf::Color color);
    void setCoord(const FieldCoord &fieldCoord);
    FieldCoord getCoord();
    

private:
    FieldCoord coord = ValuesAndTypes::noneFieldCell;

    void draw();
};