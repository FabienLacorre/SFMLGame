#ifndef __MAPINTERPRETOR_HPP
#define __MAPINTERPRETOR_HPP

#include <iostream>
#include <list>

class MapInterpretor {
public:
	MapInterpretor();
	~MapInterpretor();

	void DecryptMap(std::list<std::string> const &map);
	std::string const &GetNameTexture(int number);
private:
	std::pair<int, std::string> elems[3] = {
		{0, "empty"},
		{1, "grass"},
		{2, "water"},
	};

	std::string currentT;
};

#endif