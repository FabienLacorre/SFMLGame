#ifndef __TEXTURELOADER_HPP__
#define __TEXTURELOADER_HPP__

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class TextureLoader {
public:
	TextureLoader();
	~TextureLoader();
	void PushTexture(std::string name, std::string path);
	sf::Texture &GetImage(std::string name);

private:
	std::map<std::string, sf::Texture*> map;
};

#endif