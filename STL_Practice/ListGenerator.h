#pragma once
#ifndef _LIST_GENERATOR_
#define _LIST_GENERATOR_

#include <iostream>
#include <list>

template <class T>
class IListGenerator
{
public:
	virtual std::list<T> generate(const size_t size) = 0;
};

class IntListGenerator : IListGenerator<int>
{
public:
	std::list<int> generate(const size_t size) override;
};

class DoubleListGenerator : IListGenerator<double>
{
public:
	std::list<double> generate(const size_t size) override;
};

#endif // !_LIST_GENERATOR_