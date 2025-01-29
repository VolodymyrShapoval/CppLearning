#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
public:
	explicit LinkedList();
	explicit LinkedList(const T& value);
	explicit LinkedList(const LinkedList& linkedList);
	~LinkedList();

	T& operator [] (size_t index) const;
	bool operator == (const LinkedList<T>& other) const;
	bool operator != (const LinkedList<T>& other) const;

	LinkedList<T>& operator +(const LinkedList<T>& other) = delete;
	LinkedList<T>& operator -(const LinkedList<T>& other) = delete;
	LinkedList<T>& operator /(const LinkedList<T>& other) = delete;
	LinkedList<T>& operator *(const LinkedList<T>& other) = delete;
	LinkedList<T>& operator ++() = delete;
	LinkedList<T>& operator ++(int) = delete;
	LinkedList<T>& operator --() = delete;
	LinkedList<T>& operator --(int) = delete;

	inline int getSize() const;

	T& getHead() const;

	void pushFront(const T& value);

	void pushBack(const T& value);

	void popFront();

	void popBack();

	void insert(const T& value, int index);

	void removeAt(int index);

	void generate(int size, int start, int end);

	void print() const;

	void clear();

private:
	Node<T>* head;
	int size;
};


template <class T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const T& value)
{
	this->head = new Node<T>(value);
	this->size = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& linkedList)
{
	if (linkedList.head == nullptr)
	{
		this->head = nullptr;
		this->size = 0;
		return;
	}
	Node<T>* current = linkedList.head;
	while (current != nullptr)
	{
		pushBack(current->value);
		current = current->next;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
T& LinkedList<T>::operator [] (size_t index) const
{
	if (index >= this->size)
	{
		throw invalid_argument("Invalid index!");
	}

	Node<T>* current = head;
	while (index > 0)
	{
		current = current->next;
		--index;
	}

	return current->value;
}

template <class T>
bool LinkedList<T>::operator == (const LinkedList<T>& other) const
{
	if (this->size != other.size)
		return false;

	Node<T>* currentNode = head;
	Node<T>* otherNode = other.head;
	for (size_t i = 0; i < size; ++i)
	{
		if (currentNode->value != otherNode->value)
			return false;
		currentNode = currentNode->next;
		otherNode = otherNode->next;
	}
	return true;
}

template <class T>
bool LinkedList<T>::operator != (const LinkedList<T>& other) const
{
	return !(*this == other);
}

template <class T>
inline int LinkedList<T>::getSize() const
{
	return this->size;
}

template <class T>
inline T& LinkedList<T>::getHead() const
{
	if (head == nullptr)
	{
		throw runtime_error("Empty linked list");
	}

	return head->value;
}

template <class T>
void LinkedList<T>::pushFront(const T& value)
{
	head = new Node<T>(value, head);
	++size;
}

template <class T>
void LinkedList<T>::pushBack(const T& value)
{
	if (head == nullptr)
	{
		head = new Node<T>(value);
		++size;
		return;
	}

	Node<T>* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = new Node<T>(value);
	++size;
}

template <class T>
void LinkedList<T>::popFront()
{
	if (head == nullptr)
	{
		cout << "Empty linked list" << endl;
		return;
	}

	Node<T>* current = head;
	head = head->next;
	delete current;
	--size;
}

template <class T>
void LinkedList<T>::popBack()
{
	if (head == nullptr)
	{
		cout << "Empty linked list" << endl;
		return;
	}

	removeAt(size - 1);
}

template <class T>
void LinkedList<T>::insert(const T& value, int index)
{
	if (index > size)
	{
		throw exception("You cannot insert node to non-existent position");
	}
	else if (index < 0)
	{
		throw exception("Index cannot be less than 0");
	}
	else if (index == 0)
	{
		pushFront(value);
		return;
	}

	Node<T>* current = head;
	for (size_t i = 0; i < index - 1; ++i)
	{
		current = current->next;
	}
	current->next = new Node<T>(value, current->next);
	++size;
}

template <class T>
void LinkedList<T>::removeAt(int index)
{
	if (index >= size)
	{
		throw exception("You cannot remove node from non-existent position");
	}
	else if (index < 0)
	{
		throw exception("Index cannot be less than 0");
	}
	else if (index == 0)
	{
		popFront();
		return;
	}

	Node<T>* current = head;
	for (size_t i = 0; i < index - 1; ++i)
	{
		current = current->next;
	}
	Node<T>* deleteNode = current->next;
	current->next = deleteNode->next;
	delete deleteNode;
	--size;
}

template <class T>
void LinkedList<T>::generate(int size, int start, int end)
{
	if (size < 0)
	{
		throw exception("Size of linked list cannot be less than 0");
	}
	else if (size == 0)
	{
		return;
	}
	if (this->head != nullptr)
	{
		clear();
	}

	for (size_t i = 0; i < size; ++i)
	{
		pushFront(rand() % (end - start + 1) + start);
	}
}

template <class T>
void LinkedList<T>::print() const
{
	if (head == nullptr)
	{
		cout << "Empty linked list" << endl;
		return;
	}

	Node<T>* current = head;
	while (current != nullptr)
	{
		cout << current->value << "->";
		current = current->next;
	}
	cout << "nullptr" << endl;
}

template <class T>
void LinkedList<T>::clear()
{
	while (size)
	{
		popFront();
	}
}

#endif // !_LINKED_LIST_H_