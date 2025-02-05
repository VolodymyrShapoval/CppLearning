#pragma once
#ifndef _LIST_DISPLAY_
#define _LIST_DISPLAY_

#include <iostream>
#include <list>

template <class T>
using list_iterator = typename std::list<T>::iterator;
template <class T>
using list_const_iterator = typename std::list<T>::const_iterator;
template <class T>
using list_const_rev_iterator = typename std::list<T>::const_reverse_iterator;

template <class T>
class ListDisplay
{
public:
	static std::list<T> generate(const size_t size);
	static void print(const std::list<T>& myList);
	static void reverse_print(const std::list<T>& myList);
};

template <class T>
void ListDisplay<T>::print(const std::list<T>& myList)
{
	for (list_const_iterator<T> it = myList.cbegin(); it != myList.cend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <class T>
void ListDisplay<T>::reverse_print(const std::list<T>& myList)
{
	for (list_const_rev_iterator<T> it = myList.crbegin(); it != myList.crend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif // !_LIST_DISPLAY_
