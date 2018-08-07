#include "PanelGame.hpp"

PanelGame::PanelGame(bool blocking, bool active, Window &win, TextureLoader &textures):
Panel(blocking, active, win, textures){

	this->mapReader = new MapReader("./map/Map.txt");
    //this->mapReader->DisplayMap();

	this->mapInterpretor = new MapInterpretor();
    //this->mapInterpretor->DecryptMap(mapReader->GetMap());

	this->elems.push_back(std::make_pair(
		"player",
		new Player(this->textureLoader->GetImage("player"), 2, 16, 22, 300, 300, 2)
		));
	this->elems.push_back(std::make_pair(
		"water",
		new Entity(this->textureLoader->GetImage("water"), 2, 16, 16, 16, 16 ,0)
		));
	this->elems.push_back(std::make_pair(
		"grass",
		new Entity(this->textureLoader->GetImage("grass"), 2, 16, 16, 50, 50, 0)
		));
	this->elems.push_back(std::make_pair(
		"fountain",
		new Entity(this->textureLoader->GetImage("fountain"), 2, 48, 45, 200, 50, 0)
		));
	this->elems.push_back(std::make_pair(
		"fountain2",
		new Entity(this->textureLoader->GetImage("fountain"), 2, 48, 45, 50, 50, 0)
		));
}


PanelGame::~PanelGame(){
	std::cout << "panel Game destroyed" << std::endl;

	delete this->mapReader;
	delete this->mapInterpretor;
}

Entity *PanelGame::GetEntityByName(std::string name){
	for (auto e : this->elems){
		if (e.first == name){
			return e.second;
		}
	}
	return NULL;
}

void PanelGame::Run(sf::Event &event, sf::Clock &clock) {

	// TOUCH EVENT //
	Entity *player = this->GetEntityByName("player");
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

	// DISPLAY BACKGROUND WHIT MAP //
	std::list<std::string> background = this->mapInterpretor->DecryptMap(this->mapReader->GetMap());
	int x = 0;
	int y = 0;
	for (auto b : background){
		if (b == "jump"){
			x = 0;
			y += 1;
		} else if (b == "empty") {
			x += 1;
		} else {
			this->GetEntityByName(b)->SetPosition(x * 32, y * 32);
			this->win->DrawSprite(this->GetEntityByName(b)->GetSprite());
			x += 1;
		}
	}

	// --------------------------- //

	this->GetEntityByName("fountain")->SpriteSheetMovement(clock, 0, 3);
	this->GetEntityByName("fountain2")->SpriteSheetMovement(clock, 0, 3);

	this->win->DrawSprite(this->GetEntityByName("fountain")->GetSprite());
	this->win->DrawSprite(this->GetEntityByName("fountain2")->GetSprite());
	this->win->DrawSprite(player->GetSprite());
}