#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sprite.hpp"

class Entity {
public:
	Entity(sf::Texture &texture,
		float scale,
		int width,
		int height,
		int posX,
		int posY,
		float velocity);
	~Entity();

	Sprite &GetSprite();
	void MoveEntity(sf::Clock &clock, float x, float y);
	sf::Vector2f GetPosition();
	float GetVelocity() const;
	void SpriteSheetMovement(sf::Clock &clock, float posTop, float maxTiles);
	void SetPosition(float x, float y);

protected:
	Sprite sprite;
	float velocity;
	int width;
	int height;
	int posX;
	int posY;
	float scale;
};

#endif
