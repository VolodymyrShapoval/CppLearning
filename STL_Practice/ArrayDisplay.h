#pragma once
#ifndef _ARRAY_DISPLAY_
#define _ARRAY_DISPLAY_

#include <iostream>
#include <array>


class ArrayDisplay
{
public:
	template <class T, std::size_t N>
	static void print(const std::array<T, N>& arr);
};

template <class T, std::size_t N>
void ArrayDisplay::print(const std::array<T, N>& arr)
{
	for (const auto& elem : arr)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

#endif // !_ARRAY_DISPLAY_





