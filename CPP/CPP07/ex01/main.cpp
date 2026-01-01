
#include <iostream>
#include "iter.hpp"

void printInt(const int& x) { std::cout << x << " "; }
void doubleInt(int& x) { x *= 2; }


int main()
{
	const int len = 5;
	int arr[len] = {1, 2, 3, 4, 5};

	iter(arr, len, printInt);
	std::cout << std::endl;

	iter(arr, len, doubleInt);
	std::cout << std::endl;
	
	iter(arr, len, printInt);
	std::cout << std::endl;

	return 0;
}

