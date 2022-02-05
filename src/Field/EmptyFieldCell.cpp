#include "Field/EmptyFieldCell.hpp"
#include "Game.hpp"

EmptyFieldCell::EmptyFieldCell(const FieldCoord &fieldCoord): FieldCell{fieldCoord}{
    isEmpty = true;
}

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
void EmptyFieldCell::draw(){
    sf::Image image;
    image.create(ValuesAndTypes::Field::cellLength, ValuesAndTypes::Field::cellWidth, sf::Color::Cyan);
    sf::Texture texture;
    texture.loadFromImage(image);
    setTexture(&texture);
    Game::window->draw(*this);
}