#include "GenerateMap.h"
#include <ctime>
#include <iostream>



GenerateMap::GenerateMap(bool newWorld)
{
	if (newWorld) {
		for (int i = 0; i < 20; i++) {
			for (int x = 0; x < 25; x++) {
				std::cout << rand() % 3 << std::endl;
			}
		}
	}
	else {
		std::cout << "FALSE" << std::endl;
	}
		

}


GenerateMap::~GenerateMap()
{
}
