#pragma once
#ifndef _INT_VECTOR_TRAINING_
#define INT_VECTOR_TRAINING_

#include <iostream>
#include <vector>
#include "VectorTraining.h"

class IntVectorTraining : public VectorTraining<int>
{
public:
	static void generate_vector(std::vector<int>& vec, std::size_t size);
	static void redefine_vector(std::vector<int>& vec);
};

#endif // !_INT_VECTOR_TRAINING_
