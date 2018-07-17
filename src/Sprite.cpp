#include "Sprite.hpp"

Sprite::Sprite(const std::string &pathName){
    if (!this->texture.loadFromFile(pathName)) {
        std::cout << "erreur loading texture";
    }
    this->sprite.setTexture(this->texture);
    //this->sprite.setTextureRect(sf::IntRect(0,0,16,20));
    //this->sprite.setScale(sf::Vector2f(2, 2));
    std::cout << "Sprite created" << std::endl;
}

Sprite::~Sprite(){

}

sf::Sprite &Sprite::GetSprite(){
    return this->sprite;
}

void Sprite::MoveSprite(float velocity, std::string move){
	sf::Vector2f pos = this->sprite.getPosition();
	if (move == "top"){
		std::cout << "move top" << std::endl;
		this->sprite.setPosition(pos.x, pos.y - velocity);
	}
	else if (move == "bottom"){
		std::cout << "move bottom" << std::endl;
		this->sprite.setPosition(pos.x, pos.y + velocity);
	}
	else if (move == "right"){
		std::cout << "move right" << std::endl;
		this->sprite.setPosition(pos.x + velocity, pos.y);
	}
	else if (move == "left"){
		std::cout << "move left" << std::endl;
		this->sprite.setPosition(pos.x - velocity, pos.y);
	}
}
