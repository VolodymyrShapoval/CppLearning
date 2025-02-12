#include "OperationTimer.h"

OperationTimer::OperationTimer()
{
	start = std::chrono::high_resolution_clock::now();
}

OperationTimer::~OperationTimer()
{
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "Operation duration: " << duration.count() << " sec" << std::endl;
}