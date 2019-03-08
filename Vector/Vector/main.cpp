#include <iostream>
#include "Vector.h"
#include <string>
#include <vector>

int main()
{
	DataStructure::Vector<int> v{ 10,20,30,40,50 };

	for (auto elem : v)
	{
		std::cout << elem << std::endl;
	}

	v.clear();

	for (auto elem : v)
	{
		std::cout << elem << std::endl;
	}

	return 0;
}