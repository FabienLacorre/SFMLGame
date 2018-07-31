#include "Panel.hpp"

Panel::Panel(bool blocking, bool active, Window &win){
	this->blocking = blocking;
	this->active = active;
	this->win = &win;
}

Panel::~Panel(){
	std::cout << "panel destroyed" << std::endl;
}

void Panel::Run(){
	std::cout << std::endl;
	std::cout << "panel run" << std::endl;
	std::cout << std::endl;
}

void Panel::SetWindow(Window &win){
	this->win = &win;
}