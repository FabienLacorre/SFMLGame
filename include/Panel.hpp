#ifndef __PANEL_HPP__
#define __PANEL_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Panel {
public:
	Panel(bool blocking, bool active, Window &win);
	virtual ~Panel();
	virtual void Run();

	void SetWindow(Window &win);
protected:
	bool blocking;
	bool active;

	Window *win;
};

#endif