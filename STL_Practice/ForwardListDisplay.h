#pragma once
#ifndef _FORWARD_LIST_DISPLAY_
#define _FORWARD_LIST_DISPLAY_

#include <iostream>
#include <forward_list>

template <class T>
class ForwardListDisplay
{
public:
	static void print(const std::forward_list<T> flist);
};

template <class T>
void ForwardListDisplay<T>::print(const std::forward_list<T> flist)
{
	for (const auto& elem : flist)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

#endif // !_FORWARD_LIST_DISPLAY_



