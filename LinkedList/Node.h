#pragma once
#ifndef _NODE_H_
#define _NODE_H_

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


template <class T>
Node<T>::Node(const T& value, Node<T>* next)
{
	this->value = value;
	this->next = next;
}

template <class T>
Node<T>::Node(const Node<T>& node)
{
	this->value = node.value;
	this->next = node.next;
}

#endif // !_NODE_H_

