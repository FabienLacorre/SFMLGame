#ifndef __PANELMENU_HPP__
#define __PANELMENU_HPP__

#include "Panel.hpp"

class PanelMenu : public Panel{
public:
	PanelMenu(bool blocking, bool active);
	~PanelMenu();
private:
	void Run() override;
};

#endif