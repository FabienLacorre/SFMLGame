#include "MapReader.hpp"

MapReader::MapReader(std::string const &name){
	std::ifstream myfile(name);
	std::string line = "";

	if (!myfile.is_open()){
		std::cout << "Unable to open file: " << name << std::endl;
		return;
	}
	while (getline (myfile,line)) {
		this->map.push_back(line);
	}
	myfile.close();
}

MapReader::~MapReader(){
	
}

void MapReader::DisplayMap() const {
	int i = 0;
	for (auto m : this->map){
		std::cout << "[" << i << "] " << m << std::endl;
		i++;
	}
}

std::list<std::string> const &MapReader::GetMap() const {
	return (this->map);
}

