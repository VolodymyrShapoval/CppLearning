#pragma once
#include <iostream>

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(const T& value = T(), Node<T>* next = nullptr);
	Node(const Node<T>& node);
};

