#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Text.hpp>

class Graphical{
public:
    Graphical();

    virtual sf::Vector2f getCenter() = 0;
    virtual void draw();
    virtual ~Graphical(){};

protected:
    sf::Texture backgroundTexture;
    sf::Text text;
    sf::Font font;
    sf::RenderTexture renderTexture;
};