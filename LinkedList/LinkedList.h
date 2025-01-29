#pragma once
#include <iostream>
#include <stdexcept>
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