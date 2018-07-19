#include "Panel.hpp"

Panel::Panel(bool blocking, bool active){
	this->blocking = blocking;
	this->active = active;
}

Panel::~Panel(){

}

void Panel::Run(){
	std::cout << std::endl;
	std::cout << "panel run" << std::endl;
	std::cout << std::endl;
}