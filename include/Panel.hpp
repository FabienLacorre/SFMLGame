#ifndef __PANEL_HPP__
#define __PANEL_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Panel {
public:
	Panel(bool blocking, bool active);
	virtual ~Panel();
	virtual void Run();
protected:
	bool blocking;
	bool active;
};

#endif