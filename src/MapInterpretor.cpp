#include "MapInterpretor.hpp"

MapInterpretor::MapInterpretor(){
	std::cout << "MAP INTERPRETOR CREATED" << std::endl;
}

MapInterpretor::~MapInterpretor(){
	std::cout << "MAP INTERPRETOR DESTROYED" << std::endl;
}

std::list<std::string> &MapInterpretor::DecryptMap(std::list<std::string> const &map){
	this->currentM.clear();
	for (auto m : map){
		for (int i = 0; i < m.length(); i++){
			this->currentM.push_back(this->GetNameTexture(m[i]));
		}
		this->currentM.push_back("jump");
	}
	return this->currentM;
}

std::string const &MapInterpretor::GetNameTexture(int number){
	number = number - '0';
	for (auto e : this->elems){
		if (e.first == number){
			this->currentT = e.second;
		}
	}
	return this->currentT;
}

