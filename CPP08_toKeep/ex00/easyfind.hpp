
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void	easyfind(T container, int value)
{
	if (std::find(container.begin(), container.end(), value) != container.end()) 
		std::cout << "Value " << value << " found in the container." << std::endl;
	else
		throw std::runtime_error("Value not found");
}
