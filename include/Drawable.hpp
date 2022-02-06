#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class Drawable{
public:
    sf::Vector2f getCenter();
    virtual void draw() = 0;
    virtual ~Drawable(){};

protected:
    sf::Texture texture;
};