#include "PanelMenu.hpp"

PanelMenu::PanelMenu(bool blocking, bool active, Window &win, TextureLoader &textures):
Panel(blocking, active, win, textures){

}

PanelMenu::~PanelMenu(){
	std::cout << "panel menu destroyed" << std::endl;
}

void PanelMenu::Run() {
	std::cout << std::endl;
	std::cout << "panel menu run" << std::endl;
	std::cout << std::endl;
}