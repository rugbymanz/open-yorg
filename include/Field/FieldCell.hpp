#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ValuesAndTypes.hpp"

class FieldCell: public sf::RectangleShape{
public:
    bool isEmpty = false;

    FieldCell();
    void setBorderColor(const sf::Color color);
    void setCoord(const FieldCoord &fieldCoord);
    FieldCoord getCoord();

private:
    FieldCoord coord = ValuesAndTypes::noneFieldCell;

    void draw();
};