#include "MapInterpretor.hpp"

MapInterpretor::MapInterpretor(){
	std::cout << "MAP INTERPRETOR CREATED" << std::endl;
}

MapInterpretor::~MapInterpretor(){
	std::cout << "MAP INTERPRETOR DESTROYED" << std::endl;
}

void MapInterpretor::DecryptMap(std::list<std::string> const &map){
	for (auto m : map){
		for (int i = 0; i < m.length(); i++){
			std::cout << this->GetNameTexture(m[i]) << " ";
		}
		std::cout << std::endl;
	}
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