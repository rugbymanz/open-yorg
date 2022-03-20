#include "Field/FieldCell.hpp"
#include "SFML/Graphics/Sprite.hpp"

FieldCell::FieldCell(const FieldCoord &fieldCoord){
    setCoord(fieldCoord);
    setSize({CELL_LENGTH, CELL_WIDTH});
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);

    sf::Image image;
    image.create(CELL_LENGTH, CELL_WIDTH, BACKGROUND);
    backgroundTexture.loadFromImage(image);
    renderTexture.create(backgroundTexture.getSize().x, backgroundTexture.getSize().y);
    renderTexture.draw(sf::Sprite(backgroundTexture));
    setTexture(&renderTexture.getTexture());
}

void FieldCell::setCoord(const FieldCoord &fieldCoord){
    setPosition(fieldCoord.x * CELL_LENGTH, fieldCoord.y * CELL_WIDTH);
    coord = fieldCoord;
}

FieldCoord FieldCell::getCoord(){
    return coord;
}

void FieldCell::draw(){
    Graphical::draw();
    // image.create(Settings::Field::cellLength, Settings::Field::cellWidth, Color::White);
    // text.loadFromImage(image);
}