#include "PanelMenu.hpp"

PanelMenu::PanelMenu(bool blocking, bool active, Window &win, TextureLoader &textures):
Panel(blocking, active, win, textures){
	this->heart1 = new Entity(this->textureLoader->GetImage("heart"), 2, 12, 11, 10, 10, 0);
	this->heart2 = new Entity(this->textureLoader->GetImage("heart"), 2, 12, 11, 10+(12*2), 10, 0);
	this->heart3 = new Entity(this->textureLoader->GetImage("heart"), 2, 12, 11, 10+((12+12)*2), 10, 0);

}

PanelMenu::~PanelMenu(){
	std::cout << "panel menu destroyed" << std::endl;
}

void PanelMenu::Run(sf::Event &event, sf::Clock &clock) {
	this->win->DrawSprite(this->heart1->GetSprite());
	this->win->DrawSprite(this->heart2->GetSprite());
	this->win->DrawSprite(this->heart3->GetSprite());
}