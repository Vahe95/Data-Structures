#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> vec;
	Vector<int> vec1(10, 5);



	std::cout << vec1.front() << std::endl;
	std::cout << vec1.back() << std::endl;
	std::cout << vec1.begin() << std::endl;

	return 0;
}