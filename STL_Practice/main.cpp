#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "VectorTraining.h"
#include "IntVectorTraining.h"

int main()
{
	try
	{
		std::vector<int> templateVec;
		IntVectorTraining::generate_vector(templateVec, 10);
		VectorTraining<int>::vector_work(templateVec, 15);
		templateVec.resize(15);
		VectorTraining<int>::print(templateVec);
		IntVectorTraining::redefine_vector(templateVec);
		VectorTraining<int>::print(templateVec);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}