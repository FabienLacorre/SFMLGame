#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Entity.hpp"

class Player : public Entity {
public:
	Player(sf::Texture &texture, float scale, int width, int height,
		int posX, int posY, float velocity);
	~Player();

private:
};

#endif