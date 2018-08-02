#include "TextureLoader.hpp"
#include <assert.h>

TextureLoader::TextureLoader(){

}

TextureLoader::~TextureLoader(){

}

void TextureLoader::PushTexture(std::string name, std::string path){
	sf::Texture *t = new sf::Texture();
	if (t->loadFromFile(path)){
		this->map.insert(std::pair<std::string, sf::Texture*>(name, t));
		std::cout << "sprite " << name << " loaded" << std::endl;
	}
	else{
		std::cout << "Error loading sprite" << std::endl;
	}
}

sf::Texture &TextureLoader::GetImage(std::string name){
	return *map[name];
}
