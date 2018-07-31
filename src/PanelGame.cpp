#include "PanelGame.hpp"

PanelGame::PanelGame(bool blocking, bool active, Window &win):
Panel(blocking, active, win){

}

PanelGame::~PanelGame(){
	std::cout << "panel Game destroyed" << std::endl;
}

void PanelGame::Run() {
	std::cout << std::endl;
	std::cout << "panel Game run" << std::endl;
	std::cout << std::endl;

}