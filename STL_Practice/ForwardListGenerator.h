#pragma once
#ifndef _FORWARD_LIST_GENERATOR_
#define _FORWARD_LIST_GENERATOR_

#include <iostream>
#include <forward_list>

template <class T>
class IForwardListGenerator
{
public:
	virtual std::forward_list<T> generate(const size_t size) = 0;
};

class IntForwardListGenerator : public IForwardListGenerator<int>
{
public:
	std::forward_list<int> generate(const size_t size) override;
};

#endif // !_FORWARD_LIST_GENERATOR_



