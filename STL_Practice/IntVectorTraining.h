#pragma once
#ifndef _INT_VECTOR_TRAINING_
#define INT_VECTOR_TRAINING_

#include <iostream>
#include <vector>
#include "VectorTraining.h"

class IntVectorTraining : public VectorTraining<int>
{
public:
	static void generate_vector(std::vector<int>& vec, std::size_t size)
	{
		srand(time(NULL));

		vec.reserve(size);

		while (size > 0)
		{
			vec.push_back(rand() % 50 + 10);
			--size;
		}
	}

	static void redefine_vector(std::vector<int>& vec)
	{
		std::vector<int>::iterator it = vec.begin();

		while (it != vec.end())
		{
			*it = rand() % 50 + 10;
			std::advance(it, 1);
		}
	}
};

#endif // !_INT_VECTOR_TRAINING_
