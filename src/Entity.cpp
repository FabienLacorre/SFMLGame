#include "Entity.hpp"

Entity::Entity(sf::Texture &texture,
	float scale,
	int width,
	int height,
	int posX,
	int posY,
	float velocity):
sprite(texture)
{
	this->velocity = velocity;
	this->width = width;
	this->height = height;
	this->posX = posX;
	this->posY = posY;
	this->scale = scale;
	this->sprite.GetSprite().setPosition(sf::Vector2f(this->posX, this->posY));
	this->sprite.GetSprite().setTextureRect(sf::IntRect(0,0, width, height));
	this->sprite.GetSprite().setScale(this->scale, this->scale);
}

Entity::~Entity(){

}

Sprite &Entity::GetSprite(){
	return this->sprite;
}

void Entity::SpriteSheetMovement(sf::Clock &clock,
	float posTop, float maxTiles) {
	if (clock.getElapsedTime().asSeconds() > 0.15f){
		sf::IntRect pos = this->sprite.GetSprite().getTextureRect();
		pos.top = posTop;
		pos.left += this->width;
		if (pos.left >= this->width * maxTiles) {
			pos.left = 0;
		}
		this->sprite.GetSprite().setTextureRect(pos);
	}
}

void Entity::SetPosition(float x, float y){
	this->sprite.GetSprite().setPosition(sf::Vector2f(x, y));
}

void Entity::MoveEntity(sf::Clock &clock, float x, float y){
	sf::Vector2f pos = this->sprite.GetSprite().getPosition();

	if (x == pos.x && y < pos.y){
		this->sprite.MoveSprite(this->velocity, "top");
		SpriteSheetMovement(clock, this->height * 2, 4);
	}
	else if (x == pos.x && y > pos.y){
		this->sprite.MoveSprite(this->velocity, "bottom");
		SpriteSheetMovement(clock, this->height * 0, 4);
	}
	else if (x > pos.x && y == pos.y){
		this->sprite.MoveSprite(this->velocity, "right");
		SpriteSheetMovement(clock, this->height * 1, 4);
	}
	else if (x < pos.x && y == pos.y){
		this->sprite.MoveSprite(this->velocity, "left");
		SpriteSheetMovement(clock, this->height * 3, 4);
	}
	this->sprite.GetSprite().setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Entity::GetPosition() {
	return this->sprite.GetSprite().getPosition();
}

float Entity::GetVelocity() const {
	return this->velocity;
}
