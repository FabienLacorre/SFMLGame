#include "PanelMenu.hpp"

PanelMenu::PanelMenu(bool blocking, bool active, Window &win, TextureLoader &textures):
Panel(blocking, active, win, textures){

}

PanelMenu::~PanelMenu(){
	std::cout << "panel menu destroyed" << std::endl;
}

void PanelMenu::Run(sf::Event &event, sf::Clock &clock) {

}