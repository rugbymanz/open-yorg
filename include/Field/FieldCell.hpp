#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ValuesAndTypes.hpp"

class FieldCell: public sf::RectangleShape{
public:
    bool isEmpty = false;

    FieldCell(const FieldCoord &fieldCoord);
    void setCoord(const FieldCoord &fieldCoord);
    FieldCoord getCoord();
    virtual void draw();

private:
    FieldCoord coord = ValuesAndTypes::noneFieldCell;
};