#ifndef __PANELGAME_HPP_
#define __PANELMENU_HPP__

#include "Panel.hpp"
#include "TextureLoader.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class PanelGame : public Panel{
public:
	PanelGame(bool blocking, bool active, Window &win, TextureLoader &textures);
	~PanelGame() override;
private:
	void Run(sf::Event &event, sf::Clock &clock) override;

	// ENTITIES //
	Player *player;
	Entity *fountain;
	Entity *fountain2;
	Entity *grass;
	// -------  //
};

#endif