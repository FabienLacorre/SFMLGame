#include <iostream>
#include <SFML/Graphics.hpp>

class Sprite{
public:
    Sprite(std::string pathName);
    ~Sprite();
    sf::Sprite GetSprite();
private:
    sf::Texture texture;
    sf::Sprite sprite;
};
