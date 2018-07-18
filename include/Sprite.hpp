#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>

class Sprite{
public:
    Sprite(sf::Texture &texture);
    ~Sprite();
    sf::Sprite &GetSprite();
    void MoveSprite(float velocity, std::string move);
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
