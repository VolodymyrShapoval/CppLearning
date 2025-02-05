#include "ListDisplay.h"

std::list<int> ListDisplay<int>::generate(const size_t size)
{
	srand(time(NULL));
	std::list<int> newList;
	newList.resize(size);
	newList.assign(size, 0);

	for (list_iterator<int> it = newList.begin(); it != newList.end(); ++it)
	{
		*it = rand() % 100;
	}

	return newList;
}

std::list<double> ListDisplay<double>::generate(const size_t size)
{
	srand(time(NULL));
	std::list<double> newList;
	newList.resize(size);

	for (list_iterator<double> it = newList.begin(); it != newList.end(); ++it)
	{
		*it = (rand() % 100) + (rand() % 10) / 10.0;
	}

	return newList;
}

template class ListDisplay<int>;
template class ListDisplay<double>;