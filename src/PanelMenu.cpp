#include "PanelMenu.hpp"

PanelMenu::PanelMenu(bool blocking, bool active):
Panel(blocking, active){

}

PanelMenu::~PanelMenu(){
	std::cout << "panel menu destroyed" << std::endl;
}

void PanelMenu::Run() {
	std::cout << std::endl;
	std::cout << "panel menu run" << std::endl;
	std::cout << std::endl;
}