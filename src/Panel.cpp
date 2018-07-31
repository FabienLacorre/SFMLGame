#include "Panel.hpp"

Panel::Panel(bool blocking, bool active, Window &win, TextureLoader &textures){
	this->blocking = blocking;
	this->active = active;
	this->win = &win;
	this->textureLoader = &textures;
}

Panel::~Panel(){
	std::cout << "panel destroyed" << std::endl;
}

void Panel::Run(sf::Event &event, sf::Clock &clock){
	
}

void Panel::SetWindow(Window &win){
	this->win = &win;
}