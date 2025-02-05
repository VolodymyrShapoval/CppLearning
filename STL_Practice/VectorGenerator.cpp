#include "VectorGenerator.h"

void VectorGenerator<int>::generate_vector(std::vector<int>& vec, std::size_t size)
{
	srand(time(NULL));

	vec.reserve(size);

	while (size > 0)
	{
		vec.push_back(rand() % 50 + 10);
		--size;
	}
}

void VectorGenerator<int>::redefine_vector(std::vector<int>& vec)
{
	std::vector<int>::iterator it = vec.begin();

	while (it != vec.end())
	{
		*it = rand() % 50 + 10;
		std::advance(it, 1);
	}
}

template class VectorGenerator<int>;