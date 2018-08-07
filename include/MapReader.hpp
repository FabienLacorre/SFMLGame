#ifndef __MAPREADER_HPP__
#define __MAPREADER_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class MapReader {
public:
	MapReader(std::string const &name);
	~MapReader();
	void DisplayMap() const;
	std::list<std::string> const &GetMap() const; 

private:
	std::list<std::string> map;
};

#endif