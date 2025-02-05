#pragma once
#ifndef _VECTOR_GENERATOR_
#define _VECTOR_GENERATOR_

#include <iostream>
#include <vector>

template <class T>
class VectorGenerator
{
public:
	static void generate_vector(std::vector<int>& vec, std::size_t size);
	static void redefine_vector(std::vector<int>& vec);
};

#endif // !_VECTOR_GENERATOR_
