#include <SFML/Graphics/Sprite.hpp>

#include "Graphical.hpp"
#include "ValuesAndTypes.hpp"

Graphical::Graphical() {
	font.loadFromFile("resources/CascadiaCode.ttf");
	text.setFont(font);
	text.setCharacterSize(CELL_WIDTH);

    sf::Image image;
    image.create(CELL_LENGTH, CELL_WIDTH, BACKGROUND);
    backgroundTexture.loadFromImage(image);
    renderTexture.create(backgroundTexture.getSize().x, backgroundTexture.getSize().y);
    renderTexture.draw(sf::Sprite(backgroundTexture));
}

void Graphical::draw() {
}
