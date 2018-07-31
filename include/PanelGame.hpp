#ifndef __PANELGAME_HPP_
#define __PANELMENU_HPP__

#include "Panel.hpp"
#include "TextureLoader.hpp"
#include "Entity.hpp"

class PanelGame : public Panel{
public:
	PanelGame(bool blocking, bool active, Window &win, TextureLoader &textures);
	~PanelGame() override;
private:
	void Run(sf::Event &event, sf::Clock &clock) override;

	// ENTITIES //
	Entity *player;
	Entity *fountain;
	Entity *grass;
	// -------  //
};

#endif