#include "Sprite.hpp"

Sprite::Sprite(const std::string &pathName){
    if (!this->texture.loadFromFile(pathName)) {
        std::cout << "erreur loading texture";
    }
    this->sprite.setTexture(this->texture);
    std::cout << "Sprite creade" << std::endl;
}

Sprite::~Sprite(){

}

sf::Sprite Sprite::GetSprite(){
    return this->sprite;
}
