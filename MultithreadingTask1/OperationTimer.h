#pragma once
#ifndef _OPERATION_TIMER_
#define _OPERATION_TIMER_

#include <iostream>
#include <chrono>

class OperationTimer
{
public:
	OperationTimer();
	~OperationTimer();

private:
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
};

#endif // !_OPERATION_TIMER_



