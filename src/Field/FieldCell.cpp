#include "Field/FieldCell.hpp"

FieldCell::FieldCell(const FieldCoord &fieldCoord){
    setCoord(fieldCoord);
    setSize({ValuesAndTypes::Field::cellLength, ValuesAndTypes::Field::cellWidth});
    setOutlineColor(ValuesAndTypes::Colors::unselected);
    setOutlineThickness(ValuesAndTypes::Field::cellOutlineThickness);

    sf::Image image;
    image.create(ValuesAndTypes::Field::cellLength, ValuesAndTypes::Field::cellWidth, ValuesAndTypes::Colors::background);
    texture.loadFromImage(image);
    setTexture(&texture);
}

void FieldCell::setCoord(const FieldCoord &fieldCoord){
    setPosition(fieldCoord.x * ValuesAndTypes::Field::cellLength, fieldCoord.y * ValuesAndTypes::Field::cellWidth);
    coord = fieldCoord;
}

FieldCoord FieldCell::getCoord(){
    return coord;
}

void FieldCell::draw(){
    // image.create(Settings::Field::cellLength, Settings::Field::cellWidth, Color::White);
    // text.loadFromImage(image);
}