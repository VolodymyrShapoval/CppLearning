#pragma once
#ifndef _LIST_TRAINING_
#define _LIST_TRAINING_

#include <iostream>
#include <list>

template <class T>
using list_const_iterator = typename std::list<T>::const_iterator;

template <class T>
class ListTraining
{
public:
	static void print(const std::list<T>& myList);
	static void reverse_print(const std::list<T>& myList);
};


template <class T>
void ListTraining<T>::print(const std::list<T>& myList)
{
	for (list_const_iterator<T> it = myList.cbegin(); it != myList.cend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <class T>
void ListTraining<T>::reverse_print(const std::list<T>& myList)
{

}

#endif // !_LIST_TRAINING_
