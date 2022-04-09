#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ValuesAndTypes.hpp"
#include "Graphical.hpp"

class FieldCell: public sf::RectangleShape, public Graphical{
public:
    bool isEmpty = true;
    bool isDestructable = false;

    FieldCell(const FieldCoord &fieldCoord);
    void setCoord(const FieldCoord &fieldCoord);
    FieldCoord getCoord();
    void draw()override;
    virtual void update() = 0;
    sf::Vector2f getCenter()override;

protected:
    FieldCoord coord = NONE_FIELD_CELL;

private:
};