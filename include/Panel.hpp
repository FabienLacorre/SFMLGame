#ifndef __PANEL_HPP__
#define __PANEL_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "TextureLoader.hpp"

class Panel {
public:
	Panel(bool blocking, bool active, Window &win, TextureLoader &textures);
	virtual ~Panel();
	virtual void Run();

	void SetWindow(Window &win);
protected:
	bool blocking;
	bool active;

	Window *win;
	TextureLoader *textureLoader;
};

#endif