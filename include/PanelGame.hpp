#ifndef __PANELGAME_HPP_
#define __PANELMENU_HPP__

#include "Panel.hpp"

class PanelGame : public Panel{
public:
	PanelGame(bool blocking, bool active, Window &win);
	~PanelGame() override;
private:
	void Run() override;
};

#endif