#pragma once
#ifndef _VECTOR_DISPLAY_
#define _VECTOR_DISPLAY_

#include <iostream>
#include <string>
#include <vector>

template <class T>
using vector_const_iter = typename std::vector<T>::const_iterator;
template <class T>
using vector_const_rev_iter = typename std::vector<T>::const_reverse_iterator;

template <class T>
class VectorDisplay
{
public:
	static void print(const std::vector<T>& myVec);
	static void reverse_print(const std::vector<T>& myVec);
	static void vector_work(size_t countOfElements, const T& element, size_t reserveNumber);
	static void vector_work(const std::vector<T>& arr, size_t reserveNumber);
};


template <class T>
void VectorDisplay<T>::print(const std::vector<T>& myVec)
{
	if (myVec.empty())
	{
		std::cout << "Vector is empty" << std::endl;
		return;
	}

	std::cout << "myVec: ";
	for (vector_const_iter<T> it = myVec.cbegin(); it != myVec.cend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

template <class T>
void VectorDisplay<T>::reverse_print(const std::vector<T>& myVec)
{
	if (myVec.empty())
	{
		std::cout << "Vector is empty" << std::endl;
		return;

	}

	std::cout << "myVec(reversed): ";
	for (vector_const_rev_iter<T> it = myVec.rbegin(); it != myVec.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

template <class T>
void VectorDisplay<T>::vector_work(size_t countOfElements, const T& element, size_t reserveNumber)
{
	std::vector<T> myVec(countOfElements, element);
	myVec.reserve(reserveNumber);

	std::cout << "Is empty: " << std::boolalpha << myVec.empty() << std::endl;

	print(myVec);
	reverse_print(myVec);

	std::cout << "Capacity: " << myVec.capacity() << std::endl;
	myVec.shrink_to_fit();
	std::cout << "Capacity(after shrink): " << myVec.capacity() << std::endl;
}

template <class T>
void VectorDisplay<T>::vector_work(const std::vector<T>& arr, size_t reserveNumber)
{
	std::vector<T> myVec(arr);
	myVec.reserve(reserveNumber);

	std::cout << "Is empty: " << std::boolalpha << myVec.empty() << std::endl;

	print(myVec);
	reverse_print(myVec);

	std::cout << "Capacity: " << myVec.capacity() << std::endl;
	myVec.shrink_to_fit();
	std::cout << "Capacity(after shrink): " << myVec.capacity() << std::endl;
}

#endif // !_VECTOR_DISPLAY_

