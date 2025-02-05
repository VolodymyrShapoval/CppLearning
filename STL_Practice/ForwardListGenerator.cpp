#include "ForwardListGenerator.h"


std::forward_list<int> IntForwardListGenerator::generate(const size_t size)
{
	srand(time(NULL));

	std::forward_list<int> flist;
	flist.resize(size);

	for (auto& elem : flist)
	{
		elem = rand() % 100;
	}
	return flist;
}