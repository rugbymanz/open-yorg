#include "Game.hpp"

sf::RenderWindow *Game::window = nullptr;

void Game::tick(){
    // interface.tick();
    gameElements.tick();
    // clock.tick()
}

Game::Game(sf::RenderWindow *const window){
    this->window = window;
}
