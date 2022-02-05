#include "ValuesAndTypes.hpp"

const FieldCoord ValuesAndTypes::noneFieldCell = FieldCoord(-1, -1);
const sf::Vector2f ValuesAndTypes::noneVector2f = sf::Vector2f(-1, -1);

const sf::Color ValuesAndTypes::Colors::selected = sf::Color::Blue;
const sf::Color ValuesAndTypes::Colors::unselected = sf::Color::Black;
const sf::Color ValuesAndTypes::Colors::background = sf::Color::Cyan;

const double ValuesAndTypes::zoomSpeed = 0.1;
const double ValuesAndTypes::viewMoveSpeed = 20;