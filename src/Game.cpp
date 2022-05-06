#include "Game.hpp"
#include "ValuesAndTypes.hpp"

sf::RenderWindow *Game::window = nullptr;
int Game::crystals = NONE;

void Game::tick(){
    // interface.tick();
    gameElements.tick();
    // clock.tick()
}

Game::Game(sf::RenderWindow *const window) : input{ gameElements.field, 
                                                    interface, 
                                                    gameElements.field.pathSearchField, 
                                                    gameElements.enemies,
                                                    gameElements.bullets,
                                                    gameElements.damageCircles,
                                                    gameElements.resourceBalls,
                                                    gameElements.field.road
                                                  },
                                             interface { gameElements.field } {
    this->window = window;
}
