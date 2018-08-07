#ifndef __PANELGAME_HPP_
#define __PANELMENU_HPP__

#include "Panel.hpp"
#include "TextureLoader.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "MapReader.hpp"
#include "MapInterpretor.hpp"
#include <list>

class PanelGame : public Panel{
public:
	PanelGame(bool blocking, bool active, Window &win, TextureLoader &textures);
	~PanelGame() override;
private:
	void Run(sf::Event &event, sf::Clock &clock) override;
	Entity *GetEntityByName(std::string name);

	// ENTITIES //
	std::list<std::pair<std::string, Entity *>> elems;
	// -------  //

	// MAP //
	MapReader *mapReader;
	MapInterpretor *mapInterpretor;
	// --- //
};

#endif