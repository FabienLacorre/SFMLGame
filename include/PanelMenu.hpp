#ifndef __PANELMENU_HPP__
#define __PANELMENU_HPP__

#include "Panel.hpp"
#include "TextureLoader.hpp"

class PanelMenu : public Panel{
public:
	PanelMenu(bool blocking, bool active, Window &win, TextureLoader &texture);
	~PanelMenu() override;
private:
	void Run(sf::Event &event, sf::Clock &clock) override;

	// ENTITIES //
	Entity *heart1;
	Entity *heart2;
	Entity *heart3;
	// -------- //
};

#endif