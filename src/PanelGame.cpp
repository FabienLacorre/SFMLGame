#include "PanelGame.hpp"

PanelGame::PanelGame(bool blocking, bool active, Window &win, TextureLoader &textures):
Panel(blocking, active, win, textures){
	this->player = new Entity(this->textureLoader->GetImage("player"), 2, 16, 22, 300, 300, 2);
	this->fountain = new Entity(this->textureLoader->GetImage("fountain"), 2, 48, 45, 50, 50, 0);
	this->grass = new Entity(this->textureLoader->GetImage("grass"), 2, 16, 16, 50, 50, 0);
}

PanelGame::~PanelGame(){
	std::cout << "panel Game destroyed" << std::endl;
}

void PanelGame::Run(sf::Event &event, sf::Clock &clock) {
	// TOUCH EVENT //
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		player->MoveEntity(clock, player->GetPosition().x, player->GetPosition().y + player->GetVelocity());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		player->MoveEntity(clock, player->GetPosition().x, player->GetPosition().y - player->GetVelocity());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		player->MoveEntity(clock, player->GetPosition().x - player->GetVelocity(), player->GetPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		player->MoveEntity(clock, player->GetPosition().x + player->GetVelocity(), player->GetPosition().y);
	}
    // ----- //

	for (int i = 0; i < 37; i++){
		for (int j = 0; j < 37; j++) {
			this->grass->SetPosition(i * 16, j * 16);
			this->win->DrawSprite(grass->GetSprite());
		}
	}

	this->fountain->SpriteSheetMovement(clock, 0, 3);

	this->win->DrawSprite(this->fountain->GetSprite());
	this->win->DrawSprite(this->player->GetSprite());
}