#include "ListGenerator.h"

std::list<int> IntListGenerator::generate(const size_t size)
{
	srand(time(NULL));
	std::list<int> newList;
	newList.resize(size);
	newList.assign(size, 0);

	for (auto& elem : newList)
	{
		elem = rand() % 100;
	}

	return newList;
}

std::list<double> DoubleListGenerator::generate(const size_t size)
{
	srand(time(NULL));
	std::list<double> newList;
	newList.resize(size);

	for (auto& elem : newList) 
	{
		elem = (rand() % 100) + (rand() % 10) / 10.0;
	}

	return newList;
}