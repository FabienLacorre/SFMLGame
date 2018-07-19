#include "Sprite.hpp"

Sprite::Sprite(sf::Texture &texture){
    this->sprite.setTexture(texture);
}

Sprite::~Sprite(){

}

sf::Sprite &Sprite::GetSprite(){
    return this->sprite;
}

void Sprite::MoveSprite(float velocity, std::string move){
	sf::Vector2f pos = this->sprite.getPosition();
	if (move == "top"){
		this->sprite.setPosition(pos.x, pos.y - velocity);
	}
	else if (move == "bottom"){
		this->sprite.setPosition(pos.x, pos.y + velocity);
	}
	else if (move == "right"){
		this->sprite.setPosition(pos.x + velocity, pos.y);
	}
	else if (move == "left"){
		this->sprite.setPosition(pos.x - velocity, pos.y);
	}
}
