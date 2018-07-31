#ifndef __PANELMENU_HPP__
#define __PANELMENU_HPP__

#include "Panel.hpp"
#include "TextureLoader.hpp"

class PanelMenu : public Panel{
public:
	PanelMenu(bool blocking, bool active, Window &win, TextureLoader &texture);
	~PanelMenu() override;
private:
	void Run() override;
};

#endif