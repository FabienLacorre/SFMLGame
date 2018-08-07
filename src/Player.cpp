#include "Player.hpp"

Player::Player(sf::Texture &texture,
	float scale,
	int width,
	int height,
	int posX,
	int posY,
	float velocity): 
Entity(texture, scale, width, height, posX, posY, velocity){

}

Player::~Player(){

}