#include <Graphical.hpp>

#include <ValuesAndTypes.hpp>

Graphical::Graphical() {
	font.loadFromFile("resources/CascadiaCode.ttf");
	text.setFont(font);
	text.setCharacterSize(CELL_WIDTH);
}

void Graphical::draw() {
}
