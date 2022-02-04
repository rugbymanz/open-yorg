#include "Field/FieldCell.hpp"

FieldCell::FieldCell(){
    setSize({ValuesAndTypes::Field::cellLength, ValuesAndTypes::Field::cellWidth});
    setOutlineColor(ValuesAndTypes::Colors::normal);
    setOutlineThickness(ValuesAndTypes::Field::cellOutlineThickness);
    // image.create(2000, 2000, Color::White);
    // text.loadFromImage(image);
    // setTexture(&text);
    // setOutlineColor(Color::Black);
    // setOutlineThickness(12);
    // setFillColor(Color::Blue);
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