#include "Building/Mine.hpp"
#include "Game.hpp"
#include "Resource/ResourceBalls.hpp"

Mine::Mine(Field &field, const FieldCoord &fieldCoord, double miningRate_, ResourceBalls &resourceBalls_, Road& road_) : resourceBalls{ resourceBalls_ },Building{ fieldCoord, 2 }, field{field}, miningRate{ miningRate_ }, road{ road_ } {
    text.setString("M");
    renderTexture.draw(text);
}
void Mine::update(){
    if(isTimeToMine())
        mine();
}

void Mine::draw() {
    Building::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

bool Mine::isTimeToMine(){
	if (miningRate < miningRateClock.getElapsedTime().asSeconds()) 
		return true;
	else
		return false;
}
void Mine::mine(){
    miningRateClock.restart();
}