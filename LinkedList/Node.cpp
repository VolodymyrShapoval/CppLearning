#include "Node.h"

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

template class Node<int>;