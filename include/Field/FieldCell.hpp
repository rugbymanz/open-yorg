#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ValuesAndTypes.hpp"
#include "Graphical.hpp"

class FieldCell: public sf::RectangleShape, public Graphical{
public:
    bool isEmpty = true;
    bool isDestructable = false;
    int connectionRadius = NONE;

    FieldCell(const FieldCoord &fieldCoord, int connectionRadius_);
    void setCoord(const FieldCoord &fieldCoord);
    FieldCoord getCoord();
    void draw()override;
    virtual void update() = 0;
    sf::Vector2f getCenter()const override;

protected:
    FieldCoord coord = NONE_FIELD_CELL;

private:
};