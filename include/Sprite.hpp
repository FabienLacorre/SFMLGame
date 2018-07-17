#include <iostream>
#include <SFML/Graphics.hpp>

class Sprite{
public:
    Sprite(const std::string &pathName);
    ~Sprite();
    sf::Sprite &GetSprite();
    void MoveSprite(float velocity, std::string move);
private:
    sf::Texture texture;
    sf::Sprite sprite;
};
